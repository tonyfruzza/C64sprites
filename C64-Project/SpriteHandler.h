//
//  SpriteHandler.h
//  C64-Project
//
//  Created by Tony Fruzza on 4/19/12.
//  Copyright (c) 2012 Lightspeed Systems. All rights reserved.
//

#ifndef C64_Project_SpriteHandler_h
#define C64_Project_SpriteHandler_h

#define VMEM	0xD000


typedef struct _SpriteHandler {
    unsigned char id;
    unsigned char *on, *doubleH, *doubleW, *color, *dataLocation, *dataPtr, *x, *y;
    void (*initSpriteHandler)(struct _SpriteHandler *self, unsigned char SpriteNumber);
    void (*setSpriteMemAddy)(struct _SpriteHandler *self, unsigned int spriteMemoryLocation);
    void (*spriteMoveTo)(struct _SpriteHandler *self, unsigned int newx, unsigned char newy);
} SpriteHandler;

void initSpriteHandler(SpriteHandler *sh, unsigned char SpriteNumber);
void setSpriteMemAddy(SpriteHandler *sh, unsigned int spriteMemoryLocation);
void spriteOn(SpriteHandler *sh, unsigned char on);
void spriteMoveTo(SpriteHandler *sh, unsigned int newx, unsigned char newy);

#endif
