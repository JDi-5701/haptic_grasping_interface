#ifndef _ROS_SERVICE_PhysicalEntityGetModelUrlFromTypeIri_h
#define _ROS_SERVICE_PhysicalEntityGetModelUrlFromTypeIri_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char PHYSICALENTITYGETMODELURLFROMTYPEIRI[] = "process_srvs/PhysicalEntityGetModelUrlFromTypeIri";

  class PhysicalEntityGetModelUrlFromTypeIriRequest : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;

    PhysicalEntityGetModelUrlFromTypeIriRequest():
      typeIri("")
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
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYGETMODELURLFROMTYPEIRI; };
    virtual const char * getMD5() override { return "ac2ec4a6d15cf7c1116e90a35cc8774f"; };

  };

  class PhysicalEntityGetModelUrlFromTypeIriResponse : public ros::Msg
  {
    public:
      typedef const char* _modelUrl_type;
      _modelUrl_type modelUrl;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    PhysicalEntityGetModelUrlFromTypeIriResponse():
      modelUrl(""),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_modelUrl = strlen(this->modelUrl);
      varToArr(outbuffer + offset, length_modelUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->modelUrl, length_modelUrl);
      offset += length_modelUrl;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_modelUrl;
      arrToVar(length_modelUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modelUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modelUrl-1]=0;
      this->modelUrl = (char *)(inbuffer + offset-1);
      offset += length_modelUrl;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return PHYSICALENTITYGETMODELURLFROMTYPEIRI; };
    virtual const char * getMD5() override { return "002301875be01f754931454ebe6fb97a"; };

  };

  class PhysicalEntityGetModelUrlFromTypeIri {
    public:
    typedef PhysicalEntityGetModelUrlFromTypeIriRequest Request;
    typedef PhysicalEntityGetModelUrlFromTypeIriResponse Response;
  };

}
#endif
