#ifndef _ROS_SERVICE_GetRobotControllerNameTag_h
#define _ROS_SERVICE_GetRobotControllerNameTag_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char GETROBOTCONTROLLERNAMETAG[] = "robot_srvs/GetRobotControllerNameTag";

  class GetRobotControllerNameTagRequest : public ros::Msg
  {
    public:
      typedef const char* _robotName_type;
      _robotName_type robotName;

    GetRobotControllerNameTagRequest():
      robotName("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_robotName = strlen(this->robotName);
      varToArr(outbuffer + offset, length_robotName);
      offset += 4;
      memcpy(outbuffer + offset, this->robotName, length_robotName);
      offset += length_robotName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_robotName;
      arrToVar(length_robotName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robotName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robotName-1]=0;
      this->robotName = (char *)(inbuffer + offset-1);
      offset += length_robotName;
     return offset;
    }

    virtual const char * getType() override { return GETROBOTCONTROLLERNAMETAG; };
    virtual const char * getMD5() override { return "0e4ce7af4736710e228ed1cbe6f009e7"; };

  };

  class GetRobotControllerNameTagResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _robotNameTag_type;
      _robotNameTag_type robotNameTag;

    GetRobotControllerNameTagResponse():
      success(0),
      robotNameTag("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_robotNameTag = strlen(this->robotNameTag);
      varToArr(outbuffer + offset, length_robotNameTag);
      offset += 4;
      memcpy(outbuffer + offset, this->robotNameTag, length_robotNameTag);
      offset += length_robotNameTag;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_robotNameTag;
      arrToVar(length_robotNameTag, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robotNameTag; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robotNameTag-1]=0;
      this->robotNameTag = (char *)(inbuffer + offset-1);
      offset += length_robotNameTag;
     return offset;
    }

    virtual const char * getType() override { return GETROBOTCONTROLLERNAMETAG; };
    virtual const char * getMD5() override { return "d01d7dc6f9a1a048f109d7b8c2098adb"; };

  };

  class GetRobotControllerNameTag {
    public:
    typedef GetRobotControllerNameTagRequest Request;
    typedef GetRobotControllerNameTagResponse Response;
  };

}
#endif
