void playStep()
{
  if (beats[curBeat] != 0)
  {
    midiNoteOn(0, beats[curBeat], 127);
  }
  delay(150);
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
  beats[4] = 32;
  beats[7] = 32;
  beats[8] = 40;
  beats[10] = 32;
  beats[12] = 40;
  beats[13] = 32;
  beats[15] = 50;
}

void setupNotes()
{
  for (int n = 0; n < numNotes; n++)
  {
    int Cmaj[] {48, 50, 52, 55, 57, 60, 62, 64, 67, 67, 69, 72, 74, 76, 79, 81}; // 3 Octaves of Cmaj Pentatonic
  }
}
