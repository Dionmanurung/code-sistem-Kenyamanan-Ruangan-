  
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//#include <DHT.h>         // Library untuk sensor suhu DHT
#define DHTPIN 2           // Pin data sensor suhu terhubung ke pin 2 Arduino Mega
#define DHTTYPE DHT11      // Tipe sensor suhu (DHT11 atau DHT22)
DHT dht(DHTPIN, DHTTYPE);  // Inisialisasi objek sensor suhu DHT

const int lightPin = A0;   // Pin sensor cahaya terhubung ke pin analog A0
const int soundPin = A1;   // Pin sensor suara terhubung ke pin analog A1
const int relayPin = 7;    // Pin relay terhubung ke pin digital 7
const int buzzerPin = 3;   // Pin buzzer terhubung ke pin digital 8
const int ledPin = 9;      // Pin LED merah terhubung ke pin digital 9
const int suhu = 13;

void suara(int soundValue){
  if(soundValue > 200){
    digitalWrite(buzzerPin, HIGH);
  }
  else if (soundValue < 200){
    digitalWrite(buzzerPin, LOW);
  }
}

void temperature(float suhu){
  if (suhu > 27.00){
    digitalWrite(relayPin, LOW);
  }
  else if (suhu < 27.00){
    digitalWrite(relayPin, HIGH);
  }
}

void ldr(int ldrValue){
  if (ldrValue > 500){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
//  pinMode(lightPin, INPUT)
//  pinMode(soundPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  
}

void loop() {
  //kode untuk sensor suara
  int soundValue = analogRead(soundPin); // Membaca nilai analog dari pin sensor suara
  Serial.print("Nilai Sensor Suara: ");
  Serial.println(soundValue); // Menampilkan nilai sensor suara di monitor serial

  
  //kode untuk sensor ldr
  int ldrValue = analogRead(lightPin); // Membaca nilai analog dari pin sensor LDR
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue); // Menampilkan nilai LDR di monitor serial
 

  
  // put your main code here, to run repeatedly:
  float suhu = dht.readTemperature();
  int lightValue = analogRead(lightPin);

  Serial.print("Suhu : ");
  Serial.println(suhu);


  temperature(suhu);
  ldr(ldrValue);
  suara(soundValue);
  delay(1000);

}
