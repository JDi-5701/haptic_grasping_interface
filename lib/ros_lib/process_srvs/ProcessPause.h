#ifndef _ROS_SERVICE_ProcessPause_h
#define _ROS_SERVICE_ProcessPause_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_srvs
{

static const char PROCESSPAUSE[] = "process_srvs/ProcessPause";

  class ProcessPauseRequest : public ros::Msg
  {
    public:
      typedef bool _pause_type;
      _pause_type pause;

    ProcessPauseRequest():
      pause(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pause;
      u_pause.real = this->pause;
      *(outbuffer + offset + 0) = (u_pause.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pause);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pause;
      u_pause.base = 0;
      u_pause.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pause = u_pause.real;
      offset += sizeof(this->pause);
     return offset;
    }

    virtual const char * getType() override { return PROCESSPAUSE; };
    virtual const char * getMD5() override { return "769db6046968e824fd55099ac609f204"; };

  };

  class ProcessPauseResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ProcessPauseResponse():
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

    virtual const char * getType() override { return PROCESSPAUSE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ProcessPause {
    public:
    typedef ProcessPauseRequest Request;
    typedef ProcessPauseResponse Response;
  };

}
#endif
