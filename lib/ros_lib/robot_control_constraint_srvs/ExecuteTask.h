#ifndef _ROS_SERVICE_ExecuteTask_h
#define _ROS_SERVICE_ExecuteTask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_control_constraint_msgs/Constraints.h"
#include "geometry_msgs/Transform.h"

namespace robot_control_constraint_srvs
{

static const char EXECUTETASK[] = "robot_control_constraint_srvs/ExecuteTask";

  class ExecuteTaskRequest : public ros::Msg
  {
    public:
      typedef const char* _task_type_type;
      _task_type_type task_type;
      typedef robot_control_constraint_msgs::Constraints _task_constraints_type;
      _task_constraints_type task_constraints;
      typedef bool _move_robot_type;
      _move_robot_type move_robot;

    ExecuteTaskRequest():
      task_type(""),
      task_constraints(),
      move_robot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_task_type = strlen(this->task_type);
      varToArr(outbuffer + offset, length_task_type);
      offset += 4;
      memcpy(outbuffer + offset, this->task_type, length_task_type);
      offset += length_task_type;
      offset += this->task_constraints.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_move_robot;
      u_move_robot.real = this->move_robot;
      *(outbuffer + offset + 0) = (u_move_robot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->move_robot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_task_type;
      arrToVar(length_task_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_type-1]=0;
      this->task_type = (char *)(inbuffer + offset-1);
      offset += length_task_type;
      offset += this->task_constraints.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_move_robot;
      u_move_robot.base = 0;
      u_move_robot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->move_robot = u_move_robot.real;
      offset += sizeof(this->move_robot);
     return offset;
    }

    virtual const char * getType() override { return EXECUTETASK; };
    virtual const char * getMD5() override { return "a23356bc80c967cea898e43141f072b4"; };

  };

  class ExecuteTaskResponse : public ros::Msg
  {
    public:
      typedef int8_t _converged_type;
      _converged_type converged;
      typedef geometry_msgs::Transform _robot_EF_target_pose_type;
      _robot_EF_target_pose_type robot_EF_target_pose;

    ExecuteTaskResponse():
      converged(0),
      robot_EF_target_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_converged;
      u_converged.real = this->converged;
      *(outbuffer + offset + 0) = (u_converged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->converged);
      offset += this->robot_EF_target_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_converged;
      u_converged.base = 0;
      u_converged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->converged = u_converged.real;
      offset += sizeof(this->converged);
      offset += this->robot_EF_target_pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return EXECUTETASK; };
    virtual const char * getMD5() override { return "a7e06d44c97acfed07a51e32fd8948d4"; };

  };

  class ExecuteTask {
    public:
    typedef ExecuteTaskRequest Request;
    typedef ExecuteTaskResponse Response;
  };

}
#endif
