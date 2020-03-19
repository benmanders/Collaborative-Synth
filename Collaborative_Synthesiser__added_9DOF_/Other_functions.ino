void volume()
{
  int potentiometerVal = analogRead(A2);
  int volume = map(potentiometerVal, 0, 1023, 0, 127);
  Serial.print("volume: ");
  Serial.println(volume);
  midiSetChannelVolume(0, volume);
}

void instrument()
{
  //midiSetInstrument(0, VS1053_GM1_SYNTH_BASS_1);
  int potentiometerVal2 = analogRead(A3);
  int instrument = map(potentiometerVal2, 0, 1023, 0, 3);
  Serial.print("Instrument: ");
  Serial.println(instrument);

  
    //    if (instrument == 1)
    //    {
    //      midiSetInstrument(0, VS1053_GM1_ACOUSTIC_GRAND_PIANO);
    //      Serial.println("Piano");
    //    }
    //    if (instrument == 2)
    //    {
    //      midiSetInstrument(0, VS1053_GM1_SYNTH_BASS_1);
    //      Serial.println("Bass");
    //    }
    //    if (instrument == 3)
    //    {
    //      midiSetInstrument(0, VS1053_GM1_FLUTE);
    //      Serial.println("Flute");
    //    }
}
