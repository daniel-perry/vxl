//    Volume rendering sample
//    This sample loads a 3D volume

// Utilities, OpenCL and system includes
#include <GL/glew.h>
#include <bocl/bocl_cl.h>

//vil and camera includes
#include <vpgl/vpgl_perspective_camera.h>

//executable args
#include <vul/vul_arg.h>
#include <vul/vul_file.h>

//boxm2 scene stuff
#include <boxm2/ocl/boxm2_opencl_cache.h>
#include <boxm2/boxm2_scene.h>

//vgui stuff
#include <boxm2/view/boxm2_ocl_render_trajectory_tableau.h>

#include <boxm2/view/boxm2_view_utils.h>
#include <boxm2/boxm2_util.h>
#include <vgui/vgui.h>
#include <vgui/vgui_adaptor.h>
#include <vgui/vgui_window.h>
#include <vgui/vgui_image_tableau.h>
#include <vgui/vgui_clear_tableau.h>
#include <vgui/vgui_easy3D_tableau.h>
#include <vgui/vgui_viewer3D_tableau.h>
#include <vgui/vgui_shell_tableau.h>
#include <vgui/vgui_viewer2D_tableau.h>


int main(int argc, char ** argv)
{
#ifdef WIN32
  int my_argc = argc+1;
  char** my_argv = new char*[argc+1];
  for (int i=0; i<argc; i++)
    my_argv[i] = argv[i];
  my_argv[argc] = new char[13];
  vcl_strcpy(my_argv[argc], "--mfc-use-gl");
  vgui::init(my_argc, my_argv);
  //delete[] my_argv[argc];
  //delete[] my_argv;

#else
    //init vgui (should choose/determine toolkit)
    vgui::init(argc, argv);
#endif
    vul_arg<vcl_string> scene_file("-scene", "scene filename", vul_arg<vcl_string>::is_required);
    vul_arg<vcl_string> second_scene_file("-pscene", "second scene filename", "");
    vul_arg<unsigned>   ni("-ni", "Width of output image", 1280);
    vul_arg<unsigned>   nj("-nj", "Height of output image", 720);
    vul_arg<vcl_string> identifier("-ident", "identifier of the appearance data to be displayed, e.g. illum_bin_0", "");
    vul_arg<unsigned>   gpu_idx("-gpu_idx", "GPU index for multi GPU set up", 0);
    vul_arg<vcl_string> trajectory_file("-tr", "name of the file with waypoints", "");
    vul_arg<float> focallength("-f", "Focal Length", 1200.00);
    // need this on some toolkit implementations to get the window up.

    vul_arg_parse(argc, argv);
        
    vcl_ifstream ifile(trajectory_file().c_str());
    if(!ifile ) 
    {
        vcl_cout<<"Can't open trajectory file "<<trajectory_file()<<vcl_endl;
        return 0;
    }
    vcl_list<vgl_point_3d<double> > waypoints;
    vcl_cout<<"Trajectory "<<vcl_endl;
    while(!ifile.eof())
    {
        double x,y,z;
        ifile>>x>>y>>z;
        waypoints.push_back(vgl_point_3d<double>(x,y,z));
        vcl_cout<<x<<" "<<y<<" "<<z<<vcl_endl;
    }
    ifile.close();
    //make bocl manager
    bocl_manager_child_sptr mgr =bocl_manager_child::instance();
    if (gpu_idx() >= mgr->gpus_.size()){
      vcl_cout << "GPU index out of bounds" << vcl_endl;
      return -1;
    }
    bocl_device_sptr device = mgr->gpus_[gpu_idx()];
    vcl_cout << "Using: " << *device;
    boxm2_scene_sptr scene = new boxm2_scene(scene_file());
    vpgl_calibration_matrix<double> K(focallength(), vgl_point_2d<double>(ni()/2, nj()/2));
    vgl_rotation_3d<double> R;
    vpgl_perspective_camera<double>* pcam =
        new vpgl_perspective_camera<double>(K, waypoints.front(), R);

    //stare at the center of the scene
    vgl_vector_3d<double> up(0.0, 0.0, 1.0);
    vcl_list<vgl_point_3d<double> >::iterator waypoint_iter = waypoints.begin();
    pcam->look_at(vgl_homg_point_3d<double>(*(++waypoint_iter)), up);
    //create cache, grab singleton instance
    boxm2_lru_cache::create(scene);
    boxm2_opencl_cache_sptr opencl_cache=new boxm2_opencl_cache(scene,device); //allow 4 blocks inthe cache



    
    //create a new ocl_draw_glbuffer_tableau, window, and initialize it
    boxm2_ocl_render_trajectory_tableau_new bit_tableau;
    bit_tableau->init(device, opencl_cache, scene, ni(), nj(), pcam, identifier(), waypoints,second_scene_file());
    //create window, attach the new tableau and status bar
    vgui_window* win = vgui::produce_window(ni()+100, nj()+100, "OpenCl Volume Visualizer (Render)");
    win->get_adaptor()->set_tableau(bit_tableau);
    bit_tableau->set_statusbar(win->get_statusbar());
    win->show();
    //set vgui off
    GLboolean bGLEW = glewIsSupported("GL_VERSION_2_0  GL_ARB_pixel_buffer_object");
    vcl_cout << "GLEW is supported= " << bGLEW << vcl_endl;
    return vgui::run();
}
