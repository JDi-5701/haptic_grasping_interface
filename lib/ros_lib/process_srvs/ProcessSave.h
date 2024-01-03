#ifndef _ROS_SERVICE_ProcessSave_h
#define _ROS_SERVICE_ProcessSave_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSSAVE[] = "process_srvs/ProcessSave";

  class ProcessSaveRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef bool _saveToFile_type;
      _saveToFile_type saveToFile;

    ProcessSaveRequest():
      iri(""),
      saveToFile(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_iri = strlen(this->iri);
      varToArr(outbuffer + offset, length_iri);
      offset += 4;
      memcpy(outbuffer + offset, this->iri, length_iri);
      offset += length_iri;
      union {
        bool real;
        uint8_t base;
      } u_saveToFile;
      u_saveToFile.real = this->saveToFile;
      *(outbuffer + offset + 0) = (u_saveToFile.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->saveToFile);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_iri;
      arrToVar(length_iri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_iri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_iri-1]=0;
      this->iri = (char *)(inbuffer + offset-1);
      offset += length_iri;
      union {
        bool real;
        uint8_t base;
      } u_saveToFile;
      u_saveToFile.base = 0;
      u_saveToFile.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->saveToFile = u_saveToFile.real;
      offset += sizeof(this->saveToFile);
     return offset;
    }

    virtual const char * getType() override { return PROCESSSAVE; };
    virtual const char * getMD5() override { return "3abb7f9a5e1978b764c206d10845d651"; };

  };

  class ProcessSaveResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessSaveResponse():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSSAVE; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class ProcessSave {
    public:
    typedef ProcessSaveRequest Request;
    typedef ProcessSaveResponse Response;
  };

}
#endif
