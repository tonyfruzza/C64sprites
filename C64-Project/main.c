//
//  main.c
//  C64-Project
//
//  Created by Tony Fruzza on 4/16/12.
//  Copyright (c) 2012 Lightspeed Systems. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
#include "c64.h"
#include "conio.h"
#include "stdbool.h"
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
    int i;
    unsigned char c;
    SpriteHandler sh0;
    sh0.initSpriteHandler = initSpriteHandler;
    sh0.initSpriteHandler(&sh0, 0);
    sh0.setSpriteMemAddy(&sh0, SPRITE0_ADDY);
    for(i=0;i<63;++i){
        sh0.dataPtr[i] = butterfly[i];
    }
    while((c=getchar()) != EOF){
        switch (c) {
            case 0x4c:
            case 0x9d:
                // Left
                --*sh0.x;
                break;
            case 0x91:
                // up
                --*sh0.y;
            case 0xd1:
                // 'Q' exit
                printf("Exiting\n");
                return(0);
            default:
                printf("Key: %x\n", c);
        }
    }
    return 0;
}


