//:
// \file
// \author Vishal Jain
// \date June 9, 2013
#include <boxm2/boxm2_scene.h>
#include <boxm2/boxm2_block.h>
#include <boxm2/basic/boxm2_block_id.h>
#include <boxm2/io/boxm2_lru_cache2.h>
#include <boxm2/io/boxm2_cache2.h>
#include <boxm2/io/boxm2_sio_mgr.h>
#include <testlib/testlib_test.h>
#include <testlib/testlib_root_dir.h>
#include "test_utils.h"

// for stats
#include <vul/vul_timer.h>
#include <vcl_sys/time.h>
#include <vcl_cstdio.h>
//#include <unistd.h>

void test_lru_cache2()
{
  //init cache
  boxm2_scene_sptr scene1,scene2;
  boxm2_test_utils::create_test_simple_scene(scene1);
  boxm2_test_utils::create_test_simple_scene(scene2);
  boxm2_lru_cache2::create(scene1);
  boxm2_cache2_sptr cache = boxm2_cache2::instance();
  //simulate a render
  vcl_cout<<"loading initial BLOCK and ALPHA"<<vcl_endl;
  boxm2_block* blk1 =  cache->get_block(scene1, boxm2_block_id(0,0,0));
  boxm2_block* blk2 =  cache->get_block(scene2, boxm2_block_id(0,0,0));
  
  TEST("checking Scene 1 block id",blk1->block_id(), boxm2_block_id(0,0,0) );
  TEST("checking Scene 2 block id",blk2->block_id(), boxm2_block_id(0,0,0) );
  

}




void test_cache2()
{
  test_lru_cache2();
}


TESTMAIN(test_cache2);
