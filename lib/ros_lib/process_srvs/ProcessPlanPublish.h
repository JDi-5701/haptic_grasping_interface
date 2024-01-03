#ifndef _ROS_SERVICE_ProcessPlanPublish_h
#define _ROS_SERVICE_ProcessPlanPublish_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSPLANPUBLISH[] = "process_srvs/ProcessPlanPublish";

  class ProcessPlanPublishRequest : public ros::Msg
  {
    public:

    ProcessPlanPublishRequest()
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

    virtual const char * getType() override { return PROCESSPLANPUBLISH; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ProcessPlanPublishResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessPlanPublishResponse():
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

    virtual const char * getType() override { return PROCESSPLANPUBLISH; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class ProcessPlanPublish {
    public:
    typedef ProcessPlanPublishRequest Request;
    typedef ProcessPlanPublishResponse Response;
  };

}
#endif
