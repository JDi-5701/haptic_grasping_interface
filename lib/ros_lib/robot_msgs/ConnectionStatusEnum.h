#ifndef _ROS_robot_msgs_ConnectionStatusEnum_h
#define _ROS_robot_msgs_ConnectionStatusEnum_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_msgs
{

  class ConnectionStatusEnum : public ros::Msg
  {
    public:
      enum { UNDEFINED =      0 };
      enum { CONNECTING =  10 };
      enum { CONNECTED =  20 };
      enum { DISCONNECTING =  30 };
      enum { DISCONNECTED =  40 };

    ConnectionStatusEnum()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return "robot_msgs/ConnectionStatusEnum"; };
    virtual const char * getMD5() override { return "ac2174151de53fc923e4ab994f51327e"; };

  };

}
#endif
