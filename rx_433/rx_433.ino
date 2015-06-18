/*
ver ::cl 20120520
Configuracion basica para modulo receptor  RR 10
Utiliza libreria VirtualWire.h
pin 01 5v
pin 02 Tierra
pin 03 antena externa
pin 07 tierra
pin 10 5v
pin 11 tierra
pin 12 5v
pin 14 Arduino pin digital 2
pin 15 5v
*/

#include <VirtualWire.h>

void setup(){
    Serial.begin(9600);
    Serial.println("Configurando Recepcion");
    vw_set_ptt_inverted(true); 
    vw_setup(2000);
    vw_set_rx_pin(2);
    vw_rx_start();
}
int cont = 0;
unsigned long inicio = millis();

void loop(){
    
 if(millis()-inicio < 1000){
   uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)){
        char m[5]="H";
        digitalWrite(13, true);
	
	m[0] = (char)buf[0];
	
        cont += 1;
        digitalWrite(13, false);
 
       } 
    }else{
      Serial.println(cont);
            inicio = millis();
      cont = 0;

    }
}
