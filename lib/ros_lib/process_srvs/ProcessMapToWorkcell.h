#ifndef _ROS_SERVICE_ProcessMapToWorkcell_h
#define _ROS_SERVICE_ProcessMapToWorkcell_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Process.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSMAPTOWORKCELL[] = "process_srvs/ProcessMapToWorkcell";

  class ProcessMapToWorkcellRequest : public ros::Msg
  {
    public:
      typedef const char* _processIri_type;
      _processIri_type processIri;
      typedef const char* _workcellIri_type;
      _workcellIri_type workcellIri;
      typedef bool _doNotReloadProcess_type;
      _doNotReloadProcess_type doNotReloadProcess;

    ProcessMapToWorkcellRequest():
      processIri(""),
      workcellIri(""),
      doNotReloadProcess(0)
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
      uint32_t length_workcellIri = strlen(this->workcellIri);
      varToArr(outbuffer + offset, length_workcellIri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellIri, length_workcellIri);
      offset += length_workcellIri;
      union {
        bool real;
        uint8_t base;
      } u_doNotReloadProcess;
      u_doNotReloadProcess.real = this->doNotReloadProcess;
      *(outbuffer + offset + 0) = (u_doNotReloadProcess.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doNotReloadProcess);
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
      uint32_t length_workcellIri;
      arrToVar(length_workcellIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellIri-1]=0;
      this->workcellIri = (char *)(inbuffer + offset-1);
      offset += length_workcellIri;
      union {
        bool real;
        uint8_t base;
      } u_doNotReloadProcess;
      u_doNotReloadProcess.base = 0;
      u_doNotReloadProcess.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doNotReloadProcess = u_doNotReloadProcess.real;
      offset += sizeof(this->doNotReloadProcess);
     return offset;
    }

    virtual const char * getType() override { return PROCESSMAPTOWORKCELL; };
    virtual const char * getMD5() override { return "47ccd15b4f98bb190c844cd0e1739aa1"; };

  };

  class ProcessMapToWorkcellResponse : public ros::Msg
  {
    public:
      typedef process_msgs::Process _mappedProcess_type;
      _mappedProcess_type mappedProcess;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessMapToWorkcellResponse():
      mappedProcess(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->mappedProcess.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->mappedProcess.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PROCESSMAPTOWORKCELL; };
    virtual const char * getMD5() override { return "a24dcd614ca4fedbd9eaf9bb89f492c9"; };

  };

  class ProcessMapToWorkcell {
    public:
    typedef ProcessMapToWorkcellRequest Request;
    typedef ProcessMapToWorkcellResponse Response;
  };

}
#endif
