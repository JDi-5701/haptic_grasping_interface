#ifndef _ROS_knob_robot_control_KnobState_h
#define _ROS_knob_robot_control_KnobState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

namespace knob_robot_control
{

  class KnobState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::String _mode_type;
      _mode_type mode;
      typedef std_msgs::Int32 _position_type;
      _position_type position;
      typedef std_msgs::Float32 _force_type;
      _force_type force;

    KnobState():
      header(),
      mode(),
      position(),
      force()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->mode.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->force.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->mode.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->force.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "knob_robot_control/KnobState"; };
    virtual const char * getMD5() override { return "18a4a78df9994d9938244a2ca3b25594"; };

  };

}
#endif
