#include <testlib/testlib_register.h>

DECLARE(test_detector);
DECLARE(test_region_proc);
DECLARE(test_gauss_fit);
DECLARE(test_denoise_mrf);
DECLARE(test_denoise_mrf_bp);
DECLARE(test_segmentation);


void
register_tests()
{
  REGISTER(test_detector);
  REGISTER(test_region_proc);
  REGISTER(test_gauss_fit);
  REGISTER(test_denoise_mrf);
  REGISTER(test_denoise_mrf_bp);
  REGISTER(test_segmentation);
}

DEFINE_MAIN;
