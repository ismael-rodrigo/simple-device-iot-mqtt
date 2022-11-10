#include <Arduino.h>
#include "configuration/configurationManager.h"
#include "button/button.h"

Button butt(D3);
ConfigurationManager config;

void setup() {


  EEPROM.begin(512);
  Serial.begin(9600);

  

  config.loadEepromData();
  config.connectWiFi();


}

void loop() {
  if(butt.isLongedPressed(5000)) config.beginConfigServer("teste","030272neto");
  if(config.verifyWiFiStatus()){
    Serial.println("Connected");
    Serial.print(config.ip_current_wifi);
  }; 
  delay(300);
  
}