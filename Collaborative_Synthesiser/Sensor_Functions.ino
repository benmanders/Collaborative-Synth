  void readSensors()
  {
  
  lightSensorVal = analogRead(A1);
  potentiometerVal = analogRead(A2);
  // Serial.println(sensorValue);
  uint8_t  n = map(lightSensorVal, 0, 1023, 0, 15);
  Serial.print("light sensor ");
  Serial.println(i);
  Serial.println(" ... ");
  //uint8_t  u = map(potentiometerVal, 0, 1023, 0, 1000);
  Serial.print("Potentiometer ");
  Serial.println(potentiometerVal);

  }
