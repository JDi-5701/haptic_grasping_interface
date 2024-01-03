#ifndef _ROS_process_im_msgs_SubTaskParameters_h
#define _ROS_process_im_msgs_SubTaskParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "process_im_msgs/GraspParameters.h"
#include "process_im_msgs/PlaceParameters.h"
#include "process_im_msgs/MoveParameters.h"
#include "process_im_msgs/MoveToActorParameters.h"
#include "process_im_msgs/WeldSpotParameters.h"
#include "process_im_msgs/WeldSeamParameters.h"

namespace process_im_msgs
{

  class SubTaskParameters : public ros::Msg
  {
    public:
      typedef process_im_msgs::GraspParameters _grasp_parameters_type;
      _grasp_parameters_type grasp_parameters;
      typedef process_im_msgs::PlaceParameters _place_parameters_type;
      _place_parameters_type place_parameters;
      typedef process_im_msgs::MoveParameters _move_parameters_type;
      _move_parameters_type move_parameters;
      typedef process_im_msgs::MoveToActorParameters _move_to_actor_parameters_type;
      _move_to_actor_parameters_type move_to_actor_parameters;
      typedef process_im_msgs::WeldSpotParameters _weld_spot_parameters_type;
      _weld_spot_parameters_type weld_spot_parameters;
      typedef process_im_msgs::WeldSeamParameters _weld_seam_parameters_type;
      _weld_seam_parameters_type weld_seam_parameters;

    SubTaskParameters():
      grasp_parameters(),
      place_parameters(),
      move_parameters(),
      move_to_actor_parameters(),
      weld_spot_parameters(),
      weld_seam_parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->grasp_parameters.serialize(outbuffer + offset);
      offset += this->place_parameters.serialize(outbuffer + offset);
      offset += this->move_parameters.serialize(outbuffer + offset);
      offset += this->move_to_actor_parameters.serialize(outbuffer + offset);
      offset += this->weld_spot_parameters.serialize(outbuffer + offset);
      offset += this->weld_seam_parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->grasp_parameters.deserialize(inbuffer + offset);
      offset += this->place_parameters.deserialize(inbuffer + offset);
      offset += this->move_parameters.deserialize(inbuffer + offset);
      offset += this->move_to_actor_parameters.deserialize(inbuffer + offset);
      offset += this->weld_spot_parameters.deserialize(inbuffer + offset);
      offset += this->weld_seam_parameters.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/SubTaskParameters"; };
    virtual const char * getMD5() override { return "93951d7d6f305658189e7ed1bd192d4a"; };

  };

}
#endif
