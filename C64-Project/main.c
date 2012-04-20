//
// This for testing of a C64 Sprite lib compileable with cc65
// The Makefile needs work.
//

#include "stdio.h"
#include "stdlib.h"
#include "SpriteHandler.h"


#define BORDER          0xD020
#define SPRITE0_ADDY    0x3000
#define POKE(addr,val)  (*(unsigned char*) (addr) = (val))

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

int main(void){
    
    u_int16_t i;
    u_int8_t *c, y;
    SpriteHandler sh0;
    sh0.initSpriteHandler = initSpriteHandler;
    sh0.initSpriteHandler(&sh0, 0);
    sh0.setSpriteMemAddy(&sh0, SPRITE0_ADDY);
    for(i=0;i<63;++i){
        sh0.dataPtr[i] = butterfly[i];
    }
    
    c = 0x00C5; // Last key pressed
    while(1){
        for(y=0;y<256;++y){
            *sh0.y = y;
        }
    }
/*
    while(1){
        curKey = *c;
        if(lastKey == curKey){
            continue;
        }
        switch (curKey) {
            case 0x02:
                // Left
                --*sh0.x;
                break;
            case 0x07:
                // up
                --*sh0.y;
            case 0x3e:
                // 'Q' exit
                printf("Exiting\n");
                return(0);
            default:
                printf("KEY %x\n", curKey);
        }
        lastKey = curKey;
    }
 */
    return 0;
}


