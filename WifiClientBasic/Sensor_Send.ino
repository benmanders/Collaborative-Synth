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
  String ldrVal= String(analogRead(A1));
  //int ldrMapped = map(ldrVal, 0, 1023, 0, 15);
  //Serial.println(ldrMapped);
  makeGetRequest(host, ldrVal, client, 80);
  parseContent();
  delay(1000);
}
