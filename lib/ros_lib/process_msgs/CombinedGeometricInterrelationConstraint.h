#ifndef _ROS_process_msgs_CombinedGeometricInterrelationConstraint_h
#define _ROS_process_msgs_CombinedGeometricInterrelationConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Class.h"
#include "robot_control_constraint_msgs/Constraints.h"
#include "geometry_msgs/Pose.h"

namespace process_msgs
{

  class CombinedGeometricInterrelationConstraint : public ros::Msg
  {
    public:
      typedef process_msgs::Class _type_type;
      _type_type type;
      typedef const char* _iri_type;
      _iri_type iri;
      typedef robot_control_constraint_msgs::Constraints _constraints_type;
      _constraints_type constraints;
      typedef bool _satisfied_type;
      _satisfied_type satisfied;
      uint32_t physicalEntityIris_length;
      typedef char* _physicalEntityIris_type;
      _physicalEntityIris_type st_physicalEntityIris;
      _physicalEntityIris_type * physicalEntityIris;
      uint32_t currentPoses_length;
      typedef geometry_msgs::Pose _currentPoses_type;
      _currentPoses_type st_currentPoses;
      _currentPoses_type * currentPoses;
      typedef const char* _imageUrl_type;
      _imageUrl_type imageUrl;

    CombinedGeometricInterrelationConstraint():
      type(),
      iri(""),
      constraints(),
      satisfied(0),
      physicalEntityIris_length(0), st_physicalEntityIris(), physicalEntityIris(nullptr),
      currentPoses_length(0), st_currentPoses(), currentPoses(nullptr),
      imageUrl("")
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
      offset += this->constraints.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_satisfied;
      u_satisfied.real = this->satisfied;
      *(outbuffer + offset + 0) = (u_satisfied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->satisfied);
      *(outbuffer + offset + 0) = (this->physicalEntityIris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->physicalEntityIris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->physicalEntityIris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->physicalEntityIris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->physicalEntityIris_length);
      for( uint32_t i = 0; i < physicalEntityIris_length; i++){
      uint32_t length_physicalEntityIrisi = strlen(this->physicalEntityIris[i]);
      varToArr(outbuffer + offset, length_physicalEntityIrisi);
      offset += 4;
      memcpy(outbuffer + offset, this->physicalEntityIris[i], length_physicalEntityIrisi);
      offset += length_physicalEntityIrisi;
      }
      *(outbuffer + offset + 0) = (this->currentPoses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->currentPoses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->currentPoses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->currentPoses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentPoses_length);
      for( uint32_t i = 0; i < currentPoses_length; i++){
      offset += this->currentPoses[i].serialize(outbuffer + offset);
      }
      uint32_t length_imageUrl = strlen(this->imageUrl);
      varToArr(outbuffer + offset, length_imageUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->imageUrl, length_imageUrl);
      offset += length_imageUrl;
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
      offset += this->constraints.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_satisfied;
      u_satisfied.base = 0;
      u_satisfied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->satisfied = u_satisfied.real;
      offset += sizeof(this->satisfied);
      uint32_t physicalEntityIris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      physicalEntityIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      physicalEntityIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      physicalEntityIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->physicalEntityIris_length);
      if(physicalEntityIris_lengthT > physicalEntityIris_length)
        this->physicalEntityIris = (char**)realloc(this->physicalEntityIris, physicalEntityIris_lengthT * sizeof(char*));
      physicalEntityIris_length = physicalEntityIris_lengthT;
      for( uint32_t i = 0; i < physicalEntityIris_length; i++){
      uint32_t length_st_physicalEntityIris;
      arrToVar(length_st_physicalEntityIris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_physicalEntityIris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_physicalEntityIris-1]=0;
      this->st_physicalEntityIris = (char *)(inbuffer + offset-1);
      offset += length_st_physicalEntityIris;
        memcpy( &(this->physicalEntityIris[i]), &(this->st_physicalEntityIris), sizeof(char*));
      }
      uint32_t currentPoses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      currentPoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      currentPoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      currentPoses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->currentPoses_length);
      if(currentPoses_lengthT > currentPoses_length)
        this->currentPoses = (geometry_msgs::Pose*)realloc(this->currentPoses, currentPoses_lengthT * sizeof(geometry_msgs::Pose));
      currentPoses_length = currentPoses_lengthT;
      for( uint32_t i = 0; i < currentPoses_length; i++){
      offset += this->st_currentPoses.deserialize(inbuffer + offset);
        memcpy( &(this->currentPoses[i]), &(this->st_currentPoses), sizeof(geometry_msgs::Pose));
      }
      uint32_t length_imageUrl;
      arrToVar(length_imageUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imageUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imageUrl-1]=0;
      this->imageUrl = (char *)(inbuffer + offset-1);
      offset += length_imageUrl;
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/CombinedGeometricInterrelationConstraint"; };
    virtual const char * getMD5() override { return "112e0c04d3c771959df1a65ebb638d55"; };

  };

}
#endif
