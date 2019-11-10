#include "Tone.h"
#include "tm4c123gh6pm.h"
#include "SysTick.h"

const int sineTable[256]={128,131,134,137,140,143,146,149,
152,156,159,162,165,168,171,174,
176,179,182,185,188,191,193,196,
199,201,204,206,209,211,213,216,
218,220,222,224,226,228,230,232,
234,235,237,239,240,242,243,244,
246,247,248,249,250,251,251,252,
253,253,254,254,254,255,255,255,
255,255,255,255,254,254,253,253,
252,252,251,250,249,248,247,246,
245,244,242,241,239,238,236,235,
233,231,229,227,225,223,221,219,
217,215,212,210,207,205,202,200,
197,195,192,189,186,184,181,178,
175,172,169,166,163,160,157,154,
151,148,145,142,138,135,132,129,
126,123,120,117,113,110,107,104,
101,98,95,92,89,86,83,80,
77,74,71,69,66,63,60,58,
55,53,50,48,45,43,40,38,
36,34,32,30,28,26,24,22,
20,19,17,16,14,13,11,10,
9,8,7,6,5,4,3,3,
2,2,1,1,0,0,0,0,
0,0,0,1,1,1,2,2,
3,4,4,5,6,7,8,9,
11,12,13,15,16,18,20,21,
23,25,27,29,31,33,35,37,
39,42,44,46,49,51,54,56,
59,62,64,67,70,73,76,79,
81,84,87,90,93,96,99,103,
106,109,112,115,118,121,124,128}; 

void sawtoothWave(int delay){
	unsigned int i; 
	for (i = 0; i < 256; i++){
		GPIO_PORTB_DATA_R = i ; 	
		SysTick_Wait(5100); 
	}
}

void triangleWave(int delay){
	unsigned int i; 
	for (i = 0; i < 256; i++){
		GPIO_PORTB_DATA_R = i; 
		SysTick_Wait(delay);
	}
	 
	for (i = 255; i>0; i--){
		GPIO_PORTB_DATA_R = i; 
		SysTick_Wait(delay); 
	}
}

void squareWave (int delay){
	unsigned int i; 
	for (i = 0; i < 256; i++){
		GPIO_PORTB_DATA_R = 0xFF; 
		SysTick_Wait(delay);
	}
	 
	for (i = 255; i>0; i--){
		GPIO_PORTB_DATA_R = 0x00; 
		SysTick_Wait(delay); 
	}
}
void sineWave(int delay){	
	unsigned int i ; 
	for(i=0; i<256; i++){
		GPIO_PORTB_DATA_R = sineTable[i]; 
		SysTick_Wait(delay); 
	}
}


void Init_PortB(void){ 
  SYSCTL_RCGC2_R |= 0x00000002;     // 1) B clock
  GPIO_PORTB_CR_R |= 0xFF;           // allow changes to PB7-0      
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R = 0xFF  ;          // 5) PB7-PB0 output 
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTB_DEN_R |= 0xFF;          // 7) enable digital pins P7-PB0   
}
