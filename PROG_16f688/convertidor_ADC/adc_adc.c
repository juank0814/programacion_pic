#include <16f688.h>         // libreria del pic
#device adc=10             // 10 bit
#fuses hs,nowdt            // xt para osc 4MHZ, hs para osc>4MHZ
#use delay(clock=8M)       // clock=8000000

void main()
{
   int16 value;                        //almacenamiento de variables de tipo entero
   float Vin;                          //voltajes decimales 
   setup_adc_ports(1);               //establece el pin an2 en analógico
   setup_adc(ADC_CLOCK_DIV_8);      //habilitar el modulo a/d con el reloj interno
  
   set_tris_c(0b00000000);             // pines del puerto c son de salidad
       
   output_c(0b00000000);               // todos los pines del puerto c inician bajo
       
        
   while (true)
   {
      set_adc_channel(2);             //habilitar el canal 2 Analogico
      delay_ms(200);
      value=read_adc();               //leer el valor del conversor y almacenar en la variable value
      Vin=(5.0*value)/1024.0;         //es el valor en voltaje con formula de Vin
     
      if (Vin > 1){
               output_c(0b00001100);   //prender el pin_c2,c3
               delay_ms(1000);
                //printf("Eres mayor de edad.\n");
        }else {
                output_c(0b00000000);   //apagar el pin_c2,c3
                delay_ms(5000);
                //printf("no eres mayor de edad.\n");
        }
     
     
   }
}

