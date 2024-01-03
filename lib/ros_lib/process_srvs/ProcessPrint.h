#ifndef _ROS_SERVICE_ProcessPrint_h
#define _ROS_SERVICE_ProcessPrint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSPRINT[] = "process_srvs/ProcessPrint";

  class ProcessPrintRequest : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;
      typedef bool _printToFile_type;
      _printToFile_type printToFile;
      typedef bool _printToTerminal_type;
      _printToTerminal_type printToTerminal;
      typedef bool _printToResponse_type;
      _printToResponse_type printToResponse;

    ProcessPrintRequest():
      processIri(""),
      printToFile(0),
      printToTerminal(0),
      printToResponse(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_processIri = strlen(this->processIri);
      varToArr(outbuffer + offset, length_processIri);
      offset += 4;
      memcpy(outbuffer + offset, this->processIri, length_processIri);
      offset += length_processIri;
      union {
        bool real;
        uint8_t base;
      } u_printToFile;
      u_printToFile.real = this->printToFile;
      *(outbuffer + offset + 0) = (u_printToFile.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->printToFile);
      union {
        bool real;
        uint8_t base;
      } u_printToTerminal;
      u_printToTerminal.real = this->printToTerminal;
      *(outbuffer + offset + 0) = (u_printToTerminal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->printToTerminal);
      union {
        bool real;
        uint8_t base;
      } u_printToResponse;
      u_printToResponse.real = this->printToResponse;
      *(outbuffer + offset + 0) = (u_printToResponse.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->printToResponse);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_processIri;
      arrToVar(length_processIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_processIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_processIri-1]=0;
      this->processIri = (char *)(inbuffer + offset-1);
      offset += length_processIri;
      union {
        bool real;
        uint8_t base;
      } u_printToFile;
      u_printToFile.base = 0;
      u_printToFile.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->printToFile = u_printToFile.real;
      offset += sizeof(this->printToFile);
      union {
        bool real;
        uint8_t base;
      } u_printToTerminal;
      u_printToTerminal.base = 0;
      u_printToTerminal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->printToTerminal = u_printToTerminal.real;
      offset += sizeof(this->printToTerminal);
      union {
        bool real;
        uint8_t base;
      } u_printToResponse;
      u_printToResponse.base = 0;
      u_printToResponse.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->printToResponse = u_printToResponse.real;
      offset += sizeof(this->printToResponse);
     return offset;
    }

    virtual const char * getType() override { return PROCESSPRINT; };
    virtual const char * getMD5() override { return "4d98adec149d3f4ac0d8e89839bb52f2"; };

  };

  class ProcessPrintResponse : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;
      typedef const char* _filePath_type;
      _filePath_type filePath;
      typedef const char* _owl_type;
      _owl_type owl;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessPrintResponse():
      processIri(""),
      filePath(""),
      owl(""),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_processIri = strlen(this->processIri);
      varToArr(outbuffer + offset, length_processIri);
      offset += 4;
      memcpy(outbuffer + offset, this->processIri, length_processIri);
      offset += length_processIri;
      uint32_t length_filePath = strlen(this->filePath);
      varToArr(outbuffer + offset, length_filePath);
      offset += 4;
      memcpy(outbuffer + offset, this->filePath, length_filePath);
      offset += length_filePath;
      uint32_t length_owl = strlen(this->owl);
      varToArr(outbuffer + offset, length_owl);
      offset += 4;
      memcpy(outbuffer + offset, this->owl, length_owl);
      offset += length_owl;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_processIri;
      arrToVar(length_processIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_processIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_processIri-1]=0;
      this->processIri = (char *)(inbuffer + offset-1);
      offset += length_processIri;
      uint32_t length_filePath;
      arrToVar(length_filePath, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filePath; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filePath-1]=0;
      this->filePath = (char *)(inbuffer + offset-1);
      offset += length_filePath;
      uint32_t length_owl;
      arrToVar(length_owl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_owl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_owl-1]=0;
      this->owl = (char *)(inbuffer + offset-1);
      offset += length_owl;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSPRINT; };
    virtual const char * getMD5() override { return "a298feafe7e7e0d77ba19474c5d26088"; };

  };

  class ProcessPrint {
    public:
    typedef ProcessPrintRequest Request;
    typedef ProcessPrintResponse Response;
  };

}
#endif
