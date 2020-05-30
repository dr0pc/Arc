/*#Universidad Mariano Galvez
  #Proyecto Arquitectura de Computadoras */
#include <Servo.h>    //libreria para utilizacion de Servos
Servo servoMotor;     //Declaracion de Servos como variables
Servo servoMotora;
Servo servoMotorb;

/*###########################DECLARACION DE VARIABLES*/
char ESTADO;  //Indicador ON OFF del sistema
int C_ESFERAS; //Contador Esferas
int CA;   //contenedor A
int CB;   //contenedor B
int CC;   //contenedor C
int CD;  //Finalizacion del programa

void setup() {
Serial.begin(9600); 
/*###########################INICIALIZACION DE VARIABLES*/
C_ESFERAS = 7;      //Cantidad de Esferas
CA =0;
CB =0;
CC =0;
/*###########################INICIALIZACION DE SERVOMOTORES*/    
  servoMotor.attach(9);
  servoMotora.attach(11);
  servoMotorb.attach(13);
  servoMotora.write(185);
  servoMotorb.write(40);
}

void loop() {
/*###########################VERIFICAMOS QUE EXISTAN ESFERAS Y CONTENEDORES DISPONIBLES*/    
  
  if (C_ESFERAS > 0 && CD!=3){
     delay(2000);
/*###########################ENVIO DE INFORMACION POR BLUETOOTH*/    

    Serial.print(CA);
    Serial.print(CB);
    Serial.print(CC);
    Serial.print(C_ESFERAS);
/*###########################COLOCACION DE SERVOS EN POCICION NEUTRAL*/    

    servoMotor.write(90);
    servoMotora.write(185);
    servoMotorb.write(40);
    delay(1000);
    servoMotor.write(158);
    delay(1000);

/*########################VALIDACION DE ESPACIO Y LLENADO EN CONTENEDOR A*/    
  
      if(CA <3)
        {
          CA++;
            servoMotora.write(120);
            servoMotorb.write(40);
            delay(500);
          }
          
/*########################VALIDACION DE ESPACIO Y LLENADO EN CONTENEDOR B*/    
          else if (CB <2)
          {
            CB++;
            servoMotora.write(185);
            servoMotorb.write(40);
            delay(4000);
            }
            
/*########################VALIDACION DE ESPACIO Y LLENADO EN CONTENEDOR C*/    
        else if (CC <2)
          {
            CC++;
            servoMotora.write(185);
            servoMotorb.write(100);
            delay(4000);
            }
            
/*########################VALIDACION DE ESPACIO Y LLENADO EN CONTENEDOR C*/    
      if(CA==3 && CB==2 && CC==2){
        CD=3;
        }

 /*########################DISMINUCION DE ESFERAS EN UNO Y ENVIO DE INFORMACION POR BLUETOOTH*/    
    C_ESFERAS--;
    delay(2000);
   Serial.print(CA);
  Serial.print(CB);
  Serial.print(CC);
  Serial.print(C_ESFERAS);
  }
}
