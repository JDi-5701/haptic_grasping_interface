#ifndef _ROS_actor_msgs_ActorVec_h
#define _ROS_actor_msgs_ActorVec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actor_msgs/Actor.h"

namespace actor_msgs
{

  class ActorVec : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t ActorVec_length;
      typedef actor_msgs::Actor _ActorVec_type;
      _ActorVec_type st_ActorVec;
      _ActorVec_type * ActorVec;

    ActorVec():
      header(),
      ActorVec_length(0), st_ActorVec(), ActorVec(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ActorVec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ActorVec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ActorVec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ActorVec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ActorVec_length);
      for( uint32_t i = 0; i < ActorVec_length; i++){
      offset += this->ActorVec[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t ActorVec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ActorVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ActorVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ActorVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ActorVec_length);
      if(ActorVec_lengthT > ActorVec_length)
        this->ActorVec = (actor_msgs::Actor*)realloc(this->ActorVec, ActorVec_lengthT * sizeof(actor_msgs::Actor));
      ActorVec_length = ActorVec_lengthT;
      for( uint32_t i = 0; i < ActorVec_length; i++){
      offset += this->st_ActorVec.deserialize(inbuffer + offset);
        memcpy( &(this->ActorVec[i]), &(this->st_ActorVec), sizeof(actor_msgs::Actor));
      }
     return offset;
    }

    virtual const char * getType() override { return "actor_msgs/ActorVec"; };
    virtual const char * getMD5() override { return "277708f6aec68ba84c09796f026e7f6d"; };

  };

}
#endif
