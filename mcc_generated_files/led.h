#ifndef __LED_H
#define __LED_H
#include "../xc.h"
#include "../mcc_generated_files/pin_manager.h"


#define LED1   PORTCbits.RC0
#define LED2   PORTCbits.RC2
#define LED3   PORTCbits.RC4

#define LED1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)

#define LED2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)

#define LED3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)


#endif 