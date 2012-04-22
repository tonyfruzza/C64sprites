//
// This for testing of a C64 Sprite lib compileable with cc65
// The Makefile needs work.
//

#include "stdio.h"
#include "stdlib.h"
#include "SpriteHandler.h"

#define SPRITE0_ADDY    0x3000

static const char butterfly[63] = { 
    2,0,64,49,0,140,
    120,129,30,252,66,63,
    254,36,127,255,24,255,
    255,153,255,255,219,255,
    255,255,255,255,255,255,
    255,255,255,255,255,255,
    255,255,255,255,255,255,
    255,255,255,255,255,255,
    255,219,255,127,153,254,
    63,24,252,30,24,120,
    12,24,48
};

static const char preComputedPathX[63] = {
    228, 228, 226, 224, 221, 217, 212, 207, 201, 194, 187, 179, 171, 163, 154, 145, 136, 128, 119, 110, 102, 94, 87, 80, 73, 68, 63, 59, 55, 53, 51, 50, 50, 51, 53, 56, 59, 64, 69, 74, 81, 88, 95, 103, 112, 120, 129, 138, 147, 156, 164, 173, 181, 188, 195, 202, 208, 213, 218, 222, 224, 227, 228
};

static const char preComputedPathY[63] = {
    139, 148, 157, 165, 174, 182, 189, 196, 203, 209, 214, 218, 222, 225, 227, 228, 228, 227, 226, 223, 220, 216, 211, 205, 199, 192, 185, 177, 169, 160, 152, 143, 134, 125, 116, 108, 100, 92, 85, 78, 72, 66, 61, 57, 54, 52, 51, 50, 50, 52, 54, 57, 60, 65, 70, 76, 83, 90, 98, 106, 114, 123, 132
};

int main(void){
    char xMovements;
    u_int8_t y, count;
    SpriteHandler sh[8];
    for(count=0;count<8;++count){
        sh[count].init = initSpriteHandler;
        sh[count].init(&sh[count], count);
        sh[count].setMemAddy(&sh[count], SPRITE0_ADDY);
        sh[count].setSolidColor(&sh[count], count);
    }
    
    for(count=0;count<63;++count){
        // They're all pointing at the same mem addy
        sh[0].dataPtr[count] = butterfly[count];
    }
    setBackGroundColor(COLOR_GREY);
    setBoarderColor(COLOR_GREY);
    clearScreen();
    xMovements = 0;
    while(1){
        if(xMovements<100){
            xMovements+=2;
        }
        for(y=63;--y;){
            for(count=0;count<8;++count){
                sh[count].MoveTo(&sh[count], preComputedPathX[(y + (count*8))%63] + xMovements, preComputedPathY[(y + (count*8))%63]);
            }
        }
    }
    return 0;
}


