#ifndef _ROS_process_im_msgs_SubTaskTypes_h
#define _ROS_process_im_msgs_SubTaskTypes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace process_im_msgs
{

  class SubTaskTypes : public ros::Msg
  {
    public:
      enum { NONE =  0 };
      enum { GRASP =  70001 };
      enum { PLACE =  70002 };
      enum { PICK_PLACE =  70003 };
      enum { PICK_PLACE_ENDPOSE =  70004 };
      enum { PICK_PLACE_APPROACH_ENDPOSE =  70005 };
      enum { PUSH_DOWN =  70006 };
      enum { MOVE =  70007 };
      enum { MOVE_TO_ACTOR =  70008 };
      enum { WELD_SPOT =  70009 };
      enum { WELD_SEAM =  70010 };
      enum { MOVE_HOME =  70011 };
      enum { DETACH_TOOL =  70012 };
      enum { GRASP_RELEASE =  70013 };
      enum { NAIL =  70015 };
      enum { SAW =  70016 };
      enum { DISASSEMBLE_ENDPOSE =  70017 };
      enum { DISASSEMBLE_APPROACH_ENDPOSE =  70018 };
      enum { DUAL_ARM_MOVE =  71001 };
      enum { DUAL_ARM_MOVE_OBJECT =  71002 };
      enum { DUAL_ARM_PUSH =  71003 };
      enum { DUAL_ARM_GRASP =  71004 };
      enum { DUAL_ARM_PLACE =  71005 };
      enum { DUAL_ARM_PICK_PLACE =  71006 };
      enum { DUAL_ARM_PICK_PLACE_END_POSE =  71007 };
      enum { DUAL_ARM_PICK_PLACE_APPROACH_END_POSE =  71008 };
      enum { DUAL_ARM_ASSEMBLY_AIR_END_POSE =  71009 };
      enum { DUAL_ARM_ASSEMBLY_GROUND_END_POSE =  71010 };
      enum { DUAL_ARM_MOVE_ACTOR =  71011 };
      enum { DUAL_ARM_GRASP_RELEASE =  71012 };

    SubTaskTypes()
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

    virtual const char * getType() override { return "process_im_msgs/SubTaskTypes"; };
    virtual const char * getMD5() override { return "c5efeb0db2f3298c0464a201f94a1cb3"; };

  };

}
#endif
