//
//  SpriteHandler.c
//  C64-Project
//
//  Created by Tony Fruzza on 4/19/12.
//  Copyright (c) 2012 Lightspeed Systems. All rights reserved.
//

#include "SpriteHandler.h"
#include "stdio.h"

void initSpriteHandler(SpriteHandler *sh, unsigned char SpriteNumber){
    sh->id              = SpriteNumber;
    printf("Initializing sprite %d\n", SpriteNumber);
    sh->on             = VMEM + 21;
    sh->doubleH        = VMEM + 23;
    sh->doubleW        = VMEM + 28;
    sh->color          = VMEM + (39 + SpriteNumber);
    sh->dataLocation   = 2040;
    sh->x              = VMEM + (1 * SpriteNumber);
    sh->y              = VMEM + (1 * SpriteNumber) + 1;
    
    // Init values
    //*sh->on             &= ~0x01; // Turn it off
    *sh->on             |= 0x01; // Turn it on
    *sh->x              = 200;
    *sh->y              = 200;
    *sh->color          = 0; // black
    sh->setSpriteMemAddy = setSpriteMemAddy;
    sh->spriteMoveTo    = spriteMoveTo;
    
}

void setSpriteMemAddy(SpriteHandler *sh, unsigned int spriteMemoryLocation){
    printf("Setting sprite address to %x\n", spriteMemoryLocation);
    *sh->dataLocation   = spriteMemoryLocation/64; // Set value
    sh->dataPtr         = spriteMemoryLocation; // Set address
}

void spriteOn(SpriteHandler *sh, unsigned char on){
    *sh->on              |= sh->id;
}

void spriteMoveTo(SpriteHandler *sh, unsigned int newx, unsigned char newy){
    *sh->x                = newx; // Do work to handle wrap around
    *sh->y                = newy;
}