#ifndef _ROS_robot_movement_interface_CommandList_h
#define _ROS_robot_movement_interface_CommandList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "robot_movement_interface/Command.h"

namespace robot_movement_interface
{

  class CommandList : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t commands_length;
      typedef robot_movement_interface::Command _commands_type;
      _commands_type st_commands;
      _commands_type * commands;
      typedef bool _replace_previous_commands_type;
      _replace_previous_commands_type replace_previous_commands;

    CommandList():
      header(),
      commands_length(0), st_commands(), commands(nullptr),
      replace_previous_commands(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->commands_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->commands_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->commands_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->commands_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->commands_length);
      for( uint32_t i = 0; i < commands_length; i++){
      offset += this->commands[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_replace_previous_commands;
      u_replace_previous_commands.real = this->replace_previous_commands;
      *(outbuffer + offset + 0) = (u_replace_previous_commands.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->replace_previous_commands);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t commands_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      commands_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      commands_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      commands_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->commands_length);
      if(commands_lengthT > commands_length)
        this->commands = (robot_movement_interface::Command*)realloc(this->commands, commands_lengthT * sizeof(robot_movement_interface::Command));
      commands_length = commands_lengthT;
      for( uint32_t i = 0; i < commands_length; i++){
      offset += this->st_commands.deserialize(inbuffer + offset);
        memcpy( &(this->commands[i]), &(this->st_commands), sizeof(robot_movement_interface::Command));
      }
      union {
        bool real;
        uint8_t base;
      } u_replace_previous_commands;
      u_replace_previous_commands.base = 0;
      u_replace_previous_commands.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->replace_previous_commands = u_replace_previous_commands.real;
      offset += sizeof(this->replace_previous_commands);
     return offset;
    }

    virtual const char * getType() override { return "robot_movement_interface/CommandList"; };
    virtual const char * getMD5() override { return "5be507b3fe31c4653b720f97b4aeab6a"; };

  };

}
#endif
