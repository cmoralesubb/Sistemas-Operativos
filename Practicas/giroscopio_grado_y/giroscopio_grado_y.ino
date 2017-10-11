#include <Wire.h>
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int estado=0;
int a=0;
int b=0;

void setup() {
  configuracion_giroscopio();
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(inclinacion());
  delay(500);
}

int inclinacion(){
//Captura del gyroscopio
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);
GyY=Wire.read()<<8|Wire.read();
//Serial.println("GyY= ");
//Serial.println(GyY);

      if (GyY>2000){
        estado = -1;
        a = 0;
        b = -1;
      return estado; Serial.println(estado);
  }
  if (GyY<-2000)
  {
    estado = 1;
    a = 0;
    b = 1;
      return estado; Serial.println(estado);
  }
  a = b;
  if (-500 < GyY < 500)
  {
    estado = 0 + a;
    b = 0;
      return estado; Serial.println(estado);
  }

}
//Fin captura

void configuracion_giroscopio(){
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
}
