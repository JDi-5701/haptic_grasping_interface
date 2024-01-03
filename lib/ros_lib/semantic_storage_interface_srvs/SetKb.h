#ifndef _ROS_SERVICE_SetKb_h
#define _ROS_SERVICE_SetKb_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_srvs
{

static const char SETKB[] = "semantic_storage_interface_srvs/SetKb";

  class SetKbRequest : public ros::Msg
  {
    public:
      typedef const char* _relativeUri_type;
      _relativeUri_type relativeUri;
      typedef const char* _owl_type;
      _owl_type owl;
      typedef const char* _description_type;
      _description_type description;
      uint32_t files_length;
      typedef semantic_storage_interface_msgs::RosFile _files_type;
      _files_type st_files;
      _files_type * files;

    SetKbRequest():
      relativeUri(""),
      owl(""),
      description(""),
      files_length(0), st_files(), files(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_relativeUri = strlen(this->relativeUri);
      varToArr(outbuffer + offset, length_relativeUri);
      offset += 4;
      memcpy(outbuffer + offset, this->relativeUri, length_relativeUri);
      offset += length_relativeUri;
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
      *(outbuffer + offset + 0) = (this->files_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->files_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->files_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->files_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->files_length);
      for( uint32_t i = 0; i < files_length; i++){
      offset += this->files[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_relativeUri;
      arrToVar(length_relativeUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_relativeUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_relativeUri-1]=0;
      this->relativeUri = (char *)(inbuffer + offset-1);
      offset += length_relativeUri;
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
      uint32_t files_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      files_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      files_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      files_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->files_length);
      if(files_lengthT > files_length)
        this->files = (semantic_storage_interface_msgs::RosFile*)realloc(this->files, files_lengthT * sizeof(semantic_storage_interface_msgs::RosFile));
      files_length = files_lengthT;
      for( uint32_t i = 0; i < files_length; i++){
      offset += this->st_files.deserialize(inbuffer + offset);
        memcpy( &(this->files[i]), &(this->st_files), sizeof(semantic_storage_interface_msgs::RosFile));
      }
     return offset;
    }

    virtual const char * getType() override { return SETKB; };
    virtual const char * getMD5() override { return "7894d3caa9fc5d830288d203c02fb723"; };

  };

  class SetKbResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _contextUri_type;
      _contextUri_type contextUri;
      uint32_t blobUris_length;
      typedef char* _blobUris_type;
      _blobUris_type st_blobUris;
      _blobUris_type * blobUris;

    SetKbResponse():
      success(0),
      contextUri(""),
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
      uint32_t length_contextUri = strlen(this->contextUri);
      varToArr(outbuffer + offset, length_contextUri);
      offset += 4;
      memcpy(outbuffer + offset, this->contextUri, length_contextUri);
      offset += length_contextUri;
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
      uint32_t length_contextUri;
      arrToVar(length_contextUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_contextUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_contextUri-1]=0;
      this->contextUri = (char *)(inbuffer + offset-1);
      offset += length_contextUri;
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

    virtual const char * getType() override { return SETKB; };
    virtual const char * getMD5() override { return "901e7c72476be4ef9b2d9fbc8c564d2e"; };

  };

  class SetKb {
    public:
    typedef SetKbRequest Request;
    typedef SetKbResponse Response;
  };

}
#endif
