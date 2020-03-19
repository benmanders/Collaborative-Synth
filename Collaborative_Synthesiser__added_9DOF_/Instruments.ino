
//Drum Sounds

const int acousticBassDrum = 35;
const int bassDrum = 36;
const int sideStick = 37;
const int acousticSnare = 38;
const int handClap = 39;
const int electricSnare = 40;
const int lowFloorTom = 41;
const int closedHighHat = 42;
const int highFloorTom = 43;
const int pedalHiHat = 44;
const int lowTom = 45;
const int openHighHat = 46;
const int lowMidTom = 47;
const int hiMidTom = 48;
const int crashCymbal1 = 49;
const int highTom = 50;
const int rideCymbal1 = 51;
const int chineseCymbal = 52;
const int rideBell = 53;
const int tamborine = 54;
const int splashCymbal = 55;
const int cowbell = 56;
const int crashCymbal2 = 57;
const int vibraslap = 58;
const int rideCymbal2 = 59;
const int hiBongo = 60;
const int lowBongo = 61;
const int muteHiConga = 62;
const int openHiConga = 63;
const int lowConga = 64;
const int highTibale = 65;
const int lowTimbale = 66;
const int highAgogo = 67;
const int lowAgogo = 68;
const int cabasa = 69;
const int maracas = 70;
const int shortWhistle = 71;
const int longWhistle = 72;
const int shortGuiro = 73;
const int longGuiro = 74;
const int claves = 75;
const int hiWoodblock = 76;
const int lowWoodBlock = 77;
const int muteCuica = 78;
const int openCuica = 79;
const int muteTriangle = 80;
const int openTriangle = 81;



// Main Instruments

#define VS1053_GM1_ACOUSTIC_GRAND_PIANO 1
#define VS1053_GM1_BRIGHT_ACOUSTIC_PIANO 2
#define VS1053_GM1_ELECTRIC_GRAND_PIANO 3
#define VS1053_GM1_HONKY_TONK_PIANO 4
#define VS1053_GM1_ELECTRIC_PIANO_1 5
#define VS1053_GM1_ELECTRIC_PIANO_2 6
#define VS1053_GM1_HARPSICHORD 7
#define VS1053_GM1_CLAVI 8
#define VS1053_GM1_CELESTA 9
#define VS1053_GM1_GLOCKENSPIEL 10
#define VS1053_GM1_MUSIC_BOX 11
#define VS1053_GM1_VIBRAPHONE 12
#define VS1053_GM1_MARIMBA 13
#define VS1053_GM1_XYLOPHONE 14
#define VS1053_GM1_TUBULAR_BELLS 15
#define VS1053_GM1_DULCIMER 16
#define VS1053_GM1_DRAWBAR_ORGAN 17
#define VS1053_GM1_PERCUSSIVE_ORGAN 18
#define VS1053_GM1_ROCK_ORGAN 19
#define VS1053_GM1_CHURCH_ORGAN 20
#define VS1053_GM1_REED_ORGAN 21
#define VS1053_GM1_ACCORDIAN 22
#define VS1053_GM1_HARMONICA 23
#define VS1053_GM1_TANGO_ACCORDIAN 24
#define VS1053_GM1_ACOUSTIC_GUITAR_NYLON 25
#define VS1053_GM1_ACOUSTIC_GUITAR_STEEL 26
#define VS1053_GM1_ELECTRIC_GUITAR_JAZZ 27
#define VS1053_GM1_ELECTRIC_GUITAR_CLEAN 28
#define VS1053_GM1_ELECTRIC_GUITAR_MUTED 29
#define VS1053_GM1_OVERDRIVEN_GUITAR 30
#define VS1053_GM1_DISTORTION_GUITAR 31
#define VS1053_GM1_GUITAR_HARMONICS 32
#define VS1053_GM1_ACOUSTIC_BASS 33
#define VS1053_GM1_ELECTRIC_BASS_FINGER 34
#define VS1053_GM1_ELECTRIC_BASS_PICK 35
#define VS1053_GM1_FRETLESS_BASS 36
#define VS1053_GM1_SLAP_BASS_1 37
#define VS1053_GM1_SLAP_BASS_2 38
#define VS1053_GM1_SYNTH_BASS_1 39
#define VS1053_GM1_SYNTH_BASS_2 40
#define VS1053_GM1_VIOLIN 41
#define VS1053_GM1_VIOLA 42
#define VS1053_GM1_CELLO 43
#define VS1053_GM1_CONTRABASS 44
#define VS1053_GM1_TREMELO_STRINGS 45
#define VS1053_GM1_PIZZICATO_STRINGS 46
#define VS1053_GM1_OCHESTRAL_HARP 47
#define VS1053_GM1_TIMPANI 48
#define VS1053_GM1_STRING_ENSEMBLE_1 49
#define VS1053_GM1_STRING_ENSEMBLE_2 50
#define VS1053_GM1_SYNTH_STRINGS_1 51
#define VS1053_GM1_SYNTH_STRINGS_2 52
#define VS1053_GM1_CHOIR_AAHS 53
#define VS1053_GM1_CHOIR_OOHS 54
#define VS1053_GM1_SYNTH_VOICE 55
#define VS1053_GM1_ORCHESTRA_HIT 56
#define VS1053_GM1_TRUMPET 57
#define VS1053_GM1_TROMBONE 58
#define VS1053_GM1_TUBA 59
#define VS1053_GM1_MUTED_TRUMPET 60
#define VS1053_GM1_FRENCH_HORN 61
#define VS1053_GM1_BRASS_SECTION 62
#define VS1053_GM1_SYNTH_BRASS_1 63
#define VS1053_GM1_SYNTH_BRASS_2 64
#define VS1053_GM1_SOPRANO_SAX 65
#define VS1053_GM1_ALTO_SAX 66
#define VS1053_GM1_TENOR_SAX 67
#define VS1053_GM1_BARITONE_SAX 68
#define VS1053_GM1_OBOE 69
#define VS1053_GM1_ENGLISH_HORN 70
#define VS1053_GM1_BASSOON 71
#define VS1053_GM1_CLARINET 72
#define VS1053_GM1_PICCOLO 73
#define VS1053_GM1_FLUTE 74
#define VS1053_GM1_RECORDER 75
#define VS1053_GM1_PAN_FLUTE 76
#define VS1053_GM1_BLOWN_BOTTLE 77
#define VS1053_GM1_SHAKUHACHI 78
#define VS1053_GM1_WHISTLE 79
#define VS1053_GM1_OCARINA 80
#define VS1053_GM1_LEAD_1_SQUARE 81
#define VS1053_GM1_LEAD_2_SAWTOOTH 82
#define VS1053_GM1_LEAD_3_CALLIOPE 83
#define VS1053_GM1_LEAD_4_CHIFF 84
#define VS1053_GM1_LEAD_5_CHARGING 85
#define VS1053_GM1_LEAD_6_VOICE 86
#define VS1053_GM1_LEAD_7_FIFTHS 87
#define VS1053_GM1_LEAD_8_BASS_LEAD 88
#define VS1053_GM1_PAD_1_NEW_AGE 89
#define VS1053_GM1_PAD_2_WARM 90
#define VS1053_GM1_PAD_3_POLYSYNTH 91
#define VS1053_GM1_PAD_4_CHOIR 92
#define VS1053_GM1_PAD_5_BOWED 93
#define VS1053_GM1_PAD_6_METALLIC 94
#define VS1053_GM1_PAD_7_HALO 95
#define VS1053_GM1_PAD_8_SWEEP 96
#define VS1053_GM1_FX_1_RAIN 97
#define VS1053_GM1_FX_2_SOUNDTRACK 98
#define VS1053_GM1_FX_3_CRYSTAL 99
#define VS1053_GM1_FX_4_ATMOSPHERE 100
#define VS1053_GM1_FX_5_BRIGHTNESS 101
#define VS1053_GM1_FX_6_GOBLINS 102
#define VS1053_GM1_FX_7_ECHOS 103
#define VS1053_GM1_FX_8_SCIFI 104
#define VS1053_GM1_SITAR 105
#define VS1053_GM1_BANJO 106
#define VS1053_GM1_SHAMISEN 107
#define VS1053_GM1_KOTO 108
#define VS1053_GM1_KALIMBA 109
#define VS1053_GM1_BAGPIPE 110
#define VS1053_GM1_FIDDLE 111
#define VS1053_GM1_SHANAI 112
#define VS1053_GM1_TINKLE_BELL 113
#define VS1053_GM1_AGOGO 114
#define VS1053_GM1_STEEL_DRUMS 115
#define VS1053_GM1_WOODBLOCK 116
#define VS1053_GM1_TAIKO_DRUM 117
#define VS1053_GM1_MELODIC_TOM 118
#define VS1053_GM1_SYNTH_DRUM 119
#define VS1053_GM1_REVERSE_CYMBAL 120
#define VS1053_GM1_GUITAR_FRET_NOISE 121
#define VS1053_GM1_BREATH_NOISE 122
#define VS1053_GM1_SEASHORE 123
#define VS1053_GM1_BIRD_TWEET 124
#define VS1053_GM1_TELEPHONE_RING 125
#define VS1053_GM1_HELICOPTER 126
#define VS1053_GM1_APPLAUSE 127
#define VS1053_GM1_GUNSHOT 128
