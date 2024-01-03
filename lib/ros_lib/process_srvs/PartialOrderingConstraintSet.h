#ifndef _ROS_SERVICE_PartialOrderingConstraintSet_h
#define _ROS_SERVICE_PartialOrderingConstraintSet_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PARTIALORDERINGCONSTRAINTSET[] = "process_srvs/PartialOrderingConstraintSet";

  class PartialOrderingConstraintSetRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      uint32_t precedesIri_length;
      typedef char* _precedesIri_type;
      _precedesIri_type st_precedesIri;
      _precedesIri_type * precedesIri;
      uint32_t succeedsIri_length;
      typedef char* _succeedsIri_type;
      _succeedsIri_type st_succeedsIri;
      _succeedsIri_type * succeedsIri;

    PartialOrderingConstraintSetRequest():
      iri(""),
      precedesIri_length(0), st_precedesIri(), precedesIri(nullptr),
      succeedsIri_length(0), st_succeedsIri(), succeedsIri(nullptr)
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
      *(outbuffer + offset + 0) = (this->precedesIri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->precedesIri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->precedesIri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->precedesIri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->precedesIri_length);
      for( uint32_t i = 0; i < precedesIri_length; i++){
      uint32_t length_precedesIrii = strlen(this->precedesIri[i]);
      varToArr(outbuffer + offset, length_precedesIrii);
      offset += 4;
      memcpy(outbuffer + offset, this->precedesIri[i], length_precedesIrii);
      offset += length_precedesIrii;
      }
      *(outbuffer + offset + 0) = (this->succeedsIri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->succeedsIri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->succeedsIri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->succeedsIri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->succeedsIri_length);
      for( uint32_t i = 0; i < succeedsIri_length; i++){
      uint32_t length_succeedsIrii = strlen(this->succeedsIri[i]);
      varToArr(outbuffer + offset, length_succeedsIrii);
      offset += 4;
      memcpy(outbuffer + offset, this->succeedsIri[i], length_succeedsIrii);
      offset += length_succeedsIrii;
      }
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
      uint32_t precedesIri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      precedesIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      precedesIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      precedesIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->precedesIri_length);
      if(precedesIri_lengthT > precedesIri_length)
        this->precedesIri = (char**)realloc(this->precedesIri, precedesIri_lengthT * sizeof(char*));
      precedesIri_length = precedesIri_lengthT;
      for( uint32_t i = 0; i < precedesIri_length; i++){
      uint32_t length_st_precedesIri;
      arrToVar(length_st_precedesIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_precedesIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_precedesIri-1]=0;
      this->st_precedesIri = (char *)(inbuffer + offset-1);
      offset += length_st_precedesIri;
        memcpy( &(this->precedesIri[i]), &(this->st_precedesIri), sizeof(char*));
      }
      uint32_t succeedsIri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      succeedsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      succeedsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      succeedsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->succeedsIri_length);
      if(succeedsIri_lengthT > succeedsIri_length)
        this->succeedsIri = (char**)realloc(this->succeedsIri, succeedsIri_lengthT * sizeof(char*));
      succeedsIri_length = succeedsIri_lengthT;
      for( uint32_t i = 0; i < succeedsIri_length; i++){
      uint32_t length_st_succeedsIri;
      arrToVar(length_st_succeedsIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_succeedsIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_succeedsIri-1]=0;
      this->st_succeedsIri = (char *)(inbuffer + offset-1);
      offset += length_st_succeedsIri;
        memcpy( &(this->succeedsIri[i]), &(this->st_succeedsIri), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return PARTIALORDERINGCONSTRAINTSET; };
    virtual const char * getMD5() override { return "42f7df91cee3a9d9438165c66940b8ca"; };

  };

  class PartialOrderingConstraintSetResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PartialOrderingConstraintSetResponse():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PARTIALORDERINGCONSTRAINTSET; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class PartialOrderingConstraintSet {
    public:
    typedef PartialOrderingConstraintSetRequest Request;
    typedef PartialOrderingConstraintSetResponse Response;
  };

}
#endif
