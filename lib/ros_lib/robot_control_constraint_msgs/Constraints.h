#ifndef _ROS_robot_control_constraint_msgs_Constraints_h
#define _ROS_robot_control_constraint_msgs_Constraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_control_constraint_msgs/FixedConstraint.h"
#include "robot_control_constraint_msgs/CircleCircleConstraint.h"
#include "robot_control_constraint_msgs/CircleConeConstraint.h"
#include "robot_control_constraint_msgs/CircleCylinderConstraint.h"
#include "robot_control_constraint_msgs/CircleLineConstraint.h"
#include "robot_control_constraint_msgs/CirclePlaneConstraint.h"
#include "robot_control_constraint_msgs/CirclePointConstraint.h"
#include "robot_control_constraint_msgs/ConeCircleConstraint.h"
#include "robot_control_constraint_msgs/ConeConeConstraint.h"
#include "robot_control_constraint_msgs/ConeCylinderConstraint.h"
#include "robot_control_constraint_msgs/ConeLineConstraint.h"
#include "robot_control_constraint_msgs/ConePlaneConstraint.h"
#include "robot_control_constraint_msgs/ConePointConstraint.h"
#include "robot_control_constraint_msgs/CylinderCircleConstraint.h"
#include "robot_control_constraint_msgs/CylinderConeConstraint.h"
#include "robot_control_constraint_msgs/CylinderCylinderConstraint.h"
#include "robot_control_constraint_msgs/CylinderLineConstraint.h"
#include "robot_control_constraint_msgs/CylinderPlaneConstraint.h"
#include "robot_control_constraint_msgs/CylinderPointConstraint.h"
#include "robot_control_constraint_msgs/LineCircleConstraint.h"
#include "robot_control_constraint_msgs/LineConeConstraint.h"
#include "robot_control_constraint_msgs/LineCylinderConstraint.h"
#include "robot_control_constraint_msgs/LineLineConstraint.h"
#include "robot_control_constraint_msgs/LinePlaneConstraint.h"
#include "robot_control_constraint_msgs/LinePointConstraint.h"
#include "robot_control_constraint_msgs/PlaneCircleConstraint.h"
#include "robot_control_constraint_msgs/PlaneConeConstraint.h"
#include "robot_control_constraint_msgs/PlaneCylinderConstraint.h"
#include "robot_control_constraint_msgs/PlaneLineConstraint.h"
#include "robot_control_constraint_msgs/PlanePlaneConstraint.h"
#include "robot_control_constraint_msgs/PlanePointConstraint.h"
#include "robot_control_constraint_msgs/PointCircleConstraint.h"
#include "robot_control_constraint_msgs/PointConeConstraint.h"
#include "robot_control_constraint_msgs/PointCylinderConstraint.h"
#include "robot_control_constraint_msgs/PointLineConstraint.h"
#include "robot_control_constraint_msgs/PointPlaneConstraint.h"
#include "robot_control_constraint_msgs/PointPointConstraint.h"

namespace robot_control_constraint_msgs
{

  class Constraints : public ros::Msg
  {
    public:
      uint32_t fixed_constraints_length;
      typedef robot_control_constraint_msgs::FixedConstraint _fixed_constraints_type;
      _fixed_constraints_type st_fixed_constraints;
      _fixed_constraints_type * fixed_constraints;
      uint32_t circle_circle_constraints_length;
      typedef robot_control_constraint_msgs::CircleCircleConstraint _circle_circle_constraints_type;
      _circle_circle_constraints_type st_circle_circle_constraints;
      _circle_circle_constraints_type * circle_circle_constraints;
      uint32_t circle_cone_constraints_length;
      typedef robot_control_constraint_msgs::CircleConeConstraint _circle_cone_constraints_type;
      _circle_cone_constraints_type st_circle_cone_constraints;
      _circle_cone_constraints_type * circle_cone_constraints;
      uint32_t circle_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::CircleCylinderConstraint _circle_cylinder_constraints_type;
      _circle_cylinder_constraints_type st_circle_cylinder_constraints;
      _circle_cylinder_constraints_type * circle_cylinder_constraints;
      uint32_t circle_line_constraints_length;
      typedef robot_control_constraint_msgs::CircleLineConstraint _circle_line_constraints_type;
      _circle_line_constraints_type st_circle_line_constraints;
      _circle_line_constraints_type * circle_line_constraints;
      uint32_t circle_plane_constraints_length;
      typedef robot_control_constraint_msgs::CirclePlaneConstraint _circle_plane_constraints_type;
      _circle_plane_constraints_type st_circle_plane_constraints;
      _circle_plane_constraints_type * circle_plane_constraints;
      uint32_t circle_point_constraints_length;
      typedef robot_control_constraint_msgs::CirclePointConstraint _circle_point_constraints_type;
      _circle_point_constraints_type st_circle_point_constraints;
      _circle_point_constraints_type * circle_point_constraints;
      uint32_t cone_circle_constraints_length;
      typedef robot_control_constraint_msgs::ConeCircleConstraint _cone_circle_constraints_type;
      _cone_circle_constraints_type st_cone_circle_constraints;
      _cone_circle_constraints_type * cone_circle_constraints;
      uint32_t cone_cone_constraints_length;
      typedef robot_control_constraint_msgs::ConeConeConstraint _cone_cone_constraints_type;
      _cone_cone_constraints_type st_cone_cone_constraints;
      _cone_cone_constraints_type * cone_cone_constraints;
      uint32_t cone_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::ConeCylinderConstraint _cone_cylinder_constraints_type;
      _cone_cylinder_constraints_type st_cone_cylinder_constraints;
      _cone_cylinder_constraints_type * cone_cylinder_constraints;
      uint32_t cone_line_constraints_length;
      typedef robot_control_constraint_msgs::ConeLineConstraint _cone_line_constraints_type;
      _cone_line_constraints_type st_cone_line_constraints;
      _cone_line_constraints_type * cone_line_constraints;
      uint32_t cone_plane_constraints_length;
      typedef robot_control_constraint_msgs::ConePlaneConstraint _cone_plane_constraints_type;
      _cone_plane_constraints_type st_cone_plane_constraints;
      _cone_plane_constraints_type * cone_plane_constraints;
      uint32_t cone_point_constraints_length;
      typedef robot_control_constraint_msgs::ConePointConstraint _cone_point_constraints_type;
      _cone_point_constraints_type st_cone_point_constraints;
      _cone_point_constraints_type * cone_point_constraints;
      uint32_t cylinder_circle_constraints_length;
      typedef robot_control_constraint_msgs::CylinderCircleConstraint _cylinder_circle_constraints_type;
      _cylinder_circle_constraints_type st_cylinder_circle_constraints;
      _cylinder_circle_constraints_type * cylinder_circle_constraints;
      uint32_t cylinder_cone_constraints_length;
      typedef robot_control_constraint_msgs::CylinderConeConstraint _cylinder_cone_constraints_type;
      _cylinder_cone_constraints_type st_cylinder_cone_constraints;
      _cylinder_cone_constraints_type * cylinder_cone_constraints;
      uint32_t cylinder_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::CylinderCylinderConstraint _cylinder_cylinder_constraints_type;
      _cylinder_cylinder_constraints_type st_cylinder_cylinder_constraints;
      _cylinder_cylinder_constraints_type * cylinder_cylinder_constraints;
      uint32_t cylinder_line_constraints_length;
      typedef robot_control_constraint_msgs::CylinderLineConstraint _cylinder_line_constraints_type;
      _cylinder_line_constraints_type st_cylinder_line_constraints;
      _cylinder_line_constraints_type * cylinder_line_constraints;
      uint32_t cylinder_plane_constraints_length;
      typedef robot_control_constraint_msgs::CylinderPlaneConstraint _cylinder_plane_constraints_type;
      _cylinder_plane_constraints_type st_cylinder_plane_constraints;
      _cylinder_plane_constraints_type * cylinder_plane_constraints;
      uint32_t cylinder_point_constraints_length;
      typedef robot_control_constraint_msgs::CylinderPointConstraint _cylinder_point_constraints_type;
      _cylinder_point_constraints_type st_cylinder_point_constraints;
      _cylinder_point_constraints_type * cylinder_point_constraints;
      uint32_t line_circle_constraints_length;
      typedef robot_control_constraint_msgs::LineCircleConstraint _line_circle_constraints_type;
      _line_circle_constraints_type st_line_circle_constraints;
      _line_circle_constraints_type * line_circle_constraints;
      uint32_t line_cone_constraints_length;
      typedef robot_control_constraint_msgs::LineConeConstraint _line_cone_constraints_type;
      _line_cone_constraints_type st_line_cone_constraints;
      _line_cone_constraints_type * line_cone_constraints;
      uint32_t line_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::LineCylinderConstraint _line_cylinder_constraints_type;
      _line_cylinder_constraints_type st_line_cylinder_constraints;
      _line_cylinder_constraints_type * line_cylinder_constraints;
      uint32_t line_line_constraints_length;
      typedef robot_control_constraint_msgs::LineLineConstraint _line_line_constraints_type;
      _line_line_constraints_type st_line_line_constraints;
      _line_line_constraints_type * line_line_constraints;
      uint32_t line_plane_constraints_length;
      typedef robot_control_constraint_msgs::LinePlaneConstraint _line_plane_constraints_type;
      _line_plane_constraints_type st_line_plane_constraints;
      _line_plane_constraints_type * line_plane_constraints;
      uint32_t line_point_constraints_length;
      typedef robot_control_constraint_msgs::LinePointConstraint _line_point_constraints_type;
      _line_point_constraints_type st_line_point_constraints;
      _line_point_constraints_type * line_point_constraints;
      uint32_t plane_circle_constraints_length;
      typedef robot_control_constraint_msgs::PlaneCircleConstraint _plane_circle_constraints_type;
      _plane_circle_constraints_type st_plane_circle_constraints;
      _plane_circle_constraints_type * plane_circle_constraints;
      uint32_t plane_cone_constraints_length;
      typedef robot_control_constraint_msgs::PlaneConeConstraint _plane_cone_constraints_type;
      _plane_cone_constraints_type st_plane_cone_constraints;
      _plane_cone_constraints_type * plane_cone_constraints;
      uint32_t plane_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::PlaneCylinderConstraint _plane_cylinder_constraints_type;
      _plane_cylinder_constraints_type st_plane_cylinder_constraints;
      _plane_cylinder_constraints_type * plane_cylinder_constraints;
      uint32_t plane_line_constraints_length;
      typedef robot_control_constraint_msgs::PlaneLineConstraint _plane_line_constraints_type;
      _plane_line_constraints_type st_plane_line_constraints;
      _plane_line_constraints_type * plane_line_constraints;
      uint32_t plane_plane_constraints_length;
      typedef robot_control_constraint_msgs::PlanePlaneConstraint _plane_plane_constraints_type;
      _plane_plane_constraints_type st_plane_plane_constraints;
      _plane_plane_constraints_type * plane_plane_constraints;
      uint32_t plane_point_constraints_length;
      typedef robot_control_constraint_msgs::PlanePointConstraint _plane_point_constraints_type;
      _plane_point_constraints_type st_plane_point_constraints;
      _plane_point_constraints_type * plane_point_constraints;
      uint32_t point_circle_constraints_length;
      typedef robot_control_constraint_msgs::PointCircleConstraint _point_circle_constraints_type;
      _point_circle_constraints_type st_point_circle_constraints;
      _point_circle_constraints_type * point_circle_constraints;
      uint32_t point_cone_constraints_length;
      typedef robot_control_constraint_msgs::PointConeConstraint _point_cone_constraints_type;
      _point_cone_constraints_type st_point_cone_constraints;
      _point_cone_constraints_type * point_cone_constraints;
      uint32_t point_cylinder_constraints_length;
      typedef robot_control_constraint_msgs::PointCylinderConstraint _point_cylinder_constraints_type;
      _point_cylinder_constraints_type st_point_cylinder_constraints;
      _point_cylinder_constraints_type * point_cylinder_constraints;
      uint32_t point_line_constraints_length;
      typedef robot_control_constraint_msgs::PointLineConstraint _point_line_constraints_type;
      _point_line_constraints_type st_point_line_constraints;
      _point_line_constraints_type * point_line_constraints;
      uint32_t point_plane_constraints_length;
      typedef robot_control_constraint_msgs::PointPlaneConstraint _point_plane_constraints_type;
      _point_plane_constraints_type st_point_plane_constraints;
      _point_plane_constraints_type * point_plane_constraints;
      uint32_t point_point_constraints_length;
      typedef robot_control_constraint_msgs::PointPointConstraint _point_point_constraints_type;
      _point_point_constraints_type st_point_point_constraints;
      _point_point_constraints_type * point_point_constraints;

    Constraints():
      fixed_constraints_length(0), st_fixed_constraints(), fixed_constraints(nullptr),
      circle_circle_constraints_length(0), st_circle_circle_constraints(), circle_circle_constraints(nullptr),
      circle_cone_constraints_length(0), st_circle_cone_constraints(), circle_cone_constraints(nullptr),
      circle_cylinder_constraints_length(0), st_circle_cylinder_constraints(), circle_cylinder_constraints(nullptr),
      circle_line_constraints_length(0), st_circle_line_constraints(), circle_line_constraints(nullptr),
      circle_plane_constraints_length(0), st_circle_plane_constraints(), circle_plane_constraints(nullptr),
      circle_point_constraints_length(0), st_circle_point_constraints(), circle_point_constraints(nullptr),
      cone_circle_constraints_length(0), st_cone_circle_constraints(), cone_circle_constraints(nullptr),
      cone_cone_constraints_length(0), st_cone_cone_constraints(), cone_cone_constraints(nullptr),
      cone_cylinder_constraints_length(0), st_cone_cylinder_constraints(), cone_cylinder_constraints(nullptr),
      cone_line_constraints_length(0), st_cone_line_constraints(), cone_line_constraints(nullptr),
      cone_plane_constraints_length(0), st_cone_plane_constraints(), cone_plane_constraints(nullptr),
      cone_point_constraints_length(0), st_cone_point_constraints(), cone_point_constraints(nullptr),
      cylinder_circle_constraints_length(0), st_cylinder_circle_constraints(), cylinder_circle_constraints(nullptr),
      cylinder_cone_constraints_length(0), st_cylinder_cone_constraints(), cylinder_cone_constraints(nullptr),
      cylinder_cylinder_constraints_length(0), st_cylinder_cylinder_constraints(), cylinder_cylinder_constraints(nullptr),
      cylinder_line_constraints_length(0), st_cylinder_line_constraints(), cylinder_line_constraints(nullptr),
      cylinder_plane_constraints_length(0), st_cylinder_plane_constraints(), cylinder_plane_constraints(nullptr),
      cylinder_point_constraints_length(0), st_cylinder_point_constraints(), cylinder_point_constraints(nullptr),
      line_circle_constraints_length(0), st_line_circle_constraints(), line_circle_constraints(nullptr),
      line_cone_constraints_length(0), st_line_cone_constraints(), line_cone_constraints(nullptr),
      line_cylinder_constraints_length(0), st_line_cylinder_constraints(), line_cylinder_constraints(nullptr),
      line_line_constraints_length(0), st_line_line_constraints(), line_line_constraints(nullptr),
      line_plane_constraints_length(0), st_line_plane_constraints(), line_plane_constraints(nullptr),
      line_point_constraints_length(0), st_line_point_constraints(), line_point_constraints(nullptr),
      plane_circle_constraints_length(0), st_plane_circle_constraints(), plane_circle_constraints(nullptr),
      plane_cone_constraints_length(0), st_plane_cone_constraints(), plane_cone_constraints(nullptr),
      plane_cylinder_constraints_length(0), st_plane_cylinder_constraints(), plane_cylinder_constraints(nullptr),
      plane_line_constraints_length(0), st_plane_line_constraints(), plane_line_constraints(nullptr),
      plane_plane_constraints_length(0), st_plane_plane_constraints(), plane_plane_constraints(nullptr),
      plane_point_constraints_length(0), st_plane_point_constraints(), plane_point_constraints(nullptr),
      point_circle_constraints_length(0), st_point_circle_constraints(), point_circle_constraints(nullptr),
      point_cone_constraints_length(0), st_point_cone_constraints(), point_cone_constraints(nullptr),
      point_cylinder_constraints_length(0), st_point_cylinder_constraints(), point_cylinder_constraints(nullptr),
      point_line_constraints_length(0), st_point_line_constraints(), point_line_constraints(nullptr),
      point_plane_constraints_length(0), st_point_plane_constraints(), point_plane_constraints(nullptr),
      point_point_constraints_length(0), st_point_point_constraints(), point_point_constraints(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->fixed_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fixed_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fixed_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fixed_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixed_constraints_length);
      for( uint32_t i = 0; i < fixed_constraints_length; i++){
      offset += this->fixed_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_circle_constraints_length);
      for( uint32_t i = 0; i < circle_circle_constraints_length; i++){
      offset += this->circle_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_cone_constraints_length);
      for( uint32_t i = 0; i < circle_cone_constraints_length; i++){
      offset += this->circle_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_cylinder_constraints_length);
      for( uint32_t i = 0; i < circle_cylinder_constraints_length; i++){
      offset += this->circle_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_line_constraints_length);
      for( uint32_t i = 0; i < circle_line_constraints_length; i++){
      offset += this->circle_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_plane_constraints_length);
      for( uint32_t i = 0; i < circle_plane_constraints_length; i++){
      offset += this->circle_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->circle_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circle_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circle_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circle_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circle_point_constraints_length);
      for( uint32_t i = 0; i < circle_point_constraints_length; i++){
      offset += this->circle_point_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_circle_constraints_length);
      for( uint32_t i = 0; i < cone_circle_constraints_length; i++){
      offset += this->cone_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_cone_constraints_length);
      for( uint32_t i = 0; i < cone_cone_constraints_length; i++){
      offset += this->cone_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_cylinder_constraints_length);
      for( uint32_t i = 0; i < cone_cylinder_constraints_length; i++){
      offset += this->cone_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_line_constraints_length);
      for( uint32_t i = 0; i < cone_line_constraints_length; i++){
      offset += this->cone_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_plane_constraints_length);
      for( uint32_t i = 0; i < cone_plane_constraints_length; i++){
      offset += this->cone_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cone_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cone_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cone_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cone_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cone_point_constraints_length);
      for( uint32_t i = 0; i < cone_point_constraints_length; i++){
      offset += this->cone_point_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_circle_constraints_length);
      for( uint32_t i = 0; i < cylinder_circle_constraints_length; i++){
      offset += this->cylinder_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_cone_constraints_length);
      for( uint32_t i = 0; i < cylinder_cone_constraints_length; i++){
      offset += this->cylinder_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_cylinder_constraints_length);
      for( uint32_t i = 0; i < cylinder_cylinder_constraints_length; i++){
      offset += this->cylinder_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_line_constraints_length);
      for( uint32_t i = 0; i < cylinder_line_constraints_length; i++){
      offset += this->cylinder_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_plane_constraints_length);
      for( uint32_t i = 0; i < cylinder_plane_constraints_length; i++){
      offset += this->cylinder_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cylinder_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cylinder_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cylinder_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cylinder_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cylinder_point_constraints_length);
      for( uint32_t i = 0; i < cylinder_point_constraints_length; i++){
      offset += this->cylinder_point_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_circle_constraints_length);
      for( uint32_t i = 0; i < line_circle_constraints_length; i++){
      offset += this->line_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_cone_constraints_length);
      for( uint32_t i = 0; i < line_cone_constraints_length; i++){
      offset += this->line_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_cylinder_constraints_length);
      for( uint32_t i = 0; i < line_cylinder_constraints_length; i++){
      offset += this->line_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_line_constraints_length);
      for( uint32_t i = 0; i < line_line_constraints_length; i++){
      offset += this->line_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_plane_constraints_length);
      for( uint32_t i = 0; i < line_plane_constraints_length; i++){
      offset += this->line_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->line_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_point_constraints_length);
      for( uint32_t i = 0; i < line_point_constraints_length; i++){
      offset += this->line_point_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_circle_constraints_length);
      for( uint32_t i = 0; i < plane_circle_constraints_length; i++){
      offset += this->plane_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_cone_constraints_length);
      for( uint32_t i = 0; i < plane_cone_constraints_length; i++){
      offset += this->plane_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_cylinder_constraints_length);
      for( uint32_t i = 0; i < plane_cylinder_constraints_length; i++){
      offset += this->plane_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_line_constraints_length);
      for( uint32_t i = 0; i < plane_line_constraints_length; i++){
      offset += this->plane_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_plane_constraints_length);
      for( uint32_t i = 0; i < plane_plane_constraints_length; i++){
      offset += this->plane_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_point_constraints_length);
      for( uint32_t i = 0; i < plane_point_constraints_length; i++){
      offset += this->plane_point_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_circle_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_circle_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_circle_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_circle_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_circle_constraints_length);
      for( uint32_t i = 0; i < point_circle_constraints_length; i++){
      offset += this->point_circle_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_cone_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_cone_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_cone_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_cone_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_cone_constraints_length);
      for( uint32_t i = 0; i < point_cone_constraints_length; i++){
      offset += this->point_cone_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_cylinder_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_cylinder_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_cylinder_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_cylinder_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_cylinder_constraints_length);
      for( uint32_t i = 0; i < point_cylinder_constraints_length; i++){
      offset += this->point_cylinder_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_line_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_line_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_line_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_line_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_line_constraints_length);
      for( uint32_t i = 0; i < point_line_constraints_length; i++){
      offset += this->point_line_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_plane_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_plane_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_plane_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_plane_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_plane_constraints_length);
      for( uint32_t i = 0; i < point_plane_constraints_length; i++){
      offset += this->point_plane_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_point_constraints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_point_constraints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_point_constraints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_point_constraints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_point_constraints_length);
      for( uint32_t i = 0; i < point_point_constraints_length; i++){
      offset += this->point_point_constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t fixed_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fixed_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fixed_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fixed_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fixed_constraints_length);
      if(fixed_constraints_lengthT > fixed_constraints_length)
        this->fixed_constraints = (robot_control_constraint_msgs::FixedConstraint*)realloc(this->fixed_constraints, fixed_constraints_lengthT * sizeof(robot_control_constraint_msgs::FixedConstraint));
      fixed_constraints_length = fixed_constraints_lengthT;
      for( uint32_t i = 0; i < fixed_constraints_length; i++){
      offset += this->st_fixed_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->fixed_constraints[i]), &(this->st_fixed_constraints), sizeof(robot_control_constraint_msgs::FixedConstraint));
      }
      uint32_t circle_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_circle_constraints_length);
      if(circle_circle_constraints_lengthT > circle_circle_constraints_length)
        this->circle_circle_constraints = (robot_control_constraint_msgs::CircleCircleConstraint*)realloc(this->circle_circle_constraints, circle_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::CircleCircleConstraint));
      circle_circle_constraints_length = circle_circle_constraints_lengthT;
      for( uint32_t i = 0; i < circle_circle_constraints_length; i++){
      offset += this->st_circle_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_circle_constraints[i]), &(this->st_circle_circle_constraints), sizeof(robot_control_constraint_msgs::CircleCircleConstraint));
      }
      uint32_t circle_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_cone_constraints_length);
      if(circle_cone_constraints_lengthT > circle_cone_constraints_length)
        this->circle_cone_constraints = (robot_control_constraint_msgs::CircleConeConstraint*)realloc(this->circle_cone_constraints, circle_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::CircleConeConstraint));
      circle_cone_constraints_length = circle_cone_constraints_lengthT;
      for( uint32_t i = 0; i < circle_cone_constraints_length; i++){
      offset += this->st_circle_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_cone_constraints[i]), &(this->st_circle_cone_constraints), sizeof(robot_control_constraint_msgs::CircleConeConstraint));
      }
      uint32_t circle_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_cylinder_constraints_length);
      if(circle_cylinder_constraints_lengthT > circle_cylinder_constraints_length)
        this->circle_cylinder_constraints = (robot_control_constraint_msgs::CircleCylinderConstraint*)realloc(this->circle_cylinder_constraints, circle_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::CircleCylinderConstraint));
      circle_cylinder_constraints_length = circle_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < circle_cylinder_constraints_length; i++){
      offset += this->st_circle_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_cylinder_constraints[i]), &(this->st_circle_cylinder_constraints), sizeof(robot_control_constraint_msgs::CircleCylinderConstraint));
      }
      uint32_t circle_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_line_constraints_length);
      if(circle_line_constraints_lengthT > circle_line_constraints_length)
        this->circle_line_constraints = (robot_control_constraint_msgs::CircleLineConstraint*)realloc(this->circle_line_constraints, circle_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::CircleLineConstraint));
      circle_line_constraints_length = circle_line_constraints_lengthT;
      for( uint32_t i = 0; i < circle_line_constraints_length; i++){
      offset += this->st_circle_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_line_constraints[i]), &(this->st_circle_line_constraints), sizeof(robot_control_constraint_msgs::CircleLineConstraint));
      }
      uint32_t circle_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_plane_constraints_length);
      if(circle_plane_constraints_lengthT > circle_plane_constraints_length)
        this->circle_plane_constraints = (robot_control_constraint_msgs::CirclePlaneConstraint*)realloc(this->circle_plane_constraints, circle_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::CirclePlaneConstraint));
      circle_plane_constraints_length = circle_plane_constraints_lengthT;
      for( uint32_t i = 0; i < circle_plane_constraints_length; i++){
      offset += this->st_circle_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_plane_constraints[i]), &(this->st_circle_plane_constraints), sizeof(robot_control_constraint_msgs::CirclePlaneConstraint));
      }
      uint32_t circle_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circle_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circle_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circle_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circle_point_constraints_length);
      if(circle_point_constraints_lengthT > circle_point_constraints_length)
        this->circle_point_constraints = (robot_control_constraint_msgs::CirclePointConstraint*)realloc(this->circle_point_constraints, circle_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::CirclePointConstraint));
      circle_point_constraints_length = circle_point_constraints_lengthT;
      for( uint32_t i = 0; i < circle_point_constraints_length; i++){
      offset += this->st_circle_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->circle_point_constraints[i]), &(this->st_circle_point_constraints), sizeof(robot_control_constraint_msgs::CirclePointConstraint));
      }
      uint32_t cone_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_circle_constraints_length);
      if(cone_circle_constraints_lengthT > cone_circle_constraints_length)
        this->cone_circle_constraints = (robot_control_constraint_msgs::ConeCircleConstraint*)realloc(this->cone_circle_constraints, cone_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConeCircleConstraint));
      cone_circle_constraints_length = cone_circle_constraints_lengthT;
      for( uint32_t i = 0; i < cone_circle_constraints_length; i++){
      offset += this->st_cone_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_circle_constraints[i]), &(this->st_cone_circle_constraints), sizeof(robot_control_constraint_msgs::ConeCircleConstraint));
      }
      uint32_t cone_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_cone_constraints_length);
      if(cone_cone_constraints_lengthT > cone_cone_constraints_length)
        this->cone_cone_constraints = (robot_control_constraint_msgs::ConeConeConstraint*)realloc(this->cone_cone_constraints, cone_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConeConeConstraint));
      cone_cone_constraints_length = cone_cone_constraints_lengthT;
      for( uint32_t i = 0; i < cone_cone_constraints_length; i++){
      offset += this->st_cone_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_cone_constraints[i]), &(this->st_cone_cone_constraints), sizeof(robot_control_constraint_msgs::ConeConeConstraint));
      }
      uint32_t cone_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_cylinder_constraints_length);
      if(cone_cylinder_constraints_lengthT > cone_cylinder_constraints_length)
        this->cone_cylinder_constraints = (robot_control_constraint_msgs::ConeCylinderConstraint*)realloc(this->cone_cylinder_constraints, cone_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConeCylinderConstraint));
      cone_cylinder_constraints_length = cone_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < cone_cylinder_constraints_length; i++){
      offset += this->st_cone_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_cylinder_constraints[i]), &(this->st_cone_cylinder_constraints), sizeof(robot_control_constraint_msgs::ConeCylinderConstraint));
      }
      uint32_t cone_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_line_constraints_length);
      if(cone_line_constraints_lengthT > cone_line_constraints_length)
        this->cone_line_constraints = (robot_control_constraint_msgs::ConeLineConstraint*)realloc(this->cone_line_constraints, cone_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConeLineConstraint));
      cone_line_constraints_length = cone_line_constraints_lengthT;
      for( uint32_t i = 0; i < cone_line_constraints_length; i++){
      offset += this->st_cone_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_line_constraints[i]), &(this->st_cone_line_constraints), sizeof(robot_control_constraint_msgs::ConeLineConstraint));
      }
      uint32_t cone_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_plane_constraints_length);
      if(cone_plane_constraints_lengthT > cone_plane_constraints_length)
        this->cone_plane_constraints = (robot_control_constraint_msgs::ConePlaneConstraint*)realloc(this->cone_plane_constraints, cone_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConePlaneConstraint));
      cone_plane_constraints_length = cone_plane_constraints_lengthT;
      for( uint32_t i = 0; i < cone_plane_constraints_length; i++){
      offset += this->st_cone_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_plane_constraints[i]), &(this->st_cone_plane_constraints), sizeof(robot_control_constraint_msgs::ConePlaneConstraint));
      }
      uint32_t cone_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cone_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cone_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cone_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cone_point_constraints_length);
      if(cone_point_constraints_lengthT > cone_point_constraints_length)
        this->cone_point_constraints = (robot_control_constraint_msgs::ConePointConstraint*)realloc(this->cone_point_constraints, cone_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::ConePointConstraint));
      cone_point_constraints_length = cone_point_constraints_lengthT;
      for( uint32_t i = 0; i < cone_point_constraints_length; i++){
      offset += this->st_cone_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cone_point_constraints[i]), &(this->st_cone_point_constraints), sizeof(robot_control_constraint_msgs::ConePointConstraint));
      }
      uint32_t cylinder_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_circle_constraints_length);
      if(cylinder_circle_constraints_lengthT > cylinder_circle_constraints_length)
        this->cylinder_circle_constraints = (robot_control_constraint_msgs::CylinderCircleConstraint*)realloc(this->cylinder_circle_constraints, cylinder_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderCircleConstraint));
      cylinder_circle_constraints_length = cylinder_circle_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_circle_constraints_length; i++){
      offset += this->st_cylinder_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_circle_constraints[i]), &(this->st_cylinder_circle_constraints), sizeof(robot_control_constraint_msgs::CylinderCircleConstraint));
      }
      uint32_t cylinder_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_cone_constraints_length);
      if(cylinder_cone_constraints_lengthT > cylinder_cone_constraints_length)
        this->cylinder_cone_constraints = (robot_control_constraint_msgs::CylinderConeConstraint*)realloc(this->cylinder_cone_constraints, cylinder_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderConeConstraint));
      cylinder_cone_constraints_length = cylinder_cone_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_cone_constraints_length; i++){
      offset += this->st_cylinder_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_cone_constraints[i]), &(this->st_cylinder_cone_constraints), sizeof(robot_control_constraint_msgs::CylinderConeConstraint));
      }
      uint32_t cylinder_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_cylinder_constraints_length);
      if(cylinder_cylinder_constraints_lengthT > cylinder_cylinder_constraints_length)
        this->cylinder_cylinder_constraints = (robot_control_constraint_msgs::CylinderCylinderConstraint*)realloc(this->cylinder_cylinder_constraints, cylinder_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderCylinderConstraint));
      cylinder_cylinder_constraints_length = cylinder_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_cylinder_constraints_length; i++){
      offset += this->st_cylinder_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_cylinder_constraints[i]), &(this->st_cylinder_cylinder_constraints), sizeof(robot_control_constraint_msgs::CylinderCylinderConstraint));
      }
      uint32_t cylinder_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_line_constraints_length);
      if(cylinder_line_constraints_lengthT > cylinder_line_constraints_length)
        this->cylinder_line_constraints = (robot_control_constraint_msgs::CylinderLineConstraint*)realloc(this->cylinder_line_constraints, cylinder_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderLineConstraint));
      cylinder_line_constraints_length = cylinder_line_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_line_constraints_length; i++){
      offset += this->st_cylinder_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_line_constraints[i]), &(this->st_cylinder_line_constraints), sizeof(robot_control_constraint_msgs::CylinderLineConstraint));
      }
      uint32_t cylinder_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_plane_constraints_length);
      if(cylinder_plane_constraints_lengthT > cylinder_plane_constraints_length)
        this->cylinder_plane_constraints = (robot_control_constraint_msgs::CylinderPlaneConstraint*)realloc(this->cylinder_plane_constraints, cylinder_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderPlaneConstraint));
      cylinder_plane_constraints_length = cylinder_plane_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_plane_constraints_length; i++){
      offset += this->st_cylinder_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_plane_constraints[i]), &(this->st_cylinder_plane_constraints), sizeof(robot_control_constraint_msgs::CylinderPlaneConstraint));
      }
      uint32_t cylinder_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cylinder_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cylinder_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cylinder_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cylinder_point_constraints_length);
      if(cylinder_point_constraints_lengthT > cylinder_point_constraints_length)
        this->cylinder_point_constraints = (robot_control_constraint_msgs::CylinderPointConstraint*)realloc(this->cylinder_point_constraints, cylinder_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::CylinderPointConstraint));
      cylinder_point_constraints_length = cylinder_point_constraints_lengthT;
      for( uint32_t i = 0; i < cylinder_point_constraints_length; i++){
      offset += this->st_cylinder_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->cylinder_point_constraints[i]), &(this->st_cylinder_point_constraints), sizeof(robot_control_constraint_msgs::CylinderPointConstraint));
      }
      uint32_t line_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_circle_constraints_length);
      if(line_circle_constraints_lengthT > line_circle_constraints_length)
        this->line_circle_constraints = (robot_control_constraint_msgs::LineCircleConstraint*)realloc(this->line_circle_constraints, line_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::LineCircleConstraint));
      line_circle_constraints_length = line_circle_constraints_lengthT;
      for( uint32_t i = 0; i < line_circle_constraints_length; i++){
      offset += this->st_line_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_circle_constraints[i]), &(this->st_line_circle_constraints), sizeof(robot_control_constraint_msgs::LineCircleConstraint));
      }
      uint32_t line_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_cone_constraints_length);
      if(line_cone_constraints_lengthT > line_cone_constraints_length)
        this->line_cone_constraints = (robot_control_constraint_msgs::LineConeConstraint*)realloc(this->line_cone_constraints, line_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::LineConeConstraint));
      line_cone_constraints_length = line_cone_constraints_lengthT;
      for( uint32_t i = 0; i < line_cone_constraints_length; i++){
      offset += this->st_line_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_cone_constraints[i]), &(this->st_line_cone_constraints), sizeof(robot_control_constraint_msgs::LineConeConstraint));
      }
      uint32_t line_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_cylinder_constraints_length);
      if(line_cylinder_constraints_lengthT > line_cylinder_constraints_length)
        this->line_cylinder_constraints = (robot_control_constraint_msgs::LineCylinderConstraint*)realloc(this->line_cylinder_constraints, line_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::LineCylinderConstraint));
      line_cylinder_constraints_length = line_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < line_cylinder_constraints_length; i++){
      offset += this->st_line_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_cylinder_constraints[i]), &(this->st_line_cylinder_constraints), sizeof(robot_control_constraint_msgs::LineCylinderConstraint));
      }
      uint32_t line_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_line_constraints_length);
      if(line_line_constraints_lengthT > line_line_constraints_length)
        this->line_line_constraints = (robot_control_constraint_msgs::LineLineConstraint*)realloc(this->line_line_constraints, line_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::LineLineConstraint));
      line_line_constraints_length = line_line_constraints_lengthT;
      for( uint32_t i = 0; i < line_line_constraints_length; i++){
      offset += this->st_line_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_line_constraints[i]), &(this->st_line_line_constraints), sizeof(robot_control_constraint_msgs::LineLineConstraint));
      }
      uint32_t line_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_plane_constraints_length);
      if(line_plane_constraints_lengthT > line_plane_constraints_length)
        this->line_plane_constraints = (robot_control_constraint_msgs::LinePlaneConstraint*)realloc(this->line_plane_constraints, line_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::LinePlaneConstraint));
      line_plane_constraints_length = line_plane_constraints_lengthT;
      for( uint32_t i = 0; i < line_plane_constraints_length; i++){
      offset += this->st_line_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_plane_constraints[i]), &(this->st_line_plane_constraints), sizeof(robot_control_constraint_msgs::LinePlaneConstraint));
      }
      uint32_t line_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      line_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      line_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      line_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->line_point_constraints_length);
      if(line_point_constraints_lengthT > line_point_constraints_length)
        this->line_point_constraints = (robot_control_constraint_msgs::LinePointConstraint*)realloc(this->line_point_constraints, line_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::LinePointConstraint));
      line_point_constraints_length = line_point_constraints_lengthT;
      for( uint32_t i = 0; i < line_point_constraints_length; i++){
      offset += this->st_line_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->line_point_constraints[i]), &(this->st_line_point_constraints), sizeof(robot_control_constraint_msgs::LinePointConstraint));
      }
      uint32_t plane_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_circle_constraints_length);
      if(plane_circle_constraints_lengthT > plane_circle_constraints_length)
        this->plane_circle_constraints = (robot_control_constraint_msgs::PlaneCircleConstraint*)realloc(this->plane_circle_constraints, plane_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlaneCircleConstraint));
      plane_circle_constraints_length = plane_circle_constraints_lengthT;
      for( uint32_t i = 0; i < plane_circle_constraints_length; i++){
      offset += this->st_plane_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_circle_constraints[i]), &(this->st_plane_circle_constraints), sizeof(robot_control_constraint_msgs::PlaneCircleConstraint));
      }
      uint32_t plane_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_cone_constraints_length);
      if(plane_cone_constraints_lengthT > plane_cone_constraints_length)
        this->plane_cone_constraints = (robot_control_constraint_msgs::PlaneConeConstraint*)realloc(this->plane_cone_constraints, plane_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlaneConeConstraint));
      plane_cone_constraints_length = plane_cone_constraints_lengthT;
      for( uint32_t i = 0; i < plane_cone_constraints_length; i++){
      offset += this->st_plane_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_cone_constraints[i]), &(this->st_plane_cone_constraints), sizeof(robot_control_constraint_msgs::PlaneConeConstraint));
      }
      uint32_t plane_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_cylinder_constraints_length);
      if(plane_cylinder_constraints_lengthT > plane_cylinder_constraints_length)
        this->plane_cylinder_constraints = (robot_control_constraint_msgs::PlaneCylinderConstraint*)realloc(this->plane_cylinder_constraints, plane_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlaneCylinderConstraint));
      plane_cylinder_constraints_length = plane_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < plane_cylinder_constraints_length; i++){
      offset += this->st_plane_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_cylinder_constraints[i]), &(this->st_plane_cylinder_constraints), sizeof(robot_control_constraint_msgs::PlaneCylinderConstraint));
      }
      uint32_t plane_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_line_constraints_length);
      if(plane_line_constraints_lengthT > plane_line_constraints_length)
        this->plane_line_constraints = (robot_control_constraint_msgs::PlaneLineConstraint*)realloc(this->plane_line_constraints, plane_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlaneLineConstraint));
      plane_line_constraints_length = plane_line_constraints_lengthT;
      for( uint32_t i = 0; i < plane_line_constraints_length; i++){
      offset += this->st_plane_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_line_constraints[i]), &(this->st_plane_line_constraints), sizeof(robot_control_constraint_msgs::PlaneLineConstraint));
      }
      uint32_t plane_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_plane_constraints_length);
      if(plane_plane_constraints_lengthT > plane_plane_constraints_length)
        this->plane_plane_constraints = (robot_control_constraint_msgs::PlanePlaneConstraint*)realloc(this->plane_plane_constraints, plane_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlanePlaneConstraint));
      plane_plane_constraints_length = plane_plane_constraints_lengthT;
      for( uint32_t i = 0; i < plane_plane_constraints_length; i++){
      offset += this->st_plane_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_plane_constraints[i]), &(this->st_plane_plane_constraints), sizeof(robot_control_constraint_msgs::PlanePlaneConstraint));
      }
      uint32_t plane_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->plane_point_constraints_length);
      if(plane_point_constraints_lengthT > plane_point_constraints_length)
        this->plane_point_constraints = (robot_control_constraint_msgs::PlanePointConstraint*)realloc(this->plane_point_constraints, plane_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::PlanePointConstraint));
      plane_point_constraints_length = plane_point_constraints_lengthT;
      for( uint32_t i = 0; i < plane_point_constraints_length; i++){
      offset += this->st_plane_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->plane_point_constraints[i]), &(this->st_plane_point_constraints), sizeof(robot_control_constraint_msgs::PlanePointConstraint));
      }
      uint32_t point_circle_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_circle_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_circle_constraints_length);
      if(point_circle_constraints_lengthT > point_circle_constraints_length)
        this->point_circle_constraints = (robot_control_constraint_msgs::PointCircleConstraint*)realloc(this->point_circle_constraints, point_circle_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointCircleConstraint));
      point_circle_constraints_length = point_circle_constraints_lengthT;
      for( uint32_t i = 0; i < point_circle_constraints_length; i++){
      offset += this->st_point_circle_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_circle_constraints[i]), &(this->st_point_circle_constraints), sizeof(robot_control_constraint_msgs::PointCircleConstraint));
      }
      uint32_t point_cone_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_cone_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_cone_constraints_length);
      if(point_cone_constraints_lengthT > point_cone_constraints_length)
        this->point_cone_constraints = (robot_control_constraint_msgs::PointConeConstraint*)realloc(this->point_cone_constraints, point_cone_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointConeConstraint));
      point_cone_constraints_length = point_cone_constraints_lengthT;
      for( uint32_t i = 0; i < point_cone_constraints_length; i++){
      offset += this->st_point_cone_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_cone_constraints[i]), &(this->st_point_cone_constraints), sizeof(robot_control_constraint_msgs::PointConeConstraint));
      }
      uint32_t point_cylinder_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_cylinder_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_cylinder_constraints_length);
      if(point_cylinder_constraints_lengthT > point_cylinder_constraints_length)
        this->point_cylinder_constraints = (robot_control_constraint_msgs::PointCylinderConstraint*)realloc(this->point_cylinder_constraints, point_cylinder_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointCylinderConstraint));
      point_cylinder_constraints_length = point_cylinder_constraints_lengthT;
      for( uint32_t i = 0; i < point_cylinder_constraints_length; i++){
      offset += this->st_point_cylinder_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_cylinder_constraints[i]), &(this->st_point_cylinder_constraints), sizeof(robot_control_constraint_msgs::PointCylinderConstraint));
      }
      uint32_t point_line_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_line_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_line_constraints_length);
      if(point_line_constraints_lengthT > point_line_constraints_length)
        this->point_line_constraints = (robot_control_constraint_msgs::PointLineConstraint*)realloc(this->point_line_constraints, point_line_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointLineConstraint));
      point_line_constraints_length = point_line_constraints_lengthT;
      for( uint32_t i = 0; i < point_line_constraints_length; i++){
      offset += this->st_point_line_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_line_constraints[i]), &(this->st_point_line_constraints), sizeof(robot_control_constraint_msgs::PointLineConstraint));
      }
      uint32_t point_plane_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_plane_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_plane_constraints_length);
      if(point_plane_constraints_lengthT > point_plane_constraints_length)
        this->point_plane_constraints = (robot_control_constraint_msgs::PointPlaneConstraint*)realloc(this->point_plane_constraints, point_plane_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointPlaneConstraint));
      point_plane_constraints_length = point_plane_constraints_lengthT;
      for( uint32_t i = 0; i < point_plane_constraints_length; i++){
      offset += this->st_point_plane_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_plane_constraints[i]), &(this->st_point_plane_constraints), sizeof(robot_control_constraint_msgs::PointPlaneConstraint));
      }
      uint32_t point_point_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_point_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_point_constraints_length);
      if(point_point_constraints_lengthT > point_point_constraints_length)
        this->point_point_constraints = (robot_control_constraint_msgs::PointPointConstraint*)realloc(this->point_point_constraints, point_point_constraints_lengthT * sizeof(robot_control_constraint_msgs::PointPointConstraint));
      point_point_constraints_length = point_point_constraints_lengthT;
      for( uint32_t i = 0; i < point_point_constraints_length; i++){
      offset += this->st_point_point_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->point_point_constraints[i]), &(this->st_point_point_constraints), sizeof(robot_control_constraint_msgs::PointPointConstraint));
      }
     return offset;
    }

    virtual const char * getType() override { return "robot_control_constraint_msgs/Constraints"; };
    virtual const char * getMD5() override { return "5b97cf5af06932fba8efe9f465c6f2ab"; };

  };

}
#endif
