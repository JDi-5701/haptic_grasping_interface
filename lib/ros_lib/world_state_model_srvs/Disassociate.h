#ifndef _ROS_SERVICE_Disassociate_h
#define _ROS_SERVICE_Disassociate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char DISASSOCIATE[] = "world_state_model_srvs/Disassociate";

  class DisassociateRequest : public ros::Msg
  {
    public:
      typedef const char* _parentIri_type;
      _parentIri_type parentIri;
      typedef const char* _childIri_type;
      _childIri_type childIri;

    DisassociateRequest():
      parentIri(""),
      childIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_parentIri = strlen(this->parentIri);
      varToArr(outbuffer + offset, length_parentIri);
      offset += 4;
      memcpy(outbuffer + offset, this->parentIri, length_parentIri);
      offset += length_parentIri;
      uint32_t length_childIri = strlen(this->childIri);
      varToArr(outbuffer + offset, length_childIri);
      offset += 4;
      memcpy(outbuffer + offset, this->childIri, length_childIri);
      offset += length_childIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_parentIri;
      arrToVar(length_parentIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parentIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parentIri-1]=0;
      this->parentIri = (char *)(inbuffer + offset-1);
      offset += length_parentIri;
      uint32_t length_childIri;
      arrToVar(length_childIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_childIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_childIri-1]=0;
      this->childIri = (char *)(inbuffer + offset-1);
      offset += length_childIri;
     return offset;
    }

    virtual const char * getType() override { return DISASSOCIATE; };
    virtual const char * getMD5() override { return "d0a76c0e6315ade6080d43b42e66fd8b"; };

  };

  class DisassociateResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    DisassociateResponse():
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

    virtual const char * getType() override { return DISASSOCIATE; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class Disassociate {
    public:
    typedef DisassociateRequest Request;
    typedef DisassociateResponse Response;
  };

}
#endif
