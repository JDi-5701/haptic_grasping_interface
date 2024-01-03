#ifndef _ROS_SERVICE_LoadWorkcell_h
#define _ROS_SERVICE_LoadWorkcell_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char LOADWORKCELL[] = "world_state_model_srvs/LoadWorkcell";

  class LoadWorkcellRequest : public ros::Msg
  {
    public:
      typedef const char* _workcellUrl_type;
      _workcellUrl_type workcellUrl;
      typedef bool _reset_type;
      _reset_type reset;

    LoadWorkcellRequest():
      workcellUrl(""),
      reset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_workcellUrl = strlen(this->workcellUrl);
      varToArr(outbuffer + offset, length_workcellUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellUrl, length_workcellUrl);
      offset += length_workcellUrl;
      union {
        bool real;
        uint8_t base;
      } u_reset;
      u_reset.real = this->reset;
      *(outbuffer + offset + 0) = (u_reset.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_workcellUrl;
      arrToVar(length_workcellUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellUrl-1]=0;
      this->workcellUrl = (char *)(inbuffer + offset-1);
      offset += length_workcellUrl;
      union {
        bool real;
        uint8_t base;
      } u_reset;
      u_reset.base = 0;
      u_reset.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset = u_reset.real;
      offset += sizeof(this->reset);
     return offset;
    }

    virtual const char * getType() override { return LOADWORKCELL; };
    virtual const char * getMD5() override { return "08076deb9c1ff73d0e854c985981a25b"; };

  };

  class LoadWorkcellResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    LoadWorkcellResponse():
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

    virtual const char * getType() override { return LOADWORKCELL; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class LoadWorkcell {
    public:
    typedef LoadWorkcellRequest Request;
    typedef LoadWorkcellResponse Response;
  };

}
#endif
