//
//  spriteBullet.h
//  C64-Project
//

#ifndef C64_Project_spriteBullet_h
#define C64_Project_spriteBullet_h

#include "SpriteHandler.c"
#include "spriteData.h"

#define BULLET_VISBLE 0x01
#define BULLET_ACTIVE 0x02
//#define COLLISION_IGNORE_LIST   0x03

typedef u_int8_t bulletFlag;

typedef struct _spriteBullet {
    SpriteHandler sh;
    bulletFlag flags;
    void (*init)(struct _spriteBullet *self, u_int8_t spriteNumber);
    void (*doMovement)(struct _spriteBullet *self);
    void (*fireFrom)(struct _spriteBullet *self, u_int16_t x, u_int8_t y);
    void (*doHit)(struct _spriteBullet *self);
    
} spriteBullet;

void initBullet(spriteBullet *sb, u_int8_t spriteNumber);
void bulletDoMovement(spriteBullet *sb);
void bulletFireFrom(spriteBullet *sb, u_int16_t x, u_int8_t y);
void bulletDoHit(spriteBullet *sb);

#endif