long distancia;
long tiempo;
void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(1000);
}



int pinMotor1 = 11;
int pinMotor2 =10;
unsigned long tiempo1;
unsigned long tiempo2;
int sensorderecha=5;
int dato;
int dato2;
int sensorizquierda=4;
int contador;
37
int vector[5];
int minimo;
int maximo;
int media;
int suma;
int mediasensor;
boolean obstaculoIzquierda;
boolean obstaculoDerecha;
void setup()
{
Serial.begin(115200);
pinMode(pinMotor1, OUTPUT);
pinMode(pinMotor2, OUTPUT);
pinMode(sensorizquierda,INPUT);
pinMode(sensorderecha,INPUT);
tiempo1 =0;
tiempo2 =0;
}
void loop()
{
detectar();
adelante();
}
void detectar()
{
dato2=leersensor(sensorizquierda);
 dato=leersensor(sensorderecha);
 obstaculoIzquierda = false;
 obstaculoDerecha = false;
if(dato2>260)
{
 obstaculoIzquierda = true;
}
else if (dato>260)
{
 obstaculoDerecha = true;
}
Desarrollo de un pequeño robot móvil basado en microcontrolador
38
else
{
 obstaculoIzquierda = false;
 obstaculoDerecha = false;
}
}
int leersensor(int pin)
{
for ( contador=0; contador<5;contador=contador+1)
{
vector[contador]=analogRead(pin);
 }

mediaSensor=calcularmedia();
 return mediaSensor;
}
int calcularmedia()
{
 minimo=1023;
 maximo=0;
suma=0;
for(contador=0;contador<5;contador=contador+1)
{
minimo=min(minimo,vector[contador]);
maximo=max(maximo,vector[contador]);
suma = suma+vector[contador];
}
suma= suma -minimo-maximo;
media= suma/3;
return media;
}
void adelante()
{
if(obstaculoDerecha==true)
 {
 izquierda();
39
 }
else if (obstaculoIzquierda==true)
{
derecha();
}
else
{
dosmotor(1257,1700);
}
}
void izquierda()
{
while ((obstaculoDerecha==true) ||
(obstaculoIzquierda==true))
 {
 dosmotor(1300,1300);
 detectar();
 }
}
void derecha()
{
while ((obstaculoIzquierda==true) ||
(obstaculoDerecha==true))
 {
 dosmotor(1700,1700);
 detectar();
 }
}
void dosmotor(int anchodepulsom1, int
anchodepulsom2)
{
pulso(anchodepulsom1,pinMotor1);
pulso(anchodepulsom2,pinMotor2);
}
boolean pulso (int anchoPulso, int servo)
{
Desarrollo de un pequeño robot móvil basado en microcontrolador
40
unsigned long tiempoantiguo;
if(servo==pinMotor1)
{
 tiempoantiguo=tiempo1;
}
else if(servo==pinMotor2)
{
tiempoantiguo=tiempo2;
}
tiempoactual=millis();
if( tiempoactual>tiempoantiguo+22)
{
if(servo==pinMotor1)
{
tiempo1=millis();
}
else if(servo==pinMotor2)
{
 tiempo2=millis();
}
digitalWrite(servo, HIGH);
delayMicroseconds(anchoPulso);
digitalWrite(servo, LOW);
return true;
}
else
{
return false;
}
}
