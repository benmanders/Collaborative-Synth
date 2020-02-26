#include <SPI.h>
#include <WiFi101.h>
#include "arduino_secrets.h"
//---------------------------------------------------------------------------------------------------------------------------------------
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
//---------------------------------------------------------------------------------------------------------------------------------------
String host = "192.168.1.1";    // name address for Google (using DNS)
String onUrl  = "/H";
String offUrl = "/L";
WiFiClient client;
//---------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  while (!Serial) {}


  // wait until network exists, then connect
  connectToWifi(ssid, pass);

}

void loop()
{
  makeGetRequest(host, onUrl, client, 80);
  parseContent();
  delay(1000);
  makeGetRequest(host, offUrl, client, 80);
  parseContent();
  delay(1000);
}
