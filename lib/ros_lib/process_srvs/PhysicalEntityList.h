#ifndef _ROS_SERVICE_PhysicalEntityList_h
#define _ROS_SERVICE_PhysicalEntityList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/PhysicalEntity.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYLIST[] = "process_srvs/PhysicalEntityList";

  class PhysicalEntityListRequest : public ros::Msg
  {
    public:

    PhysicalEntityListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYLIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PhysicalEntityListResponse : public ros::Msg
  {
    public:
      uint32_t physicalEntities_length;
      typedef process_msgs::PhysicalEntity _physicalEntities_type;
      _physicalEntities_type st_physicalEntities;
      _physicalEntities_type * physicalEntities;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityListResponse():
      physicalEntities_length(0), st_physicalEntities(), physicalEntities(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->physicalEntities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->physicalEntities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->physicalEntities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->physicalEntities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->physicalEntities_length);
      for( uint32_t i = 0; i < physicalEntities_length; i++){
      offset += this->physicalEntities[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t physicalEntities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      physicalEntities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      physicalEntities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      physicalEntities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->physicalEntities_length);
      if(physicalEntities_lengthT > physicalEntities_length)
        this->physicalEntities = (process_msgs::PhysicalEntity*)realloc(this->physicalEntities, physicalEntities_lengthT * sizeof(process_msgs::PhysicalEntity));
      physicalEntities_length = physicalEntities_lengthT;
      for( uint32_t i = 0; i < physicalEntities_length; i++){
      offset += this->st_physicalEntities.deserialize(inbuffer + offset);
        memcpy( &(this->physicalEntities[i]), &(this->st_physicalEntities), sizeof(process_msgs::PhysicalEntity));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYLIST; };
    virtual const char * getMD5() override { return "b11557840da0179f2ee65c67fa47dcb3"; };

  };

  class PhysicalEntityList {
    public:
    typedef PhysicalEntityListRequest Request;
    typedef PhysicalEntityListResponse Response;
  };

}
#endif
