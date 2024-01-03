#ifndef _ROS_SERVICE_GetWorldState_h
#define _ROS_SERVICE_GetWorldState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char GETWORLDSTATE[] = "world_state_model_srvs/GetWorldState";

  class GetWorldStateRequest : public ros::Msg
  {
    public:

    GetWorldStateRequest()
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

    virtual const char * getType() override { return GETWORLDSTATE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetWorldStateResponse : public ros::Msg
  {
    public:
      typedef const char* _worldState_type;
      _worldState_type worldState;
      typedef int32_t _error_type;
      _error_type error;

    GetWorldStateResponse():
      worldState(""),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_worldState = strlen(this->worldState);
      varToArr(outbuffer + offset, length_worldState);
      offset += 4;
      memcpy(outbuffer + offset, this->worldState, length_worldState);
      offset += length_worldState;
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
      uint32_t length_worldState;
      arrToVar(length_worldState, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_worldState; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_worldState-1]=0;
      this->worldState = (char *)(inbuffer + offset-1);
      offset += length_worldState;
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

    virtual const char * getType() override { return GETWORLDSTATE; };
    virtual const char * getMD5() override { return "295510e3254520014492ecfa6388a271"; };

  };

  class GetWorldState {
    public:
    typedef GetWorldStateRequest Request;
    typedef GetWorldStateResponse Response;
  };

}
#endif
