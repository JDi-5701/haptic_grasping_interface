#ifndef _ROS_SERVICE_SetTool_h
#define _ROS_SERVICE_SetTool_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char SETTOOL[] = "robot_srvs/SetTool";

  class SetToolRequest : public ros::Msg
  {
    public:
      typedef const char* _toolSemanticName_type;
      _toolSemanticName_type toolSemanticName;
      typedef int32_t _taskType_type;
      _taskType_type taskType;

    SetToolRequest():
      toolSemanticName(""),
      taskType(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_toolSemanticName = strlen(this->toolSemanticName);
      varToArr(outbuffer + offset, length_toolSemanticName);
      offset += 4;
      memcpy(outbuffer + offset, this->toolSemanticName, length_toolSemanticName);
      offset += length_toolSemanticName;
      union {
        int32_t real;
        uint32_t base;
      } u_taskType;
      u_taskType.real = this->taskType;
      *(outbuffer + offset + 0) = (u_taskType.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_taskType.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_taskType.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_taskType.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->taskType);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_toolSemanticName;
      arrToVar(length_toolSemanticName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_toolSemanticName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_toolSemanticName-1]=0;
      this->toolSemanticName = (char *)(inbuffer + offset-1);
      offset += length_toolSemanticName;
      union {
        int32_t real;
        uint32_t base;
      } u_taskType;
      u_taskType.base = 0;
      u_taskType.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_taskType.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_taskType.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_taskType.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->taskType = u_taskType.real;
      offset += sizeof(this->taskType);
     return offset;
    }

    virtual const char * getType() override { return SETTOOL; };
    virtual const char * getMD5() override { return "d83b0fffc3cc572f835e9d75a8917147"; };

  };

  class SetToolResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    SetToolResponse():
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

    virtual const char * getType() override { return SETTOOL; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class SetTool {
    public:
    typedef SetToolRequest Request;
    typedef SetToolResponse Response;
  };

}
#endif
