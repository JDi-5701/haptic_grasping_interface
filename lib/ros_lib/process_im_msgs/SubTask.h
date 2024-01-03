#ifndef _ROS_process_im_msgs_SubTask_h
#define _ROS_process_im_msgs_SubTask_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/Info.h"

namespace process_im_msgs
{

  class SubTask : public ros::Msg
  {
    public:
      typedef process_im_msgs::Info _info_type;
      _info_type info;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef int32_t _sub_task_type_type;
      _sub_task_type_type sub_task_type;
      typedef const char* _sub_task_subject_type;
      _sub_task_subject_type sub_task_subject;
      typedef const char* _sub_task_object_type;
      _sub_task_object_type sub_task_object;
      uint32_t sub_task_performers_length;
      typedef char* _sub_task_performers_type;
      _sub_task_performers_type st_sub_task_performers;
      _sub_task_performers_type * sub_task_performers;

    SubTask():
      info(),
      uuid(""),
      sub_task_type(0),
      sub_task_subject(""),
      sub_task_object(""),
      sub_task_performers_length(0), st_sub_task_performers(), sub_task_performers(nullptr)
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
      union {
        int32_t real;
        uint32_t base;
      } u_sub_task_type;
      u_sub_task_type.real = this->sub_task_type;
      *(outbuffer + offset + 0) = (u_sub_task_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sub_task_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sub_task_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sub_task_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_task_type);
      uint32_t length_sub_task_subject = strlen(this->sub_task_subject);
      varToArr(outbuffer + offset, length_sub_task_subject);
      offset += 4;
      memcpy(outbuffer + offset, this->sub_task_subject, length_sub_task_subject);
      offset += length_sub_task_subject;
      uint32_t length_sub_task_object = strlen(this->sub_task_object);
      varToArr(outbuffer + offset, length_sub_task_object);
      offset += 4;
      memcpy(outbuffer + offset, this->sub_task_object, length_sub_task_object);
      offset += length_sub_task_object;
      *(outbuffer + offset + 0) = (this->sub_task_performers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_task_performers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_task_performers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_task_performers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_task_performers_length);
      for( uint32_t i = 0; i < sub_task_performers_length; i++){
      uint32_t length_sub_task_performersi = strlen(this->sub_task_performers[i]);
      varToArr(outbuffer + offset, length_sub_task_performersi);
      offset += 4;
      memcpy(outbuffer + offset, this->sub_task_performers[i], length_sub_task_performersi);
      offset += length_sub_task_performersi;
      }
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
      union {
        int32_t real;
        uint32_t base;
      } u_sub_task_type;
      u_sub_task_type.base = 0;
      u_sub_task_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sub_task_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sub_task_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sub_task_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sub_task_type = u_sub_task_type.real;
      offset += sizeof(this->sub_task_type);
      uint32_t length_sub_task_subject;
      arrToVar(length_sub_task_subject, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sub_task_subject; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sub_task_subject-1]=0;
      this->sub_task_subject = (char *)(inbuffer + offset-1);
      offset += length_sub_task_subject;
      uint32_t length_sub_task_object;
      arrToVar(length_sub_task_object, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sub_task_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sub_task_object-1]=0;
      this->sub_task_object = (char *)(inbuffer + offset-1);
      offset += length_sub_task_object;
      uint32_t sub_task_performers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sub_task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sub_task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sub_task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sub_task_performers_length);
      if(sub_task_performers_lengthT > sub_task_performers_length)
        this->sub_task_performers = (char**)realloc(this->sub_task_performers, sub_task_performers_lengthT * sizeof(char*));
      sub_task_performers_length = sub_task_performers_lengthT;
      for( uint32_t i = 0; i < sub_task_performers_length; i++){
      uint32_t length_st_sub_task_performers;
      arrToVar(length_st_sub_task_performers, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_sub_task_performers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_sub_task_performers-1]=0;
      this->st_sub_task_performers = (char *)(inbuffer + offset-1);
      offset += length_st_sub_task_performers;
        memcpy( &(this->sub_task_performers[i]), &(this->st_sub_task_performers), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/SubTask"; };
    virtual const char * getMD5() override { return "5852ca3e5bae2365b558c16169746208"; };

  };

}
#endif
