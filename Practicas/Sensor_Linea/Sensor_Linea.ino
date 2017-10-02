// si es menor tiende a blanco
void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop()
{
      int val;
      int va2;
      val=analogRead(A8);   //connect grayscale sensor to Analog 0
      va2=analogRead(A15);
      Serial.print("Sensor derecha ");
      Serial.println(val);//print the value to serial
      Serial.print("Sensor izquierda ");
      Serial.println(va2);//print the value to serial        
      delay(1000);
}
