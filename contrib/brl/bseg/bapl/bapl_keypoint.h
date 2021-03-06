// This is brl/bseg/bapl/bapl_keypoint.h
#ifndef bapl_keypoint_h_
#define bapl_keypoint_h_
//:
// \file
// \brief The bapl keypoint base class.
// \author Matthew Leotta, (mleotta@lems.brown.edu)
// \date Sat Nov 8 2003
//
// \verbatim
//  Modifications
//   <none>
// \endverbatim

#include <vbl/vbl_ref_count.h>
#include <vnl/vnl_vector_fixed.h>
#include <vcl_iosfwd.h>

//: Base class for all affine patch keypoints
class bapl_keypoint : public vbl_ref_count
{
 public:
  //: Constructor
  bapl_keypoint() {}
  //: Destructor
  ~bapl_keypoint() {}

  //: Accessor for the descriptor vector
  virtual const vnl_vector_fixed<double,128>& descriptor() const = 0;

  //: Print a summary of the keypoint data to a stream
  virtual void print_summary( vcl_ostream& os) const = 0;

  void set_id(unsigned id) { id_ = id; }
  unsigned id() const { return id_; }

 protected:
  unsigned id_;
};

//: Print a summary of the keypoint data to a stream
vcl_ostream& operator<< (vcl_ostream& os, bapl_keypoint const & k);

#endif // bapl_keypoint_h_
