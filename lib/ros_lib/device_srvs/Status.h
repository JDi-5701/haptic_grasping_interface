#ifndef _ROS_SERVICE_Status_h
#define _ROS_SERVICE_Status_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "device_msgs/Status.h"

namespace device_srvs
{

static const char STATUS[] = "device_srvs/Status";

  class StatusRequest : public ros::Msg
  {
    public:
      typedef int32_t _req_type;
      _req_type req;

    StatusRequest():
      req(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_req;
      u_req.real = this->req;
      *(outbuffer + offset + 0) = (u_req.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_req.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_req.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_req.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->req);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_req;
      u_req.base = 0;
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_req.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->req = u_req.real;
      offset += sizeof(this->req);
     return offset;
    }

    virtual const char * getType() override { return STATUS; };
    virtual const char * getMD5() override { return "688ec893d5ff2cccc11b9bc8bc41109b"; };

  };

  class StatusResponse : public ros::Msg
  {
    public:
      typedef device_msgs::Status _status_type;
      _status_type status;

    StatusResponse():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return STATUS; };
    virtual const char * getMD5() override { return "e65cb9131a752ed24c52dc217a8a4fe1"; };

  };

  class Status {
    public:
    typedef StatusRequest Request;
    typedef StatusResponse Response;
  };

}
#endif
