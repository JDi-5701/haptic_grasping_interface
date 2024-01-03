#ifndef _ROS_process_im_msgs_GraspParameters_h
#define _ROS_process_im_msgs_GraspParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class GraspParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;
      typedef geometry_msgs::Pose _grasp_type;
      _grasp_type grasp;
      typedef float _gripper_span_type;
      _gripper_span_type gripper_span;

    GraspParameters():
      approach(),
      grasp(),
      gripper_span(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->grasp.serialize(outbuffer + offset);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->grasp.deserialize(inbuffer + offset);
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
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/GraspParameters"; };
    virtual const char * getMD5() override { return "1b47c9f6b5a820034e0c8ebbb8411e38"; };

  };

}
#endif
