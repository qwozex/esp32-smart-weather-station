# esp32-smart-weather-station
IoT weather station &amp; air monitor with ESP32, BME280, OLED display, and local Web Dashboard.
# 🌤️ ESP32 Smart Weather Station & Air Monitor

An IoT-based smart weather station built with **ESP32**, **BME280 sensor**, and an **OLED display**. Features real-time environmental monitoring, local Web Dashboard, OpenWeatherMap API integration, and custom 3D-printable enclosure.

![Project Status](https://img.shields.io/badge/Status-Active-brightgreen)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino%20%2F%20PlatformIO-orange)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## 🌟 Key Features

- **Sensors Integration:** Measures Temperature, Humidity, and Atmospheric Pressure via I2C (BME280).
- **Outdoor Forecast:** Fetches weather forecast and city data using OpenWeatherMap REST API via Wi-Fi.
- **Local Web Dashboard:** Hosted directly on the ESP32 (AsyncWebServer) — accessible from phone or PC.
- **OLED Display UI:** Crisp 0.96" I2C OLED interface with custom weather icons.
- **3D Printed Case:** Ready-to-print STL models included for desktop mounting.

---

## 🛠️ Hardware Requirements

| Component | Description | Connection |
| :--- | :--- | :--- |
| **ESP32 DevKit V1** | Main Microcontroller (Wi-Fi + BT) | — |
| **BME280 Module** | Temperature / Humidity / Pressure Sensor | I2C (SDA: GPIO 21, SCL: GPIO 22) |
| **SSD1306 OLED 0.96"** | 128x64 Pixel Screen | I2C (SDA: GPIO 21, SCL: GPIO 22) |
| **MicroUSB Cable** | Power Supply (5V) & Flashing | — |

---

## 📐 Wiring Diagram

<img width="1408" height="768" alt="12" src="https://github.com/user-attachments/assets/8d0260e5-132d-4eb2-a84f-2bc10bdc4f5e" />
