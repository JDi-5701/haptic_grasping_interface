#ifndef _ROS_perception_msgs_ObjRecConfig_h
#define _ROS_perception_msgs_ObjRecConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace perception_msgs
{

  class ObjRecConfig : public ros::Msg
  {
    public:
      typedef const char* _typeIri_type;
      _typeIri_type typeIri;
      typedef const char* _typeName_type;
      _typeName_type typeName;
      typedef const char* _objectDetectionModelUrl_type;
      _objectDetectionModelUrl_type objectDetectionModelUrl;

    ObjRecConfig():
      typeIri(""),
      typeName(""),
      objectDetectionModelUrl("")
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
      uint32_t length_typeName = strlen(this->typeName);
      varToArr(outbuffer + offset, length_typeName);
      offset += 4;
      memcpy(outbuffer + offset, this->typeName, length_typeName);
      offset += length_typeName;
      uint32_t length_objectDetectionModelUrl = strlen(this->objectDetectionModelUrl);
      varToArr(outbuffer + offset, length_objectDetectionModelUrl);
      offset += 4;
      memcpy(outbuffer + offset, this->objectDetectionModelUrl, length_objectDetectionModelUrl);
      offset += length_objectDetectionModelUrl;
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
      uint32_t length_typeName;
      arrToVar(length_typeName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typeName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typeName-1]=0;
      this->typeName = (char *)(inbuffer + offset-1);
      offset += length_typeName;
      uint32_t length_objectDetectionModelUrl;
      arrToVar(length_objectDetectionModelUrl, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectDetectionModelUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectDetectionModelUrl-1]=0;
      this->objectDetectionModelUrl = (char *)(inbuffer + offset-1);
      offset += length_objectDetectionModelUrl;
     return offset;
    }

    virtual const char * getType() override { return "perception_msgs/ObjRecConfig"; };
    virtual const char * getMD5() override { return "6c62a50d722d8b2c9ddd8da475bf95db"; };

  };

}
#endif
