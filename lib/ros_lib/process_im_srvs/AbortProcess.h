#ifndef _ROS_SERVICE_AbortProcess_h
#define _ROS_SERVICE_AbortProcess_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_im_srvs
{

static const char ABORTPROCESS[] = "process_im_srvs/AbortProcess";

  class AbortProcessRequest : public ros::Msg
  {
    public:
      typedef bool _req_type;
      _req_type req;

    AbortProcessRequest():
      req(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_req;
      u_req.real = this->req;
      *(outbuffer + offset + 0) = (u_req.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->req);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_req;
      u_req.base = 0;
      u_req.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->req = u_req.real;
      offset += sizeof(this->req);
     return offset;
    }

    virtual const char * getType() override { return ABORTPROCESS; };
    virtual const char * getMD5() override { return "be3c44e19d0c6b00b25e356c69155e2a"; };

  };

  class AbortProcessResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    AbortProcessResponse():
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

    virtual const char * getType() override { return ABORTPROCESS; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class AbortProcess {
    public:
    typedef AbortProcessRequest Request;
    typedef AbortProcessResponse Response;
  };

}
#endif
