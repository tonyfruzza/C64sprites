//
//  SpriteHandler.c
//  C64-Project
//

#include "SpriteHandler.h"
#include "stdio.h"

void initSpriteHandler(SpriteHandler *sh, unsigned char SpriteNumber){
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
    *sh->x              = 200;
    *sh->y              = 200;
    *sh->color          = 0; // black
    // Init Methods
    sh->setMemAddy      = setSpriteMemAddy;
    sh->MoveTo          = spriteMoveTo;
    sh->setSolidColor   = setSpriteSolidColor;
}

void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation){
    printf("Setting sprite address to %x\n", spriteMemoryLocation);
    *sh->dataLocation   = spriteMemoryLocation/64; // Set value
    sh->dataPtr         = spriteMemoryLocation; // Set address
}

void spriteOn(SpriteHandler *sh, unsigned char on){
    if(on){
        *sh->on        |= (1 << sh->id);
    }else{
        // Turn off sprite
        *sh->on        &= ~(1 << sh->id);
    }
}

void spriteMoveTo(SpriteHandler *sh, unsigned int newx, unsigned char newy){
    *sh->x                = newx; // Do work to handle wrap around
    *sh->y                = newy;
}

void setSpriteSolidColor(SpriteHandler *sh, u_int8_t color){
    // Whole sprite color colors 0-15
    *sh->color            = color;
}