#ifndef _ROS_SERVICE_TaskListSubtypes_h
#define _ROS_SERVICE_TaskListSubtypes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Class.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char TASKLISTSUBTYPES[] = "process_srvs/TaskListSubtypes";

  class TaskListSubtypesRequest : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;
      typedef bool _onlyDirect_type;
      _onlyDirect_type onlyDirect;
      typedef bool _includeProcess_type;
      _includeProcess_type includeProcess;
      typedef bool _includeItself_type;
      _includeItself_type includeItself;

    TaskListSubtypesRequest():
      typeIri(""),
      onlyDirect(0),
      includeProcess(0),
      includeItself(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_typeIri = strlen(this->typeIri);
      varToArr(outbuffer + offset, length_typeIri);
      offset += 4;
      memcpy(outbuffer + offset, this->typeIri, length_typeIri);
      offset += length_typeIri;
      union {
        bool real;
        uint8_t base;
      } u_onlyDirect;
      u_onlyDirect.real = this->onlyDirect;
      *(outbuffer + offset + 0) = (u_onlyDirect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->onlyDirect);
      union {
        bool real;
        uint8_t base;
      } u_includeProcess;
      u_includeProcess.real = this->includeProcess;
      *(outbuffer + offset + 0) = (u_includeProcess.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->includeProcess);
      union {
        bool real;
        uint8_t base;
      } u_includeItself;
      u_includeItself.real = this->includeItself;
      *(outbuffer + offset + 0) = (u_includeItself.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->includeItself);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_typeIri;
      arrToVar(length_typeIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typeIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typeIri-1]=0;
      this->typeIri = (char *)(inbuffer + offset-1);
      offset += length_typeIri;
      union {
        bool real;
        uint8_t base;
      } u_onlyDirect;
      u_onlyDirect.base = 0;
      u_onlyDirect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->onlyDirect = u_onlyDirect.real;
      offset += sizeof(this->onlyDirect);
      union {
        bool real;
        uint8_t base;
      } u_includeProcess;
      u_includeProcess.base = 0;
      u_includeProcess.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->includeProcess = u_includeProcess.real;
      offset += sizeof(this->includeProcess);
      union {
        bool real;
        uint8_t base;
      } u_includeItself;
      u_includeItself.base = 0;
      u_includeItself.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->includeItself = u_includeItself.real;
      offset += sizeof(this->includeItself);
     return offset;
    }

    virtual const char * getType() override { return TASKLISTSUBTYPES; };
    virtual const char * getMD5() override { return "6cc3b7c8c187fd1ac0bf5255d523b404"; };

  };

  class TaskListSubtypesResponse : public ros::Msg
  {
    public:
      uint32_t subtaskTypes_length;
      typedef process_msgs::Class _subtaskTypes_type;
      _subtaskTypes_type st_subtaskTypes;
      _subtaskTypes_type * subtaskTypes;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    TaskListSubtypesResponse():
      subtaskTypes_length(0), st_subtaskTypes(), subtaskTypes(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->subtaskTypes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subtaskTypes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subtaskTypes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subtaskTypes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subtaskTypes_length);
      for( uint32_t i = 0; i < subtaskTypes_length; i++){
      offset += this->subtaskTypes[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t subtaskTypes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subtaskTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subtaskTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subtaskTypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subtaskTypes_length);
      if(subtaskTypes_lengthT > subtaskTypes_length)
        this->subtaskTypes = (process_msgs::Class*)realloc(this->subtaskTypes, subtaskTypes_lengthT * sizeof(process_msgs::Class));
      subtaskTypes_length = subtaskTypes_lengthT;
      for( uint32_t i = 0; i < subtaskTypes_length; i++){
      offset += this->st_subtaskTypes.deserialize(inbuffer + offset);
        memcpy( &(this->subtaskTypes[i]), &(this->st_subtaskTypes), sizeof(process_msgs::Class));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TASKLISTSUBTYPES; };
    virtual const char * getMD5() override { return "0e707b185169af8c8acd787d4950987d"; };

  };

  class TaskListSubtypes {
    public:
    typedef TaskListSubtypesRequest Request;
    typedef TaskListSubtypesResponse Response;
  };

}
#endif
