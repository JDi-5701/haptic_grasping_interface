#ifndef _ROS_SERVICE_AppendGraph_h
#define _ROS_SERVICE_AppendGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace graph_visualization_srvs
{

static const char APPENDGRAPH[] = "graph_visualization_srvs/AppendGraph";

  class AppendGraphRequest : public ros::Msg
  {
    public:
      typedef const char* _sparql_query_type;
      _sparql_query_type sparql_query;

    AppendGraphRequest():
      sparql_query("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_sparql_query = strlen(this->sparql_query);
      varToArr(outbuffer + offset, length_sparql_query);
      offset += 4;
      memcpy(outbuffer + offset, this->sparql_query, length_sparql_query);
      offset += length_sparql_query;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_sparql_query;
      arrToVar(length_sparql_query, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sparql_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sparql_query-1]=0;
      this->sparql_query = (char *)(inbuffer + offset-1);
      offset += length_sparql_query;
     return offset;
    }

    virtual const char * getType() override { return APPENDGRAPH; };
    virtual const char * getMD5() override { return "74dc606eaefa9ee45231457d92529007"; };

  };

  class AppendGraphResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    AppendGraphResponse():
      success(0)
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
     return offset;
    }

    virtual const char * getType() override { return APPENDGRAPH; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class AppendGraph {
    public:
    typedef AppendGraphRequest Request;
    typedef AppendGraphResponse Response;
  };

}
#endif
