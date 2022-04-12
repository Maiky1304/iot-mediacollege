#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);

const char* ssid = "Ma";
const char* password = "standaard_drinker";

void wifi_setup() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("HTTP server started");
}

server.on("/", handleRoot);
server.on("/sensor", readDHT11)

void handleRoot() {
    server.send(200, "text/html", "<h3>Sensor</h3><form action=\"/sensor\" method=\"/GET\"><input type=\"/text\" value=\"Submit\"></form>")
}

void readDHT11() {
    float temp = round(dht.readTemperature() * 10) / 10;
    float hum = round(dht.readHumidity() * 10) / 10;
    float heatindex = round(dht.computeHeatIndex(temp, hum, false) * 10) / 10;

    if (isnan(temp) || isnan(hum) || isnan(heatindex)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.println("Temp. " + temp);
    Serial.println("Humidity " + hum);
    Serial.println("Heat index " + heatindex);
}
