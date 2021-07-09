#ifndef __RUN_H_
#define __RUN_H_
#include <xc.h>
#include "key.h"
#include "led.h"
#include "stepmotor.h"
#include "pwm3.h"
#include "tmr0.h"


typedef struct
{
 unsigned char  dir ;
 unsigned char  fastSpeed;
 unsigned char  motorSpeed;
 unsigned int   stepTimeCounter; //motor in timer0 counter
 unsigned int  run_state;
 unsigned char  stop;
 unsigned char  accel;
 unsigned char  decel;

}par;


typedef struct
{
    unsigned char motorRunSlowly_Up;
    unsigned char motorRunFast_Up;
    unsigned char motorRunSlowly_Down;
    unsigned char  motorRunFast_Down;
    unsigned char motorStopFlag;
    unsigned char motorRunFlag;
    unsigned char motorRunMode;

}motor;

motor motor_t;
enum _dir{nothing,downSlowly,downFast,upSlowly,upFast};

extern par par_t; 


void CheckMode( unsigned char KeyValueTemp);
void CheckRun(void);








#endif
