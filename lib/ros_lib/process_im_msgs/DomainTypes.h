#ifndef _ROS_process_im_msgs_DomainTypes_h
#define _ROS_process_im_msgs_DomainTypes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_im_msgs
{

  class DomainTypes : public ros::Msg
  {
    public:
      enum { NONE =  0 };
      enum { ASSEMBLE =  80001 };
      enum { DISASSEMBLE =  80002 };
      enum { WOOD_WORK =  80003 };
      enum { WELD =  80004 };

    DomainTypes()
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

    virtual const char * getType() override { return "process_im_msgs/DomainTypes"; };
    virtual const char * getMD5() override { return "e7c893e41699693edaf5c8b02ec6cd9e"; };

  };

}
#endif
