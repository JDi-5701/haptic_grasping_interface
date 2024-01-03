#ifndef _ROS_process_im_msgs_DualArmPlaceParameters_h
#define _ROS_process_im_msgs_DualArmPlaceParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class DualArmPlaceParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _placeobject_approach_type;
      _placeobject_approach_type placeobject_approach;
      typedef geometry_msgs::Pose _placeobject_place_type;
      _placeobject_place_type placeobject_place;
      typedef geometry_msgs::Pose _execution_actor_resting_type;
      _execution_actor_resting_type execution_actor_resting;
      typedef const char* _place_execution_actor_type;
      _place_execution_actor_type place_execution_actor;
      typedef float _placeobject_gripper_span_type;
      _placeobject_gripper_span_type placeobject_gripper_span;

    DualArmPlaceParameters():
      placeobject_approach(),
      placeobject_place(),
      execution_actor_resting(),
      place_execution_actor(""),
      placeobject_gripper_span(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->placeobject_approach.serialize(outbuffer + offset);
      offset += this->placeobject_place.serialize(outbuffer + offset);
      offset += this->execution_actor_resting.serialize(outbuffer + offset);
      uint32_t length_place_execution_actor = strlen(this->place_execution_actor);
      varToArr(outbuffer + offset, length_place_execution_actor);
      offset += 4;
      memcpy(outbuffer + offset, this->place_execution_actor, length_place_execution_actor);
      offset += length_place_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_placeobject_gripper_span;
      u_placeobject_gripper_span.real = this->placeobject_gripper_span;
      *(outbuffer + offset + 0) = (u_placeobject_gripper_span.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_placeobject_gripper_span.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_placeobject_gripper_span.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_placeobject_gripper_span.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->placeobject_gripper_span);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->placeobject_approach.deserialize(inbuffer + offset);
      offset += this->placeobject_place.deserialize(inbuffer + offset);
      offset += this->execution_actor_resting.deserialize(inbuffer + offset);
      uint32_t length_place_execution_actor;
      arrToVar(length_place_execution_actor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_place_execution_actor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_place_execution_actor-1]=0;
      this->place_execution_actor = (char *)(inbuffer + offset-1);
      offset += length_place_execution_actor;
      union {
        float real;
        uint32_t base;
      } u_placeobject_gripper_span;
      u_placeobject_gripper_span.base = 0;
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_placeobject_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->placeobject_gripper_span = u_placeobject_gripper_span.real;
      offset += sizeof(this->placeobject_gripper_span);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/DualArmPlaceParameters"; };
    virtual const char * getMD5() override { return "1c3188bacc391921e797d58c8996c99b"; };

  };

}
#endif
