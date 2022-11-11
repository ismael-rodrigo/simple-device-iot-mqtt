#include <Arduino.h>
#include "configuration/configurationManager.h"
#include "button/button.h"
#include "callbacksTimeout/callbacksTimeOut.h"


Button butt(D3);
ConfigurationManager config;

WiFiClient espClient;


void setup() {


  EEPROM.begin(512);
  Serial.begin(9600);

  

  config.loadEepromData();
  config.connectWiFi();


}


void loop() {
  if(butt.isLongedPressed(5000)) config.beginConfigServer("teste","030272neto");







  if(!config.verifyWiFiStatus()){
    config.reconnectWiFi();
  };

  
}



