#ifndef _ROS_SERVICE_QueryIe_h
#define _ROS_SERVICE_QueryIe_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inference_engine_srvs
{

static const char QUERYIE[] = "inference_engine_srvs/QueryIe";

  class QueryIeRequest : public ros::Msg
  {
    public:
      typedef const char* _query_type;
      _query_type query;
      typedef int32_t _modelNo_type;
      _modelNo_type modelNo;

    QueryIeRequest():
      query(""),
      modelNo(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_query = strlen(this->query);
      varToArr(outbuffer + offset, length_query);
      offset += 4;
      memcpy(outbuffer + offset, this->query, length_query);
      offset += length_query;
      union {
        int32_t real;
        uint32_t base;
      } u_modelNo;
      u_modelNo.real = this->modelNo;
      *(outbuffer + offset + 0) = (u_modelNo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_modelNo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_modelNo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_modelNo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modelNo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_query;
      arrToVar(length_query, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_query-1]=0;
      this->query = (char *)(inbuffer + offset-1);
      offset += length_query;
      union {
        int32_t real;
        uint32_t base;
      } u_modelNo;
      u_modelNo.base = 0;
      u_modelNo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_modelNo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_modelNo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_modelNo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->modelNo = u_modelNo.real;
      offset += sizeof(this->modelNo);
     return offset;
    }

    virtual const char * getType() override { return QUERYIE; };
    virtual const char * getMD5() override { return "8f6292b51d846a24ebc386abe0763948"; };

  };

  class QueryIeResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _result_type;
      _result_type result;

    QueryIeResponse():
      success(0),
      result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_result = strlen(this->result);
      varToArr(outbuffer + offset, length_result);
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_result;
      arrToVar(length_result, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    virtual const char * getType() override { return QUERYIE; };
    virtual const char * getMD5() override { return "8c4b99d3c45e94cd751d81f8afc890bc"; };

  };

  class QueryIe {
    public:
    typedef QueryIeRequest Request;
    typedef QueryIeResponse Response;
  };

}
#endif
