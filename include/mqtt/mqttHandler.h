#include <PubSubClient.h>
#include <ESP8266WebServer.h>

class MqttHandler 
{

private:
    
    String topic_active;
    String topic_state;

public:
    PubSubClient MQTT;
    MqttHandler(WiFiClient espclient);
    void setServer( char *domain , char * portname);
    void setCallback(char *active_topic , char *state_topic);

    

};