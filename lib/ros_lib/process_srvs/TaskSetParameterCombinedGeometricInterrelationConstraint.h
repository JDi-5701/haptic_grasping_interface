#ifndef _ROS_SERVICE_TaskSetParameterCombinedGeometricInterrelationConstraint_h
#define _ROS_SERVICE_TaskSetParameterCombinedGeometricInterrelationConstraint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/CombinedGeometricInterrelationConstraint.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERCOMBINEDGEOMETRICINTERRELATIONCONSTRAINT[] = "process_srvs/TaskSetParameterCombinedGeometricInterrelationConstraint";

  class TaskSetParameterCombinedGeometricInterrelationConstraintRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef process_msgs::CombinedGeometricInterrelationConstraint _combinedGeometricInterrelationConstraint_type;
      _combinedGeometricInterrelationConstraint_type combinedGeometricInterrelationConstraint;

    TaskSetParameterCombinedGeometricInterrelationConstraintRequest():
      iri(""),
      parameterIri(""),
      combinedGeometricInterrelationConstraint()
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
      offset += this->combinedGeometricInterrelationConstraint.serialize(outbuffer + offset);
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
      offset += this->combinedGeometricInterrelationConstraint.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERCOMBINEDGEOMETRICINTERRELATIONCONSTRAINT; };
    virtual const char * getMD5() override { return "566b17957bee5df68482e1c05068b237"; };

  };

  class TaskSetParameterCombinedGeometricInterrelationConstraintResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterCombinedGeometricInterrelationConstraintResponse():
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

    virtual const char * getType() override { return TASKSETPARAMETERCOMBINEDGEOMETRICINTERRELATIONCONSTRAINT; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterCombinedGeometricInterrelationConstraint {
    public:
    typedef TaskSetParameterCombinedGeometricInterrelationConstraintRequest Request;
    typedef TaskSetParameterCombinedGeometricInterrelationConstraintResponse Response;
  };

}
#endif
