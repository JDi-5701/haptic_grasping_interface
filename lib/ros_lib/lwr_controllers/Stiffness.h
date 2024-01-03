#ifndef _ROS_lwr_controllers_Stiffness_h
#define _ROS_lwr_controllers_Stiffness_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lwr_controllers
{

  class Stiffness : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _rx_type;
      _rx_type rx;
      typedef float _ry_type;
      _ry_type ry;
      typedef float _rz_type;
      _rz_type rz;

    Stiffness():
      x(0),
      y(0),
      z(0),
      rx(0),
      ry(0),
      rz(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->rx);
      offset += serializeAvrFloat64(outbuffer + offset, this->ry);
      offset += serializeAvrFloat64(outbuffer + offset, this->rz);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ry));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rz));
     return offset;
    }

    virtual const char * getType() override { return "lwr_controllers/Stiffness"; };
    virtual const char * getMD5() override { return "88d995302418aa13534aa14fc9aeed94"; };

  };

}
#endif
