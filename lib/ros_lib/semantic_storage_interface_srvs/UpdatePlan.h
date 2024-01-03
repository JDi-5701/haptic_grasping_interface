#ifndef _ROS_SERVICE_UpdatePlan_h
#define _ROS_SERVICE_UpdatePlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_srvs
{

static const char UPDATEPLAN[] = "semantic_storage_interface_srvs/UpdatePlan";

  class UpdatePlanRequest : public ros::Msg
  {
    public:
      typedef const char* _planUri_type;
      _planUri_type planUri;
      typedef const char* _plan_type;
      _plan_type plan;
      typedef const char* _description_type;
      _description_type description;
      uint32_t newFiles_length;
      typedef semantic_storage_interface_msgs::RosFile _newFiles_type;
      _newFiles_type st_newFiles;
      _newFiles_type * newFiles;

    UpdatePlanRequest():
      planUri(""),
      plan(""),
      description(""),
      newFiles_length(0), st_newFiles(), newFiles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_planUri = strlen(this->planUri);
      varToArr(outbuffer + offset, length_planUri);
      offset += 4;
      memcpy(outbuffer + offset, this->planUri, length_planUri);
      offset += length_planUri;
      uint32_t length_plan = strlen(this->plan);
      varToArr(outbuffer + offset, length_plan);
      offset += 4;
      memcpy(outbuffer + offset, this->plan, length_plan);
      offset += length_plan;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      *(outbuffer + offset + 0) = (this->newFiles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->newFiles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->newFiles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->newFiles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->newFiles_length);
      for( uint32_t i = 0; i < newFiles_length; i++){
      offset += this->newFiles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_planUri;
      arrToVar(length_planUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planUri-1]=0;
      this->planUri = (char *)(inbuffer + offset-1);
      offset += length_planUri;
      uint32_t length_plan;
      arrToVar(length_plan, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_plan; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_plan-1]=0;
      this->plan = (char *)(inbuffer + offset-1);
      offset += length_plan;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t newFiles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      newFiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      newFiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      newFiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->newFiles_length);
      if(newFiles_lengthT > newFiles_length)
        this->newFiles = (semantic_storage_interface_msgs::RosFile*)realloc(this->newFiles, newFiles_lengthT * sizeof(semantic_storage_interface_msgs::RosFile));
      newFiles_length = newFiles_lengthT;
      for( uint32_t i = 0; i < newFiles_length; i++){
      offset += this->st_newFiles.deserialize(inbuffer + offset);
        memcpy( &(this->newFiles[i]), &(this->st_newFiles), sizeof(semantic_storage_interface_msgs::RosFile));
      }
     return offset;
    }

    virtual const char * getType() override { return UPDATEPLAN; };
    virtual const char * getMD5() override { return "dc29283ef3221780206d5e0f2fb2dd84"; };

  };

  class UpdatePlanResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      uint32_t blobUris_length;
      typedef char* _blobUris_type;
      _blobUris_type st_blobUris;
      _blobUris_type * blobUris;

    UpdatePlanResponse():
      success(0),
      blobUris_length(0), st_blobUris(), blobUris(nullptr)
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
      *(outbuffer + offset + 0) = (this->blobUris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blobUris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->blobUris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->blobUris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blobUris_length);
      for( uint32_t i = 0; i < blobUris_length; i++){
      uint32_t length_blobUrisi = strlen(this->blobUris[i]);
      varToArr(outbuffer + offset, length_blobUrisi);
      offset += 4;
      memcpy(outbuffer + offset, this->blobUris[i], length_blobUrisi);
      offset += length_blobUrisi;
      }
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
      uint32_t blobUris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      blobUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      blobUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      blobUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->blobUris_length);
      if(blobUris_lengthT > blobUris_length)
        this->blobUris = (char**)realloc(this->blobUris, blobUris_lengthT * sizeof(char*));
      blobUris_length = blobUris_lengthT;
      for( uint32_t i = 0; i < blobUris_length; i++){
      uint32_t length_st_blobUris;
      arrToVar(length_st_blobUris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_blobUris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_blobUris-1]=0;
      this->st_blobUris = (char *)(inbuffer + offset-1);
      offset += length_st_blobUris;
        memcpy( &(this->blobUris[i]), &(this->st_blobUris), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return UPDATEPLAN; };
    virtual const char * getMD5() override { return "cbe3474979c28d357ac25483e092d5f7"; };

  };

  class UpdatePlan {
    public:
    typedef UpdatePlanRequest Request;
    typedef UpdatePlanResponse Response;
  };

}
#endif
