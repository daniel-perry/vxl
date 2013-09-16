#include "volm_register.h"

#include <bprb/bprb_macros.h>
#include <bprb/bprb_batch_process_manager.h>
#include <bprb/bprb_func_process.h>
#include "volm_processes.h"
#include <volm/volm_satellite_resources_sptr.h>


void volm_register::register_datatype()
{
  REGISTER_DATATYPE(volm_satellite_resources_sptr);
}

void volm_register::register_process()
{
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_create_satellite_resources_process, "volmCreateSatResourcesProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_save_satellite_resources_process, "volmSaveSatResourcesProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_load_satellite_resources_process, "volmLoadSatResourcesProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_add_satellite_resources_process, "volmAddSatelliteResourcesProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_query_satellite_resources_process, "volmQuerySatelliteResourcesProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_correct_rational_cameras_ransac_process, "volmCorrectRationalCamerasRANSACProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_pick_nadir_resource_process, "volmPickNadirResProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_map_osm_process, "volmMapOSMProcess");
  REG_PROCESS_FUNC_CONS(bprb_func_process, bprb_batch_process_manager, volm_map_segments_process, "volmMapSegmentsProcess");
}
