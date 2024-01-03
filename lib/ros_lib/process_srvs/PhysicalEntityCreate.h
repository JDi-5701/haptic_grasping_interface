#ifndef _ROS_SERVICE_PhysicalEntityCreate_h
#define _ROS_SERVICE_PhysicalEntityCreate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/PhysicalEntity.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYCREATE[] = "process_srvs/PhysicalEntityCreate";

  class PhysicalEntityCreateRequest : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;

    PhysicalEntityCreateRequest():
      typeIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_typeIri = strlen(this->typeIri);
      varToArr(outbuffer + offset, length_typeIri);
      offset += 4;
      memcpy(outbuffer + offset, this->typeIri, length_typeIri);
      offset += length_typeIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_typeIri;
      arrToVar(length_typeIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typeIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typeIri-1]=0;
      this->typeIri = (char *)(inbuffer + offset-1);
      offset += length_typeIri;
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYCREATE; };
    virtual const char * getMD5() override { return "ac2ec4a6d15cf7c1116e90a35cc8774f"; };

  };

  class PhysicalEntityCreateResponse : public ros::Msg
  {
    public:
      typedef process_msgs::PhysicalEntity _physicalEntity_type;
      _physicalEntity_type physicalEntity;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityCreateResponse():
      physicalEntity(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->physicalEntity.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->physicalEntity.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYCREATE; };
    virtual const char * getMD5() override { return "22f39982bc8ea4d536eaf84337c339e9"; };

  };

  class PhysicalEntityCreate {
    public:
    typedef PhysicalEntityCreateRequest Request;
    typedef PhysicalEntityCreateResponse Response;
  };

}
#endif
