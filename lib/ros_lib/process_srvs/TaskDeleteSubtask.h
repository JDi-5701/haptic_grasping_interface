#ifndef _ROS_SERVICE_TaskDeleteSubtask_h
#define _ROS_SERVICE_TaskDeleteSubtask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKDELETESUBTASK[] = "process_srvs/TaskDeleteSubtask";

  class TaskDeleteSubtaskRequest : public ros::Msg
  {
    public:
      typedef const char* _taskIri_type;
      _taskIri_type taskIri;
      typedef const char* _subtaskIri_type;
      _subtaskIri_type subtaskIri;

    TaskDeleteSubtaskRequest():
      taskIri(""),
      subtaskIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_taskIri = strlen(this->taskIri);
      varToArr(outbuffer + offset, length_taskIri);
      offset += 4;
      memcpy(outbuffer + offset, this->taskIri, length_taskIri);
      offset += length_taskIri;
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
      uint32_t length_taskIri;
      arrToVar(length_taskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_taskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_taskIri-1]=0;
      this->taskIri = (char *)(inbuffer + offset-1);
      offset += length_taskIri;
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

    virtual const char * getType() override { return TASKDELETESUBTASK; };
    virtual const char * getMD5() override { return "c82056d9b3de176b48beef8cffccdc54"; };

  };

  class TaskDeleteSubtaskResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskDeleteSubtaskResponse():
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

    virtual const char * getType() override { return TASKDELETESUBTASK; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class TaskDeleteSubtask {
    public:
    typedef TaskDeleteSubtaskRequest Request;
    typedef TaskDeleteSubtaskResponse Response;
  };

}
#endif
