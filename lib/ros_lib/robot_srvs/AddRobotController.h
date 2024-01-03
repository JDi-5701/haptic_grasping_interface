#ifndef _ROS_SERVICE_AddRobotController_h
#define _ROS_SERVICE_AddRobotController_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_srvs
{

static const char ADDROBOTCONTROLLER[] = "robot_srvs/AddRobotController";

  class AddRobotControllerRequest : public ros::Msg
  {
    public:
      typedef const char* _kinematicFileURL_type;
      _kinematicFileURL_type kinematicFileURL;
      typedef const char* _robotName_type;
      _robotName_type robotName;
      typedef int32_t _modelId_type;
      _modelId_type modelId;
      typedef bool _simulation_type;
      _simulation_type simulation;
      typedef const char* _robotType_type;
      _robotType_type robotType;
      typedef const char* _robotIp_type;
      _robotIp_type robotIp;
      typedef uint16_t _robotPort_type;
      _robotPort_type robotPort;

    AddRobotControllerRequest():
      kinematicFileURL(""),
      robotName(""),
      modelId(0),
      simulation(0),
      robotType(""),
      robotIp(""),
      robotPort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_kinematicFileURL = strlen(this->kinematicFileURL);
      varToArr(outbuffer + offset, length_kinematicFileURL);
      offset += 4;
      memcpy(outbuffer + offset, this->kinematicFileURL, length_kinematicFileURL);
      offset += length_kinematicFileURL;
      uint32_t length_robotName = strlen(this->robotName);
      varToArr(outbuffer + offset, length_robotName);
      offset += 4;
      memcpy(outbuffer + offset, this->robotName, length_robotName);
      offset += length_robotName;
      union {
        int32_t real;
        uint32_t base;
      } u_modelId;
      u_modelId.real = this->modelId;
      *(outbuffer + offset + 0) = (u_modelId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_modelId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_modelId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_modelId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modelId);
      union {
        bool real;
        uint8_t base;
      } u_simulation;
      u_simulation.real = this->simulation;
      *(outbuffer + offset + 0) = (u_simulation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->simulation);
      uint32_t length_robotType = strlen(this->robotType);
      varToArr(outbuffer + offset, length_robotType);
      offset += 4;
      memcpy(outbuffer + offset, this->robotType, length_robotType);
      offset += length_robotType;
      uint32_t length_robotIp = strlen(this->robotIp);
      varToArr(outbuffer + offset, length_robotIp);
      offset += 4;
      memcpy(outbuffer + offset, this->robotIp, length_robotIp);
      offset += length_robotIp;
      *(outbuffer + offset + 0) = (this->robotPort >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robotPort >> (8 * 1)) & 0xFF;
      offset += sizeof(this->robotPort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_kinematicFileURL;
      arrToVar(length_kinematicFileURL, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_kinematicFileURL; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_kinematicFileURL-1]=0;
      this->kinematicFileURL = (char *)(inbuffer + offset-1);
      offset += length_kinematicFileURL;
      uint32_t length_robotName;
      arrToVar(length_robotName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robotName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robotName-1]=0;
      this->robotName = (char *)(inbuffer + offset-1);
      offset += length_robotName;
      union {
        int32_t real;
        uint32_t base;
      } u_modelId;
      u_modelId.base = 0;
      u_modelId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_modelId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_modelId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_modelId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->modelId = u_modelId.real;
      offset += sizeof(this->modelId);
      union {
        bool real;
        uint8_t base;
      } u_simulation;
      u_simulation.base = 0;
      u_simulation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->simulation = u_simulation.real;
      offset += sizeof(this->simulation);
      uint32_t length_robotType;
      arrToVar(length_robotType, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robotType; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robotType-1]=0;
      this->robotType = (char *)(inbuffer + offset-1);
      offset += length_robotType;
      uint32_t length_robotIp;
      arrToVar(length_robotIp, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robotIp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robotIp-1]=0;
      this->robotIp = (char *)(inbuffer + offset-1);
      offset += length_robotIp;
      this->robotPort =  ((uint16_t) (*(inbuffer + offset)));
      this->robotPort |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->robotPort);
     return offset;
    }

    virtual const char * getType() override { return ADDROBOTCONTROLLER; };
    virtual const char * getMD5() override { return "5403e136afd60043dc4f113499072184"; };

  };

  class AddRobotControllerResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    AddRobotControllerResponse():
      res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.real = this->res;
      *(outbuffer + offset + 0) = (u_res.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_res;
      u_res.base = 0;
      u_res.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->res = u_res.real;
      offset += sizeof(this->res);
     return offset;
    }

    virtual const char * getType() override { return ADDROBOTCONTROLLER; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class AddRobotController {
    public:
    typedef AddRobotControllerRequest Request;
    typedef AddRobotControllerResponse Response;
  };

}
#endif
