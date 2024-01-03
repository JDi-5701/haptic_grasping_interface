#ifndef _ROS_process_msgs_Value_h
#define _ROS_process_msgs_Value_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Individual.h"
#include "process_msgs/PhysicalEntity.h"
#include "process_msgs/CombinedGeometricInterrelationConstraint.h"
#include "geometry_msgs/Pose.h"

namespace process_msgs
{

  class Value : public ros::Msg
  {
    public:
      typedef uint8_t _valueEnum_type;
      _valueEnum_type valueEnum;
      uint32_t b_length;
      typedef bool _b_type;
      _b_type st_b;
      _b_type * b;
      uint32_t l_length;
      typedef int64_t _l_type;
      _l_type st_l;
      _l_type * l;
      uint32_t d_length;
      typedef float _d_type;
      _d_type st_d;
      _d_type * d;
      uint32_t s_length;
      typedef char* _s_type;
      _s_type st_s;
      _s_type * s;
      uint32_t individual_length;
      typedef process_msgs::Individual _individual_type;
      _individual_type st_individual;
      _individual_type * individual;
      uint32_t physicalEntity_length;
      typedef process_msgs::PhysicalEntity _physicalEntity_type;
      _physicalEntity_type st_physicalEntity;
      _physicalEntity_type * physicalEntity;
      uint32_t combinedGeometricInterrelationConstraint_length;
      typedef process_msgs::CombinedGeometricInterrelationConstraint _combinedGeometricInterrelationConstraint_type;
      _combinedGeometricInterrelationConstraint_type st_combinedGeometricInterrelationConstraint;
      _combinedGeometricInterrelationConstraint_type * combinedGeometricInterrelationConstraint;
      uint32_t pose_length;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type st_pose;
      _pose_type * pose;

    Value():
      valueEnum(0),
      b_length(0), st_b(), b(nullptr),
      l_length(0), st_l(), l(nullptr),
      d_length(0), st_d(), d(nullptr),
      s_length(0), st_s(), s(nullptr),
      individual_length(0), st_individual(), individual(nullptr),
      physicalEntity_length(0), st_physicalEntity(), physicalEntity(nullptr),
      combinedGeometricInterrelationConstraint_length(0), st_combinedGeometricInterrelationConstraint(), combinedGeometricInterrelationConstraint(nullptr),
      pose_length(0), st_pose(), pose(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->valueEnum >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valueEnum);
      *(outbuffer + offset + 0) = (this->b_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->b_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->b_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->b_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_length);
      for( uint32_t i = 0; i < b_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_bi;
      u_bi.real = this->b[i];
      *(outbuffer + offset + 0) = (u_bi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b[i]);
      }
      *(outbuffer + offset + 0) = (this->l_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->l_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->l_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->l_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l_length);
      for( uint32_t i = 0; i < l_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_li;
      u_li.real = this->l[i];
      *(outbuffer + offset + 0) = (u_li.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_li.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_li.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_li.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_li.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_li.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_li.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_li.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l[i]);
      }
      *(outbuffer + offset + 0) = (this->d_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->d_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->d_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->d_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d_length);
      for( uint32_t i = 0; i < d_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->d[i]);
      }
      *(outbuffer + offset + 0) = (this->s_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->s_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->s_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->s_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->s_length);
      for( uint32_t i = 0; i < s_length; i++){
      uint32_t length_si = strlen(this->s[i]);
      varToArr(outbuffer + offset, length_si);
      offset += 4;
      memcpy(outbuffer + offset, this->s[i], length_si);
      offset += length_si;
      }
      *(outbuffer + offset + 0) = (this->individual_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->individual_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->individual_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->individual_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->individual_length);
      for( uint32_t i = 0; i < individual_length; i++){
      offset += this->individual[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->physicalEntity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->physicalEntity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->physicalEntity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->physicalEntity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->physicalEntity_length);
      for( uint32_t i = 0; i < physicalEntity_length; i++){
      offset += this->physicalEntity[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->combinedGeometricInterrelationConstraint_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->combinedGeometricInterrelationConstraint_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->combinedGeometricInterrelationConstraint_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->combinedGeometricInterrelationConstraint_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->combinedGeometricInterrelationConstraint_length);
      for( uint32_t i = 0; i < combinedGeometricInterrelationConstraint_length; i++){
      offset += this->combinedGeometricInterrelationConstraint[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->valueEnum =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->valueEnum);
      uint32_t b_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->b_length);
      if(b_lengthT > b_length)
        this->b = (bool*)realloc(this->b, b_lengthT * sizeof(bool));
      b_length = b_lengthT;
      for( uint32_t i = 0; i < b_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_b;
      u_st_b.base = 0;
      u_st_b.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_b = u_st_b.real;
      offset += sizeof(this->st_b);
        memcpy( &(this->b[i]), &(this->st_b), sizeof(bool));
      }
      uint32_t l_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      l_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      l_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      l_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->l_length);
      if(l_lengthT > l_length)
        this->l = (int64_t*)realloc(this->l, l_lengthT * sizeof(int64_t));
      l_length = l_lengthT;
      for( uint32_t i = 0; i < l_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_l;
      u_st_l.base = 0;
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_l = u_st_l.real;
      offset += sizeof(this->st_l);
        memcpy( &(this->l[i]), &(this->st_l), sizeof(int64_t));
      }
      uint32_t d_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      d_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      d_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      d_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->d_length);
      if(d_lengthT > d_length)
        this->d = (float*)realloc(this->d, d_lengthT * sizeof(float));
      d_length = d_lengthT;
      for( uint32_t i = 0; i < d_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_d));
        memcpy( &(this->d[i]), &(this->st_d), sizeof(float));
      }
      uint32_t s_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      s_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      s_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      s_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->s_length);
      if(s_lengthT > s_length)
        this->s = (char**)realloc(this->s, s_lengthT * sizeof(char*));
      s_length = s_lengthT;
      for( uint32_t i = 0; i < s_length; i++){
      uint32_t length_st_s;
      arrToVar(length_st_s, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_s; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_s-1]=0;
      this->st_s = (char *)(inbuffer + offset-1);
      offset += length_st_s;
        memcpy( &(this->s[i]), &(this->st_s), sizeof(char*));
      }
      uint32_t individual_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      individual_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      individual_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      individual_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->individual_length);
      if(individual_lengthT > individual_length)
        this->individual = (process_msgs::Individual*)realloc(this->individual, individual_lengthT * sizeof(process_msgs::Individual));
      individual_length = individual_lengthT;
      for( uint32_t i = 0; i < individual_length; i++){
      offset += this->st_individual.deserialize(inbuffer + offset);
        memcpy( &(this->individual[i]), &(this->st_individual), sizeof(process_msgs::Individual));
      }
      uint32_t physicalEntity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      physicalEntity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      physicalEntity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      physicalEntity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->physicalEntity_length);
      if(physicalEntity_lengthT > physicalEntity_length)
        this->physicalEntity = (process_msgs::PhysicalEntity*)realloc(this->physicalEntity, physicalEntity_lengthT * sizeof(process_msgs::PhysicalEntity));
      physicalEntity_length = physicalEntity_lengthT;
      for( uint32_t i = 0; i < physicalEntity_length; i++){
      offset += this->st_physicalEntity.deserialize(inbuffer + offset);
        memcpy( &(this->physicalEntity[i]), &(this->st_physicalEntity), sizeof(process_msgs::PhysicalEntity));
      }
      uint32_t combinedGeometricInterrelationConstraint_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      combinedGeometricInterrelationConstraint_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      combinedGeometricInterrelationConstraint_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      combinedGeometricInterrelationConstraint_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->combinedGeometricInterrelationConstraint_length);
      if(combinedGeometricInterrelationConstraint_lengthT > combinedGeometricInterrelationConstraint_length)
        this->combinedGeometricInterrelationConstraint = (process_msgs::CombinedGeometricInterrelationConstraint*)realloc(this->combinedGeometricInterrelationConstraint, combinedGeometricInterrelationConstraint_lengthT * sizeof(process_msgs::CombinedGeometricInterrelationConstraint));
      combinedGeometricInterrelationConstraint_length = combinedGeometricInterrelationConstraint_lengthT;
      for( uint32_t i = 0; i < combinedGeometricInterrelationConstraint_length; i++){
      offset += this->st_combinedGeometricInterrelationConstraint.deserialize(inbuffer + offset);
        memcpy( &(this->combinedGeometricInterrelationConstraint[i]), &(this->st_combinedGeometricInterrelationConstraint), sizeof(process_msgs::CombinedGeometricInterrelationConstraint));
      }
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (geometry_msgs::Pose*)realloc(this->pose, pose_lengthT * sizeof(geometry_msgs::Pose));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    virtual const char * getType() override { return "process_msgs/Value"; };
    virtual const char * getMD5() override { return "7debe4379b81877e9da5fe686c938735"; };

  };

}
#endif
