#ifndef _ROS_SERVICE_GetObjectDetectors_h
#define _ROS_SERVICE_GetObjectDetectors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_state_model_srvs
{

static const char GETOBJECTDETECTORS[] = "world_state_model_srvs/GetObjectDetectors";

  class GetObjectDetectorsRequest : public ros::Msg
  {
    public:

    GetObjectDetectorsRequest()
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

    virtual const char * getType() override { return GETOBJECTDETECTORS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetObjectDetectorsResponse : public ros::Msg
  {
    public:
      uint32_t topicNames_length;
      typedef char* _topicNames_type;
      _topicNames_type st_topicNames;
      _topicNames_type * topicNames;
      typedef int32_t _error_type;
      _error_type error;

    GetObjectDetectorsResponse():
      topicNames_length(0), st_topicNames(), topicNames(nullptr),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->topicNames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topicNames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topicNames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topicNames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topicNames_length);
      for( uint32_t i = 0; i < topicNames_length; i++){
      uint32_t length_topicNamesi = strlen(this->topicNames[i]);
      varToArr(outbuffer + offset, length_topicNamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->topicNames[i], length_topicNamesi);
      offset += length_topicNamesi;
      }
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
      uint32_t topicNames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topicNames_length);
      if(topicNames_lengthT > topicNames_length)
        this->topicNames = (char**)realloc(this->topicNames, topicNames_lengthT * sizeof(char*));
      topicNames_length = topicNames_lengthT;
      for( uint32_t i = 0; i < topicNames_length; i++){
      uint32_t length_st_topicNames;
      arrToVar(length_st_topicNames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topicNames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topicNames-1]=0;
      this->st_topicNames = (char *)(inbuffer + offset-1);
      offset += length_st_topicNames;
        memcpy( &(this->topicNames[i]), &(this->st_topicNames), sizeof(char*));
      }
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

    virtual const char * getType() override { return GETOBJECTDETECTORS; };
    virtual const char * getMD5() override { return "7d4b8e6ac00d82f7b074719dcda77e43"; };

  };

  class GetObjectDetectors {
    public:
    typedef GetObjectDetectorsRequest Request;
    typedef GetObjectDetectorsResponse Response;
  };

}
#endif
