#ifndef __STEPMOTOR_H_
#define __STEPMOTOR_H_
#include "run.h"
#include <xc.h>
#include "pin_manager.h"
#include "tmr2.h"

//MODE 2 ->RA1
#define MODE2_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define MODE2_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
//MODE 1->RA2
#define MODE1_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define MODE1_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
//MODE 0->RA3
#define MODE0_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define MODE0_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)

//MOTOR ENABLE 
#define ENABLE_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define ENABLE_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
//MOTOR RESET
#define RESET_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RESET_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
//MOTOR SLEEP
#define SLEEP_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define SLEEP_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
//MOTOR DECAY
#define DECAY_RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define DECAY_RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
//MOTOR DIRECTION
#define CCW_RA4_SetHigh()              do { LATAbits.LATA4 = 1; } while(0)
#define CW_RA4_SetLow()                do { LATAbits.LATA4 = 0; } while(0)

typedef enum mciromodel{



    full_step,half_step,quarter_step,one_eighth,one_sixteenth,one_thirty_two

};

void (*motorRunMode)(void);

void StepMotorInit(void);
void StepMotorRun_FullStep();

void StepMotorStop(void);
void SetMotorMicorstep_Par(unsigned char mo);
void SetMotor_Start(void);
void SetMotorRun_HalfStep(void);
void SetMotorRun_EighthStep(void);


#endif 