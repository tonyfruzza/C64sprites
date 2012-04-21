//
//  SpriteHandler.h
//  C64-Project
//
/* Sprites are 24x21 with the option to double the size V or H
 * 1 individual color, or a shared set of 2 colors
 */

#ifndef C64_Project_SpriteHandler_h
#define C64_Project_SpriteHandler_h

#define VMEM	0xD000
typedef unsigned char u_int8_t;
typedef unsigned int u_int16_t;


typedef struct _SpriteHandler {
    u_int8_t id;
    u_int8_t *on, *doubleH, *doubleW, *color, *dataLocation, *dataPtr, *x, *y, *msb_forBigX,
    *multiColorOn, *priorityBehind, *multiColor1, *multiColor2;
    void (*init)(struct _SpriteHandler *self, u_int8_t SpriteNumber);
    void (*setMemAddy)(struct _SpriteHandler *self, u_int16_t spriteMemoryLocation);
    void (*MoveTo)(struct _SpriteHandler *self, unsigned int newx, u_int8_t newy);
    void (*setOn)(struct _SpriteHandler *self, u_int8_t on);
    void (*setSolidColor)(struct _SpriteHandler *self, u_int8_t);
} SpriteHandler;

void initSpriteHandler(SpriteHandler *sh, u_int8_t SpriteNumber);
void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation);
void spriteOn(SpriteHandler *sh, u_int8_t on);
void spriteMoveTo(SpriteHandler *sh, u_int16_t newx, u_int8_t newy);
void setSpriteSolidColor(SpriteHandler *sh, u_int8_t);

#endif
