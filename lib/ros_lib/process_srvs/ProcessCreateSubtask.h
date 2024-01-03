#ifndef _ROS_SERVICE_ProcessCreateSubtask_h
#define _ROS_SERVICE_ProcessCreateSubtask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"
#include "process_msgs/Task.h"

namespace process_srvs
{

static const char PROCESSCREATESUBTASK[] = "process_srvs/ProcessCreateSubtask";

  class ProcessCreateSubtaskRequest : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;
      typedef const char* _subtaskTypeIri_type;
      _subtaskTypeIri_type subtaskTypeIri;

    ProcessCreateSubtaskRequest():
      processIri(""),
      subtaskTypeIri("")
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
      uint32_t length_subtaskTypeIri = strlen(this->subtaskTypeIri);
      varToArr(outbuffer + offset, length_subtaskTypeIri);
      offset += 4;
      memcpy(outbuffer + offset, this->subtaskTypeIri, length_subtaskTypeIri);
      offset += length_subtaskTypeIri;
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
      uint32_t length_subtaskTypeIri;
      arrToVar(length_subtaskTypeIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subtaskTypeIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subtaskTypeIri-1]=0;
      this->subtaskTypeIri = (char *)(inbuffer + offset-1);
      offset += length_subtaskTypeIri;
     return offset;
    }

    virtual const char * getType() override { return PROCESSCREATESUBTASK; };
    virtual const char * getMD5() override { return "fac061bf17fb7f527463b5d3391a5cd1"; };

  };

  class ProcessCreateSubtaskResponse : public ros::Msg
  {
    public:
      typedef process_msgs::Task _subtask_type;
      _subtask_type subtask;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessCreateSubtaskResponse():
      subtask(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->subtask.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->subtask.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSCREATESUBTASK; };
    virtual const char * getMD5() override { return "10348f1d58bbd338fc260507b4847afe"; };

  };

  class ProcessCreateSubtask {
    public:
    typedef ProcessCreateSubtaskRequest Request;
    typedef ProcessCreateSubtaskResponse Response;
  };

}
#endif
