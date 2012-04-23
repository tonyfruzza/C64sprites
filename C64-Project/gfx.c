//
//  gfx.c
//  C64-Project
//

#include "gfx.h"

void clearScreen(){
    // Prints spaces all over teh screen
    unsigned char x, y, *va;
    va = (u_int8_t *) VIDEO_ADDRESS;
    for(y=25;y--;){
        for(x=40;x--;){
            va[(y*40)+x] = 96;
        }
    }
}

void setBackGroundColor(u_int8_t color){
    u_int8_t *bg;
    bg = (u_int8_t *) SCREEN_BG_COLOR;
    *bg = color;
}

void setBoarderColor(u_int8_t color){
    u_int8_t *bc;
    bc = (u_int8_t *) BORDER_COLOR;
    *bc = color;
}
