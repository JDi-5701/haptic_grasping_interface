#ifndef _ROS_control_core_msgs_CartesianState_h
#define _ROS_control_core_msgs_CartesianState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Accel.h"
#include "geometry_msgs/Wrench.h"

namespace control_core_msgs
{

  class CartesianState : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _position_type;
      _position_type position;
      typedef geometry_msgs::Twist _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Accel _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Wrench _wrench_type;
      _wrench_type wrench;

    CartesianState():
      position(),
      velocity(),
      acceleration(),
      wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->wrench.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/CartesianState"; };
    virtual const char * getMD5() override { return "146c974b35b122ce7c95e4a628f8c6ef"; };

  };

}
#endif
