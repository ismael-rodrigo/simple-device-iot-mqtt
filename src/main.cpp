#include <Arduino.h>
#include "configuration/configurationManager.h"


char ssid[25];      
char pass[25];


void setup() {
  ConfigurationManager config;
  Serial.begin(9600);
  config.beginConfigServer("teste","030272neto");

  ler(0).toCharArray(ssid, 25);
  ler(25).toCharArray(pass, 25);


  Serial.println(ssid);
  Serial.println(pass);


}

void loop() {
  Serial.print("ssss");
}