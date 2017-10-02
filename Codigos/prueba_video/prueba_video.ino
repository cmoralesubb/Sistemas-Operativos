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
byte uno_A=4;
byte uno_B=5;
byte p1=9;
byte dos_A=7;
byte dos_B=8;
byte p2=10;
byte se=6;


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
  pinMode(uno_A,OUTPUT);
  pinMode(uno_B,OUTPUT);
  pinMode(p1,OUTPUT);
  pinMode(dos_A,OUTPUT);
  pinMode(dos_B,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(se,OUTPUT);
  digitalWrite(se,HIGH);
  
  Serial.println("Setup");
  delay(3000);
}

/*
  analogRead(dist_izq)
  analogRead(dist_izq_cen)
  analogRead(dist_der_cen)
  analogRead(dist_der)
  
  byte uno_A=4;
  byte uno_B=5;
  byte P1=9;
  byte dos_A=7;
  byte dos_B=8;
  byte P2=10;
  byte SE=6;
*/

void loop() {
  
  while(calculo_dist()>distancia_min){
    Serial.println("girando");
    girar(250);
  }
  
  girando=false;
  
  //0 0 0
  if (aux_linea > linea && analogRead(lin_d_der) > linea && aux_linea > linea ) {
    Serial.println("leyendo pista");
     avanzar(130,130,100);
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
    retroceder(230,230,500);
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
  analogWrite(p2,vel_izquierda);
  analogWrite(p1,vel_derecha);

  digitalWrite(uno_A,HIGH);
  digitalWrite(uno_B,LOW);

  digitalWrite(dos_A,HIGH);
  digitalWrite(dos_B,LOW);

  delay(tiempo);
}


void empujar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  if(empujando==false){
      analogWrite(p2,vel_izquierda);
      analogWrite(p1,vel_derecha);

      digitalWrite(uno_A,HIGH);
      digitalWrite(uno_B,LOW);

      digitalWrite(dos_A,HIGH);
      digitalWrite(dos_B,LOW);

      empujando=true;
      delay(tiempo);
  }else if(){
      delay(tiempo);
  }

  
}



void retroceder(byte vel_izquierda,byte vel_derecha,short tiempo) {
  analogWrite(p2,vel_izquierda);
  analogWrite(p1,vel_derecha);

  digitalWrite(uno_A,LOW);
  digitalWrite(uno_B,HIGH);

  digitalWrite(dos_A,LOW);
  digitalWrite(dos_B,HIGH);

  delay(tiempo);

}


void girar(byte velocidad){
  if(girando == false){
    analogWrite(p2,velocidad);
    analogWrite(p1,velocidad);

    digitalWrite(uno_A,LOW);
    digitalWrite(uno_B,HIGH);

    digitalWrite(dos_A,HIGH);
    digitalWrite(dos_B,LOW);
    girando=true;
    delay(100);
  }else if (girando != false){
    delay (100);
  }
}



int calculo_dist(){
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








