#ifndef _ROS_SERVICE_GetPlan_h
#define _ROS_SERVICE_GetPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char GETPLAN[] = "semantic_storage_interface_srvs/GetPlan";

  class GetPlanRequest : public ros::Msg
  {
    public:
      typedef const char* _planUri_type;
      _planUri_type planUri;

    GetPlanRequest():
      planUri("")
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
     return offset;
    }

    virtual const char * getType() override { return GETPLAN; };
    virtual const char * getMD5() override { return "a45807d86d65c1b42b2214d30b874a55"; };

  };

  class GetPlanResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _plan_type;
      _plan_type plan;
      typedef const char* _description_type;
      _description_type description;
      uint32_t fileNames_length;
      typedef char* _fileNames_type;
      _fileNames_type st_fileNames;
      _fileNames_type * fileNames;
      uint32_t fileUris_length;
      typedef char* _fileUris_type;
      _fileUris_type st_fileUris;
      _fileUris_type * fileUris;

    GetPlanResponse():
      success(0),
      plan(""),
      description(""),
      fileNames_length(0), st_fileNames(), fileNames(nullptr),
      fileUris_length(0), st_fileUris(), fileUris(nullptr)
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
      *(outbuffer + offset + 0) = (this->fileNames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fileNames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fileNames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fileNames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fileNames_length);
      for( uint32_t i = 0; i < fileNames_length; i++){
      uint32_t length_fileNamesi = strlen(this->fileNames[i]);
      varToArr(outbuffer + offset, length_fileNamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fileNames[i], length_fileNamesi);
      offset += length_fileNamesi;
      }
      *(outbuffer + offset + 0) = (this->fileUris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fileUris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fileUris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fileUris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fileUris_length);
      for( uint32_t i = 0; i < fileUris_length; i++){
      uint32_t length_fileUrisi = strlen(this->fileUris[i]);
      varToArr(outbuffer + offset, length_fileUrisi);
      offset += 4;
      memcpy(outbuffer + offset, this->fileUris[i], length_fileUrisi);
      offset += length_fileUrisi;
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
      uint32_t fileNames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fileNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fileNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fileNames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fileNames_length);
      if(fileNames_lengthT > fileNames_length)
        this->fileNames = (char**)realloc(this->fileNames, fileNames_lengthT * sizeof(char*));
      fileNames_length = fileNames_lengthT;
      for( uint32_t i = 0; i < fileNames_length; i++){
      uint32_t length_st_fileNames;
      arrToVar(length_st_fileNames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fileNames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fileNames-1]=0;
      this->st_fileNames = (char *)(inbuffer + offset-1);
      offset += length_st_fileNames;
        memcpy( &(this->fileNames[i]), &(this->st_fileNames), sizeof(char*));
      }
      uint32_t fileUris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fileUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fileUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fileUris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fileUris_length);
      if(fileUris_lengthT > fileUris_length)
        this->fileUris = (char**)realloc(this->fileUris, fileUris_lengthT * sizeof(char*));
      fileUris_length = fileUris_lengthT;
      for( uint32_t i = 0; i < fileUris_length; i++){
      uint32_t length_st_fileUris;
      arrToVar(length_st_fileUris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fileUris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fileUris-1]=0;
      this->st_fileUris = (char *)(inbuffer + offset-1);
      offset += length_st_fileUris;
        memcpy( &(this->fileUris[i]), &(this->st_fileUris), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return GETPLAN; };
    virtual const char * getMD5() override { return "d2f4788312810748597cb3697d3524c2"; };

  };

  class GetPlan {
    public:
    typedef GetPlanRequest Request;
    typedef GetPlanResponse Response;
  };

}
#endif
