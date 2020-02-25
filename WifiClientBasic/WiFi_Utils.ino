//Setting up a WiFi connection - COMPLETE

void connectToWifi(const char ssidName[], const char pass[])
{
#ifdef ARDUINO_SAMD_ZERO
  WiFi.setPins(8, 7, 4, 2); // Set the WiFi pins on the Feather
#endif

  Serial.println("Starting...");
  Serial.println("Connecting to WiFi.");

  int conn = WiFi.begin(ssidName, pass);

  if (conn == WL_CONNECTED)
  {
    Serial.println("OK!");
  }
  else if (conn == WL_IDLE_STATUS)
  {
    Serial.println("Idle");
  }
  else
  {
    Serial.println("WiFi Connection Failed!");
  }

}

void haltFirmware()
{
  Serial.println("\n\nSTOPPING THE PROGRAM!");
  while (true) {}
}

int add(int num1, int num2)
{
  return num1 + num2;
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
