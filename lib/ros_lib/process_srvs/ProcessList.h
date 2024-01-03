#ifndef _ROS_SERVICE_ProcessList_h
#define _ROS_SERVICE_ProcessList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Process.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSLIST[] = "process_srvs/ProcessList";

  class ProcessListRequest : public ros::Msg
  {
    public:

    ProcessListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return PROCESSLIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ProcessListResponse : public ros::Msg
  {
    public:
      uint32_t processes_length;
      typedef process_msgs::Process _processes_type;
      _processes_type st_processes;
      _processes_type * processes;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessListResponse():
      processes_length(0), st_processes(), processes(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->processes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->processes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->processes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->processes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->processes_length);
      for( uint32_t i = 0; i < processes_length; i++){
      offset += this->processes[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t processes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      processes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      processes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      processes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->processes_length);
      if(processes_lengthT > processes_length)
        this->processes = (process_msgs::Process*)realloc(this->processes, processes_lengthT * sizeof(process_msgs::Process));
      processes_length = processes_lengthT;
      for( uint32_t i = 0; i < processes_length; i++){
      offset += this->st_processes.deserialize(inbuffer + offset);
        memcpy( &(this->processes[i]), &(this->st_processes), sizeof(process_msgs::Process));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSLIST; };
    virtual const char * getMD5() override { return "8b82130b61dd91f7b2ef360967a4759e"; };

  };

  class ProcessList {
    public:
    typedef ProcessListRequest Request;
    typedef ProcessListResponse Response;
  };

}
#endif
