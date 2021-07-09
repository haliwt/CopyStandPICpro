#ifndef __SENSOR_H
#define __SENSOR_H

#include "../xc.h"
#include "../mcc_generated_files/pin_manager.h"

#define	SetBit(x,y)	((x) |= (1 << (y)))				// set   1
#define	ClrBit(x,y)	((x) &= ~ (1 << (y)))			// clear 0

#define	bit0(x,y)		(((x) & (1 << (y))) == 0)		//?0?? if(b0(x,y)) ?????0
#define	bit1(x,y)		((x) & (1 << (y)))				//?1?? if(b1(x,y)) ?????1

void LED_Initialize(void);



#endif