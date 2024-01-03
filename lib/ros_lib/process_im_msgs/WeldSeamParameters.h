#ifndef _ROS_process_im_msgs_WeldSeamParameters_h
#define _ROS_process_im_msgs_WeldSeamParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class WeldSeamParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;
      uint32_t seam_length;
      typedef geometry_msgs::Pose _seam_type;
      _seam_type st_seam;
      _seam_type * seam;

    WeldSeamParameters():
      approach(),
      seam_length(0), st_seam(), seam(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->seam_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seam_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seam_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seam_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seam_length);
      for( uint32_t i = 0; i < seam_length; i++){
      offset += this->seam[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
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
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/WeldSeamParameters"; };
    virtual const char * getMD5() override { return "d7d46794ed3bbecf099365197a2942e8"; };

  };

}
#endif
