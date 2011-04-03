#ifndef boxm2_cpp_processes_h_
#define boxm2_cpp_processes_h_

#include <bprb/bprb_func_process.h>
#include <bprb/bprb_macros.h>

//the init functions
DECLARE_FUNC_CONS(boxm2_cpp_render_expected_image_process);
DECLARE_FUNC_CONS(boxm2_cpp_update_image_process);
DECLARE_FUNC_CONS(boxm2_cpp_refine_process2);
DECLARE_FUNC_CONS(boxm2_cpp_change_detection_process2);
#endif