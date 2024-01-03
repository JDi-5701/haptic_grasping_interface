#ifndef _ROS_device_msgs_Status_h
#define _ROS_device_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace device_msgs
{

  class Status : public ros::Msg
  {
    public:
      typedef const char* _deviceName_type;
      _deviceName_type deviceName;
      typedef int32_t _mode_type;
      _mode_type mode;
      typedef int32_t _action_type;
      _action_type action;
      typedef const char* _actionIdentifier_type;
      _actionIdentifier_type actionIdentifier;
      typedef int32_t _result_type;
      _result_type result;
      typedef const char* _timeStamp_type;
      _timeStamp_type timeStamp;

    Status():
      deviceName(""),
      mode(0),
      action(0),
      actionIdentifier(""),
      result(0),
      timeStamp("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_deviceName = strlen(this->deviceName);
      varToArr(outbuffer + offset, length_deviceName);
      offset += 4;
      memcpy(outbuffer + offset, this->deviceName, length_deviceName);
      offset += length_deviceName;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_actionIdentifier = strlen(this->actionIdentifier);
      varToArr(outbuffer + offset, length_actionIdentifier);
      offset += 4;
      memcpy(outbuffer + offset, this->actionIdentifier, length_actionIdentifier);
      offset += length_actionIdentifier;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result);
      uint32_t length_timeStamp = strlen(this->timeStamp);
      varToArr(outbuffer + offset, length_timeStamp);
      offset += 4;
      memcpy(outbuffer + offset, this->timeStamp, length_timeStamp);
      offset += length_timeStamp;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_deviceName;
      arrToVar(length_deviceName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_deviceName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_deviceName-1]=0;
      this->deviceName = (char *)(inbuffer + offset-1);
      offset += length_deviceName;
      union {
        int32_t real;
        uint32_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_actionIdentifier;
      arrToVar(length_actionIdentifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_actionIdentifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_actionIdentifier-1]=0;
      this->actionIdentifier = (char *)(inbuffer + offset-1);
      offset += length_actionIdentifier;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result = u_result.real;
      offset += sizeof(this->result);
      uint32_t length_timeStamp;
      arrToVar(length_timeStamp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_timeStamp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_timeStamp-1]=0;
      this->timeStamp = (char *)(inbuffer + offset-1);
      offset += length_timeStamp;
     return offset;
    }

    virtual const char * getType() override { return "device_msgs/Status"; };
    virtual const char * getMD5() override { return "58f4ef410d11b4029bfa14d919c14d93"; };

  };

}
#endif
