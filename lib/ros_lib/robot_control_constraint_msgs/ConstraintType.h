#ifndef _ROS_robot_control_constraint_msgs_ConstraintType_h
#define _ROS_robot_control_constraint_msgs_ConstraintType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_control_constraint_msgs
{

  class ConstraintType : public ros::Msg
  {
    public:
      enum { ANGLE_CONSTRAINT =  100 };
      enum { COINCIDENT_CONSTRAINT =  200 };
      enum { CONCENTRIC_CONSTRAINT =  300 };
      enum { DISTANCE_CONSTRAINT =  400 };
      enum { PARALLEL_CONSTRAINT =  500 };
      enum { PERPENDICULAR_CONSTRAINT =  600 };

    ConstraintType()
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

    virtual const char * getType() override { return "robot_control_constraint_msgs/ConstraintType"; };
    virtual const char * getMD5() override { return "58e9b112e8d3cfe05f6c804fc14e772f"; };

  };

}
#endif
