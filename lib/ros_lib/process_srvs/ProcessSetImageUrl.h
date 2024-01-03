#ifndef _ROS_SERVICE_ProcessSetImageUrl_h
#define _ROS_SERVICE_ProcessSetImageUrl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PROCESSSETIMAGEURL[] = "process_srvs/ProcessSetImageUrl";

  class ProcessSetImageUrlRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;
      typedef const char* _imageUrl_type;
      _imageUrl_type imageUrl;

    ProcessSetImageUrlRequest():
      iri(""),
      imageUrl("")
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
      uint32_t length_imageUrl = strlen(this->imageUrl);
      varToArr(outbuffer + offset, length_imageUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->imageUrl, length_imageUrl);
      offset += length_imageUrl;
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
      uint32_t length_imageUrl;
      arrToVar(length_imageUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imageUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imageUrl-1]=0;
      this->imageUrl = (char *)(inbuffer + offset-1);
      offset += length_imageUrl;
     return offset;
    }

    virtual const char * getType() override { return PROCESSSETIMAGEURL; };
    virtual const char * getMD5() override { return "aebfb9f86f726d5b1814293472b8c2b1"; };

  };

  class ProcessSetImageUrlResponse : public ros::Msg
  {
    public:
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    ProcessSetImageUrlResponse():
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

    virtual const char * getType() override { return PROCESSSETIMAGEURL; };
    virtual const char * getMD5() override { return "516d69a890f8d426cb85b27046058b23"; };

  };

  class ProcessSetImageUrl {
    public:
    typedef ProcessSetImageUrlRequest Request;
    typedef ProcessSetImageUrlResponse Response;
  };

}
#endif
