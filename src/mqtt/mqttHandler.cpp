#include "mqtt/mqttHandler.h"


MqttHandler::MqttHandler(WiFiClient espclient):
MQTT(espclient)
{
    MQTT.setCallback(void);
}

void MqttHandler::setServer(char *domain ,char * portname)
{
    uint16_t port = atoi(portname);
    MQTT.setServer(domain , port);
}




