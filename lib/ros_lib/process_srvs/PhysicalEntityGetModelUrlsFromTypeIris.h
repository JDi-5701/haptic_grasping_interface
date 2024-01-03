#ifndef _ROS_SERVICE_PhysicalEntityGetModelUrlsFromTypeIris_h
#define _ROS_SERVICE_PhysicalEntityGetModelUrlsFromTypeIris_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYGETMODELURLSFROMTYPEIRIS[] = "process_srvs/PhysicalEntityGetModelUrlsFromTypeIris";

  class PhysicalEntityGetModelUrlsFromTypeIrisRequest : public ros::Msg
  {
    public:
      uint32_t typeIris_length;
      typedef char* _typeIris_type;
      _typeIris_type st_typeIris;
      _typeIris_type * typeIris;

    PhysicalEntityGetModelUrlsFromTypeIrisRequest():
      typeIris_length(0), st_typeIris(), typeIris(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->typeIris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->typeIris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->typeIris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->typeIris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->typeIris_length);
      for( uint32_t i = 0; i < typeIris_length; i++){
      uint32_t length_typeIrisi = strlen(this->typeIris[i]);
      varToArr(outbuffer + offset, length_typeIrisi);
      offset += 4;
      memcpy(outbuffer + offset, this->typeIris[i], length_typeIrisi);
      offset += length_typeIrisi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t typeIris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      typeIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      typeIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      typeIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->typeIris_length);
      if(typeIris_lengthT > typeIris_length)
        this->typeIris = (char**)realloc(this->typeIris, typeIris_lengthT * sizeof(char*));
      typeIris_length = typeIris_lengthT;
      for( uint32_t i = 0; i < typeIris_length; i++){
      uint32_t length_st_typeIris;
      arrToVar(length_st_typeIris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_typeIris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_typeIris-1]=0;
      this->st_typeIris = (char *)(inbuffer + offset-1);
      offset += length_st_typeIris;
        memcpy( &(this->typeIris[i]), &(this->st_typeIris), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYGETMODELURLSFROMTYPEIRIS; };
    virtual const char * getMD5() override { return "fafea3771c8e19b9e4bd9c3bcbb45e0a"; };

  };

  class PhysicalEntityGetModelUrlsFromTypeIrisResponse : public ros::Msg
  {
    public:
      uint32_t modelUrls_length;
      typedef char* _modelUrls_type;
      _modelUrls_type st_modelUrls;
      _modelUrls_type * modelUrls;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityGetModelUrlsFromTypeIrisResponse():
      modelUrls_length(0), st_modelUrls(), modelUrls(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->modelUrls_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modelUrls_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modelUrls_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modelUrls_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modelUrls_length);
      for( uint32_t i = 0; i < modelUrls_length; i++){
      uint32_t length_modelUrlsi = strlen(this->modelUrls[i]);
      varToArr(outbuffer + offset, length_modelUrlsi);
      offset += 4;
      memcpy(outbuffer + offset, this->modelUrls[i], length_modelUrlsi);
      offset += length_modelUrlsi;
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t modelUrls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      modelUrls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      modelUrls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      modelUrls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->modelUrls_length);
      if(modelUrls_lengthT > modelUrls_length)
        this->modelUrls = (char**)realloc(this->modelUrls, modelUrls_lengthT * sizeof(char*));
      modelUrls_length = modelUrls_lengthT;
      for( uint32_t i = 0; i < modelUrls_length; i++){
      uint32_t length_st_modelUrls;
      arrToVar(length_st_modelUrls, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_modelUrls; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_modelUrls-1]=0;
      this->st_modelUrls = (char *)(inbuffer + offset-1);
      offset += length_st_modelUrls;
        memcpy( &(this->modelUrls[i]), &(this->st_modelUrls), sizeof(char*));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYGETMODELURLSFROMTYPEIRIS; };
    virtual const char * getMD5() override { return "8b325ef04cdb91c23b99d2d87b63aed9"; };

  };

  class PhysicalEntityGetModelUrlsFromTypeIris {
    public:
    typedef PhysicalEntityGetModelUrlsFromTypeIrisRequest Request;
    typedef PhysicalEntityGetModelUrlsFromTypeIrisResponse Response;
  };

}
#endif
