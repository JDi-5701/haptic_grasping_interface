#ifndef _ROS_control_core_msgs_JointStateTrajectory_h
#define _ROS_control_core_msgs_JointStateTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "control_core_msgs/JointState.h"

namespace control_core_msgs
{

  class JointStateTrajectory : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t time_length;
      typedef float _time_type;
      _time_type st_time;
      _time_type * time;
      uint32_t trajectory_length;
      typedef control_core_msgs::JointState _trajectory_type;
      _trajectory_type st_trajectory;
      _trajectory_type * trajectory;

    JointStateTrajectory():
      header(),
      time_length(0), st_time(), time(nullptr),
      trajectory_length(0), st_trajectory(), trajectory(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_length);
      for( uint32_t i = 0; i < time_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->time[i]);
      }
      *(outbuffer + offset + 0) = (this->trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_length);
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_length);
      if(time_lengthT > time_length)
        this->time = (float*)realloc(this->time, time_lengthT * sizeof(float));
      time_length = time_lengthT;
      for( uint32_t i = 0; i < time_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_time));
        memcpy( &(this->time[i]), &(this->st_time), sizeof(float));
      }
      uint32_t trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectory_length);
      if(trajectory_lengthT > trajectory_length)
        this->trajectory = (control_core_msgs::JointState*)realloc(this->trajectory, trajectory_lengthT * sizeof(control_core_msgs::JointState));
      trajectory_length = trajectory_lengthT;
      for( uint32_t i = 0; i < trajectory_length; i++){
      offset += this->st_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->trajectory[i]), &(this->st_trajectory), sizeof(control_core_msgs::JointState));
      }
     return offset;
    }

    virtual const char * getType() override { return "control_core_msgs/JointStateTrajectory"; };
    virtual const char * getMD5() override { return "69542ed61bf7f38b53358b0a171b499f"; };

  };

}
#endif
