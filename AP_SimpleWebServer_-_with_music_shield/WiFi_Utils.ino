//------------------------------------------------------------------------------
void setupWifi()
{
#ifdef ARDUINO_SAMD_ZERO
  WiFi.setPins(8, 7, 4, 2); // Set the WiFi pins on the Feather
#endif
}
//------------------------------------------------------------------------------
void turnOffWifi()
{
  WiFi.end(); // maybe kills wifi so you can setup again
}
//------------------------------------------------------------------------------
void connectToWifi(const char ssidName[], const char pass[])
{

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
//------------------------------------------------------------------------------
void haltFirmware()
{
  Serial.println("\n\nSTOPPING THE PROGRAM!");
  while (true) {}
}
//------------------------------------------------------------------------------
void setupAccessPoint(const char ssidName[], const char pass[])
{
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    haltFirmware();
  }
  Serial.println("Access Point Web Server");
  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  status = WiFi.beginAP(ssid);
  if (status != WL_AP_LISTENING)
  {
    Serial.println("Creating access point failed");
    haltFirmware();
  }
  delay(10000);
  server.begin();
  printWiFiStatus();
}
//------------------------------------------------------------------------------
void updateConnectionStatus()
{

  if (status != WiFi.status())
  {
    status = WiFi.status(); // it has changed update the variable

    if (status == WL_AP_CONNECTED)
    {
      byte remoteMac[6];
      // a device has connected to the AP
      Serial.print("Device connected to AP, MAC address: ");
      WiFi.APClientMacAddress(remoteMac);
      Serial.print(remoteMac[5], HEX);
      Serial.print(":");
      Serial.print(remoteMac[4], HEX);
      Serial.print(":");
      Serial.print(remoteMac[3], HEX);
      Serial.print(":");
      Serial.print(remoteMac[2], HEX);
      Serial.print(":");
      Serial.print(remoteMac[1], HEX);
      Serial.print(":");
      Serial.println(remoteMac[0], HEX);
    }
    else // a device has disconnected from the AP, and we are back in listening mode
    {
      Serial.println("Device disconnected from AP");
      turnOffWifi();
      setupAccessPoint(ssid, pass);
    }
  }
}
//------------------------------------------------------------------------------
void listenForClient()
{
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) // if you get a client,
  {
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();             // read a byte, then
        //        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print(webpage);
            client.println();
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')      // if you got anything else but a carriage return character,
        {
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H"))
        {
          digitalWrite(led, HIGH); // GET /H turns the LED on
        }
        if (currentLine.indexOf("GET /") != -1 && currentLine.length() > 7)
        {
          digitalWrite(led, LOW); // GET /L turns the LED off
          int endNum = currentLine.substring(5).indexOf(" ");
          Serial.print("LDR Val: ");
          int ldrVal = currentLine.substring(5, 5 + endNum).toInt();
          Serial.println(ldrVal);
          
          for (int n = 0; n < numNotes; n++)
          {
            int noteIndex = ldrVal;
            Serial.println(noteIndex);
            pentatonicMidi[noteIndex];
            midiNoteOn(0, pentatonicMidi[noteIndex], 127);
            delay(200);
            midiNoteOff(0, pentatonicMidi[noteIndex], 127);
          }
        }
      }
    }
    client.stop();
    Serial.println("client disconnected");
  }
}
//------------------------------------------------------------------------------
void printWiFiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");

  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
