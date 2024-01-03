#ifndef _ROS_fir_sme_gripper_msgs_Command_h
#define _ROS_fir_sme_gripper_msgs_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fir_sme_gripper_msgs
{

  class Command : public ros::Msg
  {
    public:
      typedef float _gripper_span_type;
      _gripper_span_type gripper_span;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _force_type;
      _force_type force;

    Command():
      gripper_span(0),
      speed(0),
      force(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
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
     return offset;
    }

    virtual const char * getType() override { return "fir_sme_gripper_msgs/Command"; };
    virtual const char * getMD5() override { return "dfab6d06f7c22e9b0707f0fa80282daa"; };

  };

}
#endif
