#ifndef _ROS_SERVICE_TaskSetParameterString_h
#define _ROS_SERVICE_TaskSetParameterString_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERSTRING[] = "process_srvs/TaskSetParameterString";

  class TaskSetParameterStringRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef const char* _s_type;
      _s_type s;

    TaskSetParameterStringRequest():
      iri(""),
      parameterIri(""),
      s("")
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
      uint32_t length_s = strlen(this->s);
      varToArr(outbuffer + offset, length_s);
      offset += 4;
      memcpy(outbuffer + offset, this->s, length_s);
      offset += length_s;
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
      uint32_t length_s;
      arrToVar(length_s, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_s; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_s-1]=0;
      this->s = (char *)(inbuffer + offset-1);
      offset += length_s;
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERSTRING; };
    virtual const char * getMD5() override { return "7fcf80047fbccbd7209413206eaef102"; };

  };

  class TaskSetParameterStringResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterStringResponse():
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

    virtual const char * getType() override { return TASKSETPARAMETERSTRING; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterString {
    public:
    typedef TaskSetParameterStringRequest Request;
    typedef TaskSetParameterStringResponse Response;
  };

}
#endif
