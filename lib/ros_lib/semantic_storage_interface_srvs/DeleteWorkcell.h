#ifndef _ROS_SERVICE_DeleteWorkcell_h
#define _ROS_SERVICE_DeleteWorkcell_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char DELETEWORKCELL[] = "semantic_storage_interface_srvs/DeleteWorkcell";

  class DeleteWorkcellRequest : public ros::Msg
  {
    public:
      typedef const char* _workcellUri_type;
      _workcellUri_type workcellUri;

    DeleteWorkcellRequest():
      workcellUri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_workcellUri = strlen(this->workcellUri);
      varToArr(outbuffer + offset, length_workcellUri);
      offset += 4;
      memcpy(outbuffer + offset, this->workcellUri, length_workcellUri);
      offset += length_workcellUri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_workcellUri;
      arrToVar(length_workcellUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_workcellUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_workcellUri-1]=0;
      this->workcellUri = (char *)(inbuffer + offset-1);
      offset += length_workcellUri;
     return offset;
    }

    virtual const char * getType() override { return DELETEWORKCELL; };
    virtual const char * getMD5() override { return "e1ec16a50e4e0367e86588f79d425c71"; };

  };

  class DeleteWorkcellResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    DeleteWorkcellResponse():
      success(0)
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
     return offset;
    }

    virtual const char * getType() override { return DELETEWORKCELL; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class DeleteWorkcell {
    public:
    typedef DeleteWorkcellRequest Request;
    typedef DeleteWorkcellResponse Response;
  };

}
#endif
