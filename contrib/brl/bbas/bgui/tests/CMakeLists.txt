# brl/bbas/bgui/tests/CMakeLists.txt

INCLUDE_DIRECTORIES(${BRL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${BRL_INCLUDE_DIR})

ADD_EXECUTABLE(bgui_test_all
  test_driver.cxx
  test_histogram.cxx
)
TARGET_LINK_LIBRARIES(bgui_test_all vil_algo vil testlib vcl)

ADD_TEST( bgui_test_histogram  ${EXECUTABLE_OUTPUT_PATH}/bgui_test_all test_histogram ${CMAKE_CURRENT_SOURCE_DIR}/18_al05_1770_0365.tif )

ADD_EXECUTABLE(bgui_test_include test_include.cxx)
TARGET_LINK_LIBRARIES(bgui_test_include bgui)
