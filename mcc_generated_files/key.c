#include "key.h"


unsigned char  KEY_Function(void)
{
  
  unsigned char  KeyValue=0;
   if(KEY_DOWN_FAST()==0){//if(KEY_DOWN_SLOWLY() ==0){ //RB3
       
		return 0x10;  //motor run is CCW 
   }

   if(KEY_DOWN_SLOWLY() ==0){  //if(KEY_DOWN_FAST()==0){ //RB2
   	  
	   return 0x11;
   }
   
  if(KEY_UP_FAST()==0){ //if(KEY_UP_SLOWLY()==0){ //RB5
      
	  return 0x20;//MOTOR run is CW
 

   if(KEY_UP_SLOWLY()==0){//if(KEY_UP_FAST()==0){ //RB4
      
	    return 0x22;
    }
  

    return KeyValue ;



}