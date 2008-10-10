// This is brl/bpro/core/vil_pro/vil_save_image_view_binary_process.h
#ifndef vil_save_image_view_binary_process_h_
#define vil_save_image_view_binary_process_h_
//:
// \file
// \brief A process for saving an image to disk
// \author Daniel Crispell
// \date 06/06/04
//
// \verbatim
//  Modifications
//   <none yet>
// \endverbatim

#include <vcl_string.h>
#include <bprb/bprb_process.h>

class vil_save_image_view_binary_process : public bprb_process
{
 public:

  vil_save_image_view_binary_process();

  //: Copy Constructor (no local data)
  vil_save_image_view_binary_process(const vil_save_image_view_binary_process& other): bprb_process(*static_cast<const bprb_process*>(&other)){}

 ~vil_save_image_view_binary_process();

  //: Clone the process
  virtual vil_save_image_view_binary_process* clone() const {return new vil_save_image_view_binary_process(*this);}

  vcl_string name(){return "SaveImageViewBinaryProcess";}

  bool init() { return true; }
  bool execute();
  bool finish(){return true;}
};

#endif //vil_save_image_view_binary_process_h_
