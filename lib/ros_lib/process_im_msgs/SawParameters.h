#ifndef _ROS_process_im_msgs_SawParameters_h
#define _ROS_process_im_msgs_SawParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class SawParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;
      typedef geometry_msgs::Pose _unsafe_type;
      _unsafe_type unsafe;
      typedef geometry_msgs::Pose _approachEnd_type;
      _approachEnd_type approachEnd;
      uint32_t seam_length;
      typedef geometry_msgs::Pose _seam_type;
      _seam_type st_seam;
      _seam_type * seam;
      typedef float _approachSpeed_type;
      _approachSpeed_type approachSpeed;
      typedef float _unsafeSpeed_type;
      _unsafeSpeed_type unsafeSpeed;
      typedef float _approachEndSpeed_type;
      _approachEndSpeed_type approachEndSpeed;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _rpm_type;
      _rpm_type rpm;

    SawParameters():
      approach(),
      unsafe(),
      approachEnd(),
      seam_length(0), st_seam(), seam(nullptr),
      approachSpeed(0),
      unsafeSpeed(0),
      approachEndSpeed(0),
      speed(0),
      rpm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->unsafe.serialize(outbuffer + offset);
      offset += this->approachEnd.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->seam_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seam_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seam_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seam_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seam_length);
      for( uint32_t i = 0; i < seam_length; i++){
      offset += this->seam[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->approachSpeed);
      offset += serializeAvrFloat64(outbuffer + offset, this->unsafeSpeed);
      offset += serializeAvrFloat64(outbuffer + offset, this->approachEndSpeed);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->rpm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->unsafe.deserialize(inbuffer + offset);
      offset += this->approachEnd.deserialize(inbuffer + offset);
      uint32_t seam_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      seam_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      seam_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      seam_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->seam_length);
      if(seam_lengthT > seam_length)
        this->seam = (geometry_msgs::Pose*)realloc(this->seam, seam_lengthT * sizeof(geometry_msgs::Pose));
      seam_length = seam_lengthT;
      for( uint32_t i = 0; i < seam_length; i++){
      offset += this->st_seam.deserialize(inbuffer + offset);
        memcpy( &(this->seam[i]), &(this->st_seam), sizeof(geometry_msgs::Pose));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->approachSpeed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->unsafeSpeed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->approachEndSpeed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rpm));
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/SawParameters"; };
    virtual const char * getMD5() override { return "b9bd151c5db845e6200b70acd5bcc91f"; };

  };

}
#endif
