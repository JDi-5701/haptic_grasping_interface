#ifndef _ROS_SERVICE_RobotGetHomeConfiguration_h
#define _ROS_SERVICE_RobotGetHomeConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "middleware_msgs/Status.h"

namespace inference_engine_srvs
{

static const char ROBOTGETHOMECONFIGURATION[] = "inference_engine_srvs/RobotGetHomeConfiguration";

  class RobotGetHomeConfigurationRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    RobotGetHomeConfigurationRequest():
      iri("")
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
     return offset;
    }

    virtual const char * getType() override { return ROBOTGETHOMECONFIGURATION; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class RobotGetHomeConfigurationResponse : public ros::Msg
  {
    public:
      uint32_t homeConfiguration_length;
      typedef float _homeConfiguration_type;
      _homeConfiguration_type st_homeConfiguration;
      _homeConfiguration_type * homeConfiguration;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    RobotGetHomeConfigurationResponse():
      homeConfiguration_length(0), st_homeConfiguration(), homeConfiguration(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->homeConfiguration_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->homeConfiguration_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->homeConfiguration_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->homeConfiguration_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->homeConfiguration_length);
      for( uint32_t i = 0; i < homeConfiguration_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->homeConfiguration[i]);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t homeConfiguration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      homeConfiguration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      homeConfiguration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      homeConfiguration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->homeConfiguration_length);
      if(homeConfiguration_lengthT > homeConfiguration_length)
        this->homeConfiguration = (float*)realloc(this->homeConfiguration, homeConfiguration_lengthT * sizeof(float));
      homeConfiguration_length = homeConfiguration_lengthT;
      for( uint32_t i = 0; i < homeConfiguration_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_homeConfiguration));
        memcpy( &(this->homeConfiguration[i]), &(this->st_homeConfiguration), sizeof(float));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ROBOTGETHOMECONFIGURATION; };
    virtual const char * getMD5() override { return "98a00305bec59713c024977102b1fa1e"; };

  };

  class RobotGetHomeConfiguration {
    public:
    typedef RobotGetHomeConfigurationRequest Request;
    typedef RobotGetHomeConfigurationResponse Response;
  };

}
#endif
