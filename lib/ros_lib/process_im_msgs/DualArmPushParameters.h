#ifndef _ROS_process_im_msgs_DualArmPushParameters_h
#define _ROS_process_im_msgs_DualArmPushParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class DualArmPushParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _push_approach_type;
      _push_approach_type push_approach;
      typedef geometry_msgs::Pose _push_start_type;
      _push_start_type push_start;
      typedef geometry_msgs::Pose _push_end_type;
      _push_end_type push_end;
      typedef float _gripper_span_type;
      _gripper_span_type gripper_span;
      typedef const char* _pick_execution_actor_type;
      _pick_execution_actor_type pick_execution_actor;

    DualArmPushParameters():
      push_approach(),
      push_start(),
      push_end(),
      gripper_span(0),
      pick_execution_actor("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->push_approach.serialize(outbuffer + offset);
      offset += this->push_start.serialize(outbuffer + offset);
      offset += this->push_end.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_gripper_span;
      u_gripper_span.real = this->gripper_span;
      *(outbuffer + offset + 0) = (u_gripper_span.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_span.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_span.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_span.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_span);
      uint32_t length_pick_execution_actor = strlen(this->pick_execution_actor);
      varToArr(outbuffer + offset, length_pick_execution_actor);
      offset += 4;
      memcpy(outbuffer + offset, this->pick_execution_actor, length_pick_execution_actor);
      offset += length_pick_execution_actor;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->push_approach.deserialize(inbuffer + offset);
      offset += this->push_start.deserialize(inbuffer + offset);
      offset += this->push_end.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_gripper_span;
      u_gripper_span.base = 0;
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_span = u_gripper_span.real;
      offset += sizeof(this->gripper_span);
      uint32_t length_pick_execution_actor;
      arrToVar(length_pick_execution_actor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pick_execution_actor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pick_execution_actor-1]=0;
      this->pick_execution_actor = (char *)(inbuffer + offset-1);
      offset += length_pick_execution_actor;
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/DualArmPushParameters"; };
    virtual const char * getMD5() override { return "3dde0fee9e26712e36dcf1a5ba7ed969"; };

  };

}
#endif
