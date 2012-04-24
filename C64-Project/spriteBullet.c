//
//  spriteBullet.c
//  C64-Project
//
#include "spriteBullet.h"

void initBullet(spriteBullet *sb, u_int8_t spriteNumber){
    u_int8_t i;
    sb->flags &= ~(BULLET_ACTIVE | BULLET_VISBLE);
    sb->sh.init = initSpriteHandler;
    sb->sh.init(&sb->sh, spriteNumber);
    sb->sh.setSolidColor(&sb->sh, COLOR_YELLOW);
    sb->sh.setMemAddy(&sb->sh, SPRITE2_ADDY); // Hard coding this? 
    // Init methods
    sb->doMovement  = bulletDoMovement;
    sb->fireFrom    = bulletFireFrom;
    sb->doHit       = bulletDoHit;

    // Copy in bullet sprite data, could probably be programically generated?
    for(i=63;i--;){
        sb->sh.dataPtr[i] = bullets[i];
    }
}

void bulletDoMovement(spriteBullet *sb){
    if(!(sb->flags |= BULLET_ACTIVE)){
        return;
    }
    // Move up.
    if(sb->flags && !((*sb->sh.y)-- > 56)){
        // It hit the top of the screen
        sb->flags &= ~ (BULLET_ACTIVE | BULLET_VISBLE);
    }
    sb->doHit(sb);
}

void bulletFireFrom(spriteBullet *sb, u_int16_t x, u_int8_t y){
    sb->flags |= (BULLET_ACTIVE | BULLET_VISBLE);
    sb->sh.MoveTo(&sb->sh, x, y);
}

void bulletDoHit(spriteBullet *sb){
    u_int8_t *spriteOnOffByte = (u_int8_t *) (VMEM + 21);
    u_int8_t hit = (sb->sh.getCollision(&sb->sh) & 0xFC); // Ignore collitions between 0 and 1 (ship/bullet)
    if(!(sb->flags & BULLET_ACTIVE)){
        return;
    }
    if(hit){
        // restart bullet
        sb->flags &= ~(BULLET_ACTIVE | BULLET_VISBLE);
        *spriteOnOffByte &= ~ (hit>128?0:hit); // do action to target
    }
 }