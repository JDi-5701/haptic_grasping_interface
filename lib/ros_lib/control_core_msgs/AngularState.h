#ifndef _ROS_control_core_msgs_AngularState_h
#define _ROS_control_core_msgs_AngularState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace control_core_msgs
{

  class AngularState : public ros::Msg
  {
    public:
      typedef geometry_msgs::Quaternion _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _torque_type;
      _torque_type torque;

    AngularState():
      position(),
      velocity(),
      acceleration(),
      torque()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->torque.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->torque.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/AngularState"; };
    virtual const char * getMD5() override { return "04f2d99c11a1d869cd77f0f0f8208aad"; };

  };

}
#endif
