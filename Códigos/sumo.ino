//Indicamos en que puerto estan los pines
const int LedPin=13; 

const int MotorRight1 = 6; 

const int MotorRight2 = 7; 

const int MotorRightPWM = 10; 

const int MotorLeft1 = 8;

const int MotorLeft2 = 9; 

const int MotorLeftPWM = 5;

const int SensorL = A2; 
const int SensorR = A3; 

// Declaraciones de variables de velocidad

int iSpeed = 110; // Velocidad recto

int gSpeed = 150; // Velocidad de giro

int bSpeed = 90; // Velocidad de marcha atras

int suelo;

void setup() {

//Declaramos los pines

Serial.begin(9600);

pinMode(MotorRight1, OUTPUT);

pinMode(MotorRight2, OUTPUT);

pinMode(MotorLeft1, OUTPUT);

pinMode(MotorLeft2, OUTPUT);

pinMode(MotorRightPWM, OUTPUT);

pinMode(MotorLeftPWM, OUTPUT);

pinMode(SensorL, INPUT);
pinMode(SensorR, INPUT);

//Hacemos que espere dos segundos antes de iniciar

delay(2000);

}

//Instrucciones para los sensores
void loop()
{
  // Blanco es 0
  // Oscuro es 1
  
  //Blancos en los dos sensores
  if (!digitalRead(SensorL) && !digitalRead(SensorR))
  {
    advance();
    delay(200);
    stopp();
    delay(200);
  }
  
  // Borde en los dos sensores
  if (digitalRead(SensorR) && digitalRead(SensorL)) 
  {
    stopp();
    delay(500);
    back();
    delay(1000);
    stopp();
    delay(500);
    turnR();
    delay(random(500, 5000));
    stopp();
    delay(500);
  }
  
  // Borde en el sensor derecho
  if (digitalRead(SensorR)) 
  {
    stopp();
    delay(500);
    back();
    delay(1000);
    stopp();
    delay(500);
    turnL();
    delay(1000);
    stopp();
    delay(500);
  }
  
  // Borde en el sensor izq
  if (digitalRead(SensorL)) 
  {
    stopp();
    delay(500);
    back();
    delay(1000);
    stopp();
    delay(500);
    turnR();
    delay(1000);
    stopp();
    delay(500);
  }
}
  
//Declaramos las funciones para las intrucciones
  
void advance() {
  
  // avanzar
  
  digitalWrite(MotorRight1, HIGH);
  
  digitalWrite(MotorRight2, LOW);
  
  digitalWrite(MotorLeft1, HIGH);
  
  digitalWrite(MotorLeft2, LOW);
  
  analogWrite(MotorRightPWM, iSpeed);
  
  analogWrite(MotorLeftPWM, iSpeed);
  
}

void turnR() {
  
  // Giro a la derecha con ambas ruedas
  
  digitalWrite(MotorRight1, LOW);
  
  digitalWrite(MotorRight2, HIGH);
  
  digitalWrite(MotorLeft1, HIGH);
  
  digitalWrite(MotorLeft2, HIGH);
  
  analogWrite(MotorRightPWM, gSpeed);
  
  analogWrite(MotorLeftPWM, gSpeed);

}

void turnL() {
  
  // Giro a la izquierda con ambas ruedas
  
  digitalWrite(MotorRight1, HIGH);
  
  digitalWrite(MotorRight2, HIGH);
  
  digitalWrite(MotorLeft1, LOW);
  
  digitalWrite(MotorLeft2, HIGH);
  
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
  
  analogWrite(MotorRightPWM, bSpeed);
  
  analogWrite(MotorLeftPWM, bSpeed);

}
