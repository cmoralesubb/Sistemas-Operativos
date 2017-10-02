void setup() {
  Serial.begin(9600);

}

void loop() {
  funcion (2);
  
  funcion (3,2);
  funcion (3,2,4);
delay(2000); 
}


void funcion(int numero){
  Serial.println(numero);
}
void funcion(int dato,int dato2){
  Serial.println(dato+dato2);
}


void funcion(int ingreso,int ingreso2,int ingreso3){
 Serial.println(ingreso+ingreso2+ingreso3);
}
