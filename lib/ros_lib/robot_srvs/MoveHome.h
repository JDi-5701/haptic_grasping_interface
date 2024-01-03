#ifndef _ROS_SERVICE_MoveHome_h
#define _ROS_SERVICE_MoveHome_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_msgs/Pose.h"

namespace robot_srvs
{

static const char MOVEHOME[] = "robot_srvs/MoveHome";

  class MoveHomeRequest : public ros::Msg
  {
    public:
      typedef robot_msgs::Pose _x_type;
      _x_type x;

    MoveHomeRequest():
      x()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->x.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->x.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return MOVEHOME; };
    virtual const char * getMD5() override { return "38512c179ff1fb90b3252c238936db6d"; };

  };

  class MoveHomeResponse : public ros::Msg
  {
    public:
      uint32_t q_length;
      typedef float _q_type;
      _q_type st_q;
      _q_type * q;

    MoveHomeResponse():
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

    virtual const char * getType() override { return MOVEHOME; };
    virtual const char * getMD5() override { return "ab94b9bcaaa12f74def43e4b33992df1"; };

  };

  class MoveHome {
    public:
    typedef MoveHomeRequest Request;
    typedef MoveHomeResponse Response;
  };

}
#endif
