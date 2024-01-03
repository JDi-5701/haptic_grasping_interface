#ifndef _ROS_SERVICE_ProcessCreate_h
#define _ROS_SERVICE_ProcessCreate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Process.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSCREATE[] = "process_srvs/ProcessCreate";

  class ProcessCreateRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;

    ProcessCreateRequest():
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    virtual const char * getType() override { return PROCESSCREATE; };
    virtual const char * getMD5() override { return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class ProcessCreateResponse : public ros::Msg
  {
    public:
      typedef process_msgs::Process _process_type;
      _process_type process;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessCreateResponse():
      process(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->process.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->process.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSCREATE; };
    virtual const char * getMD5() override { return "4dcc2906b1c813a5436cca9679224ab1"; };

  };

  class ProcessCreate {
    public:
    typedef ProcessCreateRequest Request;
    typedef ProcessCreateResponse Response;
  };

}
#endif
