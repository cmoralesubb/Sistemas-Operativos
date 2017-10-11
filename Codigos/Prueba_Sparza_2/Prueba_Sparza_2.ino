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

byte dist_izq_cen =7;
byte dist_der_cen =8;


byte in_dist_der=31;
byte out_dist_der=33;

byte in_dist_izq=35;
byte out_dist_izq=37;

byte in_dist_tras=39;
byte out_dist_tras=41;




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

byte distancia_minima=40;
int distancia_media=60;
int distancia_maxima=100;


byte principio=false;

void setup() {

  Serial.begin(9600);
  //Inicializacion de inputs

  pinMode(dist_izq_cen, INPUT);


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
  atacar_inicio_izquierda();
}

void atacar_inicio_izquierda(){

  //mientras esta en la pista
  while(analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t)>linea) {
    while(calculo_dist(dist_der_cen)>distancia_maxima || calculo_dist(dist_izq_cen)>distancia_maxima ){
      giro_derecha(200,200);
    }

    while(calculo_dist(dist_der_cen)<distancia_maxima || calculo_dist(dist_izq_cen)<distancia_maxima && analogRead(lin_d_der)>linea && analogRead(lin_d_izq)>linea){
      avanzar(200,200);
    }

  }
  //0 0 1 si la trasera detecta la linea 
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
   avanzar(200,200);
  }
  
  //0 1 0
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t)> linea ) {
    giro_derecha(200,200);
    
  }
  
  //0 1 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) {
    giro_izquierda(200,200);
   
  }
  //1 0 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) > linea ) {
    giro_derecha(200,200);
   
  }
  //1 0 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
    giro_derecha(200,200);

  }
  //1 1 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) > linea ) {
    retroceder(200,200,700);
    giro_derecha(200,200);

  }

  //1 1 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible

  }


}


void avanzar(byte vel_izquierda,byte vel_derecha ) {
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

  delay(tiempo);
  

}


void girar(byte velocidad_izquierda,byte velocidad_derecha){

  analogWrite(PWM2,velocidad_izquierda);
  analogWrite(PWM1,velocidad_derecha);

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

void giro_izquierda(byte vel_izquierda,byte vel_derecha ) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);

  
}

void giro_izquierda(byte vel_izquierda,byte vel_derecha,int tiempo ) {
  analogWrite(PWM2,vel_izquierda);
  analogWrite(PWM1,vel_derecha);

  digitalWrite(INA1,HIGH);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,HIGH);
  delay(tiempo);
  
}




void giro_derecha(byte velocidad_izquierda,byte velocidad_derecha) {
  analogWrite(PWM2,velocidad_izquierda);
  analogWrite(PWM1,velocidad_derecha);

  digitalWrite(INA1,LOW);
  digitalWrite(INB1,HIGH);

  digitalWrite(INA2,HIGH);
  digitalWrite(INB2,LOW);

  

}


void atras(byte velocidad_izquierda,byte velocidad_derecha) {
  analogWrite(PWM2,velocidad_izquierda);
  analogWrite(PWM1,velocidad_derecha);

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






void directo(){
  if(calculo_dist_izq()<distancia_maxima){
    giro_izquierda(200,200);
  }else if(calculo_dist_der()<distancia_maxima){
    giro_derecha(200,200);
  }else if(calculo_dist_tras()<distancia_maxima){
    giro_izquierda(200,200);
  }else if(calculo_dist(dist_der_cen)<distancia_maxima){

  }else if(calculo_dist(dist_izq_cen)<distancia_maxima){

  }
}

void directo_2(){
  if(calculo_dist_izq()<distancia_maxima){
    while(calculo_dist(dist_der_cen)>distancia_maxima|| calculo_dist(dist_izq_cen)>distancia_maxima){
      giro_izquierda(200,200);  
    }
    
  }else if(calculo_dist_der()<distancia_maxima){
     while(calculo_dist(dist_der_cen)>distancia_maxima|| calculo_dist(dist_izq_cen)>distancia_maxima){
      giro_derecha(200,200);  
    }

  }else if(calculo_dist_tras()<distancia_maxima){
     while(calculo_dist(dist_der_cen)>distancia_maxima|| calculo_dist(dist_izq_cen)>distancia_maxima){
      giro_izquierda(200,200);  
    }
    
  }else if(calculo_dist(dist_der_cen)<distancia_maxima){
    
  }else if(calculo_dist(dist_izq_cen)<distancia_maxima){

  }

}

void detener(){
 
  digitalWrite(INA1,LOW);
  digitalWrite(INB1,LOW);

  digitalWrite(INA2,LOW);
  digitalWrite(INB2,LOW);

}



