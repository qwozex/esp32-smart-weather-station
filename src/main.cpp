#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "config.h"

// Hardware instances
Adafruit_BME280 bme;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
AsyncWebServer server(80);

// Global Variables
float temp = 0.0;
float humidity = 0.0;
float pressure = 0.0;

void initDisplay() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 10);
    display.println("Initializing...");
    display.display();
}

void initBME() {
    bool status = bme.begin(0x76);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
}

void updateOLED() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("ESP32 Weather Station");

    display.setTextSize(2);
    display.setCursor(0, 20);
    display.print(temp, 1);
    display.print(" C");

    display.setTextSize(1);
    display.setCursor(0, 45);
    display.print("Hum: "); display.print(humidity, 0); display.print("% ");
    display.print("Pres: "); display.print(pressure, 0); display.print("hPa");

    display.display();
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Weather Dashboard</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { font-family: Arial, sans-serif; text-align: center; background: #121212; color: #ffffff; margin-top: 50px; }
    .card { background: #1e1e1e; padding: 20px; border-radius: 10px; display: inline-block; width: 280px; margin: 10px; }
    h1 { color: #00adb5; }
    .val { font-size: 2em; color: #eee; }
  </style>
</head>
<body>
  <h1>ESP32 Weather Station</h1>
  <div class="card"><h3>Temperature</h3><p class="val">%TEMP% &deg;C</p></div>
  <div class="card"><h3>Humidity</h3><p class="val">%HUM% %</p></div>
  <div class="card"><h3>Pressure</h3><p class="val">%PRES% hPa</p></div>
</body>
</html>)rawliteral";

String processor(const String& var) {
    if (var == "TEMP") return String(temp, 1);
    if (var == "HUM") return String(humidity, 0);
    if (var == "PRES") return String(pressure, 0);
    return String();
}

void setup() {
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);

    initDisplay();
    initBME();

    // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

    // Web Server Routes
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", index_html, processor);
    });

    server.begin();
}

void loop() {
    // Read Sensor Data
    temp = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F;

    // Update Local Screen
    updateOLED();

    delay(2000);
}