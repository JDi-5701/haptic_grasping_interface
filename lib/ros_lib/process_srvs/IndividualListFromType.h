#ifndef _ROS_SERVICE_IndividualListFromType_h
#define _ROS_SERVICE_IndividualListFromType_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Individual.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char INDIVIDUALLISTFROMTYPE[] = "process_srvs/IndividualListFromType";

  class IndividualListFromTypeRequest : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;

    IndividualListFromTypeRequest():
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

    virtual const char * getType() override { return INDIVIDUALLISTFROMTYPE; };
    virtual const char * getMD5() override { return "ac2ec4a6d15cf7c1116e90a35cc8774f"; };

  };

  class IndividualListFromTypeResponse : public ros::Msg
  {
    public:
      uint32_t individuals_length;
      typedef process_msgs::Individual _individuals_type;
      _individuals_type st_individuals;
      _individuals_type * individuals;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    IndividualListFromTypeResponse():
      individuals_length(0), st_individuals(), individuals(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->individuals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->individuals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->individuals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->individuals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->individuals_length);
      for( uint32_t i = 0; i < individuals_length; i++){
      offset += this->individuals[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t individuals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      individuals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      individuals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      individuals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->individuals_length);
      if(individuals_lengthT > individuals_length)
        this->individuals = (process_msgs::Individual*)realloc(this->individuals, individuals_lengthT * sizeof(process_msgs::Individual));
      individuals_length = individuals_lengthT;
      for( uint32_t i = 0; i < individuals_length; i++){
      offset += this->st_individuals.deserialize(inbuffer + offset);
        memcpy( &(this->individuals[i]), &(this->st_individuals), sizeof(process_msgs::Individual));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return INDIVIDUALLISTFROMTYPE; };
    virtual const char * getMD5() override { return "72344a813ee9e9d37c413915c4c4202c"; };

  };

  class IndividualListFromType {
    public:
    typedef IndividualListFromTypeRequest Request;
    typedef IndividualListFromTypeResponse Response;
  };

}
#endif
