#ifndef _ROS_SERVICE_GetKb_h
#define _ROS_SERVICE_GetKb_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char GETKB[] = "semantic_storage_interface_srvs/GetKb";

  class GetKbRequest : public ros::Msg
  {
    public:
      typedef const char* _uri_type;
      _uri_type uri;

    GetKbRequest():
      uri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_uri = strlen(this->uri);
      varToArr(outbuffer + offset, length_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_uri;
      arrToVar(length_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
     return offset;
    }

    virtual const char * getType() override { return GETKB; };
    virtual const char * getMD5() override { return "636fe5e07550f026d28388e95c38a9f4"; };

  };

  class GetKbResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _owl_type;
      _owl_type owl;
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

    GetKbResponse():
      success(0),
      owl(""),
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
      uint32_t length_owl = strlen(this->owl);
      varToArr(outbuffer + offset, length_owl);
      offset += 4;
      memcpy(outbuffer + offset, this->owl, length_owl);
      offset += length_owl;
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
      uint32_t length_owl;
      arrToVar(length_owl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_owl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_owl-1]=0;
      this->owl = (char *)(inbuffer + offset-1);
      offset += length_owl;
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

    virtual const char * getType() override { return GETKB; };
    virtual const char * getMD5() override { return "091bd1a1c2a01cfce4096d3d48a7f846"; };

  };

  class GetKb {
    public:
    typedef GetKbRequest Request;
    typedef GetKbResponse Response;
  };

}
#endif
