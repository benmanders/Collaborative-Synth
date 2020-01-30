  void readSensors()
  {
  
  sensorValueA = analogRead(A1);
  sensorValueB = analogRead(A2);
  // Serial.println(sensorValue);
  uint8_t  i = map(sensorValueA, 0, 1023, 0, 100);
  Serial.print("light sensor ");
  Serial.println(i);
  Serial.println(" ... ");
  //uint8_t  u = map(sensorValueB, 0, 1023, 0, 1000);
  Serial.print("Potentiometer ");
  Serial.println(sensorValueB);

  }
