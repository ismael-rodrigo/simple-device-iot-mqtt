#include "configuration/configurationManager.h"
#include "configuration/stringPages.h"


ConfigurationManager::ConfigurationManager():
server(80)
{
}



int contconexion;
bool ConfigurationManager::connectWiFi(const char* ssid, const char* password)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);


    while (WiFi.status() != WL_CONNECTED and contconexion <50) { 
    ++contconexion;
    delay(250);
  }
  if (contconexion <50) {   
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
      return true;
  }
  else { 
      Serial.println("");
      Serial.println("Error !");
      return false;
  }
};


ESP8266WebServer* _server; 

void pageConfig(){
    _server->send(200, "text/html", config_page_html + final_page_html);
};

void guardar_conf(){

Serial.println(_server->arg("ssid"));
gravar(0,_server->arg("ssid"));

Serial.println(_server->arg("pass"));
gravar(25,_server->arg("pass"));

Serial.println(_server->arg("broker"));
gravar(50,_server->arg("broker"));

Serial.println(_server->arg("port"));
gravar(75,_server->arg("port"));

Serial.println(_server->arg("active"));
gravar(100,_server->arg("active"));

Serial.println(_server->arg("state"));
gravar(100,_server->arg("state"));

_server->send(200, "text/html", config_page_html + message_html + final_page_html);

delay(2000);
ESP.restart();

}

void ConfigurationManager::beginConfigServer(const char* ssid, const char* password)
{   

    _server = &server;

    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP(); 
    Serial.print("IP of access point: ");
    Serial.println(myIP);
    Serial.println("WebServer intialized...");
    server.on("/", pageConfig);
    server.on("/guardar_conf", guardar_conf);
    server.begin();

    while (true) {
        server.handleClient();
    }
};




