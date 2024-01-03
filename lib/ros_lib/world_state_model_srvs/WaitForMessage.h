#ifndef _ROS_SERVICE_WaitForMessage_h
#define _ROS_SERVICE_WaitForMessage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char WAITFORMESSAGE[] = "world_state_model_srvs/WaitForMessage";

  class WaitForMessageRequest : public ros::Msg
  {
    public:
      typedef const char* _topicName_type;
      _topicName_type topicName;
      typedef int32_t _seq_type;
      _seq_type seq;

    WaitForMessageRequest():
      topicName(""),
      seq(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_topicName = strlen(this->topicName);
      varToArr(outbuffer + offset, length_topicName);
      offset += 4;
      memcpy(outbuffer + offset, this->topicName, length_topicName);
      offset += length_topicName;
      union {
        int32_t real;
        uint32_t base;
      } u_seq;
      u_seq.real = this->seq;
      *(outbuffer + offset + 0) = (u_seq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_seq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_seq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_seq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seq);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_topicName;
      arrToVar(length_topicName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topicName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topicName-1]=0;
      this->topicName = (char *)(inbuffer + offset-1);
      offset += length_topicName;
      union {
        int32_t real;
        uint32_t base;
      } u_seq;
      u_seq.base = 0;
      u_seq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_seq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_seq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_seq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq = u_seq.real;
      offset += sizeof(this->seq);
     return offset;
    }

    virtual const char * getType() override { return WAITFORMESSAGE; };
    virtual const char * getMD5() override { return "e0eee8963098bdf4b043682183b40356"; };

  };

  class WaitForMessageResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    WaitForMessageResponse():
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error = u_error.real;
      offset += sizeof(this->error);
     return offset;
    }

    virtual const char * getType() override { return WAITFORMESSAGE; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class WaitForMessage {
    public:
    typedef WaitForMessageRequest Request;
    typedef WaitForMessageResponse Response;
  };

}
#endif
