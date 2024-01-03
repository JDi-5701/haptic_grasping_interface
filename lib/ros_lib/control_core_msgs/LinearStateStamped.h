#ifndef _ROS_control_core_msgs_LinearStateStamped_h
#define _ROS_control_core_msgs_LinearStateStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "control_core_msgs/LinearState.h"

namespace control_core_msgs
{

  class LinearStateStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef control_core_msgs::LinearState _state_type;
      _state_type state;

    LinearStateStamped():
      header(),
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/LinearStateStamped"; };
    virtual const char * getMD5() override { return "7097f202dec4e82fb10612b0ae339db3"; };

  };

}
#endif
