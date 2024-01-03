#ifndef _ROS_SERVICE_ExecuteProcess_h
#define _ROS_SERVICE_ExecuteProcess_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/Process.h"

namespace process_im_srvs
{

static const char EXECUTEPROCESS[] = "process_im_srvs/ExecuteProcess";

  class ExecuteProcessRequest : public ros::Msg
  {
    public:
      typedef process_im_msgs::Process _req_type;
      _req_type req;
      typedef int32_t _sub_task_id_type;
      _sub_task_id_type sub_task_id;

    ExecuteProcessRequest():
      req(),
      sub_task_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->req.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_sub_task_id;
      u_sub_task_id.real = this->sub_task_id;
      *(outbuffer + offset + 0) = (u_sub_task_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sub_task_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sub_task_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sub_task_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sub_task_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->req.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_sub_task_id;
      u_sub_task_id.base = 0;
      u_sub_task_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sub_task_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sub_task_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sub_task_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sub_task_id = u_sub_task_id.real;
      offset += sizeof(this->sub_task_id);
     return offset;
    }

    virtual const char * getType() override { return EXECUTEPROCESS; };
    virtual const char * getMD5() override { return "e19bd696d7441c3ff6af3a28d727eebf"; };

  };

  class ExecuteProcessResponse : public ros::Msg
  {
    public:
      typedef bool _res_type;
      _res_type res;

    ExecuteProcessResponse():
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

    virtual const char * getType() override { return EXECUTEPROCESS; };
    virtual const char * getMD5() override { return "e27848a10f8e7e4030443887dfea101b"; };

  };

  class ExecuteProcess {
    public:
    typedef ExecuteProcessRequest Request;
    typedef ExecuteProcessResponse Response;
  };

}
#endif
