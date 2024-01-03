#ifndef _ROS_SERVICE_UpdateAssociationTransforms_h
#define _ROS_SERVICE_UpdateAssociationTransforms_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace world_state_model_srvs
{

static const char UPDATEASSOCIATIONTRANSFORMS[] = "world_state_model_srvs/UpdateAssociationTransforms";

  class UpdateAssociationTransformsRequest : public ros::Msg
  {
    public:
      uint32_t parentsIri_length;
      typedef char* _parentsIri_type;
      _parentsIri_type st_parentsIri;
      _parentsIri_type * parentsIri;
      uint32_t childrenIri_length;
      typedef char* _childrenIri_type;
      _childrenIri_type st_childrenIri;
      _childrenIri_type * childrenIri;
      uint32_t poses_length;
      typedef geometry_msgs::PoseWithCovarianceStamped _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    UpdateAssociationTransformsRequest():
      parentsIri_length(0), st_parentsIri(), parentsIri(nullptr),
      childrenIri_length(0), st_childrenIri(), childrenIri(nullptr),
      poses_length(0), st_poses(), poses(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->parentsIri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parentsIri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parentsIri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parentsIri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parentsIri_length);
      for( uint32_t i = 0; i < parentsIri_length; i++){
      uint32_t length_parentsIrii = strlen(this->parentsIri[i]);
      varToArr(outbuffer + offset, length_parentsIrii);
      offset += 4;
      memcpy(outbuffer + offset, this->parentsIri[i], length_parentsIrii);
      offset += length_parentsIrii;
      }
      *(outbuffer + offset + 0) = (this->childrenIri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->childrenIri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->childrenIri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->childrenIri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->childrenIri_length);
      for( uint32_t i = 0; i < childrenIri_length; i++){
      uint32_t length_childrenIrii = strlen(this->childrenIri[i]);
      varToArr(outbuffer + offset, length_childrenIrii);
      offset += 4;
      memcpy(outbuffer + offset, this->childrenIri[i], length_childrenIrii);
      offset += length_childrenIrii;
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t parentsIri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parentsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parentsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parentsIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parentsIri_length);
      if(parentsIri_lengthT > parentsIri_length)
        this->parentsIri = (char**)realloc(this->parentsIri, parentsIri_lengthT * sizeof(char*));
      parentsIri_length = parentsIri_lengthT;
      for( uint32_t i = 0; i < parentsIri_length; i++){
      uint32_t length_st_parentsIri;
      arrToVar(length_st_parentsIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_parentsIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_parentsIri-1]=0;
      this->st_parentsIri = (char *)(inbuffer + offset-1);
      offset += length_st_parentsIri;
        memcpy( &(this->parentsIri[i]), &(this->st_parentsIri), sizeof(char*));
      }
      uint32_t childrenIri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      childrenIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      childrenIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      childrenIri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->childrenIri_length);
      if(childrenIri_lengthT > childrenIri_length)
        this->childrenIri = (char**)realloc(this->childrenIri, childrenIri_lengthT * sizeof(char*));
      childrenIri_length = childrenIri_lengthT;
      for( uint32_t i = 0; i < childrenIri_length; i++){
      uint32_t length_st_childrenIri;
      arrToVar(length_st_childrenIri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_childrenIri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_childrenIri-1]=0;
      this->st_childrenIri = (char *)(inbuffer + offset-1);
      offset += length_st_childrenIri;
        memcpy( &(this->childrenIri[i]), &(this->st_childrenIri), sizeof(char*));
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::PoseWithCovarianceStamped*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::PoseWithCovarianceStamped));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::PoseWithCovarianceStamped));
      }
     return offset;
    }

    virtual const char * getType() override { return UPDATEASSOCIATIONTRANSFORMS; };
    virtual const char * getMD5() override { return "82ec0c6d74f590fc54d3e9cb5e74d9a7"; };

  };

  class UpdateAssociationTransformsResponse : public ros::Msg
  {
    public:
      typedef int32_t _error_type;
      _error_type error;

    UpdateAssociationTransformsResponse():
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.real = this->error;
      *(outbuffer + offset + 0) = (u_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_error;
      u_error.base = 0;
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error = u_error.real;
      offset += sizeof(this->error);
     return offset;
    }

    virtual const char * getType() override { return UPDATEASSOCIATIONTRANSFORMS; };
    virtual const char * getMD5() override { return "d9e7447d5716e291370d8c7c21840938"; };

  };

  class UpdateAssociationTransforms {
    public:
    typedef UpdateAssociationTransformsRequest Request;
    typedef UpdateAssociationTransformsResponse Response;
  };

}
#endif
