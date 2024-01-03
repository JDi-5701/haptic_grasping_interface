#ifndef _ROS_SERVICE_MoveTrajectory_h
#define _ROS_SERVICE_MoveTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace robot_srvs
{

static const char MOVETRAJECTORY[] = "robot_srvs/MoveTrajectory";

  class MoveTrajectoryRequest : public ros::Msg
  {
    public:
      uint32_t x_length;
      typedef geometry_msgs::Pose _x_type;
      _x_type st_x;
      _x_type * x;

    MoveTrajectoryRequest():
      x_length(0), st_x(), x(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_length);
      for( uint32_t i = 0; i < x_length; i++){
      offset += this->x[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->x_length);
      if(x_lengthT > x_length)
        this->x = (geometry_msgs::Pose*)realloc(this->x, x_lengthT * sizeof(geometry_msgs::Pose));
      x_length = x_lengthT;
      for( uint32_t i = 0; i < x_length; i++){
      offset += this->st_x.deserialize(inbuffer + offset);
        memcpy( &(this->x[i]), &(this->st_x), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    virtual const char * getType() override { return MOVETRAJECTORY; };
    virtual const char * getMD5() override { return "eaf2ffe9e6485660bcc4e8f8ec921fe9"; };

  };

  class MoveTrajectoryResponse : public ros::Msg
  {
    public:
      uint32_t q_length;
      typedef float _q_type;
      _q_type st_q;
      _q_type * q;

    MoveTrajectoryResponse():
      q_length(0), st_q(), q(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->q_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->q_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->q_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->q_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q_length);
      for( uint32_t i = 0; i < q_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t q_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      q_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      q_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      q_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->q_length);
      if(q_lengthT > q_length)
        this->q = (float*)realloc(this->q, q_lengthT * sizeof(float));
      q_length = q_lengthT;
      for( uint32_t i = 0; i < q_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_q));
        memcpy( &(this->q[i]), &(this->st_q), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return MOVETRAJECTORY; };
    virtual const char * getMD5() override { return "ab94b9bcaaa12f74def43e4b33992df1"; };

  };

  class MoveTrajectory {
    public:
    typedef MoveTrajectoryRequest Request;
    typedef MoveTrajectoryResponse Response;
  };

}
#endif
