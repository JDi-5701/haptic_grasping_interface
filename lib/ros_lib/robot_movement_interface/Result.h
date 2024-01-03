#ifndef _ROS_robot_movement_interface_Result_h
#define _ROS_robot_movement_interface_Result_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace robot_movement_interface
{

  class Result : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _command_id_type;
      _command_id_type command_id;
      typedef int32_t _result_code_type;
      _result_code_type result_code;
      typedef const char* _additional_information_type;
      _additional_information_type additional_information;

    Result():
      header(),
      command_id(0),
      result_code(0),
      additional_information("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->command_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->command_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->command_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->command_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command_id);
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.real = this->result_code;
      *(outbuffer + offset + 0) = (u_result_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result_code);
      uint32_t length_additional_information = strlen(this->additional_information);
      varToArr(outbuffer + offset, length_additional_information);
      offset += 4;
      memcpy(outbuffer + offset, this->additional_information, length_additional_information);
      offset += length_additional_information;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->command_id =  ((uint32_t) (*(inbuffer + offset)));
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->command_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->command_id);
      union {
        int32_t real;
        uint32_t base;
      } u_result_code;
      u_result_code.base = 0;
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result_code = u_result_code.real;
      offset += sizeof(this->result_code);
      uint32_t length_additional_information;
      arrToVar(length_additional_information, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_additional_information; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_additional_information-1]=0;
      this->additional_information = (char *)(inbuffer + offset-1);
      offset += length_additional_information;
     return offset;
    }

    virtual const char * getType() override { return "robot_movement_interface/Result"; };
    virtual const char * getMD5() override { return "aae92300fce82b1448d53532c9c1b997"; };

  };

}
#endif
