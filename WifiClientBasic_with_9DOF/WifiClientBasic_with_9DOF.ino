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
//------------------------------------------------LSM 9DOF SETUP----------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

#define LSM9DS1_SCK A5
#define LSM9DS1_MOSI A4

float offsetX = -0.139;
float offsetY = 0.25;
float offsetZ = -0.128;
constexpr float radToDegCoef = (180.0f / 3.1415963f);

void setupSensor()
{
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");

  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G); // 1.) Set the accelerometer range
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_16GAUSS);   // 2.) Set the magnetometer sensitivity
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);   // 3.) Setup the gyroscope
}
//------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    delay(1); // will pause Zero, Leonardo, etc until serial console opens
  }
  Serial.println("LSM9DS1 data read demo");
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
  // helper to just set the default scaling we want, see above!
  setupSensor();


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
  //sendSensorVal();
  
  send9dof();
  delay(500);
}
