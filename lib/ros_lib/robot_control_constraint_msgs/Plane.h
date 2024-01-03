#ifndef _ROS_robot_control_constraint_msgs_Plane_h
#define _ROS_robot_control_constraint_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

namespace robot_control_constraint_msgs
{

  class Plane : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _normal_type;
      _normal_type normal;
      typedef geometry_msgs::Point _point_type;
      _point_type point;
      typedef const char* _uri_type;
      _uri_type uri;
      typedef const char* _physical_entity_iri_type;
      _physical_entity_iri_type physical_entity_iri;

    Plane():
      normal(),
      point(),
      uri(""),
      physical_entity_iri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->normal.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
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
      offset += this->normal.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return "robot_control_constraint_msgs/Plane"; };
    virtual const char * getMD5() override { return "f2428509fe6bb2a46bf9eb83b134d5e9"; };

  };

}
#endif
