#ifndef _ROS_perception_msgs_ObjRecStatus_h
#define _ROS_perception_msgs_ObjRecStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_msgs
{

  class ObjRecStatus : public ros::Msg
  {
    public:
      enum { OBJREC_STATUS_UNKNOWN =  0 };
      enum { OBJREC_STATUS_GOOD =  1 };
      enum { OBJREC_STATUS_BAD_POSE =  2  };
      enum { OBJREC_STATUS_BAD_DISTANCE =  3  };

    ObjRecStatus()
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

    virtual const char * getType() override { return "perception_msgs/ObjRecStatus"; };
    virtual const char * getMD5() override { return "e2a937d5445143873a5bd453a69b1e46"; };

  };

}
#endif
