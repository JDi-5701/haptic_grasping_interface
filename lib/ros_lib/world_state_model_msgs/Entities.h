#ifndef _ROS_world_state_model_msgs_Entities_h
#define _ROS_world_state_model_msgs_Entities_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "world_state_model_msgs/Entity.h"

namespace world_state_model_msgs
{

  class Entities : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t entities_length;
      typedef world_state_model_msgs::Entity _entities_type;
      _entities_type st_entities;
      _entities_type * entities;

    Entities():
      header(),
      entities_length(0), st_entities(), entities(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->entities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entities_length);
      for( uint32_t i = 0; i < entities_length; i++){
      offset += this->entities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
     return offset;
    }

    virtual const char * getType() override { return "world_state_model_msgs/Entities"; };
    virtual const char * getMD5() override { return "3f83302f8b6f0308e00fb9e8cf7c8254"; };

  };

}
#endif
