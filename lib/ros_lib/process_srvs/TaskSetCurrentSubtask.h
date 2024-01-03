#ifndef _ROS_SERVICE_TaskSetCurrentSubtask_h
#define _ROS_SERVICE_TaskSetCurrentSubtask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKSETCURRENTSUBTASK[] = "process_srvs/TaskSetCurrentSubtask";

  class TaskSetCurrentSubtaskRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _currentSubtaskIri_type;
      _currentSubtaskIri_type currentSubtaskIri;
      typedef bool _publish_type;
      _publish_type publish;

    TaskSetCurrentSubtaskRequest():
      iri(""),
      currentSubtaskIri(""),
      publish(0)
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
      uint32_t length_currentSubtaskIri = strlen(this->currentSubtaskIri);
      varToArr(outbuffer + offset, length_currentSubtaskIri);
      offset += 4;
      memcpy(outbuffer + offset, this->currentSubtaskIri, length_currentSubtaskIri);
      offset += length_currentSubtaskIri;
      union {
        bool real;
        uint8_t base;
      } u_publish;
      u_publish.real = this->publish;
      *(outbuffer + offset + 0) = (u_publish.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->publish);
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
      uint32_t length_currentSubtaskIri;
      arrToVar(length_currentSubtaskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_currentSubtaskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_currentSubtaskIri-1]=0;
      this->currentSubtaskIri = (char *)(inbuffer + offset-1);
      offset += length_currentSubtaskIri;
      union {
        bool real;
        uint8_t base;
      } u_publish;
      u_publish.base = 0;
      u_publish.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->publish = u_publish.real;
      offset += sizeof(this->publish);
     return offset;
    }

    virtual const char * getType() override { return TASKSETCURRENTSUBTASK; };
    virtual const char * getMD5() override { return "76d33c75d798496b984294d86eb0724c"; };

  };

  class TaskSetCurrentSubtaskResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskSetCurrentSubtaskResponse():
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

    virtual const char * getType() override { return TASKSETCURRENTSUBTASK; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskSetCurrentSubtask {
    public:
    typedef TaskSetCurrentSubtaskRequest Request;
    typedef TaskSetCurrentSubtaskResponse Response;
  };

}
#endif
