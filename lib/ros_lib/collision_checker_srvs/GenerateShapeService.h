#ifndef _ROS_SERVICE_GenerateShapeService_h
#define _ROS_SERVICE_GenerateShapeService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace collision_checker_srvs
{

static const char GENERATESHAPESERVICE[] = "collision_checker_srvs/GenerateShapeService";

  class GenerateShapeServiceRequest : public ros::Msg
  {
    public:
      typedef const char* _wrlFileUri_type;
      _wrlFileUri_type wrlFileUri;

    GenerateShapeServiceRequest():
      wrlFileUri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_wrlFileUri = strlen(this->wrlFileUri);
      varToArr(outbuffer + offset, length_wrlFileUri);
      offset += 4;
      memcpy(outbuffer + offset, this->wrlFileUri, length_wrlFileUri);
      offset += length_wrlFileUri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_wrlFileUri;
      arrToVar(length_wrlFileUri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wrlFileUri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wrlFileUri-1]=0;
      this->wrlFileUri = (char *)(inbuffer + offset-1);
      offset += length_wrlFileUri;
     return offset;
    }

    virtual const char * getType() override { return GENERATESHAPESERVICE; };
    virtual const char * getMD5() override { return "32276aeed4427334c3a9430baa00d860"; };

  };

  class GenerateShapeServiceResponse : public ros::Msg
  {
    public:
      typedef const char* _offsetWrlFilename_type;
      _offsetWrlFilename_type offsetWrlFilename;

    GenerateShapeServiceResponse():
      offsetWrlFilename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_offsetWrlFilename = strlen(this->offsetWrlFilename);
      varToArr(outbuffer + offset, length_offsetWrlFilename);
      offset += 4;
      memcpy(outbuffer + offset, this->offsetWrlFilename, length_offsetWrlFilename);
      offset += length_offsetWrlFilename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_offsetWrlFilename;
      arrToVar(length_offsetWrlFilename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_offsetWrlFilename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_offsetWrlFilename-1]=0;
      this->offsetWrlFilename = (char *)(inbuffer + offset-1);
      offset += length_offsetWrlFilename;
     return offset;
    }

    virtual const char * getType() override { return GENERATESHAPESERVICE; };
    virtual const char * getMD5() override { return "4b784c069d183cb1f82696bc5ff136f8"; };

  };

  class GenerateShapeService {
    public:
    typedef GenerateShapeServiceRequest Request;
    typedef GenerateShapeServiceResponse Response;
  };

}
#endif
