#ifndef _ROS_semantic_storage_interface_msgs_WorkCell_h
#define _ROS_semantic_storage_interface_msgs_WorkCell_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "semantic_storage_interface_msgs/RosFile.h"

namespace semantic_storage_interface_msgs
{

  class WorkCell : public ros::Msg
  {
    public:
      typedef semantic_storage_interface_msgs::RosFile _scenegraph_type;
      _scenegraph_type scenegraph;
      uint32_t robot_semantic_names_length;
      typedef char* _robot_semantic_names_type;
      _robot_semantic_names_type st_robot_semantic_names;
      _robot_semantic_names_type * robot_semantic_names;
      uint32_t robot_kinematics_length;
      typedef semantic_storage_interface_msgs::RosFile _robot_kinematics_type;
      _robot_kinematics_type st_robot_kinematics;
      _robot_kinematics_type * robot_kinematics;

    WorkCell():
      scenegraph(),
      robot_semantic_names_length(0), st_robot_semantic_names(), robot_semantic_names(nullptr),
      robot_kinematics_length(0), st_robot_kinematics(), robot_kinematics(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->scenegraph.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->robot_semantic_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robot_semantic_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robot_semantic_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robot_semantic_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_semantic_names_length);
      for( uint32_t i = 0; i < robot_semantic_names_length; i++){
      uint32_t length_robot_semantic_namesi = strlen(this->robot_semantic_names[i]);
      varToArr(outbuffer + offset, length_robot_semantic_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_semantic_names[i], length_robot_semantic_namesi);
      offset += length_robot_semantic_namesi;
      }
      *(outbuffer + offset + 0) = (this->robot_kinematics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robot_kinematics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robot_kinematics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robot_kinematics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_kinematics_length);
      for( uint32_t i = 0; i < robot_kinematics_length; i++){
      offset += this->robot_kinematics[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->scenegraph.deserialize(inbuffer + offset);
      uint32_t robot_semantic_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robot_semantic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robot_semantic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robot_semantic_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robot_semantic_names_length);
      if(robot_semantic_names_lengthT > robot_semantic_names_length)
        this->robot_semantic_names = (char**)realloc(this->robot_semantic_names, robot_semantic_names_lengthT * sizeof(char*));
      robot_semantic_names_length = robot_semantic_names_lengthT;
      for( uint32_t i = 0; i < robot_semantic_names_length; i++){
      uint32_t length_st_robot_semantic_names;
      arrToVar(length_st_robot_semantic_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_robot_semantic_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_robot_semantic_names-1]=0;
      this->st_robot_semantic_names = (char *)(inbuffer + offset-1);
      offset += length_st_robot_semantic_names;
        memcpy( &(this->robot_semantic_names[i]), &(this->st_robot_semantic_names), sizeof(char*));
      }
      uint32_t robot_kinematics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robot_kinematics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robot_kinematics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robot_kinematics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robot_kinematics_length);
      if(robot_kinematics_lengthT > robot_kinematics_length)
        this->robot_kinematics = (semantic_storage_interface_msgs::RosFile*)realloc(this->robot_kinematics, robot_kinematics_lengthT * sizeof(semantic_storage_interface_msgs::RosFile));
      robot_kinematics_length = robot_kinematics_lengthT;
      for( uint32_t i = 0; i < robot_kinematics_length; i++){
      offset += this->st_robot_kinematics.deserialize(inbuffer + offset);
        memcpy( &(this->robot_kinematics[i]), &(this->st_robot_kinematics), sizeof(semantic_storage_interface_msgs::RosFile));
      }
     return offset;
    }

    virtual const char * getType() override { return "semantic_storage_interface_msgs/WorkCell"; };
    virtual const char * getMD5() override { return "538e0c6f97ecf1a20b3661174e30aa77"; };

  };

}
#endif
