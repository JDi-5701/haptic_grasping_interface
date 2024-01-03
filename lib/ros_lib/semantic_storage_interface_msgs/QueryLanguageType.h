#ifndef _ROS_semantic_storage_interface_msgs_QueryLanguageType_h
#define _ROS_semantic_storage_interface_msgs_QueryLanguageType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_msgs
{

  class QueryLanguageType : public ros::Msg
  {
    public:
      enum { SERQL =  33001 };
      enum { SPARQL =  33002 };
      enum { SERQO =  33003 };

    QueryLanguageType()
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

    virtual const char * getType() override { return "semantic_storage_interface_msgs/QueryLanguageType"; };
    virtual const char * getMD5() override { return "fa461ac9085f6535b63df3e9271443c6"; };

  };

}
#endif
