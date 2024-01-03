#ifndef _ROS_SERVICE_MoveConfiguration_h
#define _ROS_SERVICE_MoveConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char MOVECONFIGURATION[] = "robot_srvs/MoveConfiguration";

  class MoveConfigurationRequest : public ros::Msg
  {
    public:
      uint32_t q_length;
      typedef float _q_type;
      _q_type st_q;
      _q_type * q;

    MoveConfigurationRequest():
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

    virtual const char * getType() override { return MOVECONFIGURATION; };
    virtual const char * getMD5() override { return "ab94b9bcaaa12f74def43e4b33992df1"; };

  };

  class MoveConfigurationResponse : public ros::Msg
  {
    public:
      uint32_t q_length;
      typedef float _q_type;
      _q_type st_q;
      _q_type * q;

    MoveConfigurationResponse():
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

    virtual const char * getType() override { return MOVECONFIGURATION; };
    virtual const char * getMD5() override { return "ab94b9bcaaa12f74def43e4b33992df1"; };

  };

  class MoveConfiguration {
    public:
    typedef MoveConfigurationRequest Request;
    typedef MoveConfigurationResponse Response;
  };

}
#endif
