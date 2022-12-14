#include <Arduino.h>
#include "configuration/configurationManager.h"
#include "button/button.h"
#include "callbacksTimeout/callbacksTimeOut.h"
#include "PubSubClient.h"
#include <Espalexa.h>



Button configBtn(D3),activeBtn(D8);
ConfigurationManager config;

WiFiClient espClient;
PubSubClient MQTT(espClient);
Espalexa alexa;
void callback(char* topic, byte* payload, unsigned int length);
void callback_alexa(uint8_t brightness);



void setup() {

  pinMode(D4, OUTPUT);

  EEPROM.begin(512);
  Serial.begin(9600);



  config.loadEepromData();
  config.connectWiFi();


  MQTT.setServer("ec2-54-94-244-63.sa-east-1.compute.amazonaws.com" ,1883 ); 
  MQTT.setCallback(callback); 
  MQTT.connect("testeID" , "ismael" , "ismael");
  MQTT.subscribe(config.topic_active);



  alexa.addDevice("Lampada", callback_alexa); 
  alexa.begin();

}




void loop() {
  if(configBtn.isLongedPressed(5000)) {
    MQTT.disconnect();
    config.beginConfigServer("teste","030272neto");
  }

  if(!config.verifyWiFiStatus()){
    config.reconnectWiFi();
  };

  if(activeBtn.isChangedState()){
    if(digitalRead(D4)){
      MQTT.publish(config.topic_state,"ON");
      digitalWrite(D4,LOW);
    }
    else{
      MQTT.publish(config.topic_state,"OFF");
      digitalWrite(D4,HIGH);
    }
  }

  MQTT.loop();
  alexa.loop();
}


void callback(char* topic, byte* payload, unsigned int length)
{
  String payload_string;
  for(int i = 0; i < length; i++) {
      char c = (char)payload[i];
      payload_string += c;
  }
  if(String(topic) == String(config.topic_active) ){
      if(payload_string == "ON"){
        digitalWrite(D4,LOW);
        MQTT.publish(config.topic_state,"ON");
        return;
      }
      if(payload_string== "OFF"){
        digitalWrite(D4,HIGH);
        MQTT.publish(config.topic_state,"OFF");
        return;
      }
  }

}

void callback_alexa(uint8_t brightness)
{
  if(brightness==255){
    MQTT.publish(config.topic_state,"ON");
    digitalWrite(D4,LOW);
  }
  else{
    MQTT.publish(config.topic_state,"OFF");
    digitalWrite(D4,HIGH);
  }

}

