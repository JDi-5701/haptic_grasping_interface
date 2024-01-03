#ifndef _ROS_fir_sme_gripper_msgs_State_h
#define _ROS_fir_sme_gripper_msgs_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fir_sme_gripper_msgs
{

  class State : public ros::Msg
  {
    public:
      typedef float _width_type;
      _width_type width;
      typedef float _force_type;
      _force_type force;
      typedef float _acceleration_type;
      _acceleration_type acceleration;
      typedef int32_t _gripper_state_type;
      _gripper_state_type gripper_state;
      enum { GRASPING_STATE_IDLE =  0 };
      enum { GRASPING_STATE_GRASPING =  1 };
      enum { GRASPING_STATE_NO_PART_FOUND = 2 };
      enum { GRASPING_STATE_PART_LOST =  3 };
      enum { GRASPING_STATE_HOLDING =  4 };
      enum { GRASPING_STATE_RELEASING =  5 };
      enum { GRASPING_STATE_POSITIONING =  6 };
      enum { GRASPING_STATE_ERROR =  7 };

    State():
      width(0),
      force(0),
      acceleration(0),
      gripper_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_force;
      u_force.real = this->force;
      *(outbuffer + offset + 0) = (u_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.real = this->acceleration;
      *(outbuffer + offset + 0) = (u_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acceleration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration);
      union {
        int32_t real;
        uint32_t base;
      } u_gripper_state;
      u_gripper_state.real = this->gripper_state;
      *(outbuffer + offset + 0) = (u_gripper_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_force;
      u_force.base = 0;
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force = u_force.real;
      offset += sizeof(this->force);
      union {
        float real;
        uint32_t base;
      } u_acceleration;
      u_acceleration.base = 0;
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acceleration = u_acceleration.real;
      offset += sizeof(this->acceleration);
      union {
        int32_t real;
        uint32_t base;
      } u_gripper_state;
      u_gripper_state.base = 0;
      u_gripper_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_state = u_gripper_state.real;
      offset += sizeof(this->gripper_state);
     return offset;
    }

    virtual const char * getType() override { return "fir_sme_gripper_msgs/State"; };
    virtual const char * getMD5() override { return "2658b5cf7d148c29445c0950d7d91487"; };

  };

}
#endif
