#ifndef _ROS_SERVICE_WorkcellList_h
#define _ROS_SERVICE_WorkcellList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_msgs/Workcell.h"
#include "middleware_msgs/Status.h"

namespace process_srvs
{

static const char WORKCELLLIST[] = "process_srvs/WorkcellList";

  class WorkcellListRequest : public ros::Msg
  {
    public:

    WorkcellListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return WORKCELLLIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class WorkcellListResponse : public ros::Msg
  {
    public:
      uint32_t workcells_length;
      typedef process_msgs::Workcell _workcells_type;
      _workcells_type st_workcells;
      _workcells_type * workcells;
      typedef middleware_msgs::Status _status_type;
      _status_type status;

    WorkcellListResponse():
      workcells_length(0), st_workcells(), workcells(nullptr),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->workcells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->workcells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->workcells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->workcells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->workcells_length);
      for( uint32_t i = 0; i < workcells_length; i++){
      offset += this->workcells[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t workcells_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      workcells_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      workcells_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      workcells_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->workcells_length);
      if(workcells_lengthT > workcells_length)
        this->workcells = (process_msgs::Workcell*)realloc(this->workcells, workcells_lengthT * sizeof(process_msgs::Workcell));
      workcells_length = workcells_lengthT;
      for( uint32_t i = 0; i < workcells_length; i++){
      offset += this->st_workcells.deserialize(inbuffer + offset);
        memcpy( &(this->workcells[i]), &(this->st_workcells), sizeof(process_msgs::Workcell));
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return WORKCELLLIST; };
    virtual const char * getMD5() override { return "6d53e3641a296e144b5f9e878b7ec6a6"; };

  };

  class WorkcellList {
    public:
    typedef WorkcellListRequest Request;
    typedef WorkcellListResponse Response;
  };

}
#endif
