//
//  gfx.h
//  C64-Project
//

#ifndef C64_Project_gfx_h
#define C64_Project_gfx_h
#include "types.h"

#define BORDER_COLOR        0xD020
#define SCREEN_BG_COLOR     0xD021
#define VIDEO_ADDRESS       1024

void clearScreen();
void setBackGroundColor(u_int8_t color);
void setBoarderColor(u_int8_t color);


#endif
