#include <ESP8266WiFi.h>

const char* netSSID = "WIFI_SSID";
const char* netPass = "PASSWORD";

WiFiServer wifiServer(4200);

void setup() { 
  Serial.begin(200000);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.begin(netSSID,netPass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  wifiServer.begin();
}

void loop() {
  if(WiFiClient client = wifiServer.available()){
    while(client.connected()){
      while(client.available()>0){
        char c = client.read();
        Serial.write(c);
      }
      while(Serial.available()){
        client.write(Serial.read());
      }
    }
    client.stop();
  }
}
