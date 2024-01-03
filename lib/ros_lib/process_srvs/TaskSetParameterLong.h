#ifndef _ROS_SERVICE_TaskSetParameterLong_h
#define _ROS_SERVICE_TaskSetParameterLong_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETPARAMETERLONG[] = "process_srvs/TaskSetParameterLong";

  class TaskSetParameterLongRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _parameterIri_type;
      _parameterIri_type parameterIri;
      typedef int64_t _l_type;
      _l_type l;

    TaskSetParameterLongRequest():
      iri(""),
      parameterIri(""),
      l(0)
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
        int64_t real;
        uint64_t base;
      } u_l;
      u_l.real = this->l;
      *(outbuffer + offset + 0) = (u_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l);
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
        int64_t real;
        uint64_t base;
      } u_l;
      u_l.base = 0;
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l = u_l.real;
      offset += sizeof(this->l);
     return offset;
    }

    virtual const char * getType() override { return TASKSETPARAMETERLONG; };
    virtual const char * getMD5() override { return "b0f2194d4fba451bf0641f2c46b79565"; };

  };

  class TaskSetParameterLongResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetParameterLongResponse():
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

    virtual const char * getType() override { return TASKSETPARAMETERLONG; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetParameterLong {
    public:
    typedef TaskSetParameterLongRequest Request;
    typedef TaskSetParameterLongResponse Response;
  };

}
#endif
