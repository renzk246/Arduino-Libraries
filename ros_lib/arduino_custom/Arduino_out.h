#ifndef _ROS_arduino_custom_Arduino_out_h
#define _ROS_arduino_custom_Arduino_out_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arduino_custom
{

  class Arduino_out : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef float _steering_type;
      _steering_type steering;
      typedef float _throttle_type;
      _throttle_type throttle;
      typedef bool _button1_type;
      _button1_type button1;
      typedef bool _button2_type;
      _button2_type button2;

    Arduino_out():
      message(""),
      steering(0),
      throttle(0),
      button1(0),
      button2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        float real;
        uint32_t base;
      } u_steering;
      u_steering.real = this->steering;
      *(outbuffer + offset + 0) = (u_steering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        bool real;
        uint8_t base;
      } u_button1;
      u_button1.real = this->button1;
      *(outbuffer + offset + 0) = (u_button1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button1);
      union {
        bool real;
        uint8_t base;
      } u_button2;
      u_button2.real = this->button2;
      *(outbuffer + offset + 0) = (u_button2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        float real;
        uint32_t base;
      } u_steering;
      u_steering.base = 0;
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering = u_steering.real;
      offset += sizeof(this->steering);
      union {
        float real;
        uint32_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        bool real;
        uint8_t base;
      } u_button1;
      u_button1.base = 0;
      u_button1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button1 = u_button1.real;
      offset += sizeof(this->button1);
      union {
        bool real;
        uint8_t base;
      } u_button2;
      u_button2.base = 0;
      u_button2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button2 = u_button2.real;
      offset += sizeof(this->button2);
     return offset;
    }

    virtual const char * getType() override { return "arduino_custom/Arduino_out"; };
    virtual const char * getMD5() override { return "fbd26a5edd96189cd71e7a944c9cf8a9"; };

  };

}
#endif
