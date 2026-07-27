#define WIFI_SSID     "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#define API_KEY       "YOUR_OPENWEATHERMAP_API_KEY"
#define CITY          "Moscow"
#define COUNTRY_CODE  "RU"

#ifndef CONFIG_H
#define CONFIG_H

// --- Wi-Fi Settings ---
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// --- OpenWeatherMap API ---
const String API_KEY = "YOUR_API_KEY_HERE";
const String CITY = "Moscow";
const String COUNTRY_CODE = "RU";

// --- Hardware Pins ---
#define SDA_PIN 21
#define SCL_PIN 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#endif // CONFIG_H