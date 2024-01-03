#ifndef _ROS_SERVICE_TaskCreateSubtask_h
#define _ROS_SERVICE_TaskCreateSubtask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"
#include "process_msgs/Task.h"

namespace process_srvs
{

static const char TASKCREATESUBTASK[] = "process_srvs/TaskCreateSubtask";

  class TaskCreateSubtaskRequest : public ros::Msg
  {
    public:
      typedef const char* _taskIri_type;
      _taskIri_type taskIri;
      typedef const char* _subtaskTypeIri_type;
      _subtaskTypeIri_type subtaskTypeIri;

    TaskCreateSubtaskRequest():
      taskIri(""),
      subtaskTypeIri("")
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
      uint32_t length_taskIri;
      arrToVar(length_taskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_taskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_taskIri-1]=0;
      this->taskIri = (char *)(inbuffer + offset-1);
      offset += length_taskIri;
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

    virtual const char * getType() override { return TASKCREATESUBTASK; };
    virtual const char * getMD5() override { return "66f50a740816c7697411b760b789082d"; };

  };

  class TaskCreateSubtaskResponse : public ros::Msg
  {
    public:
      typedef process_msgs::Task _subtask_type;
      _subtask_type subtask;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskCreateSubtaskResponse():
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

    virtual const char * getType() override { return TASKCREATESUBTASK; };
    virtual const char * getMD5() override { return "10348f1d58bbd338fc260507b4847afe"; };

  };

  class TaskCreateSubtask {
    public:
    typedef TaskCreateSubtaskRequest Request;
    typedef TaskCreateSubtaskResponse Response;
  };

}
#endif
