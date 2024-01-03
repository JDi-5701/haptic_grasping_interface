#ifndef _ROS_SERVICE_ClearSemanticRepo_h
#define _ROS_SERVICE_ClearSemanticRepo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char CLEARSEMANTICREPO[] = "semantic_storage_interface_srvs/ClearSemanticRepo";

  class ClearSemanticRepoRequest : public ros::Msg
  {
    public:

    ClearSemanticRepoRequest()
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

    virtual const char * getType() override { return CLEARSEMANTICREPO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ClearSemanticRepoResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ClearSemanticRepoResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return CLEARSEMANTICREPO; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ClearSemanticRepo {
    public:
    typedef ClearSemanticRepoRequest Request;
    typedef ClearSemanticRepoResponse Response;
  };

}
#endif
