// This is vxl/vgl/vgl_vector_2d.txx
#ifndef vgl_vector_2d_txx_
#define vgl_vector_2d_txx_

#include "vgl_vector_2d.h"

#include <vcl_cstdlib.h> // abort()
#include <vcl_cmath.h> // sqrt() , acos()
#include <vcl_iostream.h>

template <class T>
double vgl_vector_2d<T>::length() const
{
  return vcl_sqrt( 0.0+x()*x()+y()*y() );
}

template<class T>
double angle(vgl_vector_2d<T> const& a, vgl_vector_2d<T> const& b)
{
  return vcl_acos(cos_angle(a,b));
}

template <class T>
bool parallel(vgl_vector_2d<T> const& a, vgl_vector_2d<T> const& b, double eps)
{
  T cross = cross_product(a,b); // should be zero
  if (eps <= 0 || cross == T(0)) return cross == T(0);
  // Since cross != 0, a and b cannot have zero length:
  double dev = cross / a.length() / a.length();
  return (dev < eps && -dev < eps);
}

//: Write "<vgl_vector_2d x,y> " to stream
template <class T>
vcl_ostream&  operator<<(vcl_ostream& s, vgl_vector_2d<T> const& p)
{
  return s << "<vgl_vector_2d "<< p.x() << "," << p.y() <<  "> ";
}

//: Read x y from stream
template <class T>
vcl_istream&  operator>>(vcl_istream& s, vgl_vector_2d<T>& p)
{
  T x, y; s >> x >> y;
  p.set(x,y); return s;
}


#undef VGL_VECTOR_2D_INSTANTIATE
#define VGL_VECTOR_2D_INSTANTIATE(T) \
template class vgl_vector_2d<T >;\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator+    (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator-    (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >&     operator+=   (vgl_vector_2d<T >&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >&     operator-=   (vgl_vector_2d<T >&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator+    (vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator-    (vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator*    (T, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator*    (vgl_vector_2d<T > const&, T));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      operator/    (vgl_vector_2d<T > const&, double));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >&     operator*=   (vgl_vector_2d<T >&, T));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >&     operator/=   (vgl_vector_2d<T >&, double));\
VCL_INSTANTIATE_INLINE(T      dot_product  (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(T      inner_product(vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(T      cross_product(vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(double cos_angle    (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
template               double angle        (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&);\
template               bool   parallel     (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&, double);\
VCL_INSTANTIATE_INLINE(double operator/    (vgl_vector_2d<T > const&, vgl_vector_2d<T > const&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >&     normalize    (vgl_vector_2d<T >&));\
VCL_INSTANTIATE_INLINE(vgl_vector_2d<T >      normalized   (vgl_vector_2d<T > const&));\
template        vcl_ostream&  operator<<   (vcl_ostream&, vgl_vector_2d<T >const&);\
template        vcl_istream&  operator>>   (vcl_istream&, vgl_vector_2d<T >&)

#endif // vgl_vector_2d_txx_
