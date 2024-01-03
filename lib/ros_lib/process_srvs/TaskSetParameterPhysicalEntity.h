#ifndef _ROS_SERVICE_TaskSetParameterPhysicalEntity_h
#define _ROS_SERVICE_TaskSetParameterPhysicalEntity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERPHYSICALENTITY[] = "process_srvs/TaskSetParameterPhysicalEntity";

  class TaskSetParameterPhysicalEntityRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef const char* _physicalEntityIri_type;
      _physicalEntityIri_type physicalEntityIri;

    TaskSetParameterPhysicalEntityRequest():
      iri(""),
      parameterIri(""),
      physicalEntityIri("")
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
      uint32_t length_physicalEntityIri = strlen(this->physicalEntityIri);
      varToArr(outbuffer + offset, length_physicalEntityIri);
      offset += 4;
      memcpy(outbuffer + offset, this->physicalEntityIri, length_physicalEntityIri);
      offset += length_physicalEntityIri;
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
      uint32_t length_physicalEntityIri;
      arrToVar(length_physicalEntityIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_physicalEntityIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_physicalEntityIri-1]=0;
      this->physicalEntityIri = (char *)(inbuffer + offset-1);
      offset += length_physicalEntityIri;
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERPHYSICALENTITY; };
    virtual const char * getMD5() override { return "3d643962b5fc2648c1b0fcc0862d8866"; };

  };

  class TaskSetParameterPhysicalEntityResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterPhysicalEntityResponse():
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

    virtual const char * getType() override { return TASKSETPARAMETERPHYSICALENTITY; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterPhysicalEntity {
    public:
    typedef TaskSetParameterPhysicalEntityRequest Request;
    typedef TaskSetParameterPhysicalEntityResponse Response;
  };

}
#endif
