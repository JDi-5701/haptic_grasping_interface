#ifndef _ROS_process_im_msgs_DualArmMoveParameters_h
#define _ROS_process_im_msgs_DualArmMoveParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class DualArmMoveParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _move_pose_type;
      _move_pose_type move_pose;
      typedef const char* _execution_actor_type;
      _execution_actor_type execution_actor;

    DualArmMoveParameters():
      move_pose(),
      execution_actor("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->move_pose.serialize(outbuffer + offset);
      uint32_t length_execution_actor = strlen(this->execution_actor);
      varToArr(outbuffer + offset, length_execution_actor);
      offset += 4;
      memcpy(outbuffer + offset, this->execution_actor, length_execution_actor);
      offset += length_execution_actor;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->move_pose.deserialize(inbuffer + offset);
      uint32_t length_execution_actor;
      arrToVar(length_execution_actor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_execution_actor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_execution_actor-1]=0;
      this->execution_actor = (char *)(inbuffer + offset-1);
      offset += length_execution_actor;
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/DualArmMoveParameters"; };
    virtual const char * getMD5() override { return "d8ac1eb19d70809cb4cff0211213df74"; };

  };

}
#endif
