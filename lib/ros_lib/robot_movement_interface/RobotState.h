#ifndef _ROS_robot_movement_interface_RobotState_h
#define _ROS_robot_movement_interface_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace robot_movement_interface
{

  class RobotState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _safety_state_type;
      _safety_state_type safety_state;

    RobotState():
      header(),
      safety_state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->safety_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safety_state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->safety_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->safety_state);
     return offset;
    }

    virtual const char * getType() override { return "robot_movement_interface/RobotState"; };
    virtual const char * getMD5() override { return "6d556bdebed12d9f1b17fe80c7a0d16b"; };

  };

}
#endif
