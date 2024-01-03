#ifndef _ROS_process_im_msgs_TaskParameters_h
#define _ROS_process_im_msgs_TaskParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/GraspParameters.h"
#include "process_im_msgs/PlaceParameters.h"
#include "process_im_msgs/PickPlaceParameters.h"
#include "process_im_msgs/PickPlaceEndPoseParameters.h"
#include "process_im_msgs/PickPlaceApproachEndPoseParameters.h"
#include "process_im_msgs/PushDownParameters.h"
#include "process_im_msgs/MoveParameters.h"
#include "process_im_msgs/MoveToActorParameters.h"
#include "process_im_msgs/WeldSpotParameters.h"
#include "process_im_msgs/WeldSeamParameters.h"
#include "process_im_msgs/NailParameters.h"
#include "process_im_msgs/SawParameters.h"
#include "process_im_msgs/DualArmPickPlaceApproachEndPoseParameters.h"
#include "process_im_msgs/DualArmPickPlaceEndPoseParameters.h"
#include "process_im_msgs/DualArmAssemblyAirEndPoseParameters.h"
#include "process_im_msgs/DualArmAssemblyGroundEndPoseParameters.h"
#include "process_im_msgs/DualArmGraspParameters.h"
#include "process_im_msgs/DualArmPlaceParameters.h"
#include "process_im_msgs/DualArmPushParameters.h"
#include "process_im_msgs/DualArmMoveParameters.h"
#include "process_im_msgs/DualArmMoveActorParameters.h"

namespace process_im_msgs
{

  class TaskParameters : public ros::Msg
  {
    public:
      typedef process_im_msgs::GraspParameters _grasp_parameters_type;
      _grasp_parameters_type grasp_parameters;
      typedef process_im_msgs::PlaceParameters _place_parameters_type;
      _place_parameters_type place_parameters;
      typedef process_im_msgs::PickPlaceParameters _pick_place_parameters_type;
      _pick_place_parameters_type pick_place_parameters;
      typedef process_im_msgs::PickPlaceEndPoseParameters _pick_place_endpose_parameters_type;
      _pick_place_endpose_parameters_type pick_place_endpose_parameters;
      typedef process_im_msgs::PickPlaceApproachEndPoseParameters _pick_place_approach_endpose_parameters_type;
      _pick_place_approach_endpose_parameters_type pick_place_approach_endpose_parameters;
      typedef process_im_msgs::PushDownParameters _push_down_parameters_type;
      _push_down_parameters_type push_down_parameters;
      typedef process_im_msgs::MoveParameters _move_parameters_type;
      _move_parameters_type move_parameters;
      typedef process_im_msgs::MoveToActorParameters _move_to_actor_parameters_type;
      _move_to_actor_parameters_type move_to_actor_parameters;
      typedef process_im_msgs::WeldSpotParameters _weld_spot_parameters_type;
      _weld_spot_parameters_type weld_spot_parameters;
      typedef process_im_msgs::WeldSeamParameters _weld_seam_parameters_type;
      _weld_seam_parameters_type weld_seam_parameters;
      typedef process_im_msgs::NailParameters _nail_parameters_type;
      _nail_parameters_type nail_parameters;
      typedef process_im_msgs::SawParameters _saw_parameters_type;
      _saw_parameters_type saw_parameters;
      typedef process_im_msgs::PickPlaceEndPoseParameters _disassemble_endpose_parameters_type;
      _disassemble_endpose_parameters_type disassemble_endpose_parameters;
      typedef process_im_msgs::PickPlaceApproachEndPoseParameters _disassemble_approach_endpose_parameters_type;
      _disassemble_approach_endpose_parameters_type disassemble_approach_endpose_parameters;
      typedef process_im_msgs::DualArmPickPlaceApproachEndPoseParameters _dual_arm_pick_place_approach_endpose_parameters_type;
      _dual_arm_pick_place_approach_endpose_parameters_type dual_arm_pick_place_approach_endpose_parameters;
      typedef process_im_msgs::DualArmPickPlaceEndPoseParameters _dual_arm_pick_place_endpose_parameters_type;
      _dual_arm_pick_place_endpose_parameters_type dual_arm_pick_place_endpose_parameters;
      typedef process_im_msgs::DualArmAssemblyAirEndPoseParameters _dual_arm_assembly_air_endpose_parameters_type;
      _dual_arm_assembly_air_endpose_parameters_type dual_arm_assembly_air_endpose_parameters;
      typedef process_im_msgs::DualArmAssemblyGroundEndPoseParameters _dual_arm_assembly_ground_endpose_parameters_type;
      _dual_arm_assembly_ground_endpose_parameters_type dual_arm_assembly_ground_endpose_parameters;
      typedef process_im_msgs::DualArmGraspParameters _dual_arm_grasp_parameters_type;
      _dual_arm_grasp_parameters_type dual_arm_grasp_parameters;
      typedef process_im_msgs::DualArmPlaceParameters _dual_arm_place_parameters_type;
      _dual_arm_place_parameters_type dual_arm_place_parameters;
      typedef process_im_msgs::DualArmPushParameters _dual_arm_push_parameters_type;
      _dual_arm_push_parameters_type dual_arm_push_parameters;
      typedef process_im_msgs::DualArmMoveParameters _dual_arm_move_parameters_type;
      _dual_arm_move_parameters_type dual_arm_move_parameters;
      typedef process_im_msgs::DualArmMoveActorParameters _dual_arm_move_actor_parameters_type;
      _dual_arm_move_actor_parameters_type dual_arm_move_actor_parameters;

    TaskParameters():
      grasp_parameters(),
      place_parameters(),
      pick_place_parameters(),
      pick_place_endpose_parameters(),
      pick_place_approach_endpose_parameters(),
      push_down_parameters(),
      move_parameters(),
      move_to_actor_parameters(),
      weld_spot_parameters(),
      weld_seam_parameters(),
      nail_parameters(),
      saw_parameters(),
      disassemble_endpose_parameters(),
      disassemble_approach_endpose_parameters(),
      dual_arm_pick_place_approach_endpose_parameters(),
      dual_arm_pick_place_endpose_parameters(),
      dual_arm_assembly_air_endpose_parameters(),
      dual_arm_assembly_ground_endpose_parameters(),
      dual_arm_grasp_parameters(),
      dual_arm_place_parameters(),
      dual_arm_push_parameters(),
      dual_arm_move_parameters(),
      dual_arm_move_actor_parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->grasp_parameters.serialize(outbuffer + offset);
      offset += this->place_parameters.serialize(outbuffer + offset);
      offset += this->pick_place_parameters.serialize(outbuffer + offset);
      offset += this->pick_place_endpose_parameters.serialize(outbuffer + offset);
      offset += this->pick_place_approach_endpose_parameters.serialize(outbuffer + offset);
      offset += this->push_down_parameters.serialize(outbuffer + offset);
      offset += this->move_parameters.serialize(outbuffer + offset);
      offset += this->move_to_actor_parameters.serialize(outbuffer + offset);
      offset += this->weld_spot_parameters.serialize(outbuffer + offset);
      offset += this->weld_seam_parameters.serialize(outbuffer + offset);
      offset += this->nail_parameters.serialize(outbuffer + offset);
      offset += this->saw_parameters.serialize(outbuffer + offset);
      offset += this->disassemble_endpose_parameters.serialize(outbuffer + offset);
      offset += this->disassemble_approach_endpose_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_pick_place_approach_endpose_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_pick_place_endpose_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_assembly_air_endpose_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_assembly_ground_endpose_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_grasp_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_place_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_push_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_move_parameters.serialize(outbuffer + offset);
      offset += this->dual_arm_move_actor_parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->grasp_parameters.deserialize(inbuffer + offset);
      offset += this->place_parameters.deserialize(inbuffer + offset);
      offset += this->pick_place_parameters.deserialize(inbuffer + offset);
      offset += this->pick_place_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->pick_place_approach_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->push_down_parameters.deserialize(inbuffer + offset);
      offset += this->move_parameters.deserialize(inbuffer + offset);
      offset += this->move_to_actor_parameters.deserialize(inbuffer + offset);
      offset += this->weld_spot_parameters.deserialize(inbuffer + offset);
      offset += this->weld_seam_parameters.deserialize(inbuffer + offset);
      offset += this->nail_parameters.deserialize(inbuffer + offset);
      offset += this->saw_parameters.deserialize(inbuffer + offset);
      offset += this->disassemble_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->disassemble_approach_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_pick_place_approach_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_pick_place_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_assembly_air_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_assembly_ground_endpose_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_grasp_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_place_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_push_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_move_parameters.deserialize(inbuffer + offset);
      offset += this->dual_arm_move_actor_parameters.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/TaskParameters"; };
    virtual const char * getMD5() override { return "18f8f0bb9085872bc5abad5cc6a0ac8a"; };

  };

}
#endif
