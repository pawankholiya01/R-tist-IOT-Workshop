#include <WiFi.h>
#include <HTTPClient.h>

String apiKey = "UOS9XENITOLRFETC";                 //  Enter your Write API key from ThingSpeak
const char *ssid =  "RedmiNote";                                    // replace with your wifi ssid and wpa2 key
const char *pass =  "12345678";
const char* server = "api.thingspeak.com";
WiFiClient client;
void setup() 
{
    Serial.begin(115200);
    delay(10);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
 
}


void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
    int rssi= WiFi.RSSI();
    http.begin("http://api.thingspeak.com/update?api_key=UOS9XENITOLRFETC&field1="+String(rssi)); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println("http Status Code : ");
        Serial.println(httpCode);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
    Serial.println("\nWaiting Time ");

    http.end(); //Free the resources
  }
 
  delay(20000);
 
}
