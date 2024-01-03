#ifndef _ROS_SERVICE_PhysicalEntityListTypesFromCategoryIri_h
#define _ROS_SERVICE_PhysicalEntityListTypesFromCategoryIri_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/PhysicalEntity.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYLISTTYPESFROMCATEGORYIRI[] = "process_srvs/PhysicalEntityListTypesFromCategoryIri";

  class PhysicalEntityListTypesFromCategoryIriRequest : public ros::Msg
  {
    public:
      typedef const char* _categoryIri_type;
      _categoryIri_type categoryIri;

    PhysicalEntityListTypesFromCategoryIriRequest():
      categoryIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_categoryIri = strlen(this->categoryIri);
      varToArr(outbuffer + offset, length_categoryIri);
      offset += 4;
      memcpy(outbuffer + offset, this->categoryIri, length_categoryIri);
      offset += length_categoryIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_categoryIri;
      arrToVar(length_categoryIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_categoryIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_categoryIri-1]=0;
      this->categoryIri = (char *)(inbuffer + offset-1);
      offset += length_categoryIri;
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYLISTTYPESFROMCATEGORYIRI; };
    virtual const char * getMD5() override { return "2b1289ac98e5e896b2de9c95bca1f833"; };

  };

  class PhysicalEntityListTypesFromCategoryIriResponse : public ros::Msg
  {
    public:
      uint32_t physicalEntityTypes_length;
      typedef process_msgs::PhysicalEntity _physicalEntityTypes_type;
      _physicalEntityTypes_type st_physicalEntityTypes;
      _physicalEntityTypes_type * physicalEntityTypes;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityListTypesFromCategoryIriResponse():
      physicalEntityTypes_length(0), st_physicalEntityTypes(), physicalEntityTypes(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->physicalEntityTypes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->physicalEntityTypes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->physicalEntityTypes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->physicalEntityTypes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->physicalEntityTypes_length);
      for( uint32_t i = 0; i < physicalEntityTypes_length; i++){
      offset += this->physicalEntityTypes[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t physicalEntityTypes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      physicalEntityTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      physicalEntityTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      physicalEntityTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->physicalEntityTypes_length);
      if(physicalEntityTypes_lengthT > physicalEntityTypes_length)
        this->physicalEntityTypes = (process_msgs::PhysicalEntity*)realloc(this->physicalEntityTypes, physicalEntityTypes_lengthT * sizeof(process_msgs::PhysicalEntity));
      physicalEntityTypes_length = physicalEntityTypes_lengthT;
      for( uint32_t i = 0; i < physicalEntityTypes_length; i++){
      offset += this->st_physicalEntityTypes.deserialize(inbuffer + offset);
        memcpy( &(this->physicalEntityTypes[i]), &(this->st_physicalEntityTypes), sizeof(process_msgs::PhysicalEntity));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYLISTTYPESFROMCATEGORYIRI; };
    virtual const char * getMD5() override { return "2b34a622e7e3d3c72ab3fa0d31ec13e3"; };

  };

  class PhysicalEntityListTypesFromCategoryIri {
    public:
    typedef PhysicalEntityListTypesFromCategoryIriRequest Request;
    typedef PhysicalEntityListTypesFromCategoryIriResponse Response;
  };

}
#endif
