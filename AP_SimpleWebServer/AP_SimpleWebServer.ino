#include <SPI.h>
#include <WiFi101.h>
#include "arduino_secrets.h"
#include "webpage.h"
//------------------------------------------------------------------------------
char ssid[] = SECRET_SSID;    // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;             // your network key Index number (needed only for WEP)
//------------------------------------------------------------------------------
int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);
//------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
//  while (!Serial){}  
  pinMode(led, OUTPUT);
  setupWifi();
  setupAccessPoint(ssid, pass);
}

void loop()
{
  updateConnectionStatus();
  listenForClient();
}
