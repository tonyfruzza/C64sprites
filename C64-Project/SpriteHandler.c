//
//  SpriteHandler.c
//  C64-Project
//

#include "SpriteHandler.h"
#include <stdio.h>

void initSpriteHandler(SpriteHandler *sh, u_int8_t SpriteNumber){
    sh->id              = SpriteNumber;
    sh->dataLocation    = (u_int8_t *) (2040 + SpriteNumber);
    sh->x               = (u_int8_t *) (VMEM + (2 * SpriteNumber)); // Byte x possition, set MSB to go more than 255
    sh->y               = (u_int8_t *) (VMEM + (2 * SpriteNumber) + 1); // Byte y possition
    sh->msb_forBigX     = (u_int8_t *) (VMEM + 16); // Most Significant Bit flag
    sh->on              = (u_int8_t *) (VMEM + 21); // Bit to turn sprite on/off
    sh->doubleH         = (u_int8_t *) (VMEM + 23); // Bit to double height
    sh->priorityBehind  = (u_int8_t *) (VMEM + 27); // Bit to toggle background prioity
    sh->multiColorOn    = (u_int8_t *) (VMEM + 28); // Bit to toggle multi color mode
    sh->doubleW         = (u_int8_t *) (VMEM + 29); // Bit to double width
    sh->collision       = (u_int8_t *) (VMEM + 30); // Bit to read if collision detected
    sh->collisionBack   = (u_int8_t *) (VMEM + 31); // Bit to read if collision with background is detected
    sh->multiColor1     = (u_int8_t *) (VMEM + 37); // Byte color 1 for all colored (shared)
    sh->multiColor2     = (u_int8_t *) (VMEM + 38); // Byte color 2 for all colored (shared)
    sh->color           = (u_int8_t *) (VMEM + (39 + SpriteNumber)); // Byte color for this sprite
    
    // Init values
    *sh->on            |= (1 << SpriteNumber); // Turn this spite on
    *sh->x              = 0; // hidden
    *sh->y              = 0; // hidden
    *sh->color          = 0; // black
    // Init Methods
    sh->setMemAddy      = setSpriteMemAddy;
    sh->MoveTo          = spriteMoveTo;
    sh->setSolidColor   = setSpriteSolidColor;
    sh->setMultiColorOn = setSpriteMultiColorOn;
    sh->getCollision    = getSpriteCollision;
    sh->setOn           = setSpriteOn;
    sh->setSharedMultiColors    = setSpriteSharedMultiColors;
    sh->setDoubleWidthHeight    = setSpriteDoubleWidthHeight;
}

void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation){
    *sh->dataLocation   = spriteMemoryLocation/64; // Set value
    sh->dataPtr         = (u_int8_t *)spriteMemoryLocation; // Set address
}

void setSpriteOn(SpriteHandler *sh, u_int8_t on){
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
    *sh->multiColor1        = color1;
    *sh->multiColor2        = color2;
}

u_int8_t getSpriteCollision(SpriteHandler *sh){
    return(*sh->collision ^ 1 << sh->id);
}

void setSpriteDoubleWidthHeight(SpriteHandler *sh, u_int8_t xOn, u_int8_t yOn){
    if(xOn){
        *sh->doubleW        |= (1 << sh->id);
    }else{
        *sh->doubleW        &= ~(1 << sh->id);
    }
    if(yOn){
        *sh->doubleH        |= (1 << sh->id);
    }else{
        *sh->doubleH        &= ~(1 << sh->id);
    }
}

