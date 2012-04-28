//
//  SidHandler.c
//  C64-Project
//

#include "SidHandler.h"

void initSidHandler(SidHandler *self){
    u_int8_t i;
    self->sid_addr      = (u_int8_t *) SID_ADDRESS_BASE;
    self->volume_addr   = (u_int8_t *) SID_ADDRESS_BASE + 24;
    // init all of the SID registers to 0
    for(i=0;i<24;i++){
        self->sid_addr[i] = 0x00;
    }
    // Map method names
    self->setVolume     = setSidVolume;
    self->setInstrument = setSidInstrument;
    self->playSingleNote= playSidSingleNote;
    self->stop          = stopSidPlay;
}

void setSidVolume(SidHandler *self, u_int8_t level){
    *self->volume_addr = level;
}

void setSidInstrument(SidHandler *self, sid_instrument_t type){
    switch (type) {
        case SID_INSTRUMENT_PIANO:
            self->sid_addr[2]   = 0xff;
            self->sid_addr[3]   = 0x00;
            self->sid_addr[4]   = 0x41;
            self->sid_addr[5]   = 0x09; // wave form
            self->sid_addr[6]   = 0x00; // attack/decay ?
            self->currentInstrument = SID_INSTRUMENT_PIANO;
            break;
    }
}

void playSidSingleNote(SidHandler *self, u_int8_t note){
    // Turn instrument back on
    self->stop(self);
    switch (self->currentInstrument) {
        case SID_INSTRUMENT_PIANO:
            self->sid_addr[4] = 0x41;
            break;
    }
    
    self->sid_addr[1] = note;
    self->sid_addr[0] = note;
}

void stopSidPlay(SidHandler *self){
    switch (self->currentInstrument) {
        case SID_INSTRUMENT_PIANO:
            self->sid_addr[4] = 0x40;
            break;
    }
}
