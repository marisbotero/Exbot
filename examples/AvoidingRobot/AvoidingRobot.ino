#include<Exbot.h>
int VelI=255,VelD=255; //No esta permitido usar VI y VD
int Presencia=0;
int Umbral=70;
void setup(){

  MI.Init(5,4);//Inicializacion de Motor Izquierdo
  MD.Init(6,7);//Inicializacion de Motor Derecho
  IniciarSensorPresenciaIR(A0,2);
  Serial.begin(9600);

}

void loop(){
  Presencia=LeerPresencia();
  
  if (Presencia<Umbral){
  MI.Adelante(VelI);
  MD.Adelante(VelI);
  
  
  }else{
  
  //Secuencia Sencilla
  MI.Adelante(VelI);
  MD.Atras(VelI);
  delay(800);
  }
  
}

