#ifndef _ROS_control_core_msgs_VectorStamped_h
#define _ROS_control_core_msgs_VectorStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "control_core_msgs/Vector.h"

namespace control_core_msgs
{

  class VectorStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef control_core_msgs::Vector _vector_type;
      _vector_type vector;

    VectorStamped():
      header(),
      vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vector.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/VectorStamped"; };
    virtual const char * getMD5() override { return "1af1b6b69f442d4a5deaeb506bbdee39"; };

  };

}
#endif
