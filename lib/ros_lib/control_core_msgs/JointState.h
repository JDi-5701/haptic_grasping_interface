#ifndef _ROS_control_core_msgs_JointState_h
#define _ROS_control_core_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "control_core_msgs/Vector.h"

namespace control_core_msgs
{

  class JointState : public ros::Msg
  {
    public:
      typedef control_core_msgs::Vector _position_type;
      _position_type position;
      typedef control_core_msgs::Vector _velocity_type;
      _velocity_type velocity;
      typedef control_core_msgs::Vector _acceleration_type;
      _acceleration_type acceleration;
      typedef control_core_msgs::Vector _effort_type;
      _effort_type effort;

    JointState():
      position(),
      velocity(),
      acceleration(),
      effort()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->effort.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->effort.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/JointState"; };
    virtual const char * getMD5() override { return "4687c57ff41aed07b9255a1a224fc795"; };

  };

}
#endif
