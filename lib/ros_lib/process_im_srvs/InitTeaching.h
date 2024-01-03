#ifndef _ROS_SERVICE_InitTeaching_h
#define _ROS_SERVICE_InitTeaching_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_im_srvs
{

static const char INITTEACHING[] = "process_im_srvs/InitTeaching";

  class InitTeachingRequest : public ros::Msg
  {
    public:
      typedef const char* _workcellName_type;
      _workcellName_type workcellName;
      typedef const char* _workcellUri_type;
      _workcellUri_type workcellUri;
      uint32_t dynamicActors_length;
      typedef char* _dynamicActors_type;
      _dynamicActors_type st_dynamicActors;
      _dynamicActors_type * dynamicActors;

    InitTeachingRequest():
      workcellName(""),
      workcellUri(""),
      dynamicActors_length(0), st_dynamicActors(), dynamicActors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_workcellName = strlen(this->workcellName);
      varToArr(outbuffer + offset, length_workcellName);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellName, length_workcellName);
      offset += length_workcellName;
      uint32_t length_workcellUri = strlen(this->workcellUri);
      varToArr(outbuffer + offset, length_workcellUri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellUri, length_workcellUri);
      offset += length_workcellUri;
      *(outbuffer + offset + 0) = (this->dynamicActors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dynamicActors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dynamicActors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dynamicActors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dynamicActors_length);
      for( uint32_t i = 0; i < dynamicActors_length; i++){
      uint32_t length_dynamicActorsi = strlen(this->dynamicActors[i]);
      varToArr(outbuffer + offset, length_dynamicActorsi);
      offset += 4;
      memcpy(outbuffer + offset, this->dynamicActors[i], length_dynamicActorsi);
      offset += length_dynamicActorsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_workcellName;
      arrToVar(length_workcellName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellName-1]=0;
      this->workcellName = (char *)(inbuffer + offset-1);
      offset += length_workcellName;
      uint32_t length_workcellUri;
      arrToVar(length_workcellUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellUri-1]=0;
      this->workcellUri = (char *)(inbuffer + offset-1);
      offset += length_workcellUri;
      uint32_t dynamicActors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dynamicActors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dynamicActors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dynamicActors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dynamicActors_length);
      if(dynamicActors_lengthT > dynamicActors_length)
        this->dynamicActors = (char**)realloc(this->dynamicActors, dynamicActors_lengthT * sizeof(char*));
      dynamicActors_length = dynamicActors_lengthT;
      for( uint32_t i = 0; i < dynamicActors_length; i++){
      uint32_t length_st_dynamicActors;
      arrToVar(length_st_dynamicActors, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_dynamicActors; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_dynamicActors-1]=0;
      this->st_dynamicActors = (char *)(inbuffer + offset-1);
      offset += length_st_dynamicActors;
        memcpy( &(this->dynamicActors[i]), &(this->st_dynamicActors), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return INITTEACHING; };
    virtual const char * getMD5() override { return "a39363ba35784e91fcf503e30a490336"; };

  };

  class InitTeachingResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    InitTeachingResponse():
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

    virtual const char * getType() override { return INITTEACHING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class InitTeaching {
    public:
    typedef InitTeachingRequest Request;
    typedef InitTeachingResponse Response;
  };

}
#endif
