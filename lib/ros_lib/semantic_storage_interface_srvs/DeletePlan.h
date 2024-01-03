#ifndef _ROS_SERVICE_DeletePlan_h
#define _ROS_SERVICE_DeletePlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char DELETEPLAN[] = "semantic_storage_interface_srvs/DeletePlan";

  class DeletePlanRequest : public ros::Msg
  {
    public:
      typedef const char* _planUri_type;
      _planUri_type planUri;

    DeletePlanRequest():
      planUri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_planUri = strlen(this->planUri);
      varToArr(outbuffer + offset, length_planUri);
      offset += 4;
      memcpy(outbuffer + offset, this->planUri, length_planUri);
      offset += length_planUri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_planUri;
      arrToVar(length_planUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planUri-1]=0;
      this->planUri = (char *)(inbuffer + offset-1);
      offset += length_planUri;
     return offset;
    }

    virtual const char * getType() override { return DELETEPLAN; };
    virtual const char * getMD5() override { return "a45807d86d65c1b42b2214d30b874a55"; };

  };

  class DeletePlanResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    DeletePlanResponse():
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

    virtual const char * getType() override { return DELETEPLAN; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class DeletePlan {
    public:
    typedef DeletePlanRequest Request;
    typedef DeletePlanResponse Response;
  };

}
#endif
