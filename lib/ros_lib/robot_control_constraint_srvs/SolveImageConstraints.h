#ifndef _ROS_SERVICE_SolveImageConstraints_h
#define _ROS_SERVICE_SolveImageConstraints_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Transform.h"

namespace robot_control_constraint_srvs
{

static const char SOLVEIMAGECONSTRAINTS[] = "robot_control_constraint_srvs/SolveImageConstraints";

  class SolveImageConstraintsRequest : public ros::Msg
  {
    public:
      uint32_t point_clicked_length;
      typedef geometry_msgs::Vector3 _point_clicked_type;
      _point_clicked_type st_point_clicked;
      _point_clicked_type * point_clicked;
      uint32_t point_model_length;
      typedef geometry_msgs::Vector3 _point_model_type;
      _point_model_type st_point_model;
      _point_model_type * point_model;

    SolveImageConstraintsRequest():
      point_clicked_length(0), st_point_clicked(), point_clicked(nullptr),
      point_model_length(0), st_point_model(), point_model(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->point_clicked_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_clicked_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_clicked_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_clicked_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_clicked_length);
      for( uint32_t i = 0; i < point_clicked_length; i++){
      offset += this->point_clicked[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_model_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_model_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_model_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_model_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_model_length);
      for( uint32_t i = 0; i < point_model_length; i++){
      offset += this->point_model[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t point_clicked_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_clicked_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_clicked_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_clicked_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_clicked_length);
      if(point_clicked_lengthT > point_clicked_length)
        this->point_clicked = (geometry_msgs::Vector3*)realloc(this->point_clicked, point_clicked_lengthT * sizeof(geometry_msgs::Vector3));
      point_clicked_length = point_clicked_lengthT;
      for( uint32_t i = 0; i < point_clicked_length; i++){
      offset += this->st_point_clicked.deserialize(inbuffer + offset);
        memcpy( &(this->point_clicked[i]), &(this->st_point_clicked), sizeof(geometry_msgs::Vector3));
      }
      uint32_t point_model_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_model_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_model_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_model_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_model_length);
      if(point_model_lengthT > point_model_length)
        this->point_model = (geometry_msgs::Vector3*)realloc(this->point_model, point_model_lengthT * sizeof(geometry_msgs::Vector3));
      point_model_length = point_model_lengthT;
      for( uint32_t i = 0; i < point_model_length; i++){
      offset += this->st_point_model.deserialize(inbuffer + offset);
        memcpy( &(this->point_model[i]), &(this->st_point_model), sizeof(geometry_msgs::Vector3));
      }
     return offset;
    }

    virtual const char * getType() override { return SOLVEIMAGECONSTRAINTS; };
    virtual const char * getMD5() override { return "fde17bcdc67f065a2431cc052af9fe0e"; };

  };

  class SolveImageConstraintsResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _estimated_transform_type;
      _estimated_transform_type estimated_transform;
      typedef bool _converged_type;
      _converged_type converged;

    SolveImageConstraintsResponse():
      estimated_transform(),
      converged(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->estimated_transform.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_converged;
      u_converged.real = this->converged;
      *(outbuffer + offset + 0) = (u_converged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->converged);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->estimated_transform.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_converged;
      u_converged.base = 0;
      u_converged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->converged = u_converged.real;
      offset += sizeof(this->converged);
     return offset;
    }

    virtual const char * getType() override { return SOLVEIMAGECONSTRAINTS; };
    virtual const char * getMD5() override { return "b9fa4a77e1e8a0cedd3dfcd8abf233bc"; };

  };

  class SolveImageConstraints {
    public:
    typedef SolveImageConstraintsRequest Request;
    typedef SolveImageConstraintsResponse Response;
  };

}
#endif
