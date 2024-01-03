#ifndef _ROS_process_msgs_ProcessPlan_h
#define _ROS_process_msgs_ProcessPlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Process.h"
#include "process_msgs/Task.h"

namespace process_msgs
{

  class ProcessPlan : public ros::Msg
  {
    public:
      typedef process_msgs::Process _process_type;
      _process_type process;
      uint32_t tasks_length;
      typedef process_msgs::Task _tasks_type;
      _tasks_type st_tasks;
      _tasks_type * tasks;

    ProcessPlan():
      process(),
      tasks_length(0), st_tasks(), tasks(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->process.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tasks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tasks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tasks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tasks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tasks_length);
      for( uint32_t i = 0; i < tasks_length; i++){
      offset += this->tasks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->process.deserialize(inbuffer + offset);
      uint32_t tasks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tasks_length);
      if(tasks_lengthT > tasks_length)
        this->tasks = (process_msgs::Task*)realloc(this->tasks, tasks_lengthT * sizeof(process_msgs::Task));
      tasks_length = tasks_lengthT;
      for( uint32_t i = 0; i < tasks_length; i++){
      offset += this->st_tasks.deserialize(inbuffer + offset);
        memcpy( &(this->tasks[i]), &(this->st_tasks), sizeof(process_msgs::Task));
      }
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/ProcessPlan"; };
    virtual const char * getMD5() override { return "c6d9f6ec0195b92a7ecc5022bf30f399"; };

  };

}
#endif
