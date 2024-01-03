#ifndef _ROS_SERVICE_CollisionCheckerService_h
#define _ROS_SERVICE_CollisionCheckerService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace collision_checker_srvs
{

static const char COLLISIONCHECKERSERVICE[] = "collision_checker_srvs/CollisionCheckerService";

  class CollisionCheckerServiceRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _poseA_type;
      _poseA_type poseA;
      typedef const char* _objectIriA_type;
      _objectIriA_type objectIriA;
      typedef geometry_msgs::Pose _poseB_type;
      _poseB_type poseB;
      typedef const char* _objectIriB_type;
      _objectIriB_type objectIriB;

    CollisionCheckerServiceRequest():
      poseA(),
      objectIriA(""),
      poseB(),
      objectIriB("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->poseA.serialize(outbuffer + offset);
      uint32_t length_objectIriA = strlen(this->objectIriA);
      varToArr(outbuffer + offset, length_objectIriA);
      offset += 4;
      memcpy(outbuffer + offset, this->objectIriA, length_objectIriA);
      offset += length_objectIriA;
      offset += this->poseB.serialize(outbuffer + offset);
      uint32_t length_objectIriB = strlen(this->objectIriB);
      varToArr(outbuffer + offset, length_objectIriB);
      offset += 4;
      memcpy(outbuffer + offset, this->objectIriB, length_objectIriB);
      offset += length_objectIriB;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->poseA.deserialize(inbuffer + offset);
      uint32_t length_objectIriA;
      arrToVar(length_objectIriA, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectIriA; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectIriA-1]=0;
      this->objectIriA = (char *)(inbuffer + offset-1);
      offset += length_objectIriA;
      offset += this->poseB.deserialize(inbuffer + offset);
      uint32_t length_objectIriB;
      arrToVar(length_objectIriB, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectIriB; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectIriB-1]=0;
      this->objectIriB = (char *)(inbuffer + offset-1);
      offset += length_objectIriB;
     return offset;
    }

    virtual const char * getType() override { return COLLISIONCHECKERSERVICE; };
    virtual const char * getMD5() override { return "c43316214f5286c96784b19902b50754"; };

  };

  class CollisionCheckerServiceResponse : public ros::Msg
  {
    public:
      typedef bool _collides_type;
      _collides_type collides;
      typedef float _closestDistance_type;
      _closestDistance_type closestDistance;
      typedef geometry_msgs::Point _witnessOnA_type;
      _witnessOnA_type witnessOnA;
      typedef geometry_msgs::Point _witnessOnB_type;
      _witnessOnB_type witnessOnB;
      typedef const char* _debugComment_type;
      _debugComment_type debugComment;

    CollisionCheckerServiceResponse():
      collides(0),
      closestDistance(0),
      witnessOnA(),
      witnessOnB(),
      debugComment("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_collides;
      u_collides.real = this->collides;
      *(outbuffer + offset + 0) = (u_collides.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->collides);
      offset += serializeAvrFloat64(outbuffer + offset, this->closestDistance);
      offset += this->witnessOnA.serialize(outbuffer + offset);
      offset += this->witnessOnB.serialize(outbuffer + offset);
      uint32_t length_debugComment = strlen(this->debugComment);
      varToArr(outbuffer + offset, length_debugComment);
      offset += 4;
      memcpy(outbuffer + offset, this->debugComment, length_debugComment);
      offset += length_debugComment;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_collides;
      u_collides.base = 0;
      u_collides.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->collides = u_collides.real;
      offset += sizeof(this->collides);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->closestDistance));
      offset += this->witnessOnA.deserialize(inbuffer + offset);
      offset += this->witnessOnB.deserialize(inbuffer + offset);
      uint32_t length_debugComment;
      arrToVar(length_debugComment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_debugComment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_debugComment-1]=0;
      this->debugComment = (char *)(inbuffer + offset-1);
      offset += length_debugComment;
     return offset;
    }

    virtual const char * getType() override { return COLLISIONCHECKERSERVICE; };
    virtual const char * getMD5() override { return "1599ce683bfe9cadacc7f0e3c77c17d1"; };

  };

  class CollisionCheckerService {
    public:
    typedef CollisionCheckerServiceRequest Request;
    typedef CollisionCheckerServiceResponse Response;
  };

}
#endif
