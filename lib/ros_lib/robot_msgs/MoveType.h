#ifndef _ROS_robot_msgs_MoveType_h
#define _ROS_robot_msgs_MoveType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_msgs
{

  class MoveType : public ros::Msg
  {
    public:
      enum { NONE =  0 };
      enum { CARTESIAN =  10000 };
      enum { CARTESIAN_FORCE =  11000 };
      enum { JOINT =  20000 };
      enum { JOINT_LINEAR =  21000 };
      enum { JOINT_LINEAR_FORCE =  22000 };
      enum { LINEAR =  30000 };
      enum { CIRCULAR =  40000 };

    MoveType()
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

    virtual const char * getType() override { return "robot_msgs/MoveType"; };
    virtual const char * getMD5() override { return "d37c35113b91bb767cb99af4bb195545"; };

  };

}
#endif
