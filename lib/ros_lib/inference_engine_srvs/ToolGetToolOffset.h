#ifndef _ROS_SERVICE_ToolGetToolOffset_h
#define _ROS_SERVICE_ToolGetToolOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"
#include "geometry_msgs/Transform.h"

namespace inference_engine_srvs
{

static const char TOOLGETTOOLOFFSET[] = "inference_engine_srvs/ToolGetToolOffset";

  class ToolGetToolOffsetRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    ToolGetToolOffsetRequest():
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

    virtual const char * getType() override { return TOOLGETTOOLOFFSET; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class ToolGetToolOffsetResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _toolOffset_type;
      _toolOffset_type toolOffset;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ToolGetToolOffsetResponse():
      toolOffset(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->toolOffset.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->toolOffset.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TOOLGETTOOLOFFSET; };
    virtual const char * getMD5() override { return "961ece204dc3ab1a986f474aca55f494"; };

  };

  class ToolGetToolOffset {
    public:
    typedef ToolGetToolOffsetRequest Request;
    typedef ToolGetToolOffsetResponse Response;
  };

}
#endif
