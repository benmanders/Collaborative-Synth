#include <Adafruit_VS1053.h>
//#define VS1053_BANK_DRUMS1 0x78 // DRUM PATCH
#define VS1053_BANK_DEFAULT 0x00 // DEFAULT MELODY PATCH
#define VS1053_GM1_ACOUSTIC_GRAND_PIANO 1 // ACOUSTIC GRAND 
#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
#define MIDI_CHAN_VOLUME 0x07
#define MIDI_CHAN_PROGRAM 0xC0
#define VS1053_MIDI Serial1

int lightSensorVal = 0;
int potentiometerVal = 0;
const int numBeats = 16;
uint8_t beats[numBeats];
uint8_t curBeat = 0;
const uint8_t numNotes = 16;
bool noteMatrix[numBeats][numNotes];
bool finalPattern[numBeats][numNotes];
bool finalPatternBeats[3] = {1, 4, 7};
bool finalPatternNotes[3] = {3, 7, 4};
int pentatonicMidi[numNotes] {48, 50, 52, 55, 57, 60, 62, 64, 67, 69, 72, 74, 76, 79, 81, 84}; // cmaj pentatonic - 3 octactaves

void setup()
{
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("VS1053 MIDI test");
  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  midiSetChannelBank(0, VS1053_BANK_DEFAULT);
  midiSetChannelVolume(0, 127);
  midiSetInstrument(0, VS1053_GM1_ACOUSTIC_GRAND_PIANO);
  Serial.println("Started");
  int ldrVal = analogRead(A1);
  int potentiometerVal = analogRead(A2);
  setupBeats();
  //playNotes();
  randomiseNoteMatrix();
  //setAscendingScale();
  //setInterleaveScale();
  setMatrixDensity(19);
  printMatrix();

}

void loop()
{
  //playChord();
  //readSensors();
  //playNotes();
  //setupBeats();
  setMatrixFromSensor();
  playStep();
}
