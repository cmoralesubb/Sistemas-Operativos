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
byte dist_der_cen =7;


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
int linea=100;

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
    girar(250);
  }
  girando=false;
  //0 0 0
  while(aux_linea > linea && analogRead(lin_d_der) > linea && aux_linea > linea ) {
    Serial.println("leyendo pista");
    Serial.print("linea_derecha");
    Serial.print(analogRead(lin_d_der));
    Serial.println("");
    avanzar(200,200,100);
    while(calculo_dist(dist_der_cen) < distancia_min && analogRead(lin_d_der) > linea){
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
  Serial.println("avanzando");
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  delay(tiempo);
}


void empujar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  Serial.println("Empujando");
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  delay(tiempo);
}



void retroceder(byte vel_izquierda,byte vel_derecha,short tiempo) {
  Serial.println("retroceder");
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  delay(tiempo);

}


void girar(byte velocidad){
  Serial.println("girando");
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
  int distancia;
  Serial.print(" Distancia");
  distancia =pow(3027.4/analogRead(sensor),1.2134);
  Serial.println(distancia);
  return distancia;
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
byte lin_t =13;

//SENSORES DE DISTANCIA

byte dist_izq_cen =;
byte dist_der_cen =;


byte in_dist_der=;
byte out_dist_der=;

byte in_dist_izq=;
byte out_dist_izq=;

byte in_dist_tras=;
byte out_dist_tras=;




// Variables de motores
byte INA1=22;
byte INB1=24;
byte PWM1=7;

byte INA2=26;
byte INB2=28;
byte PWM2=2;

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
int distancia_maxima=50;
int distancia_media=100;

byte principio=false;

void setup() {

  Serial.begin(9600);
  //Inicializacion de inputs

  pinMode(dist_izq_cen, INPUT);
  pinMode(dist_der, INPUT);
  pinMode(dist_t, INPUT);

  pinMode(dist_der_cen, INPUT);

  pinMode(INA1,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(INA2,OUTPUT);
  pinMode(INB2,OUTPUT);
  pinMode(PWM2,OUTPUT);


  /*ARREGLAR PINES*/
  pinMode(out_dist_tras, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(in_dist_tras, INPUT); 

  pinMode(out_dist_izq, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(in_dist_izq, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

  pinMode(out_dist_der, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(in_dist_izq, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/


  delay(3000);

 
  atacar_inicio_izquierda();

}


void loop() {
  Estrategia_1(dis);
}

void atacar_inicio_izquierda(){

  if (calculo_dist(dist_izq_cen)<30 && principio==false){
    giro_izquierda(200,200,200); // arreglar el grado de izquierda que queda para que gire un poco
    principio=true;
  }

  //mientras esta en la pista
  if(analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t)>linea) {
    //lee mientras va a la izquierda mirando
    avanzar();
    if(calculo_dist_der()<50){
      giro_derecha(); // acomodar hasta encontrar un grado que acomode
      while(calculo_dist(dist_izq_cen)<20 || calculo_dist(dist_der_cen)<20 && analogRead(lin_d_der)>linea ){
        avanzar();
      }
    }else if(calculo_dist_izq()<50){
      giro_izquierda();// acomodar hasta encontrar un grado que acomode
      while(calculo_dist(dist_izq_cen)<20 || calculo_dist(dist_der_cen)<20 && analogRead(lin_d_der)>linea ){
        avanzar();
      }
    }else if(calculo_dist_tras()<50){
      giro_derecha()// encontrar un grado que acomode y de vuelta completa
    }
  }


  //0 0 1 si la trasera detecta la linea 
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
    avanzar();
  }
  
  //0 1 0
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t)> linea ) {
    retroceder(230,230,700);
    giro_derecha(); // acomodar cuanto es para una vuelta completa 
    
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
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible

  }


}



void Estrategia_1(){



  //0 0 0
  while(analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) > linea ) {
    
  }


  //0 0 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {


  }
  
  //0 1 0
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t)> linea ) {
    retroceder(230,230,700);
    
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
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible

  }
}


void avanzar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  Serial.println("avanzando");
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  
}


void retroceder(byte vel_izquierda,byte vel_derecha,short tiempo) {
  Serial.println("retroceder");
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  

}


void girar(byte velocidad){

  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  

}



int calculo_dist(byte sensor){

  return pow(3027.4/analogRead(sensor),1.2134);
}



int calculo_dist_der(){
  int tiempo;
  digitalWrite(out_dist_der,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(out_dist_der, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
    tiempo=pulseIn(in_dist_der, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
    del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
    deja de hacerlo, LOW, la longitud del pulso entrante*/
    
    return int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/


  }


  int calculo_dist_izq(){
    int tiempo;
    digitalWrite(out_dist_izq,LOW); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(5);
    digitalWrite(out_dist_izq, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
  tiempo=pulseIn(in_dist_izq, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  return int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  
}

int calculo_dist_tras(){
  int tiempo;
  digitalWrite(out_dist_tras,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(out_dist_tras, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(in_dist_tras, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  return int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
}

void giro_izquierda(byte vel_izquierda,byte vel_derecha ,short tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  
}



void giro_derecha(byte velocidad, byte tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  

}


void atras(byte vel_izquierda,byte vel_derecha, byte tiempo) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

 
}



void prueba_todo(){
  
  Serial.print("Sensor linea izquierdo : ");
  Serial.println(analogRead(lin_d_izq));

  Serial.print("Sensor linea derecho : ");
  Serial.println(analogRead(lin_d_der));

  Serial.print("Sensor Linea Trasero : ");
  Serial.println(analogRead(lin_t));

  Serial.print("Sensor distancia delantero Izquierdo : ");
  Serial.println(calculo_dist(dist_izq_cen));

  Serial.print("Sensor distancia delantero Derecho : ");
  Serial.println(calculo_dist(dist_der_cen));

  Serial.print("Sensor distancia derecho : ");
  Serial.println(calculo_dist_der());

  Serial.print("Sensor distancia izquierdo : ");
  Serial.println(calculo_dist_izq());

  Serial.print("Sensor distancia trasero : ");
  Serial.println(calculo_dist_tras());

}








//FUNCIONES


//DEFENSA


//ATAQUE


//DEFENSA ATAQUE


//SIN DEFINIR






