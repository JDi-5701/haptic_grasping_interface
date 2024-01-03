#ifndef _ROS_process_im_msgs_PickPlaceApproachEndPoseParameters_h
#define _ROS_process_im_msgs_PickPlaceApproachEndPoseParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace process_im_msgs
{

  class PickPlaceApproachEndPoseParameters : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _grasp_approach_type;
      _grasp_approach_type grasp_approach;
      typedef geometry_msgs::Pose _grasp_type;
      _grasp_type grasp;
      typedef float _gripper_span_type;
      _gripper_span_type gripper_span;
      typedef bool _grasp_from_inside_type;
      _grasp_from_inside_type grasp_from_inside;
      typedef geometry_msgs::Pose _place_approach_approach_type;
      _place_approach_approach_type place_approach_approach;
      typedef geometry_msgs::Pose _place_approach_type;
      _place_approach_type place_approach;
      typedef geometry_msgs::Pose _place_type;
      _place_type place;
      typedef geometry_msgs::Pose _place_post_approach_type;
      _place_post_approach_type place_post_approach;
      typedef geometry_msgs::Pose _pickobject_final_pose_type;
      _pickobject_final_pose_type pickobject_final_pose;
      typedef float _grasp_approach_speed_type;
      _grasp_approach_speed_type grasp_approach_speed;
      typedef float _grasp_speed_type;
      _grasp_speed_type grasp_speed;
      typedef float _place_approach_approach_speed_type;
      _place_approach_approach_speed_type place_approach_approach_speed;
      typedef float _place_approach_speed_type;
      _place_approach_speed_type place_approach_speed;
      typedef float _place_speed_type;
      _place_speed_type place_speed;
      typedef float _place_post_approach_speed_type;
      _place_post_approach_speed_type place_post_approach_speed;
      typedef geometry_msgs::Pose _grasp_close_approach_type;
      _grasp_close_approach_type grasp_close_approach;
      typedef geometry_msgs::Pose _measurement_home_approach_type;
      _measurement_home_approach_type measurement_home_approach;
      typedef geometry_msgs::Pose _measurement_home_type;
      _measurement_home_type measurement_home;
      typedef geometry_msgs::Pose _measure_y_type;
      _measure_y_type measure_y;
      typedef geometry_msgs::Pose _measure_x_type;
      _measure_x_type measure_x;
      typedef geometry_msgs::Pose _orient_panel_type;
      _orient_panel_type orient_panel;
      typedef float _grasp_close_approach_speed_type;
      _grasp_close_approach_speed_type grasp_close_approach_speed;
      typedef float _measurement_home_approach_speed_type;
      _measurement_home_approach_speed_type measurement_home_approach_speed;
      typedef float _measurement_home_speed_type;
      _measurement_home_speed_type measurement_home_speed;
      typedef float _measure_y_speed_type;
      _measure_y_speed_type measure_y_speed;
      typedef float _measure_x_speed_type;
      _measure_x_speed_type measure_x_speed;
      typedef float _orient_panel_speed_type;
      _orient_panel_speed_type orient_panel_speed;
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;
      typedef float _depth_type;
      _depth_type depth;

    PickPlaceApproachEndPoseParameters():
      grasp_approach(),
      grasp(),
      gripper_span(0),
      grasp_from_inside(0),
      place_approach_approach(),
      place_approach(),
      place(),
      place_post_approach(),
      pickobject_final_pose(),
      grasp_approach_speed(0),
      grasp_speed(0),
      place_approach_approach_speed(0),
      place_approach_speed(0),
      place_speed(0),
      place_post_approach_speed(0),
      grasp_close_approach(),
      measurement_home_approach(),
      measurement_home(),
      measure_y(),
      measure_x(),
      orient_panel(),
      grasp_close_approach_speed(0),
      measurement_home_approach_speed(0),
      measurement_home_speed(0),
      measure_y_speed(0),
      measure_x_speed(0),
      orient_panel_speed(0),
      width(0),
      height(0),
      depth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->grasp_approach.serialize(outbuffer + offset);
      offset += this->grasp.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_gripper_span;
      u_gripper_span.real = this->gripper_span;
      *(outbuffer + offset + 0) = (u_gripper_span.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper_span.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gripper_span.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gripper_span.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gripper_span);
      union {
        bool real;
        uint8_t base;
      } u_grasp_from_inside;
      u_grasp_from_inside.real = this->grasp_from_inside;
      *(outbuffer + offset + 0) = (u_grasp_from_inside.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grasp_from_inside);
      offset += this->place_approach_approach.serialize(outbuffer + offset);
      offset += this->place_approach.serialize(outbuffer + offset);
      offset += this->place.serialize(outbuffer + offset);
      offset += this->place_post_approach.serialize(outbuffer + offset);
      offset += this->pickobject_final_pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->grasp_approach_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->grasp_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->place_approach_approach_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->place_approach_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->place_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->place_post_approach_speed);
      offset += this->grasp_close_approach.serialize(outbuffer + offset);
      offset += this->measurement_home_approach.serialize(outbuffer + offset);
      offset += this->measurement_home.serialize(outbuffer + offset);
      offset += this->measure_y.serialize(outbuffer + offset);
      offset += this->measure_x.serialize(outbuffer + offset);
      offset += this->orient_panel.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->grasp_close_approach_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->measurement_home_approach_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->measurement_home_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->measure_y_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->measure_x_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->orient_panel_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      offset += serializeAvrFloat64(outbuffer + offset, this->depth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->grasp_approach.deserialize(inbuffer + offset);
      offset += this->grasp.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_gripper_span;
      u_gripper_span.base = 0;
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gripper_span.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gripper_span = u_gripper_span.real;
      offset += sizeof(this->gripper_span);
      union {
        bool real;
        uint8_t base;
      } u_grasp_from_inside;
      u_grasp_from_inside.base = 0;
      u_grasp_from_inside.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grasp_from_inside = u_grasp_from_inside.real;
      offset += sizeof(this->grasp_from_inside);
      offset += this->place_approach_approach.deserialize(inbuffer + offset);
      offset += this->place_approach.deserialize(inbuffer + offset);
      offset += this->place.deserialize(inbuffer + offset);
      offset += this->place_post_approach.deserialize(inbuffer + offset);
      offset += this->pickobject_final_pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->grasp_approach_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->grasp_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->place_approach_approach_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->place_approach_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->place_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->place_post_approach_speed));
      offset += this->grasp_close_approach.deserialize(inbuffer + offset);
      offset += this->measurement_home_approach.deserialize(inbuffer + offset);
      offset += this->measurement_home.deserialize(inbuffer + offset);
      offset += this->measure_y.deserialize(inbuffer + offset);
      offset += this->measure_x.deserialize(inbuffer + offset);
      offset += this->orient_panel.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->grasp_close_approach_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measurement_home_approach_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measurement_home_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measure_y_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measure_x_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orient_panel_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->depth));
     return offset;
    }

    virtual const char * getType() override { return "process_im_msgs/PickPlaceApproachEndPoseParameters"; };
    virtual const char * getMD5() override { return "848a3f82c3f2c7783092cc7b4aba150c"; };

  };

}
#endif
