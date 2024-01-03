#ifndef _ROS_actor_msgs_ActorTypes_h
#define _ROS_actor_msgs_ActorTypes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace actor_msgs
{

  class ActorTypes : public ros::Msg
  {
    public:
      enum { ASSEMBLY_ACTORS =  101 };
      enum { WELDING_ACTORS =  102 };

    ActorTypes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return "actor_msgs/ActorTypes"; };
    virtual const char * getMD5() override { return "d7def6a87f6b6b51158394e275aace5b"; };

  };

}
#endif
