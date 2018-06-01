#include <Servo.h>

//Definimos las velocidades

int iSpeed = 100; // Velocidad hacia delante y atras

int gSpeed = 100; // Velocidad de giro

//Definimos los pines

const int LedPin=13; 

const int MotorRight1 = 6; 

const int MotorRight2 = 7; 

const int MotorRightPWM = 10; 

const int MotorLeft1 = 8; 

const int MotorLeft2 = 9; 

const int MotorLeftPWM = 5; 

const int buzzer = 12;

int estado = 'f';         // Estado inicial al conectar al Bluetooth


// Declaramos de los pines
void setup()  { 

Serial.begin(9600);

pinMode(MotorRight1, OUTPUT);

pinMode(MotorRight2, OUTPUT);

pinMode(MotorLeft1, OUTPUT);

pinMode(MotorLeft2, OUTPUT);

pinMode(MotorRightPWM, OUTPUT);

pinMode(MotorLeftPWM, OUTPUT);

pinMode(buzzer, OUTPUT);
}

//Intrucciones para los botones
void loop()  { 

  if(Serial.available()>0){        // Conexión Bluetooth

    estado = Serial.read();

  }

  if(estado=='a'){           // Boton recto
    advance();
    
  }
  

  if(estado=='b'){          // Boton izqueirda
    
    turnL();
   
     }

  if(estado=='c'){          // Boton derecha

    turnR();

    } 

  if(estado=='d'){          // Boton atras
    
    back();
    
  }

  if (estado =='e'){        //Boton buzzer

    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
 
}
    
  if (estado =='f'){      //Boton STOP

  stopp();
  
  }
}

//Funcion de botones y velocidad
  void advance() {
  
  // avanzar
  
  digitalWrite(MotorRight1, HIGH);
  
  digitalWrite(MotorRight2, LOW);
  
  digitalWrite(MotorLeft1, HIGH);
  
  digitalWrite(MotorLeft2, LOW);
  
  analogWrite(MotorRightPWM, iSpeed);
  
  analogWrite(MotorLeftPWM, iSpeed);

}

void turnL() {
  
  // Giro a la izquierda con ambas ruedas
  
  digitalWrite(MotorRight1, HIGH);
  
  digitalWrite(MotorRight2, LOW);
  
  digitalWrite(MotorLeft1, LOW);
  
  digitalWrite(MotorLeft2, HIGH);
  
  analogWrite(MotorRightPWM, gSpeed);
  
  analogWrite(MotorLeftPWM, gSpeed);

}
  
  
  void turnR() {
  
  // Giro a la derecha con ambas ruedas
  
  digitalWrite(MotorRight1, LOW);
  
  digitalWrite(MotorRight2, HIGH);
  
  digitalWrite(MotorLeft1, HIGH);
  
  digitalWrite(MotorLeft2, LOW);
  
  analogWrite(MotorRightPWM, gSpeed);
  
  analogWrite(MotorLeftPWM, gSpeed);

}
  
  
  void stopp() {

  // Detenerse
  
  digitalWrite(MotorRight1, LOW);
  
  digitalWrite(MotorRight2, LOW);
  
  digitalWrite(MotorLeft1, LOW);
  
  digitalWrite(MotorLeft2, LOW);
  
  analogWrite(MotorRightPWM, iSpeed);
  
  analogWrite(MotorLeftPWM, iSpeed);

}

void back() {

  // Retrocede
  
  digitalWrite(MotorRight1, LOW);
  
  digitalWrite(MotorRight2, HIGH);
  
  digitalWrite(MotorLeft1, LOW);
  
  digitalWrite(MotorLeft2, HIGH);
  
  analogWrite(MotorRightPWM, iSpeed);
  
  analogWrite(MotorLeftPWM, iSpeed);
}

