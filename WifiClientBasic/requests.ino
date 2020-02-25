unsigned int makeGetRequest(String &host, String &url, Client &httpClient, int port)
{
  Serial.println(((port == 443) ? ("https://") : ("http://")) + host + url);
  unsigned int contentLength;

  if (httpClient.connect(host.c_str(), port))
  {
    httpClient.println("GET " + url + " HTTP/1.1");
    httpClient.println("Host: " + host);
    httpClient.println("Connection: close");
    httpClient.println();
  }
  else
  {
    Serial.println("Connection Failed; check:\n\t- did WiFi Connect?\n\t- is the site HTTPS?\n\t- have you used the correct client? v(WiFiClient or WiFiSSLClient)\n\t- have you selected the correct port? (80 or 443)\n");
    haltFirmware();
  }

  while (httpClient.connected())
  {
    String line = httpClient.readStringUntil('\n');
    Serial.println(line);
    if (line.startsWith("Content-Length: "))
    {
      contentLength = getContentLength(line);
    }    
    else if (line == "\r")
    {
      break;
    }
  }
  return contentLength;
}

unsigned int getContentLength(String line)
{
  return line.substring(16).toInt(); // This line prints out the response from Carbon Intensity to the Serial Monitor – this will let you know if your request was successful
}



void parseContent()
{
  while (client.available()) 
  {
    char c = client.read();
    Serial.write(c);
  }

  if (!client.connected()) 
  {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();
  }

}
