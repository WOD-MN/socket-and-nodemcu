#include<ESP8266WiFi.h>
#define PORT 5055

// WiFi Settings
const char* SSID = "asachin_fctwn_2";
const char* PASSWORD = "CLEB12F6EF";

WiFiServer server(PORT);
void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Connecting to Wi-Fi Network");
  Serial.println(SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi with Local Address");
  Serial.print(WiFi.localIP());
  Serial.print(":");
  Serial.print(PORT);
  Serial.println();
  server.begin();
  delay(1000);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      Serial.println("Client Connected");
    }

    while (client.connected()) {
      while (client.available() > 0) {
        Serial.println(client.readString());
      }

      while (Serial.available() > 0) {
        client.println(Serial.readString());
      }
    }
    client.stop();
    Serial.println("Client Disconnected");
  }
}