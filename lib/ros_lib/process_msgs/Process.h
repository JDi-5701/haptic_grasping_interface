#ifndef _ROS_process_msgs_Process_h
#define _ROS_process_msgs_Process_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Class.h"

namespace process_msgs
{

  class Process : public ros::Msg
  {
    public:
      typedef process_msgs::Class _type_type;
      _type_type type;
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _imageUrl_type;
      _imageUrl_type imageUrl;
      typedef int32_t _status_type;
      _status_type status;
      uint32_t subtasksIri_length;
      typedef char* _subtasksIri_type;
      _subtasksIri_type st_subtasksIri;
      _subtasksIri_type * subtasksIri;
      typedef const char* _currentSubtaskIri_type;
      _currentSubtaskIri_type currentSubtaskIri;
      typedef const char* _workcellIri_type;
      _workcellIri_type workcellIri;

    Process():
      type(),
      iri(""),
      name(""),
      description(""),
      imageUrl(""),
      status(0),
      subtasksIri_length(0), st_subtasksIri(), subtasksIri(nullptr),
      currentSubtaskIri(""),
      workcellIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->type.serialize(outbuffer + offset);
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
      uint32_t length_imageUrl = strlen(this->imageUrl);
      varToArr(outbuffer + offset, length_imageUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->imageUrl, length_imageUrl);
      offset += length_imageUrl;
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->subtasksIri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subtasksIri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subtasksIri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subtasksIri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subtasksIri_length);
      for( uint32_t i = 0; i < subtasksIri_length; i++){
      uint32_t length_subtasksIrii = strlen(this->subtasksIri[i]);
      varToArr(outbuffer + offset, length_subtasksIrii);
      offset += 4;
      memcpy(outbuffer + offset, this->subtasksIri[i], length_subtasksIrii);
      offset += length_subtasksIrii;
      }
      uint32_t length_currentSubtaskIri = strlen(this->currentSubtaskIri);
      varToArr(outbuffer + offset, length_currentSubtaskIri);
      offset += 4;
      memcpy(outbuffer + offset, this->currentSubtaskIri, length_currentSubtaskIri);
      offset += length_currentSubtaskIri;
      uint32_t length_workcellIri = strlen(this->workcellIri);
      varToArr(outbuffer + offset, length_workcellIri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellIri, length_workcellIri);
      offset += length_workcellIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->type.deserialize(inbuffer + offset);
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
      uint32_t length_imageUrl;
      arrToVar(length_imageUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imageUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imageUrl-1]=0;
      this->imageUrl = (char *)(inbuffer + offset-1);
      offset += length_imageUrl;
      union {
        int32_t real;
        uint32_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->status = u_status.real;
      offset += sizeof(this->status);
      uint32_t subtasksIri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subtasksIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subtasksIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subtasksIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subtasksIri_length);
      if(subtasksIri_lengthT > subtasksIri_length)
        this->subtasksIri = (char**)realloc(this->subtasksIri, subtasksIri_lengthT * sizeof(char*));
      subtasksIri_length = subtasksIri_lengthT;
      for( uint32_t i = 0; i < subtasksIri_length; i++){
      uint32_t length_st_subtasksIri;
      arrToVar(length_st_subtasksIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_subtasksIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_subtasksIri-1]=0;
      this->st_subtasksIri = (char *)(inbuffer + offset-1);
      offset += length_st_subtasksIri;
        memcpy( &(this->subtasksIri[i]), &(this->st_subtasksIri), sizeof(char*));
      }
      uint32_t length_currentSubtaskIri;
      arrToVar(length_currentSubtaskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_currentSubtaskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_currentSubtaskIri-1]=0;
      this->currentSubtaskIri = (char *)(inbuffer + offset-1);
      offset += length_currentSubtaskIri;
      uint32_t length_workcellIri;
      arrToVar(length_workcellIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellIri-1]=0;
      this->workcellIri = (char *)(inbuffer + offset-1);
      offset += length_workcellIri;
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/Process"; };
    virtual const char * getMD5() override { return "22edbea3f1bbebf7d40f1f33953c6176"; };

  };

}
#endif
