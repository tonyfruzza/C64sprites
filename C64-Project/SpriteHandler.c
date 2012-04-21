//
//  SpriteHandler.c
//  C64-Project
//

#include "SpriteHandler.h"
#include "stdio.h"

void initSpriteHandler(SpriteHandler *sh, u_int8_t SpriteNumber){
    sh->id              = SpriteNumber;
    printf("Initializing sprite %d\n", SpriteNumber);
    sh->dataLocation   = 2040 + SpriteNumber;
    sh->x              = VMEM + (2 * SpriteNumber); // Byte x possition, set MSB to go more than 255
    sh->y              = VMEM + (2 * SpriteNumber) + 1; // Byte y possition
    sh->msb_forBigX    = VMEM + 16; // Most Significant Bit flag
    sh->on             = VMEM + 21; // Bit to turn sprite on/off
    sh->doubleH        = VMEM + 23; // Bit to double height
    sh->doubleW        = VMEM + 28; // Bit to double width
    sh->multiColorOn   = VMEM + 28; // Bit to toggle multi color mode
    sh->priorityBehind = VMEM + 27; // Bit to toggle background prioity
    sh->multiColor1    = VMEM + 37; // Byte color 1 for all colored (shared)
    sh->multiColor2    = VMEM + 38; // Byte color 2 for all colored (shared)
    sh->color          = VMEM + (39 + SpriteNumber); // Byte color for this sprite
    
    // Init values
    *sh->on             |= (1 << SpriteNumber); // Turn this spite on
    *sh->x              = 0; // hidden
    *sh->y              = 0; // hidden
    *sh->color          = 0; // black
    // Init Methods
    sh->setMemAddy      = setSpriteMemAddy;
    sh->MoveTo          = spriteMoveTo;
    sh->setSolidColor   = setSpriteSolidColor;
    sh->setMultiColorOn = setSpriteMultiColorOn;
    sh->setSharedMultiColors = setSpriteSharedMultiColors;
}

void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation){
    printf("Setting sprite address to %x\n", spriteMemoryLocation);
    *sh->dataLocation   = spriteMemoryLocation/64; // Set value
    sh->dataPtr         = (u_int8_t *)spriteMemoryLocation; // Set address
}

void spriteOn(SpriteHandler *sh, u_int8_t on){
    if(on){
        *sh->on        |= (1 << sh->id);
    }else{
        // Turn off sprite
        *sh->on        &= ~(1 << sh->id);
    }
}

void spriteMoveTo(SpriteHandler *sh, u_int16_t newx, u_int8_t newy){
    if(newx>255){
        // Set MSB for right x
        *sh->msb_forBigX |= (1 << sh->id);
        *sh->x            = newx-255;
    }else{
        *sh->msb_forBigX &= ~(1 << sh->id);
        *sh->x            = newx;
    }

    *sh->y                = newy;
}

void setSpriteSolidColor(SpriteHandler *sh, u_int8_t color){
    // Whole sprite color colors 0-15
    *sh->color            = color;
}

void setSpriteMultiColorOn(SpriteHandler *sh, u_int8_t on){
    if(on){
        *sh->multiColorOn|= (1 << sh->id);
    }else{
        *sh->multiColorOn&= ~(1 << sh->id);
    }
}

void setSpriteSharedMultiColors(SpriteHandler *sh, u_int8_t color1, u_int8_t color2){
    *sh->multiColor1    = color1;
    *sh->multiColor2    = color2;
}