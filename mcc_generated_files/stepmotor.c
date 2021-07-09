#include "stepmotor.h"

static void StepMotorRun_Down(void);

/*********************************************************************
	*
	*Function Name:void SetMotorMicorstep_Par(unsigned char mo)
	*Funciton :key input value of response active
	*Input Ref: input key pressed of value .
	*Return Ref: NO
	*
*********************************************************************/
void SetMotorMicorstep_Par(unsigned char mo)
{
	switch(mo){

	case full_step: //0
         //MODE 2 ->RA1
		MODE2_RA1_SetLow() ;           
		//MODE 1->RA2
         MODE1_RA2_SetLow() ;        
		//MODE 0->RA3
		MODE0_RA3_SetLow() ;            

	break;

	case half_step:
		  //MODE 2 ->RA1
		MODE2_RA1_SetLow() ;           
		//MODE 1->RA2
         MODE1_RA2_SetLow() ;        
		//MODE 0->RA3
		MODE0_RA3_SetHigh() ;      

	break;

	case quarter_step://2
          //MODE 2 ->RA1
		MODE2_RA1_SetLow() ;           
		//MODE 1->RA2
         MODE1_RA2_SetHigh() ;        
		//MODE 0->RA3
		MODE0_RA3_SetLow() ;     

	break;

	case one_eighth://3
		   //MODE 2 ->RA1
		MODE2_RA1_SetLow() ;           
		//MODE 1->RA2
         MODE1_RA2_SetHigh() ;        
		//MODE 0->RA3
		MODE0_RA3_SetHigh() ;   

	break;

	case one_sixteenth://4
		    //MODE 2 ->RA1
		MODE2_RA1_SetHigh() ;           
		//MODE 1->RA2
         MODE1_RA2_SetLow() ;        
		//MODE 0->RA3
		MODE0_RA3_SetLow() ;   

	break;

	case one_thirty_two://5
		     //MODE 2 ->RA1
		MODE2_RA1_SetHigh() ;           
		//MODE 1->RA2
         MODE1_RA2_SetHigh() ;        
		//MODE 0->RA3
		MODE0_RA3_SetHigh() ; 

	break;

	default:

	break;



	}


}
/****************************************************************************
	*
	*Function Name:void StepMotorInit(void)
	*Function :
	*
	*
	*
*****************************************************************************/
void StepMotorInit(void)
{
   IO_RA1_SetLow(); //drv8825->MODE0
   IO_RA2_SetLow(); //drv8825->MODE1
   IO_RA3_SetLow(); //drv8825->MODE2

   IO_RA5_SetHigh();//drv8825->Enable 1:diable 0-enable

   IO_RC3_SetLow()  ; //drv8825-> 0:reset 1:driver

   IO_RA6_SetLow(); //drv8825-> 0:sleep 1:driver

   IO_RA7_SetHigh(); //drv8825-> 1:fast decay

}
/****************************************************************************
	*
	*Function Name:StepMotorRun_FullStep();
	*Function :
	*
	*
	*
*****************************************************************************/
void StepMotorRun_FullStep(void)
{
     SetMotorMicorstep_Par(0); //full step 
	 TMR2_Start(); //rpm =300
	 SetMotor_Start();
}

/****************************************************************************
	*
	*Function Name:void StepMotorRun(void);
	*Function :
	*
	*
	*
*****************************************************************************/
void SetMotor_Start(void)
{
	//MOTOR ENABLE 
	 ENABLE_RA5_SetLow() ;    //drv8825->Enable 1:diable 0-enable      
	//MOTOR RESET
	 RESET_RC3_SetHigh()  ;     //drv8825-> 0:reset 1:driver    

	//MOTOR SLEEP
	 SLEEP_RA6_SetHigh(); //drv8825-> 0:sleep 1:driver         

	//MOTOR DECAY
	 DECAY_RA7_SetHigh()  ;//  //drv8825-> 1:fast decay,0: slow decay :open: mixed decay    
}
/****************************************************************************
	*
	*Function Name:void StepMotorRun(void);
	*Function :
	*
	*
	*
*****************************************************************************/

void StepMotorStop(void)
{
      TMR2_Stop();
}

/****************************************************************************
	*
	*Function Name:void SetMotorRun_HalfStep(void)
	*Function :
	*
	*
	*
*****************************************************************************/
void SetMotorRun_HalfStep(void)
{

	SetMotorMicorstep_Par(3); //full step 
	TMR2_Start();
	SetMotor_Start();
}
/****************************************************************************
	*
	*Function Name:void SetMotorRun_EighthStep(void)
	*Function :
	*
	*
	*
*****************************************************************************/
void SetMotorRun_EighthStep(void)
{
    SetMotorMicorstep_Par(3); //2//full step 
	TMR2_Start();
	SetMotor_Start();


}


