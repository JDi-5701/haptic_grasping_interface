#ifndef _ROS_SERVICE_Connect_h
#define _ROS_SERVICE_Connect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char CONNECT[] = "robot_srvs/Connect";

  class ConnectRequest : public ros::Msg
  {
    public:
      typedef bool _connect_type;
      _connect_type connect;

    ConnectRequest():
      connect(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_connect;
      u_connect.real = this->connect;
      *(outbuffer + offset + 0) = (u_connect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->connect);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_connect;
      u_connect.base = 0;
      u_connect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->connect = u_connect.real;
      offset += sizeof(this->connect);
     return offset;
    }

    virtual const char * getType() override { return CONNECT; };
    virtual const char * getMD5() override { return "a31bf7076ca051d3bb47d5d808c4982b"; };

  };

  class ConnectResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    ConnectResponse():
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

    virtual const char * getType() override { return CONNECT; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class Connect {
    public:
    typedef ConnectRequest Request;
    typedef ConnectResponse Response;
  };

}
#endif
