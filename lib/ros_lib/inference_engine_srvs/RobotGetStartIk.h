#ifndef _ROS_SERVICE_RobotGetStartIk_h
#define _ROS_SERVICE_RobotGetStartIk_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace inference_engine_srvs
{

static const char ROBOTGETSTARTIK[] = "inference_engine_srvs/RobotGetStartIk";

  class RobotGetStartIkRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    RobotGetStartIkRequest():
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

    virtual const char * getType() override { return ROBOTGETSTARTIK; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class RobotGetStartIkResponse : public ros::Msg
  {
    public:
      uint32_t startIk_length;
      typedef float _startIk_type;
      _startIk_type st_startIk;
      _startIk_type * startIk;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    RobotGetStartIkResponse():
      startIk_length(0), st_startIk(), startIk(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->startIk_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->startIk_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->startIk_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->startIk_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->startIk_length);
      for( uint32_t i = 0; i < startIk_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->startIk[i]);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t startIk_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      startIk_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      startIk_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      startIk_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->startIk_length);
      if(startIk_lengthT > startIk_length)
        this->startIk = (float*)realloc(this->startIk, startIk_lengthT * sizeof(float));
      startIk_length = startIk_lengthT;
      for( uint32_t i = 0; i < startIk_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_startIk));
        memcpy( &(this->startIk[i]), &(this->st_startIk), sizeof(float));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ROBOTGETSTARTIK; };
    virtual const char * getMD5() override { return "6154243fb7c8f60b6a7bfd4ec977d3fa"; };

  };

  class RobotGetStartIk {
    public:
    typedef RobotGetStartIkRequest Request;
    typedef RobotGetStartIkResponse Response;
  };

}
#endif
