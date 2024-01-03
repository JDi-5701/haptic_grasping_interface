#ifndef _ROS_process_im_msgs_TaskRequestParameters_h
#define _ROS_process_im_msgs_TaskRequestParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "process_im_msgs/PickPlaceEndPoseRequestParameters.h"
#include "process_im_msgs/PickPlaceApproachEndPoseRequestParameters.h"

namespace process_im_msgs
{

  class TaskRequestParameters : public ros::Msg
  {
    public:
      typedef bool _toolTipPoseIsValid_type;
      _toolTipPoseIsValid_type toolTipPoseIsValid;
      typedef geometry_msgs::Pose _toolTipPose_type;
      _toolTipPose_type toolTipPose;
      typedef process_im_msgs::PickPlaceEndPoseRequestParameters _pick_place_endpose_request_parameters_type;
      _pick_place_endpose_request_parameters_type pick_place_endpose_request_parameters;
      typedef process_im_msgs::PickPlaceApproachEndPoseRequestParameters _pick_place_approach_endpose_request_parameters_type;
      _pick_place_approach_endpose_request_parameters_type pick_place_approach_endpose_request_parameters;

    TaskRequestParameters():
      toolTipPoseIsValid(0),
      toolTipPose(),
      pick_place_endpose_request_parameters(),
      pick_place_approach_endpose_request_parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_toolTipPoseIsValid;
      u_toolTipPoseIsValid.real = this->toolTipPoseIsValid;
      *(outbuffer + offset + 0) = (u_toolTipPoseIsValid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->toolTipPoseIsValid);
      offset += this->toolTipPose.serialize(outbuffer + offset);
      offset += this->pick_place_endpose_request_parameters.serialize(outbuffer + offset);
      offset += this->pick_place_approach_endpose_request_parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_toolTipPoseIsValid;
      u_toolTipPoseIsValid.base = 0;
      u_toolTipPoseIsValid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->toolTipPoseIsValid = u_toolTipPoseIsValid.real;
      offset += sizeof(this->toolTipPoseIsValid);
      offset += this->toolTipPose.deserialize(inbuffer + offset);
      offset += this->pick_place_endpose_request_parameters.deserialize(inbuffer + offset);
      offset += this->pick_place_approach_endpose_request_parameters.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/TaskRequestParameters"; };
    virtual const char * getMD5() override { return "84f6a5048b4f5346225c3a5f5508a1c0"; };

  };

}
#endif
