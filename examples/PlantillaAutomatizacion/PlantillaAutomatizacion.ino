//Este es un ejemploi de programación.
//Todo lo que veas escrito de despues de // es un comentaria
//Esto quiere decir que no será cargado al arduino


char BUFF[100];//
String MyStr;//
int SensorPresencia=0,SensorLuz=0;


void setup(){
  //Lo que hay dentro del void setup(){} no
  // lo debes modificar
  Serial.begin(9600); 
  for(int i=2;i<14;i++){
  pinMode(i,OUTPUT);
   
  }
  
  
}

void loop(){
  
  
  if(Serial.available()){
    
    int numR;//Este es un un numero para saber cuantos datos se han recibido
     numR=Serial.readBytesUntil('\n',BUFF,100);//Este es un un numero para saber cuantos datos se han recibido
     BUFF[numR]=0; 
     Serial.println(int(BUFF[numR-1]));
     MyStr=String(BUFF);
 
      Serial.println(MyStr);
      
      if(MyStr=="AbrirP\r"){
        //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "AbrirP"
        digitalWrite(4,HIGH); 
        digitalWrite(6,LOW);
        delay(800);
        digitalWrite(4,LOW); 
        digitalWrite(6,LOW);
 
      }
      else if(MyStr=="CerrarP\r"){
       //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "CerrarP"
        digitalWrite(4,LOW); //Se enciende la Luz 1;
        digitalWrite(6,HIGH);
        delay(800);
        digitalWrite(4,LOW); //Se enciende la Luz 1;
        digitalWrite(6,LOW);
    
     
      }
       else if(MyStr=="L10N"){
       //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "L1ON"
   
        digitalWrite(8,HIGH); //Se enciende la Luz 1;
      
      }
      else if(MyStr=="L10FF"){
       //Estas son las acciones que se van a ejecutar
        //cuando se reciban las letras "L1ON"
      
        digitalWrite(8,LOW); //Se apaga la Luz 1;
    
     
      }
      //----Para cada luz debes copiar lo que hay entre las líneas--------------
      else if(MyStr=="L2ON\r"){
      //Estas son las acciones que se van a ejecutar
      //cuando se reciban las letras "L1ON"
       
       //En este lugar debes agregar la acción necesaria para encender la luz 2 
        
      }//-------------------------------------------------------------
      //----Para cada luz debes copiar lo que hay entre las líneas--------------
      else if(MyStr=="L2OFF\r"){
      //Estas son las acciones que se van a ejecutar
      //cuando se reciban las letras "L1ON"
       
       //En este lugar debes agregar la acción necesaria para encender la luz 2 
        
      }//-------------------------------------------------------------
      //----Para cada luz debes copiar lo que hay entre las líneas--------------
      else if(MyStr=="L3ON\r"){
      //Estas son las acciones que se van a ejecutar
      //cuando se reciban las letras "L1ON"
       
       //En este lugar debes agregar la acción necesaria para encender la luz 2 
        
      }//-------------------------------------------------------------
     
  }  

//A partir de este punto el codigo se encargar leer la alarma y hacer sonar
SensorPresencia=analogRead(A0);
if(SensorPresencia>800){
digitalWrite(2,HIGH); //Enciende la alarma
Serial.print("A");
}else{
  digitalWrite(2,LOW); //Apaga la alarma
}

//Luz Automática
SensorLuz=analogRead(A3);
if(SensorLuz>800){
digitalWrite(11,HIGH); //Enciende la luz
Serial.print("L");
}else{
digitalWrite(11,LOW);}
  
 }
  
  
  

