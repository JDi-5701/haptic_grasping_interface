#ifndef _ROS_SERVICE_TaskGet_h
#define _ROS_SERVICE_TaskGet_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"
#include "process_msgs/Task.h"

namespace process_srvs
{

static const char TASKGET[] = "process_srvs/TaskGet";

  class TaskGetRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    TaskGetRequest():
      iri("")
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
     return offset;
    }

    virtual const char * getType() override { return TASKGET; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class TaskGetResponse : public ros::Msg
  {
    public:
      typedef process_msgs::Task _task_type;
      _task_type task;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskGetResponse():
      task(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->task.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->task.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TASKGET; };
    virtual const char * getMD5() override { return "5dca7336b48381e2dbd9b6917bb4d461"; };

  };

  class TaskGet {
    public:
    typedef TaskGetRequest Request;
    typedef TaskGetResponse Response;
  };

}
#endif
