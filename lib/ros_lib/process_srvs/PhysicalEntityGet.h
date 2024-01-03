#ifndef _ROS_SERVICE_PhysicalEntityGet_h
#define _ROS_SERVICE_PhysicalEntityGet_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/PhysicalEntity.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYGET[] = "process_srvs/PhysicalEntityGet";

  class PhysicalEntityGetRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    PhysicalEntityGetRequest():
      iri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_iri = strlen(this->iri);
      varToArr(outbuffer + offset, length_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->iri, length_iri);
      offset += length_iri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_iri;
      arrToVar(length_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_iri-1]=0;
      this->iri = (char *)(inbuffer + offset-1);
      offset += length_iri;
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYGET; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class PhysicalEntityGetResponse : public ros::Msg
  {
    public:
      typedef process_msgs::PhysicalEntity _physicalEntity_type;
      _physicalEntity_type physicalEntity;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityGetResponse():
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

    virtual const char * getType() override { return PHYSICALENTITYGET; };
    virtual const char * getMD5() override { return "22f39982bc8ea4d536eaf84337c339e9"; };

  };

  class PhysicalEntityGet {
    public:
    typedef PhysicalEntityGetRequest Request;
    typedef PhysicalEntityGetResponse Response;
  };

}
#endif
