#ifndef _ROS_process_msgs_ValueTypesEnum_h
#define _ROS_process_msgs_ValueTypesEnum_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_msgs
{

  class ValueTypesEnum : public ros::Msg
  {
    public:
      enum { UNDEFINED =  0 };
      enum { BOOLEAN =  1  };
      enum { LONG =  2  };
      enum { DOUBLE =  3  };
      enum { STRING =  4  };
      enum { INDIVIDUAL =  5 };
      enum { PHYSICAL_ENTITY =  6 };
      enum { COMBINED_GEOMETRIC_INTERRELATION_CONSTRAINT =  7 };
      enum { POSE =  8 };

    ValueTypesEnum()
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

    virtual const char * getType() override { return "process_msgs/ValueTypesEnum"; };
    virtual const char * getMD5() override { return "7c3265b78d2e0daadb871981708a6314"; };

  };

}
#endif
