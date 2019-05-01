// En este programa puedes hacer el manejo un robot 
// desde un control remoto generico, lo primero que debes hacer
// es configurar los botones que vas a utilizar del control,
// para esto debes presionar un pulsador conectado en el 
// pinConf( de la funcion IRReceptorInit) en este caso en
// el pin 9, abrir el puerto serial y seguir los pasos, si 
// se hace correctamente, este paso es necesario hacerlo solo 
// una ves, pero si lo requieres despues puedes reconfigurarlo
//

#include <Exbot.h> 
unsigned long value; //variable para guardar tecla leida
int velIzq=80; // velocidad motor Izquierdo
int velDer=80; // velocidad motor Derecho

void setup(){
           //InPin,Buzzer,pinConf 
  IRReceptorInit(8,2,9); //configura los pines del IR
  Serial.begin(9600); //
}

void loop()
{
  SaveIRValues(); //Configuracion teclas control remoto
                  //cuando se presiona el pulsador del pinConf
  value=ReadIRKey(); //lee la tecla presionada
  if(value!=0)        
  {              //FunKey[n] tiene guardados los valores asociados a 
                 // cada tecla configurada anteriormente
    Serial.println(value,HEX);
    if (value==FunKey[0])  // si se oprimio la tecla guardada en la posicion cero
    {
      Adelante(velIzq,velDer,500);
    }
    else if(value==FunKey[1])
    {
      Izquierda(velIzq,velDer,100);
    }
    else if(value==FunKey[2])
    {
      Atras(velIzq,velDer,500);
    }
    else if(value==FunKey[3])
    {
      Derecha(velIzq,velDer,100);
    }
    else if(value==FunKey[4])
    {
      Parar(1);
    }
    else if(value==FunKey[5] && velIzq<=245)
    {
      velIzq+=10;
      velDer+=10;
      analogWrite(PwmMI,velIzq);
      analogWrite(PwmMD,velDer);
    }
    else if(value==FunKey[6] && velIzq>=10)
    {
      velIzq-=10;
      velDer-=10;
      analogWrite(PwmMI,velIzq);
      analogWrite(PwmMD,velDer);     
    }
    ResumeIR();
  }  
}

  


