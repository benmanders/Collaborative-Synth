  void readSensors()
  {
  
//  lightSensorVal = analogRead(A1);
//  potentiometerVal = analogRead(A2);
//  // Serial.println(sensorValue);
//  uint8_t  n = map(lightSensorVal, 0, 1023, 0, 6);
//  Serial.print("light sensor ");
//  Serial.println(n);
//  Serial.println(" ... ");
//  //uint8_t  u = map(potentiometerVal, 0, 1023, 0, 1000);
//  Serial.print("Potentiometer ");
//  Serial.println(potentiometerVal);

  }

void read9Dof()
{
  // lsm.read();
  // sensors_event_t a, m, g, temp;
  // lsm.getEvent(&a, &m, &g, &temp);

  // Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2");
  // Serial.print("\tY: "); Serial.print(a.acceleration.y);     Serial.print(" m/s^2 ");
  // Serial.print("\tZ: "); Serial.print(a.acceleration.z);     Serial.println(" m/s^2 ");
  
  // Serial.print("Mag X: ");
  // Serial.print(m.magnetic.x - .150); // Serial.print(" gauss");
  // Serial.print("\t");
  // Serial.print(m.magnetic.y  - .140);   // Serial.print(" gauss");
  // Serial.print("\t");
  // Serial.println(m.magnetic.z - .110);    // Serial.println(" gauss");
  
  // Serial.print("Gyro X: "); Serial.print(g.gyro.x);   Serial.print(" dps");
  // Serial.print("\tY: "); Serial.print(g.gyro.y);      Serial.print(" dps");
  // Serial.print("\tZ: "); Serial.print(g.gyro.z);      Serial.println(" dps");
}
