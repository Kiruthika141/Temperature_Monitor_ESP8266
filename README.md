# DHT11 Temperature & Humidity Monitor using ESP8266 and ThingSpeak

## Overview
This project measures **temperature** and **humidity** using a **DHT11 sensor** and sends the data to **ThingSpeak**, an IoT cloud platform, using the **ESP8266 Wi-Fi module**.
You can view your data on a live graph from anywhere in the world. Perfect for home automation, weather stations, or environment monitoring systems.

## Components Required
| Component | Description | Quantity |
|------------|-------------|-----------|
| **ESP8266 NodeMCU** | Wi-Fi-enabled microcontroller board | 1 |
| **DHT11 Sensor** | Measures temperature and humidity | 1 |
| **Jumper Wires** | For connections | As needed |
| **USB Cable** | To program NodeMCU | 1 |
| **ThingSpeak Account** | For cloud data visualization | Free |

## Pin Connections
| DHT11 | ESP8266 |
|--------|----------|
| VCC | 3.3V |
| GND | GND |
| DATA | D1 |

## ThingSpeak Setup
1. Go to [ThingSpeak](https://thingspeak.com/).
2. Create a free account.
3. Make a new **Channel** with two fields:
   - Field 1 → Temperature
   - Field 2 → Humidity
4. Copy your **Write API Key** and paste it into your code.
5. Upload the code and open **Serial Monitor** to verify data sending.
You’ll see live graphs of temperature and humidity! 

## How It Works
1. The **DHT11 sensor** reads temperature and humidity.
2. The **ESP8266** connects to your Wi-Fi.
3. Data is sent via HTTP POST request to **ThingSpeak**.
4. ThingSpeak stores and plots the data in real time.

## Output Example
| Time | Temperature (°C) | Humidity (%) |
|------|-------------------|--------------|
| 10:00 | 28.5 | 65 |
| 10:20 | 29.1 | 63 |
| 10:40 | 30.0 | 60 |

## Applications
- Home temperature monitoring  
- Greenhouse climate control  
- IoT-based weather station  
- Smart agriculture  
