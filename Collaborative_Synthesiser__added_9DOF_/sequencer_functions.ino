
void playStep()
{

  lsm.read();
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp);
  float  gyroY = constrain(m.magnetic.y, 0, 1);
  Serial.print("Magnetic Y : ");
  Serial.println(m.magnetic.y);
  int noteIndex = gyroY * 15;
  Serial.print("Note Index : ");
  Serial.println(noteIndex);


  for (int note = 0; note < numNotes; note++)
  {
    if (noteMatrix[curBeat][note])
    {
      midiNoteOn(0, pentatonicMidi[noteIndex], 127);
    }
  }

  delay(170);
  for (int note = 0; note < numNotes; note++)
  {
    if (noteMatrix[curBeat][note] != 0)
    {
      midiNoteOff(0, pentatonicMidi[noteIndex], 127);
    }
  }
  curBeat++;
  curBeat %= numBeats;
}


void notesOff()
{

  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      noteMatrix[b][n] = false;
    }
  }
}

void playNotesFrom9dof()
{
  lsm.read();
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp);
  float  gyroX = constrain(m.magnetic.x, 0, 1);
  Serial.print("magnetic x : ");
  Serial.println(m.magnetic.x);
  int noteIndex = gyroX * 15;
  pentatonicMidi[noteIndex];
  midiNoteOn(0, pentatonicMidi[noteIndex], 127);
  delay(200);
  midiNoteOff(0, pentatonicMidi[noteIndex], 127);
  Serial.print("noteIndex : ");
  Serial.println(noteIndex);

  //  int yReading = m.magnetic.y * 1000;
  //  int tempo = constrain(yReading, 0, 1000);
  //  Serial.println(tempo);
  //  delay(tempo);
}


void setMatrixFrom9dof()
{
  lsm.read();
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp);
  float  gyroX = constrain(m.magnetic.x, 0, 1);
  int xReading = gyroX * sequenceLength;
  Serial.println(xReading);

  //  int yReading = m.magnetic.y * 1000;
  //  int tempo = constrain(yReading, 0, 1000);
  //  Serial.println(tempo);
  //  delay(tempo);

  for (int i = 0; i < xReading ; i++)
  {
    noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = true;
  }

  for (int i = xReading; i < sequenceLength ; i++)
  {
    noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = false;
  }

}
