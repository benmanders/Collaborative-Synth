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
