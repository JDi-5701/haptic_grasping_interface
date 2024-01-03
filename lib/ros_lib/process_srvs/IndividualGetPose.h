#ifndef _ROS_SERVICE_IndividualGetPose_h
#define _ROS_SERVICE_IndividualGetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char INDIVIDUALGETPOSE[] = "process_srvs/IndividualGetPose";

  class IndividualGetPoseRequest : public ros::Msg
  {
    public:
      typedef const char* _iri_type;
      _iri_type iri;

    IndividualGetPoseRequest():
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

    virtual const char * getType() override { return INDIVIDUALGETPOSE; };
    virtual const char * getMD5() override { return "a3b9c4d6755e03b461791903d7edafb4"; };

  };

  class IndividualGetPoseResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    IndividualGetPoseResponse():
      pose(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return INDIVIDUALGETPOSE; };
    virtual const char * getMD5() override { return "57389c60b6adcdbead1d42b56c8c7644"; };

  };

  class IndividualGetPose {
    public:
    typedef IndividualGetPoseRequest Request;
    typedef IndividualGetPoseResponse Response;
  };

}
#endif
