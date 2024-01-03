#ifndef _ROS_process_msgs_PhysicalEntity_h
#define _ROS_process_msgs_PhysicalEntity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Class.h"

namespace process_msgs
{

  class PhysicalEntity : public ros::Msg
  {
    public:
      typedef process_msgs::Class _type_type;
      _type_type type;
      typedef process_msgs::Class _category_type;
      _category_type category;
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _shapeIri_type;
      _shapeIri_type shapeIri;
      typedef const char* _modelUrl_type;
      _modelUrl_type modelUrl;
      typedef const char* _sourceUrl_type;
      _sourceUrl_type sourceUrl;

    PhysicalEntity():
      type(),
      category(),
      iri(""),
      name(""),
      description(""),
      shapeIri(""),
      modelUrl(""),
      sourceUrl("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->type.serialize(outbuffer + offset);
      offset += this->category.serialize(outbuffer + offset);
      uint32_t length_iri = strlen(this->iri);
      varToArr(outbuffer + offset, length_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->iri, length_iri);
      offset += length_iri;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_shapeIri = strlen(this->shapeIri);
      varToArr(outbuffer + offset, length_shapeIri);
      offset += 4;
      memcpy(outbuffer + offset, this->shapeIri, length_shapeIri);
      offset += length_shapeIri;
      uint32_t length_modelUrl = strlen(this->modelUrl);
      varToArr(outbuffer + offset, length_modelUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->modelUrl, length_modelUrl);
      offset += length_modelUrl;
      uint32_t length_sourceUrl = strlen(this->sourceUrl);
      varToArr(outbuffer + offset, length_sourceUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->sourceUrl, length_sourceUrl);
      offset += length_sourceUrl;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->type.deserialize(inbuffer + offset);
      offset += this->category.deserialize(inbuffer + offset);
      uint32_t length_iri;
      arrToVar(length_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_iri-1]=0;
      this->iri = (char *)(inbuffer + offset-1);
      offset += length_iri;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_shapeIri;
      arrToVar(length_shapeIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_shapeIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_shapeIri-1]=0;
      this->shapeIri = (char *)(inbuffer + offset-1);
      offset += length_shapeIri;
      uint32_t length_modelUrl;
      arrToVar(length_modelUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modelUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modelUrl-1]=0;
      this->modelUrl = (char *)(inbuffer + offset-1);
      offset += length_modelUrl;
      uint32_t length_sourceUrl;
      arrToVar(length_sourceUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sourceUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sourceUrl-1]=0;
      this->sourceUrl = (char *)(inbuffer + offset-1);
      offset += length_sourceUrl;
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/PhysicalEntity"; };
    virtual const char * getMD5() override { return "661024a9e6e1908841b763433e4b51dd"; };

  };

}
#endif
