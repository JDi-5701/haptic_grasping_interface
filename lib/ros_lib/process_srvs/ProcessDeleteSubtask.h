#ifndef _ROS_SERVICE_ProcessDeleteSubtask_h
#define _ROS_SERVICE_ProcessDeleteSubtask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSDELETESUBTASK[] = "process_srvs/ProcessDeleteSubtask";

  class ProcessDeleteSubtaskRequest : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;
      typedef const char* _subtaskIri_type;
      _subtaskIri_type subtaskIri;

    ProcessDeleteSubtaskRequest():
      processIri(""),
      subtaskIri("")
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
      uint32_t length_subtaskIri = strlen(this->subtaskIri);
      varToArr(outbuffer + offset, length_subtaskIri);
      offset += 4;
      memcpy(outbuffer + offset, this->subtaskIri, length_subtaskIri);
      offset += length_subtaskIri;
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
      uint32_t length_subtaskIri;
      arrToVar(length_subtaskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subtaskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subtaskIri-1]=0;
      this->subtaskIri = (char *)(inbuffer + offset-1);
      offset += length_subtaskIri;
     return offset;
    }

    virtual const char * getType() override { return PROCESSDELETESUBTASK; };
    virtual const char * getMD5() override { return "e78512cacb54b4373f008f9421dd92a4"; };

  };

  class ProcessDeleteSubtaskResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessDeleteSubtaskResponse():
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

    virtual const char * getType() override { return PROCESSDELETESUBTASK; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class ProcessDeleteSubtask {
    public:
    typedef ProcessDeleteSubtaskRequest Request;
    typedef ProcessDeleteSubtaskResponse Response;
  };

}
#endif
