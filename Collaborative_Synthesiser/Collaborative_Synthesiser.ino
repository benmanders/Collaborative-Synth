#include <Adafruit_VS1053.h>
#define VS1053_BANK_DRUMS1 0x78
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

uint8_t numNotes = 15;

void setup()
{
  Serial.begin(115200);
  Serial.println("VS1053 MIDI test");
  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  midiSetChannelBank(0, VS1053_BANK_DRUMS1);
  midiSetChannelVolume(0, 127);
  Serial.println("Started");
  setupBeats();
  setupNotes();
}

void loop()
{
readSensors();
playStep();
}