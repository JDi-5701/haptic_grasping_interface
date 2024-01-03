#ifndef _ROS_SERVICE_OpenGripper_h
#define _ROS_SERVICE_OpenGripper_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char OPENGRIPPER[] = "robot_srvs/OpenGripper";

  class OpenGripperRequest : public ros::Msg
  {
    public:
      typedef const char* _gripperName_type;
      _gripperName_type gripperName;
      typedef float _closeRange_type;
      _closeRange_type closeRange;
      typedef float _closeForce_type;
      _closeForce_type closeForce;

    OpenGripperRequest():
      gripperName(""),
      closeRange(0),
      closeForce(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_gripperName = strlen(this->gripperName);
      varToArr(outbuffer + offset, length_gripperName);
      offset += 4;
      memcpy(outbuffer + offset, this->gripperName, length_gripperName);
      offset += length_gripperName;
      offset += serializeAvrFloat64(outbuffer + offset, this->closeRange);
      offset += serializeAvrFloat64(outbuffer + offset, this->closeForce);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_gripperName;
      arrToVar(length_gripperName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gripperName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gripperName-1]=0;
      this->gripperName = (char *)(inbuffer + offset-1);
      offset += length_gripperName;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->closeRange));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->closeForce));
     return offset;
    }

    virtual const char * getType() override { return OPENGRIPPER; };
    virtual const char * getMD5() override { return "0616854ea69c10c7199c7b90581f998e"; };

  };

  class OpenGripperResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    OpenGripperResponse():
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

    virtual const char * getType() override { return OPENGRIPPER; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class OpenGripper {
    public:
    typedef OpenGripperRequest Request;
    typedef OpenGripperResponse Response;
  };

}
#endif
