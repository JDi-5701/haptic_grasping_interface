#ifndef _ROS_SERVICE_ConvertCADModel_h
#define _ROS_SERVICE_ConvertCADModel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_srvs
{

static const char CONVERTCADMODEL[] = "semantic_storage_interface_srvs/ConvertCADModel";

  class ConvertCADModelRequest : public ros::Msg
  {
    public:
      typedef semantic_storage_interface_msgs::RosFile _blob_type;
      _blob_type blob;

    ConvertCADModelRequest():
      blob()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->blob.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->blob.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CONVERTCADMODEL; };
    virtual const char * getMD5() override { return "e932d5c4d150002a7278ed5e12506a44"; };

  };

  class ConvertCADModelResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _owl_type;
      _owl_type owl;

    ConvertCADModelResponse():
      success(0),
      owl("")
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
      uint32_t length_owl = strlen(this->owl);
      varToArr(outbuffer + offset, length_owl);
      offset += 4;
      memcpy(outbuffer + offset, this->owl, length_owl);
      offset += length_owl;
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
      uint32_t length_owl;
      arrToVar(length_owl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_owl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_owl-1]=0;
      this->owl = (char *)(inbuffer + offset-1);
      offset += length_owl;
     return offset;
    }

    virtual const char * getType() override { return CONVERTCADMODEL; };
    virtual const char * getMD5() override { return "69a321bd5438391f22c9a83596e29cd6"; };

  };

  class ConvertCADModel {
    public:
    typedef ConvertCADModelRequest Request;
    typedef ConvertCADModelResponse Response;
  };

}
#endif
