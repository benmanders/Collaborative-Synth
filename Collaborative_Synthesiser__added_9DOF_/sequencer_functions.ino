
void playStep()
{

  for (int note = 0; note < numNotes; note++)
  {
    if (noteMatrix[curBeat][note])
    {
      midiNoteOn(0, pentatonicMidi[note], 127);
    }
  }

  delay(170);
  for (int note = 0; note < numNotes; note++)
  {
    if (noteMatrix[curBeat][note] != 0)
    {
      midiNoteOff(0, pentatonicMidi[note], 127);
    }
  }
  curBeat++;
  curBeat %= numBeats;
}

/*
  void setupBeats()
  {
  int noteIndex = map(analogRead(A1), 0, 1023, 0, 15);
  Serial.println(noteIndex);
  {
    for (int i = 0; i < numBeats; i++)
    {
      beats[i] = 0;
    }
    beats[0] = 48;
    beats[8] = pentatonicMidi[noteIndex];
    beats[20] = pentatonicMidi[noteIndex];
    beats[28] = pentatonicMidi[noteIndex];
    beats[40] = pentatonicMidi[noteIndex];
    beats[50] = 48;
    beats[56] = pentatonicMidi[noteIndex];
    beats[60] = 52;


  }
  }

  void playChord()
  {
  for (int n = 0; n < numNotes; n += 2)
  {
    midiNoteOn(0, pentatonicMidi[n], 127);
  }
  delay(200);
  for (int n = 0; n < numNotes; n++)
  {
    midiNoteOff(0, pentatonicMidi[n], 127);
  }
  }

  void playNotes()
  {

  for (int n = 0; n < numNotes; n++)
  {
    int noteIndex = map(analogRead(A1), 0, 1023, 0, 15);
    Serial.println(noteIndex);
    pentatonicMidi[noteIndex];
    midiNoteOn(0, pentatonicMidi[noteIndex], 127);
    delay(200);
    midiNoteOff(0, pentatonicMidi[noteIndex], 127);
  }
  }

  void randomiseNoteMatrix()
  {
  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      noteMatrix[b][n] = !(random(20) < 17);
    }
  }

  }


  void setAscendingScale()
  {
  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      noteMatrix[b][n] = (b == n) ;
    }
  }
  }


  void setInterleaveScale()
  {
  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      if ((b == n))
      {
        noteMatrix[b][n] = true;
      }
      else if ((b == numBeats - n) )
      {
        noteMatrix[b][n] = true;
      }
      else
      {
        noteMatrix[b][n] = false;
      }
    }
  }
  }

  void printMatrix()
  {
  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      Serial.print(noteMatrix[b][n]);
      Serial.print('\t');
    }
    Serial.println();
  }
  }


  void setMatrixFromSensor()
  {
  int reading = map(analogRead(A1), 0 , 1023, 0, sequenceLength);
  reading = constrain(reading, 0, sequenceLength - 1);
  Serial.println(reading);
  for (int i = 0; i < reading ; i++)
  {
    noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = true;
  }

  for (int i = reading; i < sequenceLength ; i++)
  {
    noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = false;
    //Serial.println(i);

  }

  }

  void setMatrixDensity(int a)
  {
  for (int b = 0; b < numBeats; b++)
  {
    for (int n = 0; n < numNotes; n++)
    {
      noteMatrix[b][n] = !(random(20) < a);
    }
  }
  }

*/
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
  int noteIndex = gyroX * 15;
  Serial.println(noteIndex);
  pentatonicMidi[noteIndex];
  midiNoteOn(0, pentatonicMidi[noteIndex], 127);
  delay(200);
  midiNoteOff(0, pentatonicMidi[noteIndex], 127);
}

void setMatrixFrom9dof()
{
  lsm.read();
  sensors_event_t a, m, g, temp;
  lsm.getEvent(&a, &m, &g, &temp);
  float  gyroX = constrain(m.magnetic.x, 0, 1);
  int reading = gyroX * sequenceLength;
  Serial.println(reading);

    for (int i = 0; i < reading ; i++)
    {
      noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = true;
    }
  
    for (int i = reading; i < sequenceLength ; i++)
    {
      noteMatrix[finalPatternBeats[i]][finalPatternNotes[i]] = false;
      //Serial.println(i);
  }
}
