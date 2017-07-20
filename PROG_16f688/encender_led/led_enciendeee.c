#include <16f688.h>               // libreria del pic
#fuses hs,nowdt                   // xt para osc 4MHZ, hs para osc>4MHZ
#use delay(clock=8M)              // clock=20000000

void main()
{

   SET_TRIS_c(0x00);//� (0b00000000)     // todos los pines del puerto c son de salida
   //SET_TRIS_c(0b11111111);             // todos los pines del puerto c son de entrada
   //SET_TRIS_c(0b11110000;              // pines B7-B4 son de entrada y pines B3-B0 son de salida
   
   OUTPUT_c(PIN_C2);//�  (0x00)          // el pin_c2 o todo el puerto c inicial abajo, limpia el puerto
   //INPUT_c(PIN_C2);//� (0x00)          // el pin_c2 o todo el puerto c inicial abajo

   while(true)
   {
      OUTPUT_HIGH(PIN_C2);               // colocar en alto el pin_c2
      //output_c(0b00001100);            //� colocar en alto barios pines del puerto c en este caso(c2, c3)
      delay_ms(200);
      
      OUTPUT_LOW(PIN_C2);                // colocar en bajo el pin_c2
      //output_c(0b00000000);            //� colocar en bajo barios pines del puerto c 
      delay_ms(200);
   }
}


