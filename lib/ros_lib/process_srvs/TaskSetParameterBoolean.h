#ifndef _ROS_SERVICE_TaskSetParameterBoolean_h
#define _ROS_SERVICE_TaskSetParameterBoolean_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERBOOLEAN[] = "process_srvs/TaskSetParameterBoolean";

  class TaskSetParameterBooleanRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef bool _b_type;
      _b_type b;

    TaskSetParameterBooleanRequest():
      iri(""),
      parameterIri(""),
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_iri = strlen(this->iri);
      varToArr(outbuffer + offset, length_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->iri, length_iri);
      offset += length_iri;
      uint32_t length_parameterIri = strlen(this->parameterIri);
      varToArr(outbuffer + offset, length_parameterIri);
      offset += 4;
      memcpy(outbuffer + offset, this->parameterIri, length_parameterIri);
      offset += length_parameterIri;
      union {
        bool real;
        uint8_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_iri;
      arrToVar(length_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_iri-1]=0;
      this->iri = (char *)(inbuffer + offset-1);
      offset += length_iri;
      uint32_t length_parameterIri;
      arrToVar(length_parameterIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameterIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameterIri-1]=0;
      this->parameterIri = (char *)(inbuffer + offset-1);
      offset += length_parameterIri;
      union {
        bool real;
        uint8_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b = u_b.real;
      offset += sizeof(this->b);
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERBOOLEAN; };
    virtual const char * getMD5() override { return "082fbef2c0e590648c13dc07252bf16a"; };

  };

  class TaskSetParameterBooleanResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterBooleanResponse():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERBOOLEAN; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterBoolean {
    public:
    typedef TaskSetParameterBooleanRequest Request;
    typedef TaskSetParameterBooleanResponse Response;
  };

}
#endif
