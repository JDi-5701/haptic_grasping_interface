#ifndef _ROS_SERVICE_WaitForObjectDetectors_h
#define _ROS_SERVICE_WaitForObjectDetectors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char WAITFOROBJECTDETECTORS[] = "world_state_model_srvs/WaitForObjectDetectors";

  class WaitForObjectDetectorsRequest : public ros::Msg
  {
    public:

    WaitForObjectDetectorsRequest()
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

    virtual const char * getType() override { return WAITFOROBJECTDETECTORS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaitForObjectDetectorsResponse : public ros::Msg
  {
    public:

    WaitForObjectDetectorsResponse()
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

    virtual const char * getType() override { return WAITFOROBJECTDETECTORS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WaitForObjectDetectors {
    public:
    typedef WaitForObjectDetectorsRequest Request;
    typedef WaitForObjectDetectorsResponse Response;
  };

}
#endif
