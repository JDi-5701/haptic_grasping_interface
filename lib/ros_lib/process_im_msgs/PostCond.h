#ifndef _ROS_process_im_msgs_PostCond_h
#define _ROS_process_im_msgs_PostCond_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_im_msgs
{

  class PostCond : public ros::Msg
  {
    public:
      typedef const char* _predicate_type;
      _predicate_type predicate;
      typedef const char* _subject_type;
      _subject_type subject;
      typedef const char* _object_type;
      _object_type object;
      typedef bool _satisfied_type;
      _satisfied_type satisfied;

    PostCond():
      predicate(""),
      subject(""),
      object(""),
      satisfied(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_predicate = strlen(this->predicate);
      varToArr(outbuffer + offset, length_predicate);
      offset += 4;
      memcpy(outbuffer + offset, this->predicate, length_predicate);
      offset += length_predicate;
      uint32_t length_subject = strlen(this->subject);
      varToArr(outbuffer + offset, length_subject);
      offset += 4;
      memcpy(outbuffer + offset, this->subject, length_subject);
      offset += length_subject;
      uint32_t length_object = strlen(this->object);
      varToArr(outbuffer + offset, length_object);
      offset += 4;
      memcpy(outbuffer + offset, this->object, length_object);
      offset += length_object;
      union {
        bool real;
        uint8_t base;
      } u_satisfied;
      u_satisfied.real = this->satisfied;
      *(outbuffer + offset + 0) = (u_satisfied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->satisfied);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_predicate;
      arrToVar(length_predicate, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_predicate; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_predicate-1]=0;
      this->predicate = (char *)(inbuffer + offset-1);
      offset += length_predicate;
      uint32_t length_subject;
      arrToVar(length_subject, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subject; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subject-1]=0;
      this->subject = (char *)(inbuffer + offset-1);
      offset += length_subject;
      uint32_t length_object;
      arrToVar(length_object, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object-1]=0;
      this->object = (char *)(inbuffer + offset-1);
      offset += length_object;
      union {
        bool real;
        uint8_t base;
      } u_satisfied;
      u_satisfied.base = 0;
      u_satisfied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->satisfied = u_satisfied.real;
      offset += sizeof(this->satisfied);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/PostCond"; };
    virtual const char * getMD5() override { return "9aec8ff56284e0d7ad7e937dc8bb3134"; };

  };

}
#endif
