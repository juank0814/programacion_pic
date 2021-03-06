#include <16f688.h>             // libreria del pic
#device adc=10                  // 10 bit
#fuses hs,nowdt                 // xt para osc 4MHZ, hs para osc>4MHZ
#use delay(clock=8M)            // clock=8000000

void main()
{
   int conteo=0;                             // el conteo inicia en 0
   long int value;                           //almacenamiento de variables de tipo entero
   float Vin;                                //voltajes decimales 
   SETUP_ADC_PORTS(sAN2);                    //puertos a trabajar analogicamente y tension de referencia
   SETUP_ADC_PORTS(VSS_VREF);
   setup_adc(ADC_CLOCK_DIV_32);              //habilitar el modulo a/d con el reloj interno
  
   SET_TRIS_c(0x00);//� (0b00000000)         // todos los pines del puerto c son de salida
   OUTPUT_c(0x00);//�  (PIN_C2)              // el pin_c2 o todo el puerto c inicial abajo, limpia el puerto
      
   while (true){
      while (Vin>1){                      //garantizar que funcione solo cuando Vin sea mayor a 1 v
      set_adc_channel(2);                  //habilitar el canal 0 Analogico de las entradas analogicas
      delay_us(30);                        //minimo retardo para que se estabilice o cargue el capacitor
      value=read_adc();                    //leer el valor del conversor y almacenar en la variable value
      Vin=(3.3*value)/1024.0;              //es el valor en voltaje con formula de Vin
     
      if (Vin >=2.8){
               
               output_c(0b00000000);       //colocar en bajo barios pines del puerto c en este caso
               delay_us(1000);
               conteo++;
                                              
        }if (conteo=12) {
               //while(1);
               conteo=0;
               delay_ms(300);
        }       
        }
         output_c(0b00001000);   //colocar en alto barios pines del puerto c en este caso(c2, c3)
         delay_ms(300);
   }
}

