#ifndef _ROS_SERVICE_SetPlanBlob_h
#define _ROS_SERVICE_SetPlanBlob_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_srvs
{

static const char SETPLANBLOB[] = "semantic_storage_interface_srvs/SetPlanBlob";

  class SetPlanBlobRequest : public ros::Msg
  {
    public:
      typedef const char* _relativeUri_type;
      _relativeUri_type relativeUri;
      typedef semantic_storage_interface_msgs::RosFile _blob_type;
      _blob_type blob;

    SetPlanBlobRequest():
      relativeUri(""),
      blob()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_relativeUri = strlen(this->relativeUri);
      varToArr(outbuffer + offset, length_relativeUri);
      offset += 4;
      memcpy(outbuffer + offset, this->relativeUri, length_relativeUri);
      offset += length_relativeUri;
      offset += this->blob.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_relativeUri;
      arrToVar(length_relativeUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_relativeUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_relativeUri-1]=0;
      this->relativeUri = (char *)(inbuffer + offset-1);
      offset += length_relativeUri;
      offset += this->blob.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETPLANBLOB; };
    virtual const char * getMD5() override { return "20704246bbbc381fa1dab5d83931e8ee"; };

  };

  class SetPlanBlobResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _blobUri_type;
      _blobUri_type blobUri;

    SetPlanBlobResponse():
      success(0),
      blobUri("")
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
      uint32_t length_blobUri = strlen(this->blobUri);
      varToArr(outbuffer + offset, length_blobUri);
      offset += 4;
      memcpy(outbuffer + offset, this->blobUri, length_blobUri);
      offset += length_blobUri;
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
      uint32_t length_blobUri;
      arrToVar(length_blobUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_blobUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_blobUri-1]=0;
      this->blobUri = (char *)(inbuffer + offset-1);
      offset += length_blobUri;
     return offset;
    }

    virtual const char * getType() override { return SETPLANBLOB; };
    virtual const char * getMD5() override { return "6c67e80140a40dab05a18491c76993e1"; };

  };

  class SetPlanBlob {
    public:
    typedef SetPlanBlobRequest Request;
    typedef SetPlanBlobResponse Response;
  };

}
#endif
