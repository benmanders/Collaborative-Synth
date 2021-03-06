void readSensor()
{
  int ldrVal = analogRead(A1);
  int ldrMapped = map(ldrVal, 0, 1023, 0, 15);
  Serial.println(ldrMapped);

  if (ldrMapped < 8)
  {
    Serial.println(onUrl);
  }

  else
  {
    Serial.println(offUrl);
  }
  delay(500);
}



void sendSensorVal()
{

  int ldrMapped = map(analogRead(A1), 0, 1023, 0, 15);
  String ldrSend = "/" + String(ldrMapped);
  //int ldrMapped = map(ldrVal, 0, 1023, 0, 15);
  //Serial.println(ldrMapped);
  makeGetRequest(host, ldrSend, client, 80);
  parseContent();
  delay(1000);
}
