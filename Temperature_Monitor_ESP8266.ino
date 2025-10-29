#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#include <ThingSpeak.h>
const char* ssid = "YOUR WIFINAME";//EDIT 
const char* password = "YOUR WIFI PASSWORD";//EDIT
WiFiServer server(80);
WiFiClient client;
unsigned long myChannelNumber = 1;//EDIT
const char * myWriteAPIKey = "YOUR THINGSPEAK API KEY"; //EDIT
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;
#define DHTPIN D5 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  dht.begin();
  ThingSpeak.begin(client); 
}
void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    delay(2500);
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    if (isnan(h) || isnan(t) || isnan(f)) 
    {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
    Serial.print("Temperature (ºC): ");
    Serial.print(t);
    Serial.println("ºC");
    Serial.print("Humidity");
    Serial.println(h);
    ThingSpeak.setField(1, t);
    ThingSpeak.setField(2, h);
    ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
    lastTime = millis();
  }
}

