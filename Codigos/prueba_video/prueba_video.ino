//Auxiliar de linea (emulador de lectura de linea)
int aux_linea=300;

//SENSORES DE LINEA
byte lin_d_izq =;
byte lin_d_der =;
byte lin_t =;

//SENSORES DE DISTANCIA

byte dist_izq =;
byte dist_izq_cen =;
byte dist_der_cen =;
byte dist_der =;
byte dist_t =;


//VARIABLES DE MOTORES
int PWM1=7;
int motor1A = 22; 
int motor1B = 24; 
int PWM2=2;
int motor2A=26;
int motor2B=28;

//VARIABLES DE CONDICIONES
byte i,j,k;

//(Sensor de linea) < linea aceptara condicion, si linea es menor tiende a blanco
byte linea=100;


short aux_dist; // variable auxiliar de distancia
short dist_cm=0; // leera los centimetros de los sensores con la funcion pw
short dist_sin_cm=0;


//variables estaticas de distancias
byte distancia_min=20; //Distancia a la que leera el objetivo y ocurrira la condicion

boolean girando = false; // booleano de giro 
boolean empujando=false;



void setup() {

  Serial.begin(9600);
  //Inicializacion de inputs
  /*
  pinMode(dist_izq, INPUT);
  pinMode(dist_izq_cen, INPUT);

  pinMode(dist_der, INPUT);
  pinMode(dist_t, INPUT);
  */
  pinMode(dist_der_cen, INPUT);
  
  //Inicializacion de Inputs de Motor
  pinMode(motor1A, OUTPUT);   
  pinMode(motor1B, OUTPUT);  
  pinMode(PWM1, OUTPUT);
  pinMode(motor2A, OUTPUT);   
  pinMode(motor2B, OUTPUT);  
  pinMode(PWM2, OUTPUT);     
  
  Serial.println("Setup");
  delay(3000);
}



void loop() {
  
  while(calculo_dist_sen_der()>distancia_min){
    Serial.println("girando");
    girar(250);
  }
  
  //0 0 0
  if (aux_linea > linea && analogRead(lin_d_der) > linea && aux_linea > linea ) {
    Serial.println("leyendo pista");
    //avanzar(130,130,100);
    if (calculo_dist<distancia_min){
      Serial.println("Empujando");
      empujar(250,250,100);
    }

  }

  //0 0 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
  
  }

  //0 1 0
  if (aux_linea > linea && analogRead(lin_d_der) < linea && aux_linea> linea ) {
    retroceder(230,230,1000);
    Serial.println("retroceder");
  }
  
  //0 1 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) {

  }
  
  //1 0 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) > linea ) {

  }
  
  //1 0 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {

  }
  
  //1 1 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) > linea ) {
  
  }
  
  //1 1 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible ya que los 3 no detectaran las lineas blancas
  
  }
}


void avanzar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    analogWrite(PWM1,vel_izquierda);
    //digitalWrite(PWM1,HIGH);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
    analogWrite(PWM2,vel_derecha);
}

void empujar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
    while(aux_linea > linea && analogRead(lin_d_der) > linea && aux_linea > linea ){
      digitalWrite(motor1A, HIGH);
      digitalWrite(motor1B, LOW);
      analogWrite(PWM1,vel_izquierda);
      //digitalWrite(PWM1,HIGH);
      digitalWrite(motor2A, HIGH);
      digitalWrite(motor2B, LOW);
      analogWrite(PWM2,vel_derecha);
      delay(tiempo);
    }
     
}


void retroceder(byte vel_izquierda,byte vel_derecha,short tiempo) {
digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, HIGH);
    analogWrite(PWM1,vel_izquierda); // speed at 250
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
    analogWrite(PWM2,vel_derecha); // speed at 250

  delay(tiempo);

}


void girar(byte velocidad){
  while(){
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    analogWrite(PWM1,vel_izquierda); // speed at 250
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
    analogWrite(PWM2,vel_derecha); // speed at 250
    delay(100);
  }
}



int calculo_dist_sen_der(){
  return pow(3027.4/analogRead(dist_der_cen),1.2134);
}



void izquierda(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  analogWrite(p2,vel_izquierda);
  analogWrite(p1,vel_derecha);

  digitalWrite(uno_A,HIGH);
  digitalWrite(uno_B,LOW);

  digitalWrite(dos_A,HIGH);
  digitalWrite(dos_B,LOW);

  delay(tiempo);
}









void derecha(byte velocidad, byte tiempo) {


}


void atras(byte vel_izquierda,byte vel_derecha, byte tiempo) {


}








