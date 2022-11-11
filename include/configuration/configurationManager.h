#include <ESP8266WebServer.h>
#include "utils/eeprom_rw.h"

class ConfigurationManager
{
private:

public:
    char ssid_wifi[25];
    char password_wifi[25];
    IPAddress  ip_current_wifi;

    ESP8266WebServer server;
    void beginConfigServer(const char* ssid, const char* password);

    void loadEepromData();
    bool connectWiFi();
    bool verifyWiFiStatus();
    void reconnectWiFi();


    ConfigurationManager();

};

