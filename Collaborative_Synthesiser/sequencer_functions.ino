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
  for (int i = 0; i < numBeats; i++)
  {
    beats[i] = 0;
  }
  beats[0] = 32;
  beats[3] = 32;
  beats[4] = 32;
  beats[7]  = 31;
  beats[10] = 32;
}
