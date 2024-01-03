#ifndef _ROS_SERVICE_GetEntities_h
#define _ROS_SERVICE_GetEntities_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "world_state_model_msgs/Entity.h"

namespace world_state_model_srvs
{

static const char GETENTITIES[] = "world_state_model_srvs/GetEntities";

  class GetEntitiesRequest : public ros::Msg
  {
    public:
      uint32_t iris_length;
      typedef char* _iris_type;
      _iris_type st_iris;
      _iris_type * iris;

    GetEntitiesRequest():
      iris_length(0), st_iris(), iris(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->iris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->iris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->iris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->iris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->iris_length);
      for( uint32_t i = 0; i < iris_length; i++){
      uint32_t length_irisi = strlen(this->iris[i]);
      varToArr(outbuffer + offset, length_irisi);
      offset += 4;
      memcpy(outbuffer + offset, this->iris[i], length_irisi);
      offset += length_irisi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t iris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      iris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      iris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      iris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->iris_length);
      if(iris_lengthT > iris_length)
        this->iris = (char**)realloc(this->iris, iris_lengthT * sizeof(char*));
      iris_length = iris_lengthT;
      for( uint32_t i = 0; i < iris_length; i++){
      uint32_t length_st_iris;
      arrToVar(length_st_iris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_iris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_iris-1]=0;
      this->st_iris = (char *)(inbuffer + offset-1);
      offset += length_st_iris;
        memcpy( &(this->iris[i]), &(this->st_iris), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return GETENTITIES; };
    virtual const char * getMD5() override { return "3bf1d86ccdad05e3381be2865842dc57"; };

  };

  class GetEntitiesResponse : public ros::Msg
  {
    public:
      uint32_t entities_length;
      typedef world_state_model_msgs::Entity _entities_type;
      _entities_type st_entities;
      _entities_type * entities;
      typedef int32_t _error_type;
      _error_type error;

    GetEntitiesResponse():
      entities_length(0), st_entities(), entities(nullptr),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->entities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entities_length);
      for( uint32_t i = 0; i < entities_length; i++){
      offset += this->entities[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t entities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entities_length);
      if(entities_lengthT > entities_length)
        this->entities = (world_state_model_msgs::Entity*)realloc(this->entities, entities_lengthT * sizeof(world_state_model_msgs::Entity));
      entities_length = entities_lengthT;
      for( uint32_t i = 0; i < entities_length; i++){
      offset += this->st_entities.deserialize(inbuffer + offset);
        memcpy( &(this->entities[i]), &(this->st_entities), sizeof(world_state_model_msgs::Entity));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error = u_error.real;
      offset += sizeof(this->error);
     return offset;
    }

    virtual const char * getType() override { return GETENTITIES; };
    virtual const char * getMD5() override { return "f0eabbd5e515760303500f9601678a73"; };

  };

  class GetEntities {
    public:
    typedef GetEntitiesRequest Request;
    typedef GetEntitiesResponse Response;
  };

}
#endif
