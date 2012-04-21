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
#define COLOR_BLACK     0
#define COLOR_WHITE     1
#define COLOR_RED       2
#define COLOR_CYAN      3
#define COLOR_MAGENTA   4
#define COLOR_GREEN     5
#define COLOR_BLUE      6
#define COLOR_YELLOW    7
#define COLOR_ORANGE    8
#define COLOR_BROWN     9
#define COLOR_PINK      10
#define COLOR_DARK_GREY 11
#define COLOR_GREY      12
#define COLOR_LIGHT_GREEN   13
#define COLOR_LIGHT_BLUE    14
#define COLOR_LIGHT_GREY    15

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
    void (*setSolidColor)(struct _SpriteHandler *self, u_int8_t color);
    void (*setMultiColorOn)(struct _SpriteHandler *self, u_int8_t on);
    void (*setSharedMultiColors)(struct _SpriteHandler *self, u_int8_t color1, u_int8_t color2);
} SpriteHandler;

void initSpriteHandler(SpriteHandler *sh, u_int8_t SpriteNumber);
void setSpriteMemAddy(SpriteHandler *sh, u_int16_t spriteMemoryLocation);
void spriteOn(SpriteHandler *sh, u_int8_t on);
void spriteMoveTo(SpriteHandler *sh, u_int16_t newx, u_int8_t newy);
void setSpriteSolidColor(SpriteHandler *sh, u_int8_t color);
void setSpriteMultiColorOn(SpriteHandler *sh, u_int8_t on);
void setSpriteSharedMultiColors(SpriteHandler *sh, u_int8_t color1, u_int8_t color2);

#endif
