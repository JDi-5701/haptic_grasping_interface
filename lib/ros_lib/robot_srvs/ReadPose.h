#ifndef _ROS_SERVICE_ReadPose_h
#define _ROS_SERVICE_ReadPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace robot_srvs
{

static const char READPOSE[] = "robot_srvs/ReadPose";

  class ReadPoseRequest : public ros::Msg
  {
    public:

    ReadPoseRequest()
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

    virtual const char * getType() override { return READPOSE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ReadPoseResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;
      typedef geometry_msgs::Pose _x_type;
      _x_type x;

    ReadPoseResponse():
      res(0),
      x()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.real = this->res;
      *(outbuffer + offset + 0) = (u_res.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->res);
      offset += this->x.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.base = 0;
      u_res.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->res = u_res.real;
      offset += sizeof(this->res);
      offset += this->x.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return READPOSE; };
    virtual const char * getMD5() override { return "db580d157c3cba731b4a3c5fd7a1f0b6"; };

  };

  class ReadPose {
    public:
    typedef ReadPoseRequest Request;
    typedef ReadPoseResponse Response;
  };

}
#endif
