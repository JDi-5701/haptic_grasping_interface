#ifndef _ROS_SERVICE_Stop_h
#define _ROS_SERVICE_Stop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_srvs
{

static const char STOP[] = "perception_srvs/Stop";

  class StopRequest : public ros::Msg
  {
    public:

    StopRequest()
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

    virtual const char * getType() override { return STOP; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StopResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    StopResponse():
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error = u_error.real;
      offset += sizeof(this->error);
     return offset;
    }

    virtual const char * getType() override { return STOP; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class Stop {
    public:
    typedef StopRequest Request;
    typedef StopResponse Response;
  };

}
#endif
