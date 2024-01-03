#ifndef _ROS_process_im_msgs_DualArmAssemblyAirEndPoseParameters_h
#define _ROS_process_im_msgs_DualArmAssemblyAirEndPoseParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class DualArmAssemblyAirEndPoseParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pickobject_grasp_approach_type;
      _pickobject_grasp_approach_type pickobject_grasp_approach;
      typedef geometry_msgs::Pose _pickobject_grasp_type;
      _pickobject_grasp_type pickobject_grasp;
      typedef geometry_msgs::Pose _pickobject_assembly_type;
      _pickobject_assembly_type pickobject_assembly;
      typedef geometry_msgs::Pose _pickobject_final_pose_type;
      _pickobject_final_pose_type pickobject_final_pose;
      typedef geometry_msgs::Pose _pickobject_sync_type;
      _pickobject_sync_type pickobject_sync;
      typedef geometry_msgs::Pose _pick_execution_actor_resting_type;
      _pick_execution_actor_resting_type pick_execution_actor_resting;
      typedef const char* _pick_execution_actor_type;
      _pick_execution_actor_type pick_execution_actor;
      typedef float _pickobject_gripper_span_type;
      _pickobject_gripper_span_type pickobject_gripper_span;
      typedef geometry_msgs::Pose _placeobject_grasp_approach_type;
      _placeobject_grasp_approach_type placeobject_grasp_approach;
      typedef geometry_msgs::Pose _placeobject_grasp_type;
      _placeobject_grasp_type placeobject_grasp;
      typedef geometry_msgs::Pose _placeobject_assembly_type;
      _placeobject_assembly_type placeobject_assembly;
      typedef const char* _place_execution_actor_type;
      _place_execution_actor_type place_execution_actor;
      typedef float _placeobject_gripper_span_type;
      _placeobject_gripper_span_type placeobject_gripper_span;
      typedef geometry_msgs::Pose _assembledobject_resting_type;
      _assembledobject_resting_type assembledobject_resting;

    DualArmAssemblyAirEndPoseParameters():
      pickobject_grasp_approach(),
      pickobject_grasp(),
      pickobject_assembly(),
      pickobject_final_pose(),
      pickobject_sync(),
      pick_execution_actor_resting(),
      pick_execution_actor(""),
      pickobject_gripper_span(0),
      placeobject_grasp_approach(),
      placeobject_grasp(),
      placeobject_assembly(),
      place_execution_actor(""),
      placeobject_gripper_span(0),
      assembledobject_resting()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pickobject_grasp_approach.serialize(outbuffer + offset);
      offset += this->pickobject_grasp.serialize(outbuffer + offset);
      offset += this->pickobject_assembly.serialize(outbuffer + offset);
      offset += this->pickobject_final_pose.serialize(outbuffer + offset);
      offset += this->pickobject_sync.serialize(outbuffer + offset);
      offset += this->pick_execution_actor_resting.serialize(outbuffer + offset);
      uint32_t length_pick_execution_actor = strlen(this->pick_execution_actor);
      varToArr(outbuffer + offset, length_pick_execution_actor);
      offset += 4;
      memcpy(outbuffer + offset, this->pick_execution_actor, length_pick_execution_actor);
      offset += length_pick_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_pickobject_gripper_span;
      u_pickobject_gripper_span.real = this->pickobject_gripper_span;
      *(outbuffer + offset + 0) = (u_pickobject_gripper_span.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pickobject_gripper_span.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pickobject_gripper_span.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pickobject_gripper_span.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pickobject_gripper_span);
      offset += this->placeobject_grasp_approach.serialize(outbuffer + offset);
      offset += this->placeobject_grasp.serialize(outbuffer + offset);
      offset += this->placeobject_assembly.serialize(outbuffer + offset);
      uint32_t length_place_execution_actor = strlen(this->place_execution_actor);
      varToArr(outbuffer + offset, length_place_execution_actor);
      offset += 4;
      memcpy(outbuffer + offset, this->place_execution_actor, length_place_execution_actor);
      offset += length_place_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_placeobject_gripper_span;
      u_placeobject_gripper_span.real = this->placeobject_gripper_span;
      *(outbuffer + offset + 0) = (u_placeobject_gripper_span.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_placeobject_gripper_span.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_placeobject_gripper_span.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_placeobject_gripper_span.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->placeobject_gripper_span);
      offset += this->assembledobject_resting.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pickobject_grasp_approach.deserialize(inbuffer + offset);
      offset += this->pickobject_grasp.deserialize(inbuffer + offset);
      offset += this->pickobject_assembly.deserialize(inbuffer + offset);
      offset += this->pickobject_final_pose.deserialize(inbuffer + offset);
      offset += this->pickobject_sync.deserialize(inbuffer + offset);
      offset += this->pick_execution_actor_resting.deserialize(inbuffer + offset);
      uint32_t length_pick_execution_actor;
      arrToVar(length_pick_execution_actor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pick_execution_actor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pick_execution_actor-1]=0;
      this->pick_execution_actor = (char *)(inbuffer + offset-1);
      offset += length_pick_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_pickobject_gripper_span;
      u_pickobject_gripper_span.base = 0;
      u_pickobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pickobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pickobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pickobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pickobject_gripper_span = u_pickobject_gripper_span.real;
      offset += sizeof(this->pickobject_gripper_span);
      offset += this->placeobject_grasp_approach.deserialize(inbuffer + offset);
      offset += this->placeobject_grasp.deserialize(inbuffer + offset);
      offset += this->placeobject_assembly.deserialize(inbuffer + offset);
      uint32_t length_place_execution_actor;
      arrToVar(length_place_execution_actor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_place_execution_actor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_place_execution_actor-1]=0;
      this->place_execution_actor = (char *)(inbuffer + offset-1);
      offset += length_place_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_placeobject_gripper_span;
      u_placeobject_gripper_span.base = 0;
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->placeobject_gripper_span = u_placeobject_gripper_span.real;
      offset += sizeof(this->placeobject_gripper_span);
      offset += this->assembledobject_resting.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/DualArmAssemblyAirEndPoseParameters"; };
    virtual const char * getMD5() override { return "4356d98b0dd36a3d2d9b94d192ddd409"; };

  };

}
#endif
