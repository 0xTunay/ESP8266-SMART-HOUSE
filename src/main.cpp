#include <ESP8266WiFi.h>
#include< "ESP8266WebServer.h>

const char* ssid = "zte08";
const char* password = "23021921k";

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

void loop() {
    server.handleClient();
}
