#ifndef _ROS_SERVICE_DeleteObject_h
#define _ROS_SERVICE_DeleteObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace semantic_storage_interface_srvs
{

static const char DELETEOBJECT[] = "semantic_storage_interface_srvs/DeleteObject";

  class DeleteObjectRequest : public ros::Msg
  {
    public:
      typedef const char* _objectUri_type;
      _objectUri_type objectUri;

    DeleteObjectRequest():
      objectUri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_objectUri = strlen(this->objectUri);
      varToArr(outbuffer + offset, length_objectUri);
      offset += 4;
      memcpy(outbuffer + offset, this->objectUri, length_objectUri);
      offset += length_objectUri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_objectUri;
      arrToVar(length_objectUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectUri-1]=0;
      this->objectUri = (char *)(inbuffer + offset-1);
      offset += length_objectUri;
     return offset;
    }

    virtual const char * getType() override { return DELETEOBJECT; };
    virtual const char * getMD5() override { return "06fe469f04cb31c37eab5ceb841c1bc5"; };

  };

  class DeleteObjectResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    DeleteObjectResponse():
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

    virtual const char * getType() override { return DELETEOBJECT; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class DeleteObject {
    public:
    typedef DeleteObjectRequest Request;
    typedef DeleteObjectResponse Response;
  };

}
#endif
