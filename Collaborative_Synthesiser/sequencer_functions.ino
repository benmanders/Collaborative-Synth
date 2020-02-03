void playStep()
{
  if (beats[curBeat] != 0)
  {
    midiNoteOn(0, beats[curBeat], 127);
  }
  delay(100);
  midiNoteOff(0, beats[curBeat], 127);
  curBeat++;
  curBeat %= numBeats;
}

void setupBeats()
{
  for (int n = 0; n < numNotes; n++)
  {
    int pentatonicMidi[16] {48, 50, 52, 55, 57, 60, 62, 64, 67, 69, 72, 74, 76, 79, 81, 84};
    int noteIndex = map(analogRead(A1), 0, 1023, 0, 15);
    Serial.println(noteIndex);
    pentatonicMidi[noteIndex];
  }

  {
    for (int i = 0; i < numBeats; i++)
    {
      beats[i] = 0;
    }
    beats[0] = pentatonicMidi[noteIndex];
    beats[4] = pentatonicMidi[noteIndex];
    beats[10] = pentatonicMidi[noteIndex];
    beats[14] = pentatonicMidi[noteIndex];
    beats[20] = pentatonicMidi[noteIndex];
    beats[25] = pentatonicMidi[noteIndex];
    beats[28] = pentatonicMidi[noteIndex];
    //beats[30] = 52;
  }
}

//void playNotes()
//{
//  for (int n = 0; n < numNotes; n++)
//  {
//    int pentatonicMidi[16] {48, 50, 52, 55, 57, 60, 62, 64, 67, 69, 72, 74, 76, 79, 81, 84};
//    int noteIndex = map(analogRead(A1), 0, 1023, 0, 15);
//    Serial.println(noteIndex);
//    pentatonicMidi[noteIndex];
//    midiNoteOn(0, pentatonicMidi[noteIndex], 127);
//    delay(200);
//    midiNoteOff(0, pentatonicMidi[noteIndex], 127);
//  }
//}
