#ifndef _ROS_SERVICE_MoveJoints_h
#define _ROS_SERVICE_MoveJoints_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char MOVEJOINTS[] = "robot_srvs/MoveJoints";

  class MoveJointsRequest : public ros::Msg
  {
    public:
      typedef float _q0_type;
      _q0_type q0;
      typedef float _q1_type;
      _q1_type q1;
      typedef float _q2_type;
      _q2_type q2;
      typedef float _q3_type;
      _q3_type q3;
      typedef float _q4_type;
      _q4_type q4;
      typedef float _q5_type;
      _q5_type q5;

    MoveJointsRequest():
      q0(0),
      q1(0),
      q2(0),
      q3(0),
      q4(0),
      q5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->q0);
      offset += serializeAvrFloat64(outbuffer + offset, this->q1);
      offset += serializeAvrFloat64(outbuffer + offset, this->q2);
      offset += serializeAvrFloat64(outbuffer + offset, this->q3);
      offset += serializeAvrFloat64(outbuffer + offset, this->q4);
      offset += serializeAvrFloat64(outbuffer + offset, this->q5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q4));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q5));
     return offset;
    }

    virtual const char * getType() override { return MOVEJOINTS; };
    virtual const char * getMD5() override { return "1ca490ad8fc43e626be96bfdb57d8049"; };

  };

  class MoveJointsResponse : public ros::Msg
  {
    public:
      typedef float _q0_res_type;
      _q0_res_type q0_res;
      typedef float _q1_res_type;
      _q1_res_type q1_res;
      typedef float _q2_res_type;
      _q2_res_type q2_res;
      typedef float _q3_res_type;
      _q3_res_type q3_res;
      typedef float _q4_res_type;
      _q4_res_type q4_res;
      typedef float _q5_res_type;
      _q5_res_type q5_res;

    MoveJointsResponse():
      q0_res(0),
      q1_res(0),
      q2_res(0),
      q3_res(0),
      q4_res(0),
      q5_res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->q0_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->q1_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->q2_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->q3_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->q4_res);
      offset += serializeAvrFloat64(outbuffer + offset, this->q5_res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q0_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q1_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q2_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q3_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q4_res));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->q5_res));
     return offset;
    }

    virtual const char * getType() override { return MOVEJOINTS; };
    virtual const char * getMD5() override { return "9578b7fdd329cc35102c42084525e19c"; };

  };

  class MoveJoints {
    public:
    typedef MoveJointsRequest Request;
    typedef MoveJointsResponse Response;
  };

}
#endif
