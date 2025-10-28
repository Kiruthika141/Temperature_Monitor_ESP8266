#include <ESP8266WiFi.h>
#include <DHT.h>
const char* ssid = "YOUR WIFINAME";//EDIT 
const char* password = "YOUR WIFI PASSWORD";//EDIT
const char* server = "api.thingspeak.com";
String apiKey = "THINGSPEAK API KEY"; //EDIT
#define DHTPIN D1     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  Serial.println();
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi connected");
}
void loop() 
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  if (client.connect(server, 80)) 
  {
    String postStr = "api_key=" + apiKey;
    postStr += "&field1=";
    postStr += String(temperature);
    postStr += "&field2=";
    postStr += String(humidity);
    client.println("POST /update HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postStr.length());
    client.println();
    client.print(postStr);
    Serial.println("Data sent to ThingSpeak");
  }
  client.stop();
  delay(500);
}