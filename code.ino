#include "Adafruit_DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int delay_time = 10000;
int led = D7;   // The on-board LED

void setup() {
    pinMode(led, OUTPUT);
    dht.begin();
}

void loop() {
    digitalWrite(led, HIGH);    // Turn ON the LED
    
    float t = dht.getTempCelcius();
    String temp = String(t);
    Particle.publish("temp", temp, PRIVATE);
    delay(delay_time);               
    
    digitalWrite(led, LOW);     // Turn OFF the LED
    delay(delay_time);              
}
