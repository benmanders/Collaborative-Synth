#include <SPI.h>
#include <WiFi101.h>
#include "arduino_secrets.h"
//---------------------------------------------------------------------------------------------------------------------------------------
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
//---------------------------------------------------------------------------------------------------------------------------------------
String host = "192.168.1.1";    // name address for Google (using DNS)
String home = "";
String onUrl  = "/H";
String offUrl = "/L";
WiFiClient client;
//---------------------------------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
//  while (!Serial) {}
  setupWifiCard();
  listNetworks();
  while (!isNetworkPresent(ssid)) {}
  connectToWifi(ssid, pass);
  makeGetRequest(host, home, client, 80);
}

void loop()
{
//  int ldrVal = analogRead(A1);
//  int ldrMapped = map(ldrVal, 0, 1023, 0, 15);
//  Serial.println(ldrMapped);
//
//  if (ldrMapped < 8)
//  {
//    makeGetRequest(host, onUrl, client, 80);
//    parseContent();
//    delay(1000);
//  }
//  
//  else
//  {
//    makeGetRequest(host, offUrl, client, 80);
//    parseContent();
//    delay(1000);
//  }
 
  //readSensor();
  sendSensorVal();
  delay(500);
}
