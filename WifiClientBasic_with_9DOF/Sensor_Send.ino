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


void send9dof()
{
  lsm.read();
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp);
  float  gyroX = constrain(m.magnetic.x, 0, 1);
  String noteIndex = "/" + String(gyroX * 15);
  Serial.print("Note Index: ");
  Serial.println(noteIndex);
  makeGetRequest(host, noteIndex, client, 80);
  parseContent();
  delay(1000);

  
}
