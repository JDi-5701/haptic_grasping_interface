#ifndef _ROS_process_im_msgs_MoveToActorParameters_h
#define _ROS_process_im_msgs_MoveToActorParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class MoveToActorParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _approach_type;
      _approach_type approach;

    MoveToActorParameters():
      approach()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->approach.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->approach.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/MoveToActorParameters"; };
    virtual const char * getMD5() override { return "f2fd24e7e15f6f46b0759d2a2787e661"; };

  };

}
#endif
