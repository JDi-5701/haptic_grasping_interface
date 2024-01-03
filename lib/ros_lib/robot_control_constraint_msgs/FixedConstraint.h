#ifndef _ROS_robot_control_constraint_msgs_FixedConstraint_h
#define _ROS_robot_control_constraint_msgs_FixedConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_control_constraint_msgs
{

  class FixedConstraint : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef int32_t _fixedPoseIndex_type;
      _fixedPoseIndex_type fixedPoseIndex;
      typedef int32_t _constrainedPoseIndex_type;
      _constrainedPoseIndex_type constrainedPoseIndex;

    FixedConstraint():
      id(""),
      fixedPoseIndex(0),
      constrainedPoseIndex(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        int32_t real;
        uint32_t base;
      } u_fixedPoseIndex;
      u_fixedPoseIndex.real = this->fixedPoseIndex;
      *(outbuffer + offset + 0) = (u_fixedPoseIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fixedPoseIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fixedPoseIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fixedPoseIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixedPoseIndex);
      union {
        int32_t real;
        uint32_t base;
      } u_constrainedPoseIndex;
      u_constrainedPoseIndex.real = this->constrainedPoseIndex;
      *(outbuffer + offset + 0) = (u_constrainedPoseIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_constrainedPoseIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_constrainedPoseIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_constrainedPoseIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->constrainedPoseIndex);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        int32_t real;
        uint32_t base;
      } u_fixedPoseIndex;
      u_fixedPoseIndex.base = 0;
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fixedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fixedPoseIndex = u_fixedPoseIndex.real;
      offset += sizeof(this->fixedPoseIndex);
      union {
        int32_t real;
        uint32_t base;
      } u_constrainedPoseIndex;
      u_constrainedPoseIndex.base = 0;
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_constrainedPoseIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->constrainedPoseIndex = u_constrainedPoseIndex.real;
      offset += sizeof(this->constrainedPoseIndex);
     return offset;
    }

    virtual const char * getType() override { return "robot_control_constraint_msgs/FixedConstraint"; };
    virtual const char * getMD5() override { return "eb0e456aa573b34593187b5694117a65"; };

  };

}
#endif
