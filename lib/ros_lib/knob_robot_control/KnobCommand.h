#ifndef _ROS_knob_robot_control_KnobCommand_h
#define _ROS_knob_robot_control_KnobCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"

namespace knob_robot_control
{

  class KnobCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Int32 _num_positions_type;
      _num_positions_type num_positions;
      typedef std_msgs::Int32 _position_type;
      _position_type position;
      typedef std_msgs::Float32 _position_width_radians_type;
      _position_width_radians_type position_width_radians;
      typedef std_msgs::Float32 _detent_strength_unit_type;
      _detent_strength_unit_type detent_strength_unit;
      typedef std_msgs::Float32 _endstop_strength_unit_type;
      _endstop_strength_unit_type endstop_strength_unit;
      typedef std_msgs::Float32 _snap_point_type;
      _snap_point_type snap_point;
      typedef std_msgs::String _text_type;
      _text_type text;
      typedef std_msgs::Float32 _tcp_force_type;
      _tcp_force_type tcp_force;

    KnobCommand():
      header(),
      num_positions(),
      position(),
      position_width_radians(),
      detent_strength_unit(),
      endstop_strength_unit(),
      snap_point(),
      text(),
      tcp_force()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->num_positions.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->position_width_radians.serialize(outbuffer + offset);
      offset += this->detent_strength_unit.serialize(outbuffer + offset);
      offset += this->endstop_strength_unit.serialize(outbuffer + offset);
      offset += this->snap_point.serialize(outbuffer + offset);
      offset += this->text.serialize(outbuffer + offset);
      offset += this->tcp_force.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->num_positions.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->position_width_radians.deserialize(inbuffer + offset);
      offset += this->detent_strength_unit.deserialize(inbuffer + offset);
      offset += this->endstop_strength_unit.deserialize(inbuffer + offset);
      offset += this->snap_point.deserialize(inbuffer + offset);
      offset += this->text.deserialize(inbuffer + offset);
      offset += this->tcp_force.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "knob_robot_control/KnobCommand"; };
    virtual const char * getMD5() override { return "43b9403acedf42b94137034e08469871"; };

  };

}
#endif
