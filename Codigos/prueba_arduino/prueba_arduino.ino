/*
  EXPO ROBOTICA UBB 2017
  CLAUDIO MORALES GUTIERREZ
  IECI
*/
//byte tipo dato de 0-255
byte sen_izq=A15; // sensor de la izquierda
byte sen_der=A8; // sensor de la derecha

int line=100; //lectura analoga de la linea blanca

//--velocidades--//
byte vel_trasero=150; // establece la maxima velocidad
byte vel_delantero=255;

byte velocidad_maxima=255;
byte velocidad_media=255;
byte velocidad_minima=100;


boolean doblando_izq;
boolean doblando_der;
boolean avanzando;
boolean retrocediendo;

boolean doblando_recto;

/* INPUTS DE PLACA L298D*/

//Motor delantero A
byte ENA=8; 
byte IN1=9;  
byte IN2=10;

//Motor B Trasero
byte ENB=13; 
byte IN3=11; 
byte IN4=12;

//--SENTIDO DE GIRO--//
byte sentido_giro=1;

void setup(){
  Serial1.begin(38400);
  Serial.begin(9600);
  delay(5000);
  //calibrar(); // calibra poniendo en falso
  pinMode(sen_izq,INPUT);   // sensor inicia como entrada
  pinMode(sen_der,INPUT);   // snesor inicia como entrada
  
  /*MOTOR DELANTERO*/
  pinMode(ENA,OUTPUT);
  pinMode (IN1, OUTPUT);    // Input1 conectada al pin _ 
  pinMode (IN2, OUTPUT);    // Input2 conectada al pin _ 
 
  /*MOTOR DELANTERO*/
  pinMode(ENB,OUTPUT);
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin _ 
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin _

}

void loop(){
    char c=Serial1.read();
  if(c=='g'){
    digitalWrite (IN3,LOW);
    
    digitalWrite (IN4,LOW);

  }

  if(c=='a'){
     digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,velocidad_media);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,velocidad_maxima);

  delay(1000);
 
  //dobla hacia adelante

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,velocidad_maxima);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,velocidad_media);

  delay(1000);

      digitalWrite (IN1,LOW);
    digitalWrite (IN2,LOW);

    digitalWrite (IN1,HIGH);
    digitalWrite (IN2,LOW);
    
    delayMicroseconds(9000);
    
    digitalWrite (IN1,LOW);
    
    digitalWrite (IN2,LOW);


  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,velocidad_media);

    
  }
  
 

}


