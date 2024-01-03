#ifndef _ROS_process_msgs_Effect_h
#define _ROS_process_msgs_Effect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Class.h"

namespace process_msgs
{

  class Effect : public ros::Msg
  {
    public:
      typedef process_msgs::Class _type_type;
      _type_type type;
      typedef const char* _iri_type;
      _iri_type iri;

    Effect():
      type(),
      iri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->type.serialize(outbuffer + offset);
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
      offset += this->type.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return "process_msgs/Effect"; };
    virtual const char * getMD5() override { return "01dd1a8426d1ed6239cfde3ca7f060c2"; };

  };

}
#endif
