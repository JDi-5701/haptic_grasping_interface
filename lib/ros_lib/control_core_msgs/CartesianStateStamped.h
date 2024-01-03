#ifndef _ROS_control_core_msgs_CartesianStateStamped_h
#define _ROS_control_core_msgs_CartesianStateStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "control_core_msgs/CartesianState.h"

namespace control_core_msgs
{

  class CartesianStateStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef control_core_msgs::CartesianState _state_type;
      _state_type state;

    CartesianStateStamped():
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

    virtual const char * getType() override { return "control_core_msgs/CartesianStateStamped"; };
    virtual const char * getMD5() override { return "c9ed8fe6dfc8e947ca6e8bd068f04705"; };

  };

}
#endif
