#ifndef _ROS_process_im_msgs_Process_h
#define _ROS_process_im_msgs_Process_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/Info.h"
#include "process_im_msgs/Task.h"

namespace process_im_msgs
{

  class Process : public ros::Msg
  {
    public:
      typedef process_im_msgs::Info _info_type;
      _info_type info;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef const char* _process_type_type;
      _process_type_type process_type;
      uint32_t process_tasks_length;
      typedef process_im_msgs::Task _process_tasks_type;
      _process_tasks_type st_process_tasks;
      _process_tasks_type * process_tasks;
      typedef const char* _workcell_name_type;
      _workcell_name_type workcell_name;
      typedef const char* _workcell_uri_type;
      _workcell_uri_type workcell_uri;

    Process():
      info(),
      uuid(""),
      process_type(""),
      process_tasks_length(0), st_process_tasks(), process_tasks(nullptr),
      workcell_name(""),
      workcell_uri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      uint32_t length_uuid = strlen(this->uuid);
      varToArr(outbuffer + offset, length_uuid);
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_uuid);
      offset += length_uuid;
      uint32_t length_process_type = strlen(this->process_type);
      varToArr(outbuffer + offset, length_process_type);
      offset += 4;
      memcpy(outbuffer + offset, this->process_type, length_process_type);
      offset += length_process_type;
      *(outbuffer + offset + 0) = (this->process_tasks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->process_tasks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->process_tasks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->process_tasks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->process_tasks_length);
      for( uint32_t i = 0; i < process_tasks_length; i++){
      offset += this->process_tasks[i].serialize(outbuffer + offset);
      }
      uint32_t length_workcell_name = strlen(this->workcell_name);
      varToArr(outbuffer + offset, length_workcell_name);
      offset += 4;
      memcpy(outbuffer + offset, this->workcell_name, length_workcell_name);
      offset += length_workcell_name;
      uint32_t length_workcell_uri = strlen(this->workcell_uri);
      varToArr(outbuffer + offset, length_workcell_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcell_uri, length_workcell_uri);
      offset += length_workcell_uri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
      uint32_t length_uuid;
      arrToVar(length_uuid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uuid-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_uuid;
      uint32_t length_process_type;
      arrToVar(length_process_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_process_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_process_type-1]=0;
      this->process_type = (char *)(inbuffer + offset-1);
      offset += length_process_type;
      uint32_t process_tasks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      process_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      process_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      process_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->process_tasks_length);
      if(process_tasks_lengthT > process_tasks_length)
        this->process_tasks = (process_im_msgs::Task*)realloc(this->process_tasks, process_tasks_lengthT * sizeof(process_im_msgs::Task));
      process_tasks_length = process_tasks_lengthT;
      for( uint32_t i = 0; i < process_tasks_length; i++){
      offset += this->st_process_tasks.deserialize(inbuffer + offset);
        memcpy( &(this->process_tasks[i]), &(this->st_process_tasks), sizeof(process_im_msgs::Task));
      }
      uint32_t length_workcell_name;
      arrToVar(length_workcell_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcell_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcell_name-1]=0;
      this->workcell_name = (char *)(inbuffer + offset-1);
      offset += length_workcell_name;
      uint32_t length_workcell_uri;
      arrToVar(length_workcell_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcell_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcell_uri-1]=0;
      this->workcell_uri = (char *)(inbuffer + offset-1);
      offset += length_workcell_uri;
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/Process"; };
    virtual const char * getMD5() override { return "621b9d0da406db4bf9a1ba4e7e61924c"; };

  };

}
#endif
