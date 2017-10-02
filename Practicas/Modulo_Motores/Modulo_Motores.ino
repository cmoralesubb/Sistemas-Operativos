//Programa desarrollado por Christian H. 


/*los pines del PWM estan en las salidas PWM 7 y 2, mientras que las direcciones
son dadas por pines digitales como salidas (puerto 22,24,26y28).
las entradas analogas de la placa no estan funcionando en este programa
como dato la solo lectura de la entrada analoga para medir corriente inicia
con un voltaje minimo de 0.13 [V]
*/

int PWM1=7;
int motor1A = 22; 
int motor1B = 24; 
int PWM2=2;
int motor2A=26;
int motor2B=28;
//int en1 = 5;

int motorSpeedH = 255; //velocidad de 0 a 255
int motorSpeedL = 125;

void setup(){
  pinMode(motor1A, OUTPUT);   
  pinMode(motor1B, OUTPUT);  
  pinMode(PWM1, OUTPUT);
  pinMode(motor2A, OUTPUT);   
  pinMode(motor2B, OUTPUT);  
  pinMode(PWM2, OUTPUT);     
}

void loop()
{
   delay(3000);
   Go();
   delay(5000);
   Stop();
   delay(1000);
   Back();
   delay(1000);
}

void Stop()
{   //to stopping the motor:
    //set both of pins A AND B to the same value (HIGH or LOW)
    // or set en to 0 -> analogWrite(en1, 0);
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);      
}

void Go()
{
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    analogWrite(PWM1,motorSpeedH);
    //digitalWrite(PWM1,HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
    analogWrite(PWM2,motorSpeedH);
    //digitalWrite(PWM2,HIGH);
    //analogWrite(en1,motorSpeed); // speed at 250
}

void Back()
{
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    analogWrite(PWM1,motorSpeedL); // speed at 250
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
    analogWrite(PWM2,motorSpeedL); // speed at 250
}
