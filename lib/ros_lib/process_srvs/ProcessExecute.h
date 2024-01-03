#ifndef _ROS_SERVICE_ProcessExecute_h
#define _ROS_SERVICE_ProcessExecute_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_srvs
{

static const char PROCESSEXECUTE[] = "process_srvs/ProcessExecute";

  class ProcessExecuteRequest : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;

    ProcessExecuteRequest():
      processIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_processIri = strlen(this->processIri);
      varToArr(outbuffer + offset, length_processIri);
      offset += 4;
      memcpy(outbuffer + offset, this->processIri, length_processIri);
      offset += length_processIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_processIri;
      arrToVar(length_processIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_processIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_processIri-1]=0;
      this->processIri = (char *)(inbuffer + offset-1);
      offset += length_processIri;
     return offset;
    }

    virtual const char * getType() override { return PROCESSEXECUTE; };
    virtual const char * getMD5() override { return "0beb18b01966b87b9d67ad9b9e3961e4"; };

  };

  class ProcessExecuteResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ProcessExecuteResponse():
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

    virtual const char * getType() override { return PROCESSEXECUTE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ProcessExecute {
    public:
    typedef ProcessExecuteRequest Request;
    typedef ProcessExecuteResponse Response;
  };

}
#endif
