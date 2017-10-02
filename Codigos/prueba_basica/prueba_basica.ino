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

//Variables de motores

byte 1A=4;
byte 1B=5;
byte P1=9;
byte 2A=7;
byte 2B=8;
byte P2=10;
byte SE=6;


//VARIABLES DE CONDICIONES
byte i;

//Sensor de linea menor->tiende a blanco por tanto marca el limite de la diferencia
byte linea;

//variables estaticas de distancias

byte distancia_min = 100;

void setup() {

  Serial.begin(9600);
  //Inicializacion de inputs
  pinMode(dist_izq, INPUT);
  pinMode(dist_izq_cen, INPUT);
  pinMode(dist_der_cen, INPUT);
  pinMode(dist_der, INPUT);
  pinMode(dist_t, INPUT);

  pinMode(1A,OUTPUT);
  pinMode(1B,OUTPUT);
  pinMode(P1,OUTPUT);
  pinMode(2A,OUTPUT);
  pinMode(2B,OUTPUT);
  pinMode(P2,OUTPUT);
  pinMode(SE,OUTPUT);
   
  digitalWrite(SE,HIGH);

 
}

/*
  analogRead(dist_izq)
  analogRead(dist_izq_cen)
  analogRead(dist_der_cen)
  analogRead(dist_der)
  
  byte 1A=4;
  byte 1B=5;
  byte P1=9;
  byte 2A=7;
  byte 2B=8;
  byte P2=10;
  byte SE=6;
*/
void loop() {
  //0 0 0
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) > linea ) {
    if (analogRead(dist_izq)< distancia_min){
      
        izquierda(50,230,3000);
        avanzar(230,230,5000);
        
        
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }

  //0 0 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }
  //0 1 0
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t) > linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }
  //0 1 1
  if (analogRead(lin_d_izq) > linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
      
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }
  //1 0 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) > linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }
  //1 0 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) > linea && analogRead(lin_t) < linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }
  //1 1 0
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) > linea ) {
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }


    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }

  //1 1 1
  if (analogRead(lin_d_izq) < linea && analogRead(lin_d_der) < linea && analogRead(lin_t) < linea ) { // Caso Imposible
    if (analogRead(dist_izq) < distancia_min) {
      // Izquierda o derecha
    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }

    if (analogRead() < distancia_min) {

    }
  }



}


void avanzar(byte vel_izquierda,byte vel_derecha ,short tiempo) {
        analogWrite(P2,vel_izquierda);
        analogWrite(P1,vel_derecha);
        
        digitalWrite(1A,HIGH);
        digitalWrite(1B,LOW)

        digitalWrite(2A,HIGH);
        digitalWrite(2B,LOW);
        
        delay(tiempo);
}
void derecha(byte velocidad, byte tiempo) {



}

void izquierda(byte vel_izquierda,byte vel_derecha ,short tiempo) {
        analogWrite(P2,vel_izquierda);
        analogWrite(P1,vel_derecha);
        
        digitalWrite(1A,HIGH);
        digitalWrite(1B,LOW)

        digitalWrite(2A,HIGH);
        digitalWrite(2B,LOW);
        
        delay(tiempo);
}


void atras(byte velocidad, byte tiempo) {

}
//FUNCIONES


//DEFENSA


//ATAQUE


//DEFENSA ATAQUE


//SIN DEFINIR





