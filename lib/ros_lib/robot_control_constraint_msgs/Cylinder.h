#ifndef _ROS_robot_control_constraint_msgs_Cylinder_h
#define _ROS_robot_control_constraint_msgs_Cylinder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace robot_control_constraint_msgs
{

  class Cylinder : public ros::Msg
  {
    public:
      typedef float _radius_type;
      _radius_type radius;
      typedef geometry_msgs::Vector3 _axis_type;
      _axis_type axis;
      typedef geometry_msgs::Vector3 _point_type;
      _point_type point;
      typedef float _height_type;
      _height_type height;
      typedef const char* _uri_type;
      _uri_type uri;
      typedef const char* _physical_entity_iri_type;
      _physical_entity_iri_type physical_entity_iri;

    Cylinder():
      radius(0),
      axis(),
      point(),
      height(0),
      uri(""),
      physical_entity_iri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      offset += this->axis.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      uint32_t length_uri = strlen(this->uri);
      varToArr(outbuffer + offset, length_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      uint32_t length_physical_entity_iri = strlen(this->physical_entity_iri);
      varToArr(outbuffer + offset, length_physical_entity_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->physical_entity_iri, length_physical_entity_iri);
      offset += length_physical_entity_iri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
      offset += this->axis.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      uint32_t length_uri;
      arrToVar(length_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      uint32_t length_physical_entity_iri;
      arrToVar(length_physical_entity_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_physical_entity_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_physical_entity_iri-1]=0;
      this->physical_entity_iri = (char *)(inbuffer + offset-1);
      offset += length_physical_entity_iri;
     return offset;
    }

    virtual const char * getType() override { return "robot_control_constraint_msgs/Cylinder"; };
    virtual const char * getMD5() override { return "361928ac40b5f80a7c862b3bbc130ffd"; };

  };

}
#endif
