/*
  Tips

  usar byte
  Serial.print(F("Hola Mundo"));//Gasto de Memoria Flash. en vez de la normal

  int led = 13;//Utilizar una variable para definir un PIN gasta RAM y Memoria de Programa
  #define LED 13 // SI utilizamos una constante no se gastará RAM y se gastará mucho menos espacio de p
*/

/*
  anotaciones sobre sensores de linea
  porque dos?

  random(1,2); funcion random de 1 a 2

  CONSIDERAR LECTURA PREVIA

  byte sensor_lec=analogRead(sensor);
*/

int aux_linea=500;

//SENSORES DE LINEA
byte lin_d_izq =15;
byte lin_d_der =14;
//byte lin_t =;

//SENSORES DE DISTANCIA
/*
byte dist_izq =;
byte dist_izq_cen =;
byte dist_der =;
byte dist_t =;
*/
byte dist_der_cen =8;


// Variables de motores
byte INA1=22;
byte INB1=24;
byte PWM1=7;

byte INA2=26;
byte INB2=28;
byte PWM2=2;


byte vel_izquierda=250;
byte vel_derecha=250;

byte vel_maxima=255;
byte vel_media=170;
byte vel_baja=100;



//VARIABLES DE CONDICIONES
byte i;

//Sensor de linea menor->tiende a blanco por tanto marca el limite de la diferencia
int linea=200;

short aux_dist;
short dist_cm=0; // leera los centimetros de los sensores con la funcion pw
short dist_sin_cm=0;

//variables estaticas de distancias

byte distancia_min=20;

boolean girando = false;


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

  pinMode(INA1,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(INA2,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(PWM2,OUTPUT);

  //pinMode(se,OUTPUT);
  //digitalWrite(se,HIGH);

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
  Serial.println(analogRead(lin_d_der));

  while(calculo_dist(dist_der_cen)>distancia_min){
    Serial.println("girando");
    girar(250);
  }

  girando=false;
  //0 0 0
  if (aux_linea > linea && analogRead(lin_d_der) > linea && aux_linea > linea ) {
    Serial.println("leyendo pista");
    Serial.print(linea derecha);
    Serial.print(analogRead(lin_d_der));
    
     avanzar(130,130,100);
    if (calculo_dist(dist_der_cen)<distancia_min){
      Serial.println("Empujando");
      empujar(250,250,100);
    }

  }

/*
  //0 0 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
  

  }
  */
  //0 1 0
  if (aux_linea > linea && analogRead(lin_d_der) < linea && aux_linea> linea ) {
    retroceder(230,230,700);
    Serial.println("retroceder");
  }
  /*
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
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible
  
  }
  */
}


void avanzar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  delay(tiempo);
}


void empujar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  delay(tiempo);
}



void retroceder(byte vel_izquierda,byte vel_derecha,short tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  delay(tiempo);

}


void girar(byte velocidad){
  if(girando == false){
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);
    girando=true;
    delay(100);
  }else if (girando != false){
    delay (100);
  }
}



int calculo_dist(byte sensor){
  return pow(3027.4/analogRead(sensor),1.2134);
}



void izquierda(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  delay(tiempo);
}









void derecha(byte velocidad, byte tiempo) {


}


void atras(byte vel_izquierda,byte vel_derecha, byte tiempo) {


}


//FUNCIONES


//DEFENSA


//ATAQUE


//DEFENSA ATAQUE


//SIN DEFINIR





