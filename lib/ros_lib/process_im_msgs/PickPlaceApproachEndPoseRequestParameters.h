#ifndef _ROS_process_im_msgs_PickPlaceApproachEndPoseRequestParameters_h
#define _ROS_process_im_msgs_PickPlaceApproachEndPoseRequestParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class PickPlaceApproachEndPoseRequestParameters : public ros::Msg
  {
    public:
      typedef bool _use_laser_distance_d2_type;
      _use_laser_distance_d2_type use_laser_distance_d2;
      typedef float _laser_distance_d2_type;
      _laser_distance_d2_type laser_distance_d2;
      typedef bool _move_measure_d2_type;
      _move_measure_d2_type move_measure_d2;
      typedef bool _use_measures_d2_type;
      _use_measures_d2_type use_measures_d2;
      typedef float _measure_x1_d2_type;
      _measure_x1_d2_type measure_x1_d2;
      typedef float _measure_x2_d2_type;
      _measure_x2_d2_type measure_x2_d2;
      typedef float _measure_y1_d2_type;
      _measure_y1_d2_type measure_y1_d2;
      typedef bool _afterMoveMeasureYPoseIsValid_type;
      _afterMoveMeasureYPoseIsValid_type afterMoveMeasureYPoseIsValid;
      typedef geometry_msgs::Pose _afterMoveMeasureYPose_type;
      _afterMoveMeasureYPose_type afterMoveMeasureYPose;
      typedef bool _afterMoveMeasureXPoseIsValid_type;
      _afterMoveMeasureXPoseIsValid_type afterMoveMeasureXPoseIsValid;
      typedef geometry_msgs::Pose _afterMoveMeasureXPose_type;
      _afterMoveMeasureXPose_type afterMoveMeasureXPose;

    PickPlaceApproachEndPoseRequestParameters():
      use_laser_distance_d2(0),
      laser_distance_d2(0),
      move_measure_d2(0),
      use_measures_d2(0),
      measure_x1_d2(0),
      measure_x2_d2(0),
      measure_y1_d2(0),
      afterMoveMeasureYPoseIsValid(0),
      afterMoveMeasureYPose(),
      afterMoveMeasureXPoseIsValid(0),
      afterMoveMeasureXPose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_laser_distance_d2;
      u_use_laser_distance_d2.real = this->use_laser_distance_d2;
      *(outbuffer + offset + 0) = (u_use_laser_distance_d2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_laser_distance_d2);
      offset += serializeAvrFloat64(outbuffer + offset, this->laser_distance_d2);
      union {
        bool real;
        uint8_t base;
      } u_move_measure_d2;
      u_move_measure_d2.real = this->move_measure_d2;
      *(outbuffer + offset + 0) = (u_move_measure_d2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->move_measure_d2);
      union {
        bool real;
        uint8_t base;
      } u_use_measures_d2;
      u_use_measures_d2.real = this->use_measures_d2;
      *(outbuffer + offset + 0) = (u_use_measures_d2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_measures_d2);
      offset += serializeAvrFloat64(outbuffer + offset, this->measure_x1_d2);
      offset += serializeAvrFloat64(outbuffer + offset, this->measure_x2_d2);
      offset += serializeAvrFloat64(outbuffer + offset, this->measure_y1_d2);
      union {
        bool real;
        uint8_t base;
      } u_afterMoveMeasureYPoseIsValid;
      u_afterMoveMeasureYPoseIsValid.real = this->afterMoveMeasureYPoseIsValid;
      *(outbuffer + offset + 0) = (u_afterMoveMeasureYPoseIsValid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->afterMoveMeasureYPoseIsValid);
      offset += this->afterMoveMeasureYPose.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_afterMoveMeasureXPoseIsValid;
      u_afterMoveMeasureXPoseIsValid.real = this->afterMoveMeasureXPoseIsValid;
      *(outbuffer + offset + 0) = (u_afterMoveMeasureXPoseIsValid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->afterMoveMeasureXPoseIsValid);
      offset += this->afterMoveMeasureXPose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_use_laser_distance_d2;
      u_use_laser_distance_d2.base = 0;
      u_use_laser_distance_d2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_laser_distance_d2 = u_use_laser_distance_d2.real;
      offset += sizeof(this->use_laser_distance_d2);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->laser_distance_d2));
      union {
        bool real;
        uint8_t base;
      } u_move_measure_d2;
      u_move_measure_d2.base = 0;
      u_move_measure_d2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->move_measure_d2 = u_move_measure_d2.real;
      offset += sizeof(this->move_measure_d2);
      union {
        bool real;
        uint8_t base;
      } u_use_measures_d2;
      u_use_measures_d2.base = 0;
      u_use_measures_d2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_measures_d2 = u_use_measures_d2.real;
      offset += sizeof(this->use_measures_d2);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measure_x1_d2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measure_x2_d2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measure_y1_d2));
      union {
        bool real;
        uint8_t base;
      } u_afterMoveMeasureYPoseIsValid;
      u_afterMoveMeasureYPoseIsValid.base = 0;
      u_afterMoveMeasureYPoseIsValid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->afterMoveMeasureYPoseIsValid = u_afterMoveMeasureYPoseIsValid.real;
      offset += sizeof(this->afterMoveMeasureYPoseIsValid);
      offset += this->afterMoveMeasureYPose.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_afterMoveMeasureXPoseIsValid;
      u_afterMoveMeasureXPoseIsValid.base = 0;
      u_afterMoveMeasureXPoseIsValid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->afterMoveMeasureXPoseIsValid = u_afterMoveMeasureXPoseIsValid.real;
      offset += sizeof(this->afterMoveMeasureXPoseIsValid);
      offset += this->afterMoveMeasureXPose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/PickPlaceApproachEndPoseRequestParameters"; };
    virtual const char * getMD5() override { return "62c720aba7f3367b6e144d3e9b70ac3f"; };

  };

}
#endif
