#include <PubSubClient.h>
#include <ESP8266WebServer.h>

class MqttHandler 
{

private:
    void _callback();

public:
    PubSubClient MQTT;
    MqttHandler(WiFiClient espclient);
    void setServer( char *domain , char * portname);
    

};