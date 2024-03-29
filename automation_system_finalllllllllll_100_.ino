#include <NewPing.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//sensor pins
#define e_s1 5//echo pin
#define t_s1 6 //Trigger pin

#define e_s2 9 //echo pin
#define t_s2 7 //Trigger pin

int relay = 8; // Out for light

long dis_a=0,dis_b=0;
unsigned int person=0;


void ultra_read(int pin_t,int pin_e,long &ultra_time){
long time;
pinMode(pin_t,OUTPUT);
pinMode(pin_e,INPUT);
digitalWrite(pin_t,HIGH);
delayMicroseconds(2);
digitalWrite(pin_t,LOW);
delayMicroseconds(10);
time=pulseIn (pin_e,HIGH);
ultra_time =  time / 29 / 2;
}


void setup(){
Serial.begin(9600);
P.begin();
// Set the intensity (brightness) of the display (0-15)
  P.setIntensity(15);
pinMode(relay, OUTPUT);


delay(0); //

}

void loop(){

ultra_read(t_s1,e_s1,dis_a);delay(30);
ultra_read(t_s2,e_s2,dis_b);delay(30);


Serial.print("da:");Serial.println(dis_a);
Serial.print("db:");Serial.println(dis_b);
Serial.print("person:");Serial.println(person);
Serial.print("    ");  
 

if(dis_a<40 ){

 person = person + 1;
 digitalWrite(e_s2,LOW);
 delay(3000);
 digitalWrite(e_s2,HIGH);
 
}

if(dis_b<40)
{
 person = person - 1;
 digitalWrite(e_s1,LOW);
 delay(3000);
 digitalWrite(e_s1,HIGH);
  }


  personCounter();
 
  P.setTextAlignment(PA_CENTER);
  P.print(person);
}
void personCounter(){
  if(person>0){
    digitalWrite(relay,  HIGH);
  }
  else{
    digitalWrite(relay, LOW);
  }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
