#include <16F688.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES HS                    	//High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES MCLR                  	//Master Clear pin enabled
#FUSES NOCPD                 	//No EE protection
#FUSES NOPUT                 	//No Power Up Timer
#FUSES IESO                  	//Internal External Switch Over mode enabled
#FUSES FCMEN                 	//Fail-safe clock monitor enabled
#FUSES RESERVED              	//Used to set the reserved FUSE bits

#use delay(clock=8000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

