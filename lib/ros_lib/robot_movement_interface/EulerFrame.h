#ifndef _ROS_robot_movement_interface_EulerFrame_h
#define _ROS_robot_movement_interface_EulerFrame_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robot_movement_interface
{

  class EulerFrame : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _alpha_type;
      _alpha_type alpha;
      typedef float _beta_type;
      _beta_type beta;
      typedef float _gamma_type;
      _gamma_type gamma;

    EulerFrame():
      x(0),
      y(0),
      z(0),
      alpha(0),
      beta(0),
      gamma(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_alpha;
      u_alpha.real = this->alpha;
      *(outbuffer + offset + 0) = (u_alpha.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alpha.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alpha.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alpha.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alpha);
      union {
        float real;
        uint32_t base;
      } u_beta;
      u_beta.real = this->beta;
      *(outbuffer + offset + 0) = (u_beta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->beta);
      union {
        float real;
        uint32_t base;
      } u_gamma;
      u_gamma.real = this->gamma;
      *(outbuffer + offset + 0) = (u_gamma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gamma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gamma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gamma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gamma);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_alpha;
      u_alpha.base = 0;
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alpha.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alpha = u_alpha.real;
      offset += sizeof(this->alpha);
      union {
        float real;
        uint32_t base;
      } u_beta;
      u_beta.base = 0;
      u_beta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_beta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_beta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_beta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->beta = u_beta.real;
      offset += sizeof(this->beta);
      union {
        float real;
        uint32_t base;
      } u_gamma;
      u_gamma.base = 0;
      u_gamma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gamma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gamma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gamma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gamma = u_gamma.real;
      offset += sizeof(this->gamma);
     return offset;
    }

    virtual const char * getType() override { return "robot_movement_interface/EulerFrame"; };
    virtual const char * getMD5() override { return "a80a1671d4b1c7800db798b2cad836f8"; };

  };

}
#endif
