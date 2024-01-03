#ifndef _ROS_world_state_model_msgs_Entity_h
#define _ROS_world_state_model_msgs_Entity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace world_state_model_msgs
{

  class Entity : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;
      typedef geometry_msgs::PoseWithCovarianceStamped _pose_type;
      _pose_type pose;
      typedef float _poseAccuracy_type;
      _poseAccuracy_type poseAccuracy;

    Entity():
      iri(""),
      typeIri(""),
      pose(),
      poseAccuracy(0)
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
      uint32_t length_typeIri = strlen(this->typeIri);
      varToArr(outbuffer + offset, length_typeIri);
      offset += 4;
      memcpy(outbuffer + offset, this->typeIri, length_typeIri);
      offset += length_typeIri;
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->poseAccuracy);
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
      uint32_t length_typeIri;
      arrToVar(length_typeIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typeIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typeIri-1]=0;
      this->typeIri = (char *)(inbuffer + offset-1);
      offset += length_typeIri;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->poseAccuracy));
     return offset;
    }

    virtual const char * getType() override { return "world_state_model_msgs/Entity"; };
    virtual const char * getMD5() override { return "62f9b009beb216d480faa8e1409333c8"; };

  };

}
#endif
