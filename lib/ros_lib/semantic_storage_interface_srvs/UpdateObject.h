#ifndef _ROS_SERVICE_UpdateObject_h
#define _ROS_SERVICE_UpdateObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_srvs
{

static const char UPDATEOBJECT[] = "semantic_storage_interface_srvs/UpdateObject";

  class UpdateObjectRequest : public ros::Msg
  {
    public:
      typedef const char* _objectUri_type;
      _objectUri_type objectUri;
      typedef const char* _object_type;
      _object_type object;
      typedef const char* _description_type;
      _description_type description;
      uint32_t newFiles_length;
      typedef semantic_storage_interface_msgs::RosFile _newFiles_type;
      _newFiles_type st_newFiles;
      _newFiles_type * newFiles;

    UpdateObjectRequest():
      objectUri(""),
      object(""),
      description(""),
      newFiles_length(0), st_newFiles(), newFiles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_objectUri = strlen(this->objectUri);
      varToArr(outbuffer + offset, length_objectUri);
      offset += 4;
      memcpy(outbuffer + offset, this->objectUri, length_objectUri);
      offset += length_objectUri;
      uint32_t length_object = strlen(this->object);
      varToArr(outbuffer + offset, length_object);
      offset += 4;
      memcpy(outbuffer + offset, this->object, length_object);
      offset += length_object;
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
      uint32_t length_objectUri;
      arrToVar(length_objectUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectUri-1]=0;
      this->objectUri = (char *)(inbuffer + offset-1);
      offset += length_objectUri;
      uint32_t length_object;
      arrToVar(length_object, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object-1]=0;
      this->object = (char *)(inbuffer + offset-1);
      offset += length_object;
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

    virtual const char * getType() override { return UPDATEOBJECT; };
    virtual const char * getMD5() override { return "846e65fb312d13c83098479bbdbb672f"; };

  };

  class UpdateObjectResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      uint32_t blobUris_length;
      typedef char* _blobUris_type;
      _blobUris_type st_blobUris;
      _blobUris_type * blobUris;

    UpdateObjectResponse():
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

    virtual const char * getType() override { return UPDATEOBJECT; };
    virtual const char * getMD5() override { return "cbe3474979c28d357ac25483e092d5f7"; };

  };

  class UpdateObject {
    public:
    typedef UpdateObjectRequest Request;
    typedef UpdateObjectResponse Response;
  };

}
#endif
