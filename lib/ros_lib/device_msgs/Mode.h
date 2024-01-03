#ifndef _ROS_device_msgs_Mode_h
#define _ROS_device_msgs_Mode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace device_msgs
{

  class Mode : public ros::Msg
  {
    public:
      enum { DISABLED =  0 };
      enum { STATIONARY =  1 };
      enum { MOVING =  2 };
      enum { OPEN =  3 };
      enum { CLOSE =  4 };
      enum { ERROR =  5 };
      enum { GRASPING_STATE_IDLE =  1001 };
      enum { GRASPING_STATE_GRASPING =  1002 };
      enum { GRASPING_STATE_NO_PART_FOUND =  1003 };
      enum { GRASPING_STATE_PART_LOST =  1004 };
      enum { GRASPING_STATE_HOLDING =  1005 };
      enum { GRASPING_STATE_RELEASING =  1006 };
      enum { GRASPING_STATE_POSITIONING =  1007 };
      enum { GRASPING_STATE_ERROR =  1008 };

    Mode()
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

    virtual const char * getType() override { return "device_msgs/Mode"; };
    virtual const char * getMD5() override { return "c74a57d54db327b056e8b0c1b534c0cc"; };

  };

}
#endif
