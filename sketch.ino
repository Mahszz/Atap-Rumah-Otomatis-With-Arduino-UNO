#include <Servo.h>
#include <DHT.h>
#define Type DHT11 
Servo servo1;
const int pinHujan = 2;
const int pinLdr = 3;
const int pinLampu = 12;
const int pinDht = 10;

DHT SK(pinDht,Type);
float kelembaban;
float suhu;
int deras, cahaya;
int tutup = 110;
int buka = 0;

void setup() {
  Serial.begin(9600);
  SK.begin();
  servo1.attach(7);
  delay (3000);
  
  pinMode(pinHujan, INPUT);
  pinMode(pinLdr, INPUT);
  pinMode(pinLampu, OUTPUT);

}

void loop() {
  
  kelembaban = SK.readHumidity();
  suhu = SK.readTemperature();
  Serial.print("suhu:");
  Serial.print(suhu);
  Serial.print ("\nkelembaban:");
  Serial.print (kelembaban);
  delay (3000);
  
  deras = digitalRead(pinHujan);
  cahaya = digitalRead(pinLdr);
  //sensor hujan, jika hujan bernilai = 0 dan jika tidak bernilai = 1
  //sensor cahaya, jika bercahaya bernilai = 1 dan jika tidak bercahaya = 0

  //kondisi hujan dan mendung 
  if (deras == 0 && cahaya == 1)
  {
    servo1.write(tutup);
    digitalWrite(pinLampu, HIGH);
  }

  //kondisi hujan dan terang
  else if(deras == 0 && cahaya == 0 )
  {
    servo1.write(tutup);
    digitalWrite(pinLampu, HIGH);
  }

  //kondisi tidak hujan dan mendung 
  else if (deras == 1 && cahaya == 1)
  {
    servo1.write(tutup);
    digitalWrite(pinLampu, HIGH);
  }

  //konsidi tidak hujan dan tidak mendung
  else if (deras == 1 && cahaya == 0 )
  {
    servo1.write(buka);
    digitalWrite(pinLampu, LOW);
  }
  delay(300);
}


