#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

float Ch0;
byte incomingByte = 0;

int TiempoEspera=1;

#define DHTTYPE DHT11                       
#define DHTPIN  15                                                              
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  if (Serial.available() > 0) { 

    incomingByte = Serial.read(); 

    if (incomingByte == 82) {     
      Ch0 = analogRead(A0)*5.0/1023.0; //numero de bits 2 a la 10
      Serial.print("Voltaje: ");
      Serial.println(Ch0,4);

      Ch0 = analogRead(A1);
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      Serial.print("Humedad: ");
      Serial.print(h);
      Serial.print(" % ");
      Serial.print("Temperatura: ");
      Serial.print(t); 
    }
  }
  delay(TiempoEspera);
}
