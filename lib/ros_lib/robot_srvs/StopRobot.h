#ifndef _ROS_SERVICE_StopRobot_h
#define _ROS_SERVICE_StopRobot_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char STOPROBOT[] = "robot_srvs/StopRobot";

  class StopRobotRequest : public ros::Msg
  {
    public:
      typedef bool _isHardStop_type;
      _isHardStop_type isHardStop;

    StopRobotRequest():
      isHardStop(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isHardStop;
      u_isHardStop.real = this->isHardStop;
      *(outbuffer + offset + 0) = (u_isHardStop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isHardStop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isHardStop;
      u_isHardStop.base = 0;
      u_isHardStop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isHardStop = u_isHardStop.real;
      offset += sizeof(this->isHardStop);
     return offset;
    }

    virtual const char * getType() override { return STOPROBOT; };
    virtual const char * getMD5() override { return "00115be3906b0e95b40c8310e984b898"; };

  };

  class StopRobotResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    StopRobotResponse():
      res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.real = this->res;
      *(outbuffer + offset + 0) = (u_res.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.base = 0;
      u_res.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->res = u_res.real;
      offset += sizeof(this->res);
     return offset;
    }

    virtual const char * getType() override { return STOPROBOT; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class StopRobot {
    public:
    typedef StopRobotRequest Request;
    typedef StopRobotResponse Response;
  };

}
#endif
