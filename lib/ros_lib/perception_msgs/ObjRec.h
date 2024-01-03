#ifndef _ROS_perception_msgs_ObjRec_h
#define _ROS_perception_msgs_ObjRec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace perception_msgs
{

  class ObjRec : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;
      typedef const char* _iri_type;
      _iri_type iri;
      typedef geometry_msgs::PoseWithCovarianceStamped _pose_type;
      _pose_type pose;
      typedef float _poseAccuracy_type;
      _poseAccuracy_type poseAccuracy;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef uint8_t _status_type;
      _status_type status;

    ObjRec():
      typeIri(""),
      iri(""),
      pose(),
      poseAccuracy(0),
      confidence(0),
      status(0)
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
      uint32_t length_iri = strlen(this->iri);
      varToArr(outbuffer + offset, length_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->iri, length_iri);
      offset += length_iri;
      offset += this->pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->poseAccuracy);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
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
      uint32_t length_iri;
      arrToVar(length_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_iri-1]=0;
      this->iri = (char *)(inbuffer + offset-1);
      offset += length_iri;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->poseAccuracy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return "perception_msgs/ObjRec"; };
    virtual const char * getMD5() override { return "fad0416470d1ed72a8cf581ec56378ee"; };

  };

}
#endif
