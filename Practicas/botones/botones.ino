byte inputPin = 2;
 
int value = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}
 
void loop(){
  value = analogRead(inputPin);  //lectura digital de pin
 
  //mandar mensaje a puerto serie en función del valor leido
  Serial.println(value);
  delay(1000);
}
