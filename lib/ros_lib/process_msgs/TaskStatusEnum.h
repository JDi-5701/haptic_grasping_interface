#ifndef _ROS_process_msgs_TaskStatusEnum_h
#define _ROS_process_msgs_TaskStatusEnum_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_msgs
{

  class TaskStatusEnum : public ros::Msg
  {
    public:
      enum { UNDEFINED =      0  };
      enum { INCOMPLETE =  10000  };
      enum { VALID =  20000  };
      enum { INVALID =  30000  };
      enum { EXECUTABLE =  40000  };
      enum { EXECUTING =  50000 };
      enum { COMPLETED =  60000  };
      enum { FAILED =  70000  };
      enum { STOPPED =  80000  };

    TaskStatusEnum()
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

    virtual const char * getType() override { return "process_msgs/TaskStatusEnum"; };
    virtual const char * getMD5() override { return "51d42af6e46d5c816d3d5d6607b797ce"; };

  };

}
#endif
