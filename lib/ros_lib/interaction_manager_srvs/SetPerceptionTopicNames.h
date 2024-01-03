#ifndef _ROS_SERVICE_SetPerceptionTopicNames_h
#define _ROS_SERVICE_SetPerceptionTopicNames_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace interaction_manager_srvs
{

static const char SETPERCEPTIONTOPICNAMES[] = "interaction_manager_srvs/SetPerceptionTopicNames";

  class SetPerceptionTopicNamesRequest : public ros::Msg
  {
    public:
      uint32_t perceptionTopicNames_length;
      typedef char* _perceptionTopicNames_type;
      _perceptionTopicNames_type st_perceptionTopicNames;
      _perceptionTopicNames_type * perceptionTopicNames;

    SetPerceptionTopicNamesRequest():
      perceptionTopicNames_length(0), st_perceptionTopicNames(), perceptionTopicNames(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->perceptionTopicNames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->perceptionTopicNames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->perceptionTopicNames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->perceptionTopicNames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->perceptionTopicNames_length);
      for( uint32_t i = 0; i < perceptionTopicNames_length; i++){
      uint32_t length_perceptionTopicNamesi = strlen(this->perceptionTopicNames[i]);
      varToArr(outbuffer + offset, length_perceptionTopicNamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->perceptionTopicNames[i], length_perceptionTopicNamesi);
      offset += length_perceptionTopicNamesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t perceptionTopicNames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      perceptionTopicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      perceptionTopicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      perceptionTopicNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->perceptionTopicNames_length);
      if(perceptionTopicNames_lengthT > perceptionTopicNames_length)
        this->perceptionTopicNames = (char**)realloc(this->perceptionTopicNames, perceptionTopicNames_lengthT * sizeof(char*));
      perceptionTopicNames_length = perceptionTopicNames_lengthT;
      for( uint32_t i = 0; i < perceptionTopicNames_length; i++){
      uint32_t length_st_perceptionTopicNames;
      arrToVar(length_st_perceptionTopicNames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_perceptionTopicNames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_perceptionTopicNames-1]=0;
      this->st_perceptionTopicNames = (char *)(inbuffer + offset-1);
      offset += length_st_perceptionTopicNames;
        memcpy( &(this->perceptionTopicNames[i]), &(this->st_perceptionTopicNames), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return SETPERCEPTIONTOPICNAMES; };
    virtual const char * getMD5() override { return "eee7d4be2303c2912a2cd940e7a67878"; };

  };

  class SetPerceptionTopicNamesResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetPerceptionTopicNamesResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETPERCEPTIONTOPICNAMES; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetPerceptionTopicNames {
    public:
    typedef SetPerceptionTopicNamesRequest Request;
    typedef SetPerceptionTopicNamesResponse Response;
  };

}
#endif
