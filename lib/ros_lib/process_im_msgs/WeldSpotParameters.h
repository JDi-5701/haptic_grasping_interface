#ifndef _ROS_process_im_msgs_WeldSpotParameters_h
#define _ROS_process_im_msgs_WeldSpotParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class WeldSpotParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;
      typedef geometry_msgs::Pose _spot_type;
      _spot_type spot;

    WeldSpotParameters():
      approach(),
      spot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->spot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->spot.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/WeldSpotParameters"; };
    virtual const char * getMD5() override { return "b5cd7ae90703db188c54da845e4eaa91"; };

  };

}
#endif
