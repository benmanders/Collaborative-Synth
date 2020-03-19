
#include <Adafruit_VS1053.h>
#define VS1053_BANK_DRUMS1 0x78 // DRUM PATCH
#define VS1053_BANK_DEFAULT 0x00 // DEFAULT MELODY PATCH
#define VS1053_GM1_ACOUSTIC_GRAND_PIANO 1 // ACOUSTIC GRAND
#define VS1053_GM1_SYNTH_BASS_1 39 // SYNTH BASS
#define VS1053_GM1_FLUTE 74 // FLUTE
#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
#define MIDI_CHAN_VOLUME 0x07
#define MIDI_CHAN_PROGRAM 0xC0
#define VS1053_MIDI Serial1

//------------------------------------------------LSM 9DOF SETUP----------------------------------------------------------------------
#include <Wire.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>

Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

#define LSM9DS1_SCK A5
#define LSM9DS1_MOSI A4

float offsetX = -0.139;
float offsetY = 0.25;
float offsetZ = -0.128;
constexpr float radToDegCoef = (180.0f / 3.1415963f);

void setupSensor()
{
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");

  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G); // 1.) Set the accelerometer range
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_16GAUSS);   // 2.) Set the magnetometer sensitivity
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);   // 3.) Setup the gyroscope
}
//-----------------------------------------------------------------------------------------------------------------------------

int lightSensorVal = 0;
int potentiometerVal = 0;
const int numBeats = 16;
uint8_t beats[numBeats];
uint8_t curBeat = 0;
const uint8_t numNotes = 16;
bool noteMatrix[numBeats][numNotes];
bool finalPattern[numBeats][numNotes];
const int sequenceLength = 17;

//------------------------------------------------------Device 1---------------------------------------------------------------
int finalPatternBeats[sequenceLength] = {1, 4, 7, 5, 2, 6, 4, 11, 13, 15, 1, 7, 5, 2, 14, 1, 15};
int finalPatternNotes[sequenceLength] = {3, 7, 4, 11, 10, 5, 9, 1, 2, 3, 5, 2, 9, 7, 13, 7, 15};
int pentatonicMidi[numNotes] {48, 50, 52, 55, 57, 60, 62, 64, 67, 69, 72, 74, 76, 79, 81, 84}; // cmaj pentatonic - 3 octaves (high)
//-----------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------Device 2---------------------------------------------------------------
//int finalPatternBeats[sequenceLength] = {5, 10, 3, 1, 4, 13, 14, 15, 7, 7, 6, 11, 2, 2, 3, 5, 10};
//int finalPatternNotes[sequenceLength] = {3, 7, 4, 11, 10, 5, 9, 1, 2, 3, 5, 2, 9, 7, 13, 7, 15};
//int pentatonicMidi[numNotes] {12, 14, 16, 19, 21, 24, 26, 28, 31, 33, 36, 38, 40, 43, 45, 48}; // cmaj pentatonic - 3 octaves (low)
//-----------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------Drum Patch---------------------------------------------------------------
//int finalPatternBeats[sequenceLength] = {0, 4, 8, 10, 12, 16, 2, 6, 11, 15, 16, 2, 10, 14, 16, 6, 2};
//int finalPatternNotes[sequenceLength] = {1, 1, 1, 4, 1, 4, 9, 9, 9, 9, 9, 9, 9, 13, 13, 3, 5};
//int pentatonicMidi[numNotes] {35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50}; // bass drum, hi hat & tom
//-----------------------------------------------------------------------------------------------------------------------------

int run;
int buttonPin;

void setup()
{
  Serial.begin(115200);
  //  while (!Serial)
  //  {
  //    delay(1); // will pause Zero, Leonardo, etc until serial console opens
  //  }
  Serial.println("LSM9DS1 data read demo");
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");
  setupSensor();
  Serial.println("VS1053 MIDI test");
  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  midiSetChannelBank(0, VS1053_BANK_DEFAULT);
  //midiSetChannelBank(0, VS1053_BANK_DRUMS1);
  midiSetChannelVolume(0, 127);
  midiSetInstrument(0, VS1053_GM1_FLUTE);
  // midiSetInstrument(0, VS1053_BANK_DRUMS1);
  Serial.println("Started");
  int ldrVal = analogRead(A1);
  //int potentiometerVal = analogRead(A2);

  //setupBeats();
  //playNotes();
  //randomiseNoteMatrix();
  //setAscendingScale();
  //setInterleaveScale();
  //setMatrixDensity(18);
  //printMatrix();

  notesOff();


  // run = 0; //starts stopped
  // buttonPin = 10; //whatever pin your button is plugged into
  // pinMode(buttonPin, INPUT_PULLUP);

}

void loop()
{

  //
  //  if (digitalRead(buttonPin) == LOW) //funcitons based off of button pulling input pin LOW
  //  {
  //    if (run == 0)
  //    {
  //      run = 255;
  //    }
  //    else
  //    {
  //      run = 0;
  //    }
  //  }
  //
  //  if (run > 0)
  //  {

  volume();
  instrument();
  read9Dof();
  //playNotesFrom9dof();
  setMatrixFrom9dof();
  playStep();


  //}
}
