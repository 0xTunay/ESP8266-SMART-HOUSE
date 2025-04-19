#include "../lib/Arduino/libraries/ESP8266WebServer/src/ESP8266WebServer.h"
#include "../lib/Arduino/libraries/ESP8266WebServer/src/ESP8266WebServer.h"
#include "../lib/Arduino/libraries/ESP8266WiFi/src/ESP8266WiFi.h"

const char* ssid = "XXX";
const char* password = "XXX";

ESP8266WebServer server(80);

void handleRoot() {
    server.send(200, "text/plain", "Hello, ESP!");
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    Serial.print("Подключаемся к Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Wi-Fi подключен");
    Serial.print("IP-адрес: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP сервер запущен");
}
/*TEST SSH COMMIT*/
void loop() {
    server.handleClient();
}
