// #include "mqtt/mqttHandler.h"



// String _active_topic;
// String _state_topic;
// uint8_t _pin_state_topic;

// void callback(char* topic, byte* payload, unsigned int length)
// {
//     // String payload_string;
//     // for(int i = 0; i < length; i++) 
//     // {
//     //     char c = (char)payload[i];
//     //     payload_string += c;
//     // };
//     if(String(topic) == _state_topic){
//         bool newState = payload[0];
//         //digitalWrite(_pin_state_topic , newState);
//         if(newState){
//             Serial.println("Active");
//         }
//         else{
//             Serial.println("Deactive");
//         }

//     }
// }


// MqttHandler::MqttHandler():
// MQTT()
// {

// }
// //const char* clientID , const char* user , const char* password,char *domain ,char * portname
// void MqttHandler::connect()
// {
//     MQTT.setServer("ec2-54-94-244-63.sa-east-1.compute.amazonaws.com" ,1883 ); 
//     MQTT.setCallback(callback); 
//     MQTT.connect("testeID" , "ismael" , "ismael");
//     MQTT.subscribe("teste-sub");
// }


// void MqttHandler::linkTopicStateToPinOutput(char *state_topic , uint8_t pin){
//     _state_topic = state_topic;
//     _pin_state_topic = pin;
//     MQTT.subscribe(state_topic);
// }




