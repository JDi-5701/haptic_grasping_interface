#ifndef _ROS_robot_msgs_Pose_h
#define _ROS_robot_msgs_Pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_msgs
{

  class Pose : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _a_type;
      _a_type a;
      typedef float _b_type;
      _b_type b;
      typedef float _c_type;
      _c_type c;

    Pose():
      x(0),
      y(0),
      z(0),
      a(0),
      b(0),
      c(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->a);
      offset += serializeAvrFloat64(outbuffer + offset, this->b);
      offset += serializeAvrFloat64(outbuffer + offset, this->c);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->a));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->b));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->c));
     return offset;
    }

    virtual const char * getType() override { return "robot_msgs/Pose"; };
    virtual const char * getMD5() override { return "3496ba5f1a8a3758e00aeb5becb9a91a"; };

  };

}
#endif
