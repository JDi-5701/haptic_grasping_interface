#ifndef _ROS_robot_movement_interface_Command_h
#define _ROS_robot_movement_interface_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace robot_movement_interface
{

  class Command : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _command_id_type;
      _command_id_type command_id;
      typedef const char* _command_type_type;
      _command_type_type command_type;
      typedef const char* _pose_reference_type;
      _pose_reference_type pose_reference;
      typedef const char* _pose_type_type;
      _pose_type_type pose_type;
      uint32_t pose_length;
      typedef float _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      typedef const char* _velocity_type_type;
      _velocity_type_type velocity_type;
      uint32_t velocity_length;
      typedef float _velocity_type;
      _velocity_type st_velocity;
      _velocity_type * velocity;
      typedef const char* _acceleration_type_type;
      _acceleration_type_type acceleration_type;
      uint32_t acceleration_length;
      typedef float _acceleration_type;
      _acceleration_type st_acceleration;
      _acceleration_type * acceleration;
      typedef const char* _force_threshold_type_type;
      _force_threshold_type_type force_threshold_type;
      uint32_t force_threshold_length;
      typedef float _force_threshold_type;
      _force_threshold_type st_force_threshold;
      _force_threshold_type * force_threshold;
      typedef const char* _effort_type_type;
      _effort_type_type effort_type;
      uint32_t effort_length;
      typedef float _effort_type;
      _effort_type st_effort;
      _effort_type * effort;
      typedef const char* _blending_type_type;
      _blending_type_type blending_type;
      uint32_t blending_length;
      typedef float _blending_type;
      _blending_type st_blending;
      _blending_type * blending;
      uint32_t additional_parameters_length;
      typedef char* _additional_parameters_type;
      _additional_parameters_type st_additional_parameters;
      _additional_parameters_type * additional_parameters;
      uint32_t additional_values_length;
      typedef float _additional_values_type;
      _additional_values_type st_additional_values;
      _additional_values_type * additional_values;

    Command():
      header(),
      command_id(0),
      command_type(""),
      pose_reference(""),
      pose_type(""),
      pose_length(0), st_pose(), pose(nullptr),
      velocity_type(""),
      velocity_length(0), st_velocity(), velocity(nullptr),
      acceleration_type(""),
      acceleration_length(0), st_acceleration(), acceleration(nullptr),
      force_threshold_type(""),
      force_threshold_length(0), st_force_threshold(), force_threshold(nullptr),
      effort_type(""),
      effort_length(0), st_effort(), effort(nullptr),
      blending_type(""),
      blending_length(0), st_blending(), blending(nullptr),
      additional_parameters_length(0), st_additional_parameters(), additional_parameters(nullptr),
      additional_values_length(0), st_additional_values(), additional_values(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->command_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->command_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->command_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command_id);
      uint32_t length_command_type = strlen(this->command_type);
      varToArr(outbuffer + offset, length_command_type);
      offset += 4;
      memcpy(outbuffer + offset, this->command_type, length_command_type);
      offset += length_command_type;
      uint32_t length_pose_reference = strlen(this->pose_reference);
      varToArr(outbuffer + offset, length_pose_reference);
      offset += 4;
      memcpy(outbuffer + offset, this->pose_reference, length_pose_reference);
      offset += length_pose_reference;
      uint32_t length_pose_type = strlen(this->pose_type);
      varToArr(outbuffer + offset, length_pose_type);
      offset += 4;
      memcpy(outbuffer + offset, this->pose_type, length_pose_type);
      offset += length_pose_type;
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++){
      union {
        float real;
        uint32_t base;
      } u_posei;
      u_posei.real = this->pose[i];
      *(outbuffer + offset + 0) = (u_posei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose[i]);
      }
      uint32_t length_velocity_type = strlen(this->velocity_type);
      varToArr(outbuffer + offset, length_velocity_type);
      offset += 4;
      memcpy(outbuffer + offset, this->velocity_type, length_velocity_type);
      offset += length_velocity_type;
      *(outbuffer + offset + 0) = (this->velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_velocityi;
      u_velocityi.real = this->velocity[i];
      *(outbuffer + offset + 0) = (u_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity[i]);
      }
      uint32_t length_acceleration_type = strlen(this->acceleration_type);
      varToArr(outbuffer + offset, length_acceleration_type);
      offset += 4;
      memcpy(outbuffer + offset, this->acceleration_type, length_acceleration_type);
      offset += length_acceleration_type;
      *(outbuffer + offset + 0) = (this->acceleration_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acceleration_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acceleration_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acceleration_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration_length);
      for( uint32_t i = 0; i < acceleration_length; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerationi;
      u_accelerationi.real = this->acceleration[i];
      *(outbuffer + offset + 0) = (u_accelerationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerationi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerationi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerationi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acceleration[i]);
      }
      uint32_t length_force_threshold_type = strlen(this->force_threshold_type);
      varToArr(outbuffer + offset, length_force_threshold_type);
      offset += 4;
      memcpy(outbuffer + offset, this->force_threshold_type, length_force_threshold_type);
      offset += length_force_threshold_type;
      *(outbuffer + offset + 0) = (this->force_threshold_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->force_threshold_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->force_threshold_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->force_threshold_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force_threshold_length);
      for( uint32_t i = 0; i < force_threshold_length; i++){
      union {
        float real;
        uint32_t base;
      } u_force_thresholdi;
      u_force_thresholdi.real = this->force_threshold[i];
      *(outbuffer + offset + 0) = (u_force_thresholdi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_thresholdi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_thresholdi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_thresholdi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force_threshold[i]);
      }
      uint32_t length_effort_type = strlen(this->effort_type);
      varToArr(outbuffer + offset, length_effort_type);
      offset += 4;
      memcpy(outbuffer + offset, this->effort_type, length_effort_type);
      offset += length_effort_type;
      *(outbuffer + offset + 0) = (this->effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++){
      union {
        float real;
        uint32_t base;
      } u_efforti;
      u_efforti.real = this->effort[i];
      *(outbuffer + offset + 0) = (u_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_efforti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort[i]);
      }
      uint32_t length_blending_type = strlen(this->blending_type);
      varToArr(outbuffer + offset, length_blending_type);
      offset += 4;
      memcpy(outbuffer + offset, this->blending_type, length_blending_type);
      offset += length_blending_type;
      *(outbuffer + offset + 0) = (this->blending_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blending_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->blending_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->blending_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blending_length);
      for( uint32_t i = 0; i < blending_length; i++){
      union {
        float real;
        uint32_t base;
      } u_blendingi;
      u_blendingi.real = this->blending[i];
      *(outbuffer + offset + 0) = (u_blendingi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blendingi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blendingi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blendingi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blending[i]);
      }
      *(outbuffer + offset + 0) = (this->additional_parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->additional_parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->additional_parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->additional_parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->additional_parameters_length);
      for( uint32_t i = 0; i < additional_parameters_length; i++){
      uint32_t length_additional_parametersi = strlen(this->additional_parameters[i]);
      varToArr(outbuffer + offset, length_additional_parametersi);
      offset += 4;
      memcpy(outbuffer + offset, this->additional_parameters[i], length_additional_parametersi);
      offset += length_additional_parametersi;
      }
      *(outbuffer + offset + 0) = (this->additional_values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->additional_values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->additional_values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->additional_values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->additional_values_length);
      for( uint32_t i = 0; i < additional_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_additional_valuesi;
      u_additional_valuesi.real = this->additional_values[i];
      *(outbuffer + offset + 0) = (u_additional_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_additional_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_additional_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_additional_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->additional_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->command_id =  ((uint32_t) (*(inbuffer + offset)));
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->command_id);
      uint32_t length_command_type;
      arrToVar(length_command_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command_type-1]=0;
      this->command_type = (char *)(inbuffer + offset-1);
      offset += length_command_type;
      uint32_t length_pose_reference;
      arrToVar(length_pose_reference, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pose_reference; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pose_reference-1]=0;
      this->pose_reference = (char *)(inbuffer + offset-1);
      offset += length_pose_reference;
      uint32_t length_pose_type;
      arrToVar(length_pose_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pose_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pose_type-1]=0;
      this->pose_type = (char *)(inbuffer + offset-1);
      offset += length_pose_type;
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (float*)realloc(this->pose, pose_lengthT * sizeof(float));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pose;
      u_st_pose.base = 0;
      u_st_pose.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pose.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pose.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pose.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pose = u_st_pose.real;
      offset += sizeof(this->st_pose);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(float));
      }
      uint32_t length_velocity_type;
      arrToVar(length_velocity_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_velocity_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_velocity_type-1]=0;
      this->velocity_type = (char *)(inbuffer + offset-1);
      offset += length_velocity_type;
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_length);
      if(velocity_lengthT > velocity_length)
        this->velocity = (float*)realloc(this->velocity, velocity_lengthT * sizeof(float));
      velocity_length = velocity_lengthT;
      for( uint32_t i = 0; i < velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_velocity;
      u_st_velocity.base = 0;
      u_st_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_velocity = u_st_velocity.real;
      offset += sizeof(this->st_velocity);
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(float));
      }
      uint32_t length_acceleration_type;
      arrToVar(length_acceleration_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_acceleration_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_acceleration_type-1]=0;
      this->acceleration_type = (char *)(inbuffer + offset-1);
      offset += length_acceleration_type;
      uint32_t acceleration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->acceleration_length);
      if(acceleration_lengthT > acceleration_length)
        this->acceleration = (float*)realloc(this->acceleration, acceleration_lengthT * sizeof(float));
      acceleration_length = acceleration_lengthT;
      for( uint32_t i = 0; i < acceleration_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_acceleration;
      u_st_acceleration.base = 0;
      u_st_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_acceleration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_acceleration = u_st_acceleration.real;
      offset += sizeof(this->st_acceleration);
        memcpy( &(this->acceleration[i]), &(this->st_acceleration), sizeof(float));
      }
      uint32_t length_force_threshold_type;
      arrToVar(length_force_threshold_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_force_threshold_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_force_threshold_type-1]=0;
      this->force_threshold_type = (char *)(inbuffer + offset-1);
      offset += length_force_threshold_type;
      uint32_t force_threshold_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      force_threshold_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      force_threshold_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      force_threshold_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->force_threshold_length);
      if(force_threshold_lengthT > force_threshold_length)
        this->force_threshold = (float*)realloc(this->force_threshold, force_threshold_lengthT * sizeof(float));
      force_threshold_length = force_threshold_lengthT;
      for( uint32_t i = 0; i < force_threshold_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_force_threshold;
      u_st_force_threshold.base = 0;
      u_st_force_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_force_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_force_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_force_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_force_threshold = u_st_force_threshold.real;
      offset += sizeof(this->st_force_threshold);
        memcpy( &(this->force_threshold[i]), &(this->st_force_threshold), sizeof(float));
      }
      uint32_t length_effort_type;
      arrToVar(length_effort_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_effort_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_effort_type-1]=0;
      this->effort_type = (char *)(inbuffer + offset-1);
      offset += length_effort_type;
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_length);
      if(effort_lengthT > effort_length)
        this->effort = (float*)realloc(this->effort, effort_lengthT * sizeof(float));
      effort_length = effort_lengthT;
      for( uint32_t i = 0; i < effort_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_effort;
      u_st_effort.base = 0;
      u_st_effort.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_effort = u_st_effort.real;
      offset += sizeof(this->st_effort);
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(float));
      }
      uint32_t length_blending_type;
      arrToVar(length_blending_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_blending_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_blending_type-1]=0;
      this->blending_type = (char *)(inbuffer + offset-1);
      offset += length_blending_type;
      uint32_t blending_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      blending_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      blending_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      blending_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->blending_length);
      if(blending_lengthT > blending_length)
        this->blending = (float*)realloc(this->blending, blending_lengthT * sizeof(float));
      blending_length = blending_lengthT;
      for( uint32_t i = 0; i < blending_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_blending;
      u_st_blending.base = 0;
      u_st_blending.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_blending.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_blending.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_blending.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_blending = u_st_blending.real;
      offset += sizeof(this->st_blending);
        memcpy( &(this->blending[i]), &(this->st_blending), sizeof(float));
      }
      uint32_t additional_parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      additional_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      additional_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      additional_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->additional_parameters_length);
      if(additional_parameters_lengthT > additional_parameters_length)
        this->additional_parameters = (char**)realloc(this->additional_parameters, additional_parameters_lengthT * sizeof(char*));
      additional_parameters_length = additional_parameters_lengthT;
      for( uint32_t i = 0; i < additional_parameters_length; i++){
      uint32_t length_st_additional_parameters;
      arrToVar(length_st_additional_parameters, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_additional_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_additional_parameters-1]=0;
      this->st_additional_parameters = (char *)(inbuffer + offset-1);
      offset += length_st_additional_parameters;
        memcpy( &(this->additional_parameters[i]), &(this->st_additional_parameters), sizeof(char*));
      }
      uint32_t additional_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      additional_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      additional_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      additional_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->additional_values_length);
      if(additional_values_lengthT > additional_values_length)
        this->additional_values = (float*)realloc(this->additional_values, additional_values_lengthT * sizeof(float));
      additional_values_length = additional_values_lengthT;
      for( uint32_t i = 0; i < additional_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_additional_values;
      u_st_additional_values.base = 0;
      u_st_additional_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_additional_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_additional_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_additional_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_additional_values = u_st_additional_values.real;
      offset += sizeof(this->st_additional_values);
        memcpy( &(this->additional_values[i]), &(this->st_additional_values), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "robot_movement_interface/Command"; };
    virtual const char * getMD5() override { return "095c1a58a8d3e400bdf88ed00339ed6d"; };

  };

}
#endif
