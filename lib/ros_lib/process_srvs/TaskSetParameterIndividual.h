#ifndef _ROS_SERVICE_TaskSetParameterIndividual_h
#define _ROS_SERVICE_TaskSetParameterIndividual_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERINDIVIDUAL[] = "process_srvs/TaskSetParameterIndividual";

  class TaskSetParameterIndividualRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef const char* _individualIri_type;
      _individualIri_type individualIri;

    TaskSetParameterIndividualRequest():
      iri(""),
      parameterIri(""),
      individualIri("")
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
      uint32_t length_individualIri = strlen(this->individualIri);
      varToArr(outbuffer + offset, length_individualIri);
      offset += 4;
      memcpy(outbuffer + offset, this->individualIri, length_individualIri);
      offset += length_individualIri;
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
      uint32_t length_individualIri;
      arrToVar(length_individualIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_individualIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_individualIri-1]=0;
      this->individualIri = (char *)(inbuffer + offset-1);
      offset += length_individualIri;
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERINDIVIDUAL; };
    virtual const char * getMD5() override { return "404733588df3f652074c733567d5f2fe"; };

  };

  class TaskSetParameterIndividualResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterIndividualResponse():
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

    virtual const char * getType() override { return TASKSETPARAMETERINDIVIDUAL; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterIndividual {
    public:
    typedef TaskSetParameterIndividualRequest Request;
    typedef TaskSetParameterIndividualResponse Response;
  };

}
#endif
