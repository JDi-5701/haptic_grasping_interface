#ifndef _ROS_process_msgs_Parameter_h
#define _ROS_process_msgs_Parameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Value.h"

namespace process_msgs
{

  class Parameter : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      uint32_t range_length;
      typedef char* _range_type;
      _range_type st_range;
      _range_type * range;
      typedef process_msgs::Value _value_type;
      _value_type value;
      typedef bool _isOptional_type;
      _isOptional_type isOptional;
      typedef int32_t _hiddenLevel_type;
      _hiddenLevel_type hiddenLevel;
      typedef const char* _quantityName_type;
      _quantityName_type quantityName;
      typedef const char* _quantitySymbol_type;
      _quantitySymbol_type quantitySymbol;
      typedef const char* _unitName_type;
      _unitName_type unitName;
      typedef const char* _unitSymbol_type;
      _unitSymbol_type unitSymbol;

    Parameter():
      iri(""),
      name(""),
      description(""),
      range_length(0), st_range(), range(nullptr),
      value(),
      isOptional(0),
      hiddenLevel(0),
      quantityName(""),
      quantitySymbol(""),
      unitName(""),
      unitSymbol("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      *(outbuffer + offset + 0) = (this->range_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->range_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->range_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->range_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_length);
      for( uint32_t i = 0; i < range_length; i++){
      uint32_t length_rangei = strlen(this->range[i]);
      varToArr(outbuffer + offset, length_rangei);
      offset += 4;
      memcpy(outbuffer + offset, this->range[i], length_rangei);
      offset += length_rangei;
      }
      offset += this->value.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isOptional;
      u_isOptional.real = this->isOptional;
      *(outbuffer + offset + 0) = (u_isOptional.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isOptional);
      union {
        int32_t real;
        uint32_t base;
      } u_hiddenLevel;
      u_hiddenLevel.real = this->hiddenLevel;
      *(outbuffer + offset + 0) = (u_hiddenLevel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hiddenLevel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hiddenLevel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hiddenLevel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hiddenLevel);
      uint32_t length_quantityName = strlen(this->quantityName);
      varToArr(outbuffer + offset, length_quantityName);
      offset += 4;
      memcpy(outbuffer + offset, this->quantityName, length_quantityName);
      offset += length_quantityName;
      uint32_t length_quantitySymbol = strlen(this->quantitySymbol);
      varToArr(outbuffer + offset, length_quantitySymbol);
      offset += 4;
      memcpy(outbuffer + offset, this->quantitySymbol, length_quantitySymbol);
      offset += length_quantitySymbol;
      uint32_t length_unitName = strlen(this->unitName);
      varToArr(outbuffer + offset, length_unitName);
      offset += 4;
      memcpy(outbuffer + offset, this->unitName, length_unitName);
      offset += length_unitName;
      uint32_t length_unitSymbol = strlen(this->unitSymbol);
      varToArr(outbuffer + offset, length_unitSymbol);
      offset += 4;
      memcpy(outbuffer + offset, this->unitSymbol, length_unitSymbol);
      offset += length_unitSymbol;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      uint32_t range_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      range_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->range_length);
      if(range_lengthT > range_length)
        this->range = (char**)realloc(this->range, range_lengthT * sizeof(char*));
      range_length = range_lengthT;
      for( uint32_t i = 0; i < range_length; i++){
      uint32_t length_st_range;
      arrToVar(length_st_range, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_range; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_range-1]=0;
      this->st_range = (char *)(inbuffer + offset-1);
      offset += length_st_range;
        memcpy( &(this->range[i]), &(this->st_range), sizeof(char*));
      }
      offset += this->value.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_isOptional;
      u_isOptional.base = 0;
      u_isOptional.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isOptional = u_isOptional.real;
      offset += sizeof(this->isOptional);
      union {
        int32_t real;
        uint32_t base;
      } u_hiddenLevel;
      u_hiddenLevel.base = 0;
      u_hiddenLevel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hiddenLevel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hiddenLevel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hiddenLevel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hiddenLevel = u_hiddenLevel.real;
      offset += sizeof(this->hiddenLevel);
      uint32_t length_quantityName;
      arrToVar(length_quantityName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_quantityName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_quantityName-1]=0;
      this->quantityName = (char *)(inbuffer + offset-1);
      offset += length_quantityName;
      uint32_t length_quantitySymbol;
      arrToVar(length_quantitySymbol, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_quantitySymbol; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_quantitySymbol-1]=0;
      this->quantitySymbol = (char *)(inbuffer + offset-1);
      offset += length_quantitySymbol;
      uint32_t length_unitName;
      arrToVar(length_unitName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_unitName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_unitName-1]=0;
      this->unitName = (char *)(inbuffer + offset-1);
      offset += length_unitName;
      uint32_t length_unitSymbol;
      arrToVar(length_unitSymbol, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_unitSymbol; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_unitSymbol-1]=0;
      this->unitSymbol = (char *)(inbuffer + offset-1);
      offset += length_unitSymbol;
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/Parameter"; };
    virtual const char * getMD5() override { return "750f88947e5b0f5b36493f1369c9ba94"; };

  };

}
#endif
