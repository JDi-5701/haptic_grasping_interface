#ifndef _ROS_middleware_msgs_StatusLevelsEnum_h
#define _ROS_middleware_msgs_StatusLevelsEnum_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace middleware_msgs
{

  class StatusLevelsEnum : public ros::Msg
  {
    public:
      enum { UNDEFINED =      0  };
      enum { DEBUG =  10100 };
      enum { INFO =  10200 };
      enum { WARNING =  10300 };
      enum { ERROR =  10400 };
      enum { FATAL =  10500 };

    StatusLevelsEnum()
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

    virtual const char * getType() override { return "middleware_msgs/StatusLevelsEnum"; };
    virtual const char * getMD5() override { return "61f6faa4a317e3ef3861f5e4456ee2dd"; };

  };

}
#endif
