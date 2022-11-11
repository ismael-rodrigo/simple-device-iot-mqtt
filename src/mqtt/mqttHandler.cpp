#include "mqtt/mqttHandler.h"


MqttHandler::MqttHandler(WiFiClient espclient):
MQTT(espclient)
{
    MQTT.setCallback(callback);
}

void MqttHandler::setServer(char *domain ,char * portname)
{
    uint16_t port = atoi(portname);
    MQTT.setServer(domain , port);
}






void callback(char* topic, byte* payload, unsigned int length)
{
    String payload_string;
    for(int i = 0; i < length; i++) 
    {
        char c = (char)payload[i];
        payload_string += c;
    };

    if(String(topic) == "")
    
    
}