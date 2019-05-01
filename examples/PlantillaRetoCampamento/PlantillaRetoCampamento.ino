//Este es un ejemplo de programación.
//Todo lo que veas escrito de despues de // es un comentario
//
//Esto quiere decir que no será cargado al Arduino

/* Asi se inicia un comentario de varias lineas

  Las conexiones son las siguientes
  
  Motor A ---> Pines 4 y 6. (Motor de Puertas)
 
  Ventilador -> Pin 7.  
  L1 -------> Pin 8.
  L2 -------> Pin 9.
  L3 -------> Pin 10.
  L4 -------> Pin 11.
  L5 -------> Pin 12.
  L6(BUZZER-> Pin 13.
  
  Fotorresistencia ---> A3
  Sensor de Luz  --->A0

Asi se termina un comentario de varias lineas */

char BUFF[100];//NO BORRAR
String MyStr;// NO BORRAR
int SensorPresencia=0,SensorLuz=0; //En estas lineas se declaran las variables para los sensores.

void setup(){
  //Inicialización pines NO MODIFICAR
  Serial.begin(9600); 
  for(int i=2;i<14;i++){
  pinMode(i,OUTPUT);  
  }
}

void loop(){
  
  if(Serial.available()){
    int numR;// NO BORRAR  //Este es un un numero para saber cuantos datos se han recibido
     numR=Serial.readBytesUntil('\n',BUFF,100);//Esos leen los datos
     BUFF[numR]=0; //NO BORRAR
     Serial.println(int(BUFF[numR-1])); //NO BORRAR
     MyStr=String(BUFF); //NO BORRAR
 
     Serial.println(MyStr); //Escribe en pantalla el comando recibido
      
      if(MyStr=="AbrirP\r"){ 
        //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "AbrirP"
        //Siempre se debe agregar \r al final.
        digitalWrite(4,HIGH); 
        digitalWrite(6,LOW);
        delay(800);
        digitalWrite(4,LOW); 
        digitalWrite(6,LOW);
 
      }
      else if(MyStr=="CerrarP\r"){
       //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "CerrarP"
        //Siempre se debe agregar \r al final que equivale a la tecla enter.
        
        digitalWrite(4,LOW); //Estas dos lineas encienden el motor.
        digitalWrite(6,HIGH);//Estas dos lineas encienden el motor.
        delay(800);
        digitalWrite(4,LOW); //Estas dos lineas apagan el motor.
        digitalWrite(6,LOW);//Estas dos lineas apagan el motor.
    
      }else if(MyStr=="L1ON\r"){
      //Estas es la accion que vas a realizar cuando reciban las letras "L1ON"
       //En este lugar debes agregar la acción necesaria para encender la luz 2  
       digitalWrite(8,HIGH);  
      }//-------------------------------------------------------------
      //----Para cada luz debes copiar lo que hay entre los guiones--------------
      else if(MyStr=="L1OFF\r"){
      //Estas son las acciones que se van a ejecutar
      //cuando se reciban las letras "L1ON"
      //En este lugar debes agregar la acción necesaria para apagar la luz 1 
       digitalWrite(8,LOW); 
      }//-------------------------------------------------------------
     //----Para cada luz debes copiar lo que hay entre los guiones--------------
      else if(MyStr=="L2ON\r"){
      //Estas son las acciones que se van a ejecutar
      //cuando se reciban las letras "L1ON"
       //En este lugar debes agregar la acción necesaria para encender la luz 2 ahora si por tu cuenta.
        
        
      }//-------------------------------------------------------------
   
     
  }  

//A partir de este punto el codigo se encargar leer la alarma y hacer sonar
SensorPresencia=analogRead(A0); //Se lee el valor del sensor de Presencia.
delay(2); //tiempo de espera
if(SensorPresencia<200){ // Esta valor debe ser cambiado de acuerdo a las condiciones del ambiente.
  digitalWrite(3,HIGH); //Enciende la alarma
  Serial.println("AON"); //Se le dice a la aplicacion que encienda la alarma
}else{
  digitalWrite(3,LOW); //Apaga la alarm
  Serial.println("AOFF");//Se le dice a la aplicacion que apague la alarma
}

Serial.print("Presencia:"); //NO BORRAR // Lineas para notificar el valor al celular.
Serial.println(SensorPresencia);// NO BORRAR // Lineas para notificar el valor al celular.


//Luz Automática
SensorLuz=analogRead(A3); //Se lee el valor del sensor de Presencia.
delay(2);
if(SensorLuz<200){ // Esta valor debe ser cambiado de acuerdo a las condiciones del ambiente.
  //Aquí debes agregar tu codigo para encender la luz automatica.
  Serial.println("LuzON");
}else{
  //Aquí debes agregar tu codigo para apagar la luz automatica.
  Serial.println("LuzOFF");
 }
 
 Serial.print("SensorLuz:"); //NO BORRAR // Lineas para notificar el valor al celular.
 Serial.println(SensorLuz); //NO BORRAR // Lineas para notificar el valor al celular.
 
 
}
  
  

