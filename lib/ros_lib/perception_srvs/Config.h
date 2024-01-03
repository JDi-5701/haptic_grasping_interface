#ifndef _ROS_SERVICE_Config_h
#define _ROS_SERVICE_Config_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_srvs
{

static const char CONFIG[] = "perception_srvs/Config";

  class ConfigRequest : public ros::Msg
  {
    public:
      typedef const char* _workcellIri_type;
      _workcellIri_type workcellIri;

    ConfigRequest():
      workcellIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_workcellIri = strlen(this->workcellIri);
      varToArr(outbuffer + offset, length_workcellIri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellIri, length_workcellIri);
      offset += length_workcellIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_workcellIri;
      arrToVar(length_workcellIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellIri-1]=0;
      this->workcellIri = (char *)(inbuffer + offset-1);
      offset += length_workcellIri;
     return offset;
    }

    virtual const char * getType() override { return CONFIG; };
    virtual const char * getMD5() override { return "a03649fa16b6c295a7b244f7d396c472"; };

  };

  class ConfigResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    ConfigResponse():
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

    virtual const char * getType() override { return CONFIG; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class Config {
    public:
    typedef ConfigRequest Request;
    typedef ConfigResponse Response;
  };

}
#endif
