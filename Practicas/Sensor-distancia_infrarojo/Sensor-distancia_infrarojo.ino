int sensorPin = 0;
 int cm;
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin , INPUT);  //definir pin como entrada
}
 
void loop(){
  int value = 0;
  value = analogRead(sensorPin);  //lectura analogo de pin
  Serial.print("Normal : ");
  Serial.println(value);
  
  cm = pow(3027.4 / value, 1.2134);
 
  Serial.print("Centimetros : ");
  Serial.println(cm);
  delay(500);
  cm=0;
  value=0;
  
  
}
