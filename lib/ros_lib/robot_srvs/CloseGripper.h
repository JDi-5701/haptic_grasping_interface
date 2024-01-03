#ifndef _ROS_SERVICE_CloseGripper_h
#define _ROS_SERVICE_CloseGripper_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char CLOSEGRIPPER[] = "robot_srvs/CloseGripper";

  class CloseGripperRequest : public ros::Msg
  {
    public:
      typedef const char* _gripperName_type;
      _gripperName_type gripperName;
      typedef float _closeRange_type;
      _closeRange_type closeRange;
      typedef float _closeForce_type;
      _closeForce_type closeForce;

    CloseGripperRequest():
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

    virtual const char * getType() override { return CLOSEGRIPPER; };
    virtual const char * getMD5() override { return "0616854ea69c10c7199c7b90581f998e"; };

  };

  class CloseGripperResponse : public ros::Msg
  {
    public:
      typedef bool _re_type;
      _re_type re;

    CloseGripperResponse():
      re(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_re;
      u_re.real = this->re;
      *(outbuffer + offset + 0) = (u_re.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->re);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_re;
      u_re.base = 0;
      u_re.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->re = u_re.real;
      offset += sizeof(this->re);
     return offset;
    }

    virtual const char * getType() override { return CLOSEGRIPPER; };
    virtual const char * getMD5() override { return "40b8ce32ad0b747f1e21dd682e3d7ebb"; };

  };

  class CloseGripper {
    public:
    typedef CloseGripperRequest Request;
    typedef CloseGripperResponse Response;
  };

}
#endif
