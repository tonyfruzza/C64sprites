//
//  SpriteHandler.h
//  C64-Project
//
/* Sprites are 24x21 with the option to double the size V or H
 * 1 individual color, or a shared set of 2 colors
 */

#ifndef C64_Project_SpriteHandler_h
#define C64_Project_SpriteHandler_h
#include "gfx.h"
#define VMEM                0xD000

typedef struct _SpriteHandler {
    u_int8_t id;
    u_int8_t *on, *doubleH, *doubleW, *color, *dataLocation, *dataPtr, *x, *y, *msb_forBigX,
    *multiColorOn, *priorityBehind, *multiColor1, *multiColor2, *collision, *collisionBack;
    void (*init)(struct _SpriteHandler *self, u_int8_t SpriteNumber);
    void (*setMemAddy)(struct _SpriteHandler *self, u_int16_t spriteMemoryLocation);
    void (*MoveTo)(struct _SpriteHandler *self, u_int16_t newx, u_int8_t newy);
    void (*setOn)(struct _SpriteHandler *self, u_int8_t on);
    void (*setSolidColor)(struct _SpriteHandler *self, u_int8_t color);
    void (*setMultiColorOn)(struct _SpriteHandler *self, u_int8_t on);
    void (*setSharedMultiColors)(struct _SpriteHandler *self, u_int8_t color1, u_int8_t color2);
    void (*setDoubleWidthHeight)(struct _SpriteHandler *self, u_int8_t xOn, u_int8_t yOn);
    u_int8_t (*getCollision)(struct _SpriteHandler *self);
} SpriteHandler;

void initSpriteHandler(SpriteHandler *sh, u_int8_t SpriteNumber);
void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation);
void setSpriteOn(SpriteHandler *sh, u_int8_t on);
void spriteMoveTo(SpriteHandler *sh, u_int16_t newx, u_int8_t newy);
void setSpriteSolidColor(SpriteHandler *sh, u_int8_t color);
void setSpriteMultiColorOn(SpriteHandler *sh, u_int8_t on);
void setSpriteSharedMultiColors(SpriteHandler *sh, u_int8_t color1, u_int8_t color2);
void setSpriteDoubleWidthHeight(SpriteHandler *sh, u_int8_t xOn, u_int8_t yOn);
u_int8_t getSpriteCollision(SpriteHandler *sh);

#endif
