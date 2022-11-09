#include <ESP8266WebServer.h>
#include "utils/eeprom_rw.h"

class ConfigurationManager
{
private:

public:
    ESP8266WebServer server;
    void beginConfigServer(const char* ssid, const char* password);


    bool connectWiFi(const char* ssid, const char* password);

    ConfigurationManager();

};

