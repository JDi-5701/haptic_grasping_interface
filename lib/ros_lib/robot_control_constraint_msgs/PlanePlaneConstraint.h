#ifndef _ROS_robot_control_constraint_msgs_PlanePlaneConstraint_h
#define _ROS_robot_control_constraint_msgs_PlanePlaneConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_control_constraint_msgs/Plane.h"

namespace robot_control_constraint_msgs
{

  class PlanePlaneConstraint : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef robot_control_constraint_msgs::Plane _fixed_type;
      _fixed_type fixed;
      typedef robot_control_constraint_msgs::Plane _constrained_type;
      _constrained_type constrained;
      typedef int32_t _type_type;
      _type_type type;
      typedef bool _flip_type;
      _flip_type flip;
      uint32_t parameter_length;
      typedef float _parameter_type;
      _parameter_type st_parameter;
      _parameter_type * parameter;
      typedef bool _converged_type;
      _converged_type converged;
      typedef int32_t _fixedPoseIndex_type;
      _fixedPoseIndex_type fixedPoseIndex;
      typedef int32_t _constrainedPoseIndex_type;
      _constrainedPoseIndex_type constrainedPoseIndex;

    PlanePlaneConstraint():
      id(""),
      fixed(),
      constrained(),
      type(0),
      flip(0),
      parameter_length(0), st_parameter(), parameter(nullptr),
      converged(0),
      fixedPoseIndex(0),
      constrainedPoseIndex(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->fixed.serialize(outbuffer + offset);
      offset += this->constrained.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        bool real;
        uint8_t base;
      } u_flip;
      u_flip.real = this->flip;
      *(outbuffer + offset + 0) = (u_flip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flip);
      *(outbuffer + offset + 0) = (this->parameter_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameter_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameter_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameter_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameter_length);
      for( uint32_t i = 0; i < parameter_length; i++){
      union {
        float real;
        uint32_t base;
      } u_parameteri;
      u_parameteri.real = this->parameter[i];
      *(outbuffer + offset + 0) = (u_parameteri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_parameteri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_parameteri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_parameteri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameter[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_converged;
      u_converged.real = this->converged;
      *(outbuffer + offset + 0) = (u_converged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->converged);
      union {
        int32_t real;
        uint32_t base;
      } u_fixedPoseIndex;
      u_fixedPoseIndex.real = this->fixedPoseIndex;
      *(outbuffer + offset + 0) = (u_fixedPoseIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fixedPoseIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fixedPoseIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fixedPoseIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixedPoseIndex);
      union {
        int32_t real;
        uint32_t base;
      } u_constrainedPoseIndex;
      u_constrainedPoseIndex.real = this->constrainedPoseIndex;
      *(outbuffer + offset + 0) = (u_constrainedPoseIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_constrainedPoseIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_constrainedPoseIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_constrainedPoseIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->constrainedPoseIndex);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->fixed.deserialize(inbuffer + offset);
      offset += this->constrained.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        bool real;
        uint8_t base;
      } u_flip;
      u_flip.base = 0;
      u_flip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flip = u_flip.real;
      offset += sizeof(this->flip);
      uint32_t parameter_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameter_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameter_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameter_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameter_length);
      if(parameter_lengthT > parameter_length)
        this->parameter = (float*)realloc(this->parameter, parameter_lengthT * sizeof(float));
      parameter_length = parameter_lengthT;
      for( uint32_t i = 0; i < parameter_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_parameter;
      u_st_parameter.base = 0;
      u_st_parameter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_parameter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_parameter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_parameter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_parameter = u_st_parameter.real;
      offset += sizeof(this->st_parameter);
        memcpy( &(this->parameter[i]), &(this->st_parameter), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_converged;
      u_converged.base = 0;
      u_converged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->converged = u_converged.real;
      offset += sizeof(this->converged);
      union {
        int32_t real;
        uint32_t base;
      } u_fixedPoseIndex;
      u_fixedPoseIndex.base = 0;
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fixedPoseIndex = u_fixedPoseIndex.real;
      offset += sizeof(this->fixedPoseIndex);
      union {
        int32_t real;
        uint32_t base;
      } u_constrainedPoseIndex;
      u_constrainedPoseIndex.base = 0;
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->constrainedPoseIndex = u_constrainedPoseIndex.real;
      offset += sizeof(this->constrainedPoseIndex);
     return offset;
    }

    virtual const char * getType() override { return "robot_control_constraint_msgs/PlanePlaneConstraint"; };
    virtual const char * getMD5() override { return "7ded3e05ba0d942c270f65655ea56c85"; };

  };

}
#endif
