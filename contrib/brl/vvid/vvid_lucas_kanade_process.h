// This is brl/vvid/vvid_lucas_kanade_process.h
#ifndef vvid_lucas_kanade_process_h_
#define vvid_lucas_kanade_process_h_
//--------------------------------------------------------------------------------
//:
// \file
// \brief  computes the Lucas-Kanade motion vector.
// \author
//   J.L. Mundy
//
// \verbatim
//  Modifications:
//   J.L. Mundy February 19, 2003
//  Initial version.
// \endverbatim
//-----------------------------------------------------------------------------

#include <vcl_vector.h>
#include <vil/vil_memory_image_of.h>
#include <vvid/vvid_video_process.h>

class vvid_lucas_kanade_process : public vvid_video_process
{
 public:
  enum state_symbol {NO_IMAGE=0, FIRST_IMAGE, IN_PROCESS};
  vvid_lucas_kanade_process(bool down_sample=false, int window_size=2,
                            double thresh=20000);
  ~vvid_lucas_kanade_process();
  virtual output_type get_output_type(){return IMAGE;}
  //: compute lucas_kanade
  virtual bool execute();
  virtual bool finish();
  bool downsample_;
  int window_size_;
  double thresh_;
 private:
  //local methods
  void compute_lucas_kanade(vil_memory_image_of<float>& image);
  void update_queue(vil_image ix);
  //members
  state_symbol state_;
  bool first_frame_;
  vcl_vector<vil_image> queue_;
};

#endif // vvid_lucas_kanade_process_h_
