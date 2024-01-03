#ifndef _ROS_process_im_msgs_PlaceParameters_h
#define _ROS_process_im_msgs_PlaceParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class PlaceParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;
      typedef geometry_msgs::Pose _place_type;
      _place_type place;

    PlaceParameters():
      approach(),
      place()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->place.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->place.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/PlaceParameters"; };
    virtual const char * getMD5() override { return "f0b3ae0c9f1c242a5477dc2275332b87"; };

  };

}
#endif
