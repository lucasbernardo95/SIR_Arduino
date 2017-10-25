#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 7 // pino do sensor
#define DHTTYPE DHT22     // DHT 22 (AM2302)
#define UMIDADE A0
int rele = 12;

// Definicoes do sensor : pino, tipo
DHT dht(DHTPIN, DHTTYPE);

void setup(){

  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW); 
  dht.begin();//inicia a lib do sensor dht22
}

void loop(){

    if(Serial.available() > 0){
        char leituraSerial = Serial.read();  
        
        if(leituraSerial == '1'){   
          digitalWrite(rele, HIGH); 
        }else if(leituraSerial == '2'){
          digitalWrite(rele, LOW);
        }else if(leituraSerial == 't'){
            //Lê a umidade do ambiente 
            float umidade = dht.readHumidity();
            //Lê a temperatura do ambiente
            float temperatura = dht.readTemperature();
            //Umidade do solo
            int valor = analogRead(UMIDADE);
            int umidadeSolo = map(valor, 1023, 0, 0, 255);
  
            Serial.print(umidade);
            Serial.print(":");
            Serial.print(temperatura);
            Serial.print(":");
            Serial.println(umidadeSolo);
        }
    
    
    }
}
