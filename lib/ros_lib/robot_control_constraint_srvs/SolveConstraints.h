#ifndef _ROS_SERVICE_SolveConstraints_h
#define _ROS_SERVICE_SolveConstraints_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_control_constraint_msgs/Constraints.h"
#include "geometry_msgs/Pose.h"

namespace robot_control_constraint_srvs
{

static const char SOLVECONSTRAINTS[] = "robot_control_constraint_srvs/SolveConstraints";

  class SolveConstraintsRequest : public ros::Msg
  {
    public:
      typedef robot_control_constraint_msgs::Constraints _constraint_request_type;
      _constraint_request_type constraint_request;
      uint32_t current_pose_length;
      typedef geometry_msgs::Pose _current_pose_type;
      _current_pose_type st_current_pose;
      _current_pose_type * current_pose;
      typedef float _fixed_bounding_sphere_radius_type;
      _fixed_bounding_sphere_radius_type fixed_bounding_sphere_radius;
      typedef float _constrained_bounding_sphere_radius_type;
      _constrained_bounding_sphere_radius_type constrained_bounding_sphere_radius;

    SolveConstraintsRequest():
      constraint_request(),
      current_pose_length(0), st_current_pose(), current_pose(nullptr),
      fixed_bounding_sphere_radius(0),
      constrained_bounding_sphere_radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->constraint_request.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->current_pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_pose_length);
      for( uint32_t i = 0; i < current_pose_length; i++){
      offset += this->current_pose[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_fixed_bounding_sphere_radius;
      u_fixed_bounding_sphere_radius.real = this->fixed_bounding_sphere_radius;
      *(outbuffer + offset + 0) = (u_fixed_bounding_sphere_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fixed_bounding_sphere_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fixed_bounding_sphere_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fixed_bounding_sphere_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixed_bounding_sphere_radius);
      union {
        float real;
        uint32_t base;
      } u_constrained_bounding_sphere_radius;
      u_constrained_bounding_sphere_radius.real = this->constrained_bounding_sphere_radius;
      *(outbuffer + offset + 0) = (u_constrained_bounding_sphere_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_constrained_bounding_sphere_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_constrained_bounding_sphere_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_constrained_bounding_sphere_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->constrained_bounding_sphere_radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->constraint_request.deserialize(inbuffer + offset);
      uint32_t current_pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      current_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      current_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      current_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->current_pose_length);
      if(current_pose_lengthT > current_pose_length)
        this->current_pose = (geometry_msgs::Pose*)realloc(this->current_pose, current_pose_lengthT * sizeof(geometry_msgs::Pose));
      current_pose_length = current_pose_lengthT;
      for( uint32_t i = 0; i < current_pose_length; i++){
      offset += this->st_current_pose.deserialize(inbuffer + offset);
        memcpy( &(this->current_pose[i]), &(this->st_current_pose), sizeof(geometry_msgs::Pose));
      }
      union {
        float real;
        uint32_t base;
      } u_fixed_bounding_sphere_radius;
      u_fixed_bounding_sphere_radius.base = 0;
      u_fixed_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fixed_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fixed_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fixed_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fixed_bounding_sphere_radius = u_fixed_bounding_sphere_radius.real;
      offset += sizeof(this->fixed_bounding_sphere_radius);
      union {
        float real;
        uint32_t base;
      } u_constrained_bounding_sphere_radius;
      u_constrained_bounding_sphere_radius.base = 0;
      u_constrained_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_constrained_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_constrained_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_constrained_bounding_sphere_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->constrained_bounding_sphere_radius = u_constrained_bounding_sphere_radius.real;
      offset += sizeof(this->constrained_bounding_sphere_radius);
     return offset;
    }

    virtual const char * getType() override { return SOLVECONSTRAINTS; };
    virtual const char * getMD5() override { return "189aa8593b4b68330a9091fba5b1c1e6"; };

  };

  class SolveConstraintsResponse : public ros::Msg
  {
    public:
      typedef const char* _error_message_type;
      _error_message_type error_message;
      typedef robot_control_constraint_msgs::Constraints _constraint_result_type;
      _constraint_result_type constraint_result;
      typedef int8_t _converged_type;
      _converged_type converged;
      uint32_t new_pose_length;
      typedef geometry_msgs::Pose _new_pose_type;
      _new_pose_type st_new_pose;
      _new_pose_type * new_pose;

    SolveConstraintsResponse():
      error_message(""),
      constraint_result(),
      converged(0),
      new_pose_length(0), st_new_pose(), new_pose(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_error_message = strlen(this->error_message);
      varToArr(outbuffer + offset, length_error_message);
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      offset += this->constraint_result.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_converged;
      u_converged.real = this->converged;
      *(outbuffer + offset + 0) = (u_converged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->converged);
      *(outbuffer + offset + 0) = (this->new_pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->new_pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->new_pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->new_pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->new_pose_length);
      for( uint32_t i = 0; i < new_pose_length; i++){
      offset += this->new_pose[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_error_message;
      arrToVar(length_error_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
      offset += this->constraint_result.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_converged;
      u_converged.base = 0;
      u_converged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->converged = u_converged.real;
      offset += sizeof(this->converged);
      uint32_t new_pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      new_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      new_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      new_pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->new_pose_length);
      if(new_pose_lengthT > new_pose_length)
        this->new_pose = (geometry_msgs::Pose*)realloc(this->new_pose, new_pose_lengthT * sizeof(geometry_msgs::Pose));
      new_pose_length = new_pose_lengthT;
      for( uint32_t i = 0; i < new_pose_length; i++){
      offset += this->st_new_pose.deserialize(inbuffer + offset);
        memcpy( &(this->new_pose[i]), &(this->st_new_pose), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    virtual const char * getType() override { return SOLVECONSTRAINTS; };
    virtual const char * getMD5() override { return "6130d3b1529ce88c6ce682225aee7c7d"; };

  };

  class SolveConstraints {
    public:
    typedef SolveConstraintsRequest Request;
    typedef SolveConstraintsResponse Response;
  };

}
#endif
