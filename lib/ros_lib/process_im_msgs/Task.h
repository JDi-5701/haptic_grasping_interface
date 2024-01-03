#ifndef _ROS_process_im_msgs_Task_h
#define _ROS_process_im_msgs_Task_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/Info.h"
#include "process_im_msgs/PreCond.h"
#include "process_im_msgs/SubTask.h"
#include "process_im_msgs/PostCond.h"

namespace process_im_msgs
{

  class Task : public ros::Msg
  {
    public:
      typedef process_im_msgs::Info _info_type;
      _info_type info;
      typedef const char* _uuid_type;
      _uuid_type uuid;
      typedef int32_t _task_type_type;
      _task_type_type task_type;
      typedef const char* _task_subject_type;
      _task_subject_type task_subject;
      typedef const char* _task_object_type;
      _task_object_type task_object;
      uint32_t task_performers_length;
      typedef char* _task_performers_type;
      _task_performers_type st_task_performers;
      _task_performers_type * task_performers;
      typedef const char* _task_performer_type;
      _task_performer_type task_performer;
      typedef const char* _task_tool_type;
      _task_tool_type task_tool;
      uint32_t task_pre_conds_length;
      typedef process_im_msgs::PreCond _task_pre_conds_type;
      _task_pre_conds_type st_task_pre_conds;
      _task_pre_conds_type * task_pre_conds;
      uint32_t sub_tasks_length;
      typedef process_im_msgs::SubTask _sub_tasks_type;
      _sub_tasks_type st_sub_tasks;
      _sub_tasks_type * sub_tasks;
      uint32_t task_post_conds_length;
      typedef process_im_msgs::PostCond _task_post_conds_type;
      _task_post_conds_type st_task_post_conds;
      _task_post_conds_type * task_post_conds;
      typedef int32_t _task_repeat_cycles_type;
      _task_repeat_cycles_type task_repeat_cycles;

    Task():
      info(),
      uuid(""),
      task_type(0),
      task_subject(""),
      task_object(""),
      task_performers_length(0), st_task_performers(), task_performers(nullptr),
      task_performer(""),
      task_tool(""),
      task_pre_conds_length(0), st_task_pre_conds(), task_pre_conds(nullptr),
      sub_tasks_length(0), st_sub_tasks(), sub_tasks(nullptr),
      task_post_conds_length(0), st_task_post_conds(), task_post_conds(nullptr),
      task_repeat_cycles(0)
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
      } u_task_type;
      u_task_type.real = this->task_type;
      *(outbuffer + offset + 0) = (u_task_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_task_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_task_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_task_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_type);
      uint32_t length_task_subject = strlen(this->task_subject);
      varToArr(outbuffer + offset, length_task_subject);
      offset += 4;
      memcpy(outbuffer + offset, this->task_subject, length_task_subject);
      offset += length_task_subject;
      uint32_t length_task_object = strlen(this->task_object);
      varToArr(outbuffer + offset, length_task_object);
      offset += 4;
      memcpy(outbuffer + offset, this->task_object, length_task_object);
      offset += length_task_object;
      *(outbuffer + offset + 0) = (this->task_performers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->task_performers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->task_performers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->task_performers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_performers_length);
      for( uint32_t i = 0; i < task_performers_length; i++){
      uint32_t length_task_performersi = strlen(this->task_performers[i]);
      varToArr(outbuffer + offset, length_task_performersi);
      offset += 4;
      memcpy(outbuffer + offset, this->task_performers[i], length_task_performersi);
      offset += length_task_performersi;
      }
      uint32_t length_task_performer = strlen(this->task_performer);
      varToArr(outbuffer + offset, length_task_performer);
      offset += 4;
      memcpy(outbuffer + offset, this->task_performer, length_task_performer);
      offset += length_task_performer;
      uint32_t length_task_tool = strlen(this->task_tool);
      varToArr(outbuffer + offset, length_task_tool);
      offset += 4;
      memcpy(outbuffer + offset, this->task_tool, length_task_tool);
      offset += length_task_tool;
      *(outbuffer + offset + 0) = (this->task_pre_conds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->task_pre_conds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->task_pre_conds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->task_pre_conds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_pre_conds_length);
      for( uint32_t i = 0; i < task_pre_conds_length; i++){
      offset += this->task_pre_conds[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->sub_tasks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sub_tasks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sub_tasks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sub_tasks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_tasks_length);
      for( uint32_t i = 0; i < sub_tasks_length; i++){
      offset += this->sub_tasks[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->task_post_conds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->task_post_conds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->task_post_conds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->task_post_conds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_post_conds_length);
      for( uint32_t i = 0; i < task_post_conds_length; i++){
      offset += this->task_post_conds[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_task_repeat_cycles;
      u_task_repeat_cycles.real = this->task_repeat_cycles;
      *(outbuffer + offset + 0) = (u_task_repeat_cycles.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_task_repeat_cycles.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_task_repeat_cycles.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_task_repeat_cycles.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_repeat_cycles);
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
      } u_task_type;
      u_task_type.base = 0;
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_task_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->task_type = u_task_type.real;
      offset += sizeof(this->task_type);
      uint32_t length_task_subject;
      arrToVar(length_task_subject, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_subject; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_subject-1]=0;
      this->task_subject = (char *)(inbuffer + offset-1);
      offset += length_task_subject;
      uint32_t length_task_object;
      arrToVar(length_task_object, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_object-1]=0;
      this->task_object = (char *)(inbuffer + offset-1);
      offset += length_task_object;
      uint32_t task_performers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      task_performers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->task_performers_length);
      if(task_performers_lengthT > task_performers_length)
        this->task_performers = (char**)realloc(this->task_performers, task_performers_lengthT * sizeof(char*));
      task_performers_length = task_performers_lengthT;
      for( uint32_t i = 0; i < task_performers_length; i++){
      uint32_t length_st_task_performers;
      arrToVar(length_st_task_performers, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_task_performers; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_task_performers-1]=0;
      this->st_task_performers = (char *)(inbuffer + offset-1);
      offset += length_st_task_performers;
        memcpy( &(this->task_performers[i]), &(this->st_task_performers), sizeof(char*));
      }
      uint32_t length_task_performer;
      arrToVar(length_task_performer, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_performer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_performer-1]=0;
      this->task_performer = (char *)(inbuffer + offset-1);
      offset += length_task_performer;
      uint32_t length_task_tool;
      arrToVar(length_task_tool, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_tool; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_tool-1]=0;
      this->task_tool = (char *)(inbuffer + offset-1);
      offset += length_task_tool;
      uint32_t task_pre_conds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      task_pre_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      task_pre_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      task_pre_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->task_pre_conds_length);
      if(task_pre_conds_lengthT > task_pre_conds_length)
        this->task_pre_conds = (process_im_msgs::PreCond*)realloc(this->task_pre_conds, task_pre_conds_lengthT * sizeof(process_im_msgs::PreCond));
      task_pre_conds_length = task_pre_conds_lengthT;
      for( uint32_t i = 0; i < task_pre_conds_length; i++){
      offset += this->st_task_pre_conds.deserialize(inbuffer + offset);
        memcpy( &(this->task_pre_conds[i]), &(this->st_task_pre_conds), sizeof(process_im_msgs::PreCond));
      }
      uint32_t sub_tasks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sub_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sub_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sub_tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sub_tasks_length);
      if(sub_tasks_lengthT > sub_tasks_length)
        this->sub_tasks = (process_im_msgs::SubTask*)realloc(this->sub_tasks, sub_tasks_lengthT * sizeof(process_im_msgs::SubTask));
      sub_tasks_length = sub_tasks_lengthT;
      for( uint32_t i = 0; i < sub_tasks_length; i++){
      offset += this->st_sub_tasks.deserialize(inbuffer + offset);
        memcpy( &(this->sub_tasks[i]), &(this->st_sub_tasks), sizeof(process_im_msgs::SubTask));
      }
      uint32_t task_post_conds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      task_post_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      task_post_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      task_post_conds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->task_post_conds_length);
      if(task_post_conds_lengthT > task_post_conds_length)
        this->task_post_conds = (process_im_msgs::PostCond*)realloc(this->task_post_conds, task_post_conds_lengthT * sizeof(process_im_msgs::PostCond));
      task_post_conds_length = task_post_conds_lengthT;
      for( uint32_t i = 0; i < task_post_conds_length; i++){
      offset += this->st_task_post_conds.deserialize(inbuffer + offset);
        memcpy( &(this->task_post_conds[i]), &(this->st_task_post_conds), sizeof(process_im_msgs::PostCond));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_task_repeat_cycles;
      u_task_repeat_cycles.base = 0;
      u_task_repeat_cycles.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_task_repeat_cycles.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_task_repeat_cycles.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_task_repeat_cycles.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->task_repeat_cycles = u_task_repeat_cycles.real;
      offset += sizeof(this->task_repeat_cycles);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/Task"; };
    virtual const char * getMD5() override { return "ab70832d2376991cfd77ac3cbd2d5838"; };

  };

}
#endif
