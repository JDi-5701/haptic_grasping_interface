#ifndef _ROS_SERVICE_DeleteBlob_h
#define _ROS_SERVICE_DeleteBlob_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char DELETEBLOB[] = "semantic_storage_interface_srvs/DeleteBlob";

  class DeleteBlobRequest : public ros::Msg
  {
    public:
      typedef const char* _blobUri_type;
      _blobUri_type blobUri;

    DeleteBlobRequest():
      blobUri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return DELETEBLOB; };
    virtual const char * getMD5() override { return "1bec03394c9fa8830bf549173f8291ce"; };

  };

  class DeleteBlobResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    DeleteBlobResponse():
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

    virtual const char * getType() override { return DELETEBLOB; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class DeleteBlob {
    public:
    typedef DeleteBlobRequest Request;
    typedef DeleteBlobResponse Response;
  };

}
#endif
