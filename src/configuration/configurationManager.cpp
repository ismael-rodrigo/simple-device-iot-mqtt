#include "configuration/configurationManager.h"
#include "configuration/stringPages.h"


ConfigurationManager::ConfigurationManager():
server(80)
{
}




void ConfigurationManager::loadEepromData()
{
    ler(0).toCharArray(ssid_wifi, 25);
    ler(25).toCharArray(password_wifi, 25);
    ler(50).toCharArray(topic_active, 25);
    ler(75).toCharArray(topic_state, 25);
}


int contconexion;
bool ConfigurationManager::connectWiFi()
{

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid_wifi, password_wifi);
    
    Serial.println(ssid_wifi);
    Serial.println(password_wifi);
    
    while (WiFi.status() != WL_CONNECTED and contconexion <50) { 
    ++contconexion;
    Serial.print(".");
    delay(250);
  }
  if (contconexion <50) {   
        ip_current_wifi = WiFi.localIP();
        Serial.print("Conected");
        return true;
  }
  else { 
        Serial.print("Not connect");
        return false;
  }
};



bool ConfigurationManager::verifyWiFiStatus()
{
    if(WiFi.status() != WL_CONNECTED){
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid_wifi, password_wifi);
        return false;
    }
    return true;
};

void ConfigurationManager::reconnectWiFi()
{
    WiFi.reconnect();
}




ESP8266WebServer* _server; 

void pageConfig()
{
    _server->send(200, "text/html", config_page_html + final_page_html);
};

void guardar_conf()
{
    gravar(0,_server->arg("ssid"));
    gravar(25,_server->arg("pass"));
    gravar(50,_server->arg("broker"));
    gravar(75,_server->arg("port"));
    gravar(100,_server->arg("active"));
    gravar(100,_server->arg("state"));
    _server->send(200, "text/html", config_page_html + message_html + final_page_html);
    delay(2000);
    ESP.restart();
}

void ConfigurationManager::beginConfigServer(const char* ssid, const char* password)
{   
    _server = &server;
    WiFi.softAP(ssid, password);
    ip_current_wifi = WiFi.softAPIP(); 
    server.on("/", pageConfig);
    server.on("/guardar_conf", guardar_conf);
    server.begin();
    while (true){
        server.handleClient();
    }
};




