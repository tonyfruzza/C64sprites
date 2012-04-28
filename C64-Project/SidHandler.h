//
//  SidHandler.h
//  C64-Project
//  Supporting structure and memory locations For the Sound Interface Device
//  microprocesor which contains 3 voices
//

#ifndef C64_Project_SidHandler_h
#define C64_Project_SidHandler_h
#include "types.h"

// 54272
#define SID_ADDRESS_BASE            0xD400
#define SID_INSTRUMENT_PIANO        0x01
#define SID_INSTRUMENT_FLUTE        0x02
#define SID_INSTRUMENT_HARPSICHORD  0x04
#define SID_INSTRUMENT_XYLOPHONE    0x08
#define SID_INSTRUMENT_ACCORDIAN    0x10
#define SID_INSTRUMENT_TRUMPET      0x20
#define SID_INSTRUMENT_NOISE        0x40

typedef u_int8_t sid_instrument_t;

typedef struct _SidHandler{
    u_int8_t *sid_addr, *volume_addr, *note1, *note2, currentInstrument;
    void (*init)(struct _SidHandler *sidHand);
    void (*setVolume)(struct _SidHandler *sidHand, u_int8_t level);
    void (*setInstrument)(struct _SidHandler *sidHand, sid_instrument_t type);
    void (*playSingleNote)(struct _SidHandler *sidHand, u_int8_t note);
    void (*stop)(struct _SidHandler *sidHand);
} SidHandler;

void initSidHandler(SidHandler *sidHand);
void setSidVolume(SidHandler *sidHand, u_int8_t level);
void setSidInstrument(SidHandler *sidHand, sid_instrument_t type);
void playSidSingleNote(SidHandler *sidHand, u_int8_t note);
void stopSidPlay(SidHandler *sidHand);


#endif
