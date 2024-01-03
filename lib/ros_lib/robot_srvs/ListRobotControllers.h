#ifndef _ROS_SERVICE_ListRobotControllers_h
#define _ROS_SERVICE_ListRobotControllers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char LISTROBOTCONTROLLERS[] = "robot_srvs/ListRobotControllers";

  class ListRobotControllersRequest : public ros::Msg
  {
    public:

    ListRobotControllersRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return LISTROBOTCONTROLLERS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListRobotControllersResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      uint32_t robotIris_length;
      typedef char* _robotIris_type;
      _robotIris_type st_robotIris;
      _robotIris_type * robotIris;
      uint32_t robotNameTags_length;
      typedef char* _robotNameTags_type;
      _robotNameTags_type st_robotNameTags;
      _robotNameTags_type * robotNameTags;

    ListRobotControllersResponse():
      success(0),
      robotIris_length(0), st_robotIris(), robotIris(nullptr),
      robotNameTags_length(0), st_robotNameTags(), robotNameTags(nullptr)
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
      *(outbuffer + offset + 0) = (this->robotIris_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robotIris_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robotIris_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robotIris_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robotIris_length);
      for( uint32_t i = 0; i < robotIris_length; i++){
      uint32_t length_robotIrisi = strlen(this->robotIris[i]);
      varToArr(outbuffer + offset, length_robotIrisi);
      offset += 4;
      memcpy(outbuffer + offset, this->robotIris[i], length_robotIrisi);
      offset += length_robotIrisi;
      }
      *(outbuffer + offset + 0) = (this->robotNameTags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robotNameTags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robotNameTags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robotNameTags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robotNameTags_length);
      for( uint32_t i = 0; i < robotNameTags_length; i++){
      uint32_t length_robotNameTagsi = strlen(this->robotNameTags[i]);
      varToArr(outbuffer + offset, length_robotNameTagsi);
      offset += 4;
      memcpy(outbuffer + offset, this->robotNameTags[i], length_robotNameTagsi);
      offset += length_robotNameTagsi;
      }
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
      uint32_t robotIris_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robotIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robotIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robotIris_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robotIris_length);
      if(robotIris_lengthT > robotIris_length)
        this->robotIris = (char**)realloc(this->robotIris, robotIris_lengthT * sizeof(char*));
      robotIris_length = robotIris_lengthT;
      for( uint32_t i = 0; i < robotIris_length; i++){
      uint32_t length_st_robotIris;
      arrToVar(length_st_robotIris, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_robotIris; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_robotIris-1]=0;
      this->st_robotIris = (char *)(inbuffer + offset-1);
      offset += length_st_robotIris;
        memcpy( &(this->robotIris[i]), &(this->st_robotIris), sizeof(char*));
      }
      uint32_t robotNameTags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robotNameTags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robotNameTags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robotNameTags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robotNameTags_length);
      if(robotNameTags_lengthT > robotNameTags_length)
        this->robotNameTags = (char**)realloc(this->robotNameTags, robotNameTags_lengthT * sizeof(char*));
      robotNameTags_length = robotNameTags_lengthT;
      for( uint32_t i = 0; i < robotNameTags_length; i++){
      uint32_t length_st_robotNameTags;
      arrToVar(length_st_robotNameTags, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_robotNameTags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_robotNameTags-1]=0;
      this->st_robotNameTags = (char *)(inbuffer + offset-1);
      offset += length_st_robotNameTags;
        memcpy( &(this->robotNameTags[i]), &(this->st_robotNameTags), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return LISTROBOTCONTROLLERS; };
    virtual const char * getMD5() override { return "0be14b342ec3e7bbf63f3d91ca0d4906"; };

  };

  class ListRobotControllers {
    public:
    typedef ListRobotControllersRequest Request;
    typedef ListRobotControllersResponse Response;
  };

}
#endif
