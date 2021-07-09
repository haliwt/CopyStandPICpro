#include "run.h"

par par_t; 
/*********************************************************************
	*
	*Function Name:void CheckMode(uint8_t KeyTemp)
	*Funciton :key input value of response active
	*Input Ref: input key pressed of value .
	*Return Ref: NO
	*
*********************************************************************/
void CheckMode( unsigned char KeyTemp)
{
      switch(KeyTemp){

	   case 0:
	        motor_t.motorRunMode=nothing;
			par_t.stepTimeCounter=0;
			par_t.accel =0;
			StepMotorStop();
			TMR0_StopTimer(); //
		break;

       case 0x10: //Down motor run : slowly 
           par_t.motorSpeed =0x10;
		   IO_RA4_SetLow(); //Dir
		   par_t.dir=1;
	       motor_t.motorRunMode=downSlowly;
		    TMR0_StartTimer(); //
		   KeyTemp=0;
	   break;

	   case 0x11: //Down motor run :faster 
	         IO_RA4_SetLow();
		    par_t.dir=1;
            par_t.motorSpeed =downFast;
		    motor_t.motorRunMode=downFast;
		    TMR0_StartTimer(); //
			KeyTemp=0;
	   break;

	   case 0x20: //Up motor run :slowly
	         IO_RA4_SetHigh();
		    par_t.dir=2;
            par_t.motorSpeed =upFast;
		    motor_t.motorRunMode=upSlowly;
			TMR0_StartTimer(); //
             KeyTemp=0;
	   break;

	   case 0x22: //UP motor run :faster
	        IO_RA4_SetHigh();
		   par_t.dir=2;
           par_t.motorSpeed =upFast;
		   motor_t.motorRunMode=upFast;
		   TMR0_StartTimer(); //
		   KeyTemp=0;

	   break;
         default :
		
	   break;
      }

}
/*********************************************************************
	*
	*Function Name:void CheckRun(void)
	*Funciton :key input value of response active
	*Input Ref: input key pressed of value .
	*Return Ref: NO
	*
*********************************************************************/
void CheckRun(void)
{
   
 
	 switch( motor_t.motorRunMode){

        case nothing: //0
		    par_t.run_state =0;
            StepMotorStop();
			TMR0_StopTimer(); //
	    break;

		case downSlowly:  //1 down
          
		   if(motor_t.motorStopFlag ==0x10){
			  par_t.stepTimeCounter=0;
			   par_t.accel =0;
			   par_t.run_state =0;
			   StepMotorStop();
			   TMR0_StopTimer(); //
			}
		   else{
			    par_t.run_state++;
				if(par_t.run_state> 310)par_t.run_state =360;
			     motor_t.motorStopFlag=0;
			   if(par_t.run_state <260){
			   	    PWM3_LoadDutyValue(899);//duty cycle 50% T=2ms
			        SetMotorRun_EighthStep();//StepMotorRun_FullStep();//SetMotorRun_EighthStep();
			 	   	par_t.stepTimeCounter=260;
			 	}
		   	    else{
					 PWM3_LoadDutyValue(799);//duty cycle 50% T=2ms
				     SetMotorRun_HalfStep(); //1/8
		   	    }
		   }

	    break;

		case downFast:  //2
		    if(motor_t.motorStopFlag ==0x10){
			   par_t.stepTimeCounter=0;
			   par_t.accel =0;
			   par_t.run_state =0;
               StepMotorStop();
			   TMR0_StopTimer(); //
			  
		   }
		   else{
				 par_t.run_state++;
				 motor_t.motorStopFlag=0;
			    PWM3_LoadDutyValue(899);//duty cycle 80% T=2ms
			   	StepMotorRun_FullStep();
			   	  
		   	}

		break;
        //Motor Up run **********************************************
		case upSlowly: //3

		  if(motor_t.motorStopFlag==0x20){
			     par_t.run_state =0;
				 par_t.stepTimeCounter=0;
				 par_t.accel =0;
				 StepMotorStop();
				 TMR0_StopTimer(); //
				
		  }
		  else{
			par_t.run_state ++;
			if(par_t.run_state> 310)par_t.run_state =360;
		  	motor_t.motorStopFlag=0;
            if(par_t.run_state <260){
				    PWM3_LoadDutyValue(899);//duty cycle 80% T=2ms
			        SetMotorRun_EighthStep();//StepMotorRun_FullStep();//SetMotorRun_EighthStep();
			 	   	par_t.stepTimeCounter=260;
		   }
		   else{
				  PWM3_LoadDutyValue(799);//duty cycle 50% T=2ms
				  SetMotorRun_HalfStep();
		   	  }
		  } 

		break;

		case upFast:  //4
           if(motor_t.motorStopFlag==0x20){
			    par_t.run_state =0;
			    par_t.stepTimeCounter=0;
				 par_t.accel =0;
		       StepMotorStop();
			   TMR0_StopTimer(); //
			   
		  }
		  else{
		  	 par_t.run_state++;
			 motor_t.motorStopFlag=0;
			
		    PWM3_LoadDutyValue(899);//duty cycle 80% T=2ms    
			StepMotorRun_FullStep();
				
		  	}
		break;

		default:

		break;


	  }



}




