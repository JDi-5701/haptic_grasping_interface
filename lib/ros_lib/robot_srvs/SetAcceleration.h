#ifndef _ROS_SERVICE_SetAcceleration_h
#define _ROS_SERVICE_SetAcceleration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char SETACCELERATION[] = "robot_srvs/SetAcceleration";

  class SetAccelerationRequest : public ros::Msg
  {
    public:
      typedef float _acceleration_type;
      _acceleration_type acceleration;

    SetAccelerationRequest():
      acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration));
     return offset;
    }

    virtual const char * getType() override { return SETACCELERATION; };
    virtual const char * getMD5() override { return "7116d79853cec8276f2ea65056d18b78"; };

  };

  class SetAccelerationResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    SetAccelerationResponse():
      res(0)
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
     return offset;
    }

    virtual const char * getType() override { return SETACCELERATION; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class SetAcceleration {
    public:
    typedef SetAccelerationRequest Request;
    typedef SetAccelerationResponse Response;
  };

}
#endif
