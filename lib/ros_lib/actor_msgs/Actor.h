#ifndef _ROS_actor_msgs_Actor_h
#define _ROS_actor_msgs_Actor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace actor_msgs
{

  class Actor : public ros::Msg
  {
    public:
      uint32_t targetPoseVec_length;
      typedef geometry_msgs::Pose _targetPoseVec_type;
      _targetPoseVec_type st_targetPoseVec;
      _targetPoseVec_type * targetPoseVec;
      typedef const char* _targetType_type;
      _targetType_type targetType;
      typedef int32_t _actorType_type;
      _actorType_type actorType;
      typedef const char* _associatedActor_type;
      _associatedActor_type associatedActor;
      typedef const char* _targetProperty_type;
      _targetProperty_type targetProperty;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _timeStamp_type;
      _timeStamp_type timeStamp;
      typedef const char* _semanticName_type;
      _semanticName_type semanticName;
      typedef int32_t _targetId_type;
      _targetId_type targetId;
      typedef const char* _modelPath_type;
      _modelPath_type modelPath;
      typedef bool _isRobot_type;
      _isRobot_type isRobot;
      typedef const char* _kinematicModelPath_type;
      _kinematicModelPath_type kinematicModelPath;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _weldingCurrent_type;
      _weldingCurrent_type weldingCurrent;
      typedef float _weldingVoltage_type;
      _weldingVoltage_type weldingVoltage;
      typedef float _robotMovingSpeed_type;
      _robotMovingSpeed_type robotMovingSpeed;
      typedef float _spotWeldingTime_type;
      _spotWeldingTime_type spotWeldingTime;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _rpm_type;
      _rpm_type rpm;

    Actor():
      targetPoseVec_length(0), st_targetPoseVec(), targetPoseVec(nullptr),
      targetType(""),
      actorType(0),
      associatedActor(""),
      targetProperty(""),
      description(""),
      timeStamp(""),
      semanticName(""),
      targetId(0),
      modelPath(""),
      isRobot(0),
      kinematicModelPath(""),
      speed(0),
      weldingCurrent(0),
      weldingVoltage(0),
      robotMovingSpeed(0),
      spotWeldingTime(0),
      distance(0),
      rpm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->targetPoseVec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->targetPoseVec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->targetPoseVec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->targetPoseVec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targetPoseVec_length);
      for( uint32_t i = 0; i < targetPoseVec_length; i++){
      offset += this->targetPoseVec[i].serialize(outbuffer + offset);
      }
      uint32_t length_targetType = strlen(this->targetType);
      varToArr(outbuffer + offset, length_targetType);
      offset += 4;
      memcpy(outbuffer + offset, this->targetType, length_targetType);
      offset += length_targetType;
      union {
        int32_t real;
        uint32_t base;
      } u_actorType;
      u_actorType.real = this->actorType;
      *(outbuffer + offset + 0) = (u_actorType.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actorType.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actorType.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actorType.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actorType);
      uint32_t length_associatedActor = strlen(this->associatedActor);
      varToArr(outbuffer + offset, length_associatedActor);
      offset += 4;
      memcpy(outbuffer + offset, this->associatedActor, length_associatedActor);
      offset += length_associatedActor;
      uint32_t length_targetProperty = strlen(this->targetProperty);
      varToArr(outbuffer + offset, length_targetProperty);
      offset += 4;
      memcpy(outbuffer + offset, this->targetProperty, length_targetProperty);
      offset += length_targetProperty;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_timeStamp = strlen(this->timeStamp);
      varToArr(outbuffer + offset, length_timeStamp);
      offset += 4;
      memcpy(outbuffer + offset, this->timeStamp, length_timeStamp);
      offset += length_timeStamp;
      uint32_t length_semanticName = strlen(this->semanticName);
      varToArr(outbuffer + offset, length_semanticName);
      offset += 4;
      memcpy(outbuffer + offset, this->semanticName, length_semanticName);
      offset += length_semanticName;
      union {
        int32_t real;
        uint32_t base;
      } u_targetId;
      u_targetId.real = this->targetId;
      *(outbuffer + offset + 0) = (u_targetId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targetId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targetId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targetId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targetId);
      uint32_t length_modelPath = strlen(this->modelPath);
      varToArr(outbuffer + offset, length_modelPath);
      offset += 4;
      memcpy(outbuffer + offset, this->modelPath, length_modelPath);
      offset += length_modelPath;
      union {
        bool real;
        uint8_t base;
      } u_isRobot;
      u_isRobot.real = this->isRobot;
      *(outbuffer + offset + 0) = (u_isRobot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isRobot);
      uint32_t length_kinematicModelPath = strlen(this->kinematicModelPath);
      varToArr(outbuffer + offset, length_kinematicModelPath);
      offset += 4;
      memcpy(outbuffer + offset, this->kinematicModelPath, length_kinematicModelPath);
      offset += length_kinematicModelPath;
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      union {
        float real;
        uint32_t base;
      } u_weldingCurrent;
      u_weldingCurrent.real = this->weldingCurrent;
      *(outbuffer + offset + 0) = (u_weldingCurrent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weldingCurrent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weldingCurrent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weldingCurrent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weldingCurrent);
      union {
        float real;
        uint32_t base;
      } u_weldingVoltage;
      u_weldingVoltage.real = this->weldingVoltage;
      *(outbuffer + offset + 0) = (u_weldingVoltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weldingVoltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weldingVoltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weldingVoltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weldingVoltage);
      union {
        float real;
        uint32_t base;
      } u_robotMovingSpeed;
      u_robotMovingSpeed.real = this->robotMovingSpeed;
      *(outbuffer + offset + 0) = (u_robotMovingSpeed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_robotMovingSpeed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_robotMovingSpeed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_robotMovingSpeed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robotMovingSpeed);
      union {
        float real;
        uint32_t base;
      } u_spotWeldingTime;
      u_spotWeldingTime.real = this->spotWeldingTime;
      *(outbuffer + offset + 0) = (u_spotWeldingTime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_spotWeldingTime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_spotWeldingTime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_spotWeldingTime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->spotWeldingTime);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->rpm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t targetPoseVec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      targetPoseVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      targetPoseVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      targetPoseVec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->targetPoseVec_length);
      if(targetPoseVec_lengthT > targetPoseVec_length)
        this->targetPoseVec = (geometry_msgs::Pose*)realloc(this->targetPoseVec, targetPoseVec_lengthT * sizeof(geometry_msgs::Pose));
      targetPoseVec_length = targetPoseVec_lengthT;
      for( uint32_t i = 0; i < targetPoseVec_length; i++){
      offset += this->st_targetPoseVec.deserialize(inbuffer + offset);
        memcpy( &(this->targetPoseVec[i]), &(this->st_targetPoseVec), sizeof(geometry_msgs::Pose));
      }
      uint32_t length_targetType;
      arrToVar(length_targetType, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_targetType; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_targetType-1]=0;
      this->targetType = (char *)(inbuffer + offset-1);
      offset += length_targetType;
      union {
        int32_t real;
        uint32_t base;
      } u_actorType;
      u_actorType.base = 0;
      u_actorType.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_actorType.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_actorType.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_actorType.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->actorType = u_actorType.real;
      offset += sizeof(this->actorType);
      uint32_t length_associatedActor;
      arrToVar(length_associatedActor, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_associatedActor; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_associatedActor-1]=0;
      this->associatedActor = (char *)(inbuffer + offset-1);
      offset += length_associatedActor;
      uint32_t length_targetProperty;
      arrToVar(length_targetProperty, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_targetProperty; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_targetProperty-1]=0;
      this->targetProperty = (char *)(inbuffer + offset-1);
      offset += length_targetProperty;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_timeStamp;
      arrToVar(length_timeStamp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_timeStamp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_timeStamp-1]=0;
      this->timeStamp = (char *)(inbuffer + offset-1);
      offset += length_timeStamp;
      uint32_t length_semanticName;
      arrToVar(length_semanticName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_semanticName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_semanticName-1]=0;
      this->semanticName = (char *)(inbuffer + offset-1);
      offset += length_semanticName;
      union {
        int32_t real;
        uint32_t base;
      } u_targetId;
      u_targetId.base = 0;
      u_targetId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targetId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targetId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targetId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->targetId = u_targetId.real;
      offset += sizeof(this->targetId);
      uint32_t length_modelPath;
      arrToVar(length_modelPath, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modelPath; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modelPath-1]=0;
      this->modelPath = (char *)(inbuffer + offset-1);
      offset += length_modelPath;
      union {
        bool real;
        uint8_t base;
      } u_isRobot;
      u_isRobot.base = 0;
      u_isRobot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isRobot = u_isRobot.real;
      offset += sizeof(this->isRobot);
      uint32_t length_kinematicModelPath;
      arrToVar(length_kinematicModelPath, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_kinematicModelPath; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_kinematicModelPath-1]=0;
      this->kinematicModelPath = (char *)(inbuffer + offset-1);
      offset += length_kinematicModelPath;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      union {
        float real;
        uint32_t base;
      } u_weldingCurrent;
      u_weldingCurrent.base = 0;
      u_weldingCurrent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weldingCurrent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weldingCurrent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weldingCurrent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weldingCurrent = u_weldingCurrent.real;
      offset += sizeof(this->weldingCurrent);
      union {
        float real;
        uint32_t base;
      } u_weldingVoltage;
      u_weldingVoltage.base = 0;
      u_weldingVoltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weldingVoltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weldingVoltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weldingVoltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weldingVoltage = u_weldingVoltage.real;
      offset += sizeof(this->weldingVoltage);
      union {
        float real;
        uint32_t base;
      } u_robotMovingSpeed;
      u_robotMovingSpeed.base = 0;
      u_robotMovingSpeed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_robotMovingSpeed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_robotMovingSpeed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_robotMovingSpeed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->robotMovingSpeed = u_robotMovingSpeed.real;
      offset += sizeof(this->robotMovingSpeed);
      union {
        float real;
        uint32_t base;
      } u_spotWeldingTime;
      u_spotWeldingTime.base = 0;
      u_spotWeldingTime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_spotWeldingTime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_spotWeldingTime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_spotWeldingTime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->spotWeldingTime = u_spotWeldingTime.real;
      offset += sizeof(this->spotWeldingTime);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rpm));
     return offset;
    }

    virtual const char * getType() override { return "actor_msgs/Actor"; };
    virtual const char * getMD5() override { return "ba28f550ffa7d90ef6cea75c1aa568a1"; };

  };

}
#endif
