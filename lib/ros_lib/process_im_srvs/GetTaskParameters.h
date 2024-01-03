#ifndef _ROS_SERVICE_GetTaskParameters_h
#define _ROS_SERVICE_GetTaskParameters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/TaskRequestParameters.h"
#include "process_im_msgs/TaskParameters.h"

namespace process_im_srvs
{

static const char GETTASKPARAMETERS[] = "process_im_srvs/GetTaskParameters";

  class GetTaskParametersRequest : public ros::Msg
  {
    public:
      typedef int32_t _task_type_type;
      _task_type_type task_type;
      typedef const char* _subject_name_type;
      _subject_name_type subject_name;
      typedef const char* _object_name_type;
      _object_name_type object_name;
      typedef const char* _subject_tool_name_type;
      _subject_tool_name_type subject_tool_name;
      typedef const char* _object_tool_name_type;
      _object_tool_name_type object_tool_name;
      uint32_t execution_actors_length;
      typedef char* _execution_actors_type;
      _execution_actors_type st_execution_actors;
      _execution_actors_type * execution_actors;
      typedef const char* _workcell_uri_type;
      _workcell_uri_type workcell_uri;
      typedef process_im_msgs::TaskRequestParameters _requestParameters_type;
      _requestParameters_type requestParameters;
      typedef const char* _taskIri_type;
      _taskIri_type taskIri;

    GetTaskParametersRequest():
      task_type(0),
      subject_name(""),
      object_name(""),
      subject_tool_name(""),
      object_tool_name(""),
      execution_actors_length(0), st_execution_actors(), execution_actors(nullptr),
      workcell_uri(""),
      requestParameters(),
      taskIri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      uint32_t length_subject_name = strlen(this->subject_name);
      varToArr(outbuffer + offset, length_subject_name);
      offset += 4;
      memcpy(outbuffer + offset, this->subject_name, length_subject_name);
      offset += length_subject_name;
      uint32_t length_object_name = strlen(this->object_name);
      varToArr(outbuffer + offset, length_object_name);
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      uint32_t length_subject_tool_name = strlen(this->subject_tool_name);
      varToArr(outbuffer + offset, length_subject_tool_name);
      offset += 4;
      memcpy(outbuffer + offset, this->subject_tool_name, length_subject_tool_name);
      offset += length_subject_tool_name;
      uint32_t length_object_tool_name = strlen(this->object_tool_name);
      varToArr(outbuffer + offset, length_object_tool_name);
      offset += 4;
      memcpy(outbuffer + offset, this->object_tool_name, length_object_tool_name);
      offset += length_object_tool_name;
      *(outbuffer + offset + 0) = (this->execution_actors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->execution_actors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->execution_actors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->execution_actors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->execution_actors_length);
      for( uint32_t i = 0; i < execution_actors_length; i++){
      uint32_t length_execution_actorsi = strlen(this->execution_actors[i]);
      varToArr(outbuffer + offset, length_execution_actorsi);
      offset += 4;
      memcpy(outbuffer + offset, this->execution_actors[i], length_execution_actorsi);
      offset += length_execution_actorsi;
      }
      uint32_t length_workcell_uri = strlen(this->workcell_uri);
      varToArr(outbuffer + offset, length_workcell_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcell_uri, length_workcell_uri);
      offset += length_workcell_uri;
      offset += this->requestParameters.serialize(outbuffer + offset);
      uint32_t length_taskIri = strlen(this->taskIri);
      varToArr(outbuffer + offset, length_taskIri);
      offset += 4;
      memcpy(outbuffer + offset, this->taskIri, length_taskIri);
      offset += length_taskIri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      uint32_t length_subject_name;
      arrToVar(length_subject_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subject_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subject_name-1]=0;
      this->subject_name = (char *)(inbuffer + offset-1);
      offset += length_subject_name;
      uint32_t length_object_name;
      arrToVar(length_object_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      uint32_t length_subject_tool_name;
      arrToVar(length_subject_tool_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subject_tool_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subject_tool_name-1]=0;
      this->subject_tool_name = (char *)(inbuffer + offset-1);
      offset += length_subject_tool_name;
      uint32_t length_object_tool_name;
      arrToVar(length_object_tool_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_tool_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_tool_name-1]=0;
      this->object_tool_name = (char *)(inbuffer + offset-1);
      offset += length_object_tool_name;
      uint32_t execution_actors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      execution_actors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      execution_actors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      execution_actors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->execution_actors_length);
      if(execution_actors_lengthT > execution_actors_length)
        this->execution_actors = (char**)realloc(this->execution_actors, execution_actors_lengthT * sizeof(char*));
      execution_actors_length = execution_actors_lengthT;
      for( uint32_t i = 0; i < execution_actors_length; i++){
      uint32_t length_st_execution_actors;
      arrToVar(length_st_execution_actors, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_execution_actors; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_execution_actors-1]=0;
      this->st_execution_actors = (char *)(inbuffer + offset-1);
      offset += length_st_execution_actors;
        memcpy( &(this->execution_actors[i]), &(this->st_execution_actors), sizeof(char*));
      }
      uint32_t length_workcell_uri;
      arrToVar(length_workcell_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcell_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcell_uri-1]=0;
      this->workcell_uri = (char *)(inbuffer + offset-1);
      offset += length_workcell_uri;
      offset += this->requestParameters.deserialize(inbuffer + offset);
      uint32_t length_taskIri;
      arrToVar(length_taskIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_taskIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_taskIri-1]=0;
      this->taskIri = (char *)(inbuffer + offset-1);
      offset += length_taskIri;
     return offset;
    }

    virtual const char * getType() override { return GETTASKPARAMETERS; };
    virtual const char * getMD5() override { return "be57d965760f1eab369e855bdd1cf904"; };

  };

  class GetTaskParametersResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef process_im_msgs::TaskParameters _parameters_type;
      _parameters_type parameters;

    GetTaskParametersResponse():
      success(0),
      parameters()
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
      offset += this->parameters.serialize(outbuffer + offset);
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
      offset += this->parameters.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETTASKPARAMETERS; };
    virtual const char * getMD5() override { return "c0ed27aea5d9ce1b72e31584d2c2fe1f"; };

  };

  class GetTaskParameters {
    public:
    typedef GetTaskParametersRequest Request;
    typedef GetTaskParametersResponse Response;
  };

}
#endif
