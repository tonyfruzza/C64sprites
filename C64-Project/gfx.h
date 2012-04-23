//
//  gfx.h
//  C64-Project
//

#ifndef C64_Project_gfx_h
#define C64_Project_gfx_h

typedef unsigned char u_int8_t;
typedef unsigned int u_int16_t;
#ifndef TRUE
#define TRUE 0x01
#endif
#ifndef FALSE
#define FLASE 0x00
#endif

#define BORDER_COLOR        0xD020
#define SCREEN_BG_COLOR     0xD021
#define VIDEO_ADDRESS       1024

#define COLOR_BLACK         0
#define COLOR_WHITE         1
#define COLOR_RED           2
#define COLOR_CYAN          3
#define COLOR_MAGENTA       4
#define COLOR_GREEN         5
#define COLOR_BLUE          6
#define COLOR_YELLOW        7
#define COLOR_ORANGE        8
#define COLOR_BROWN         9
#define COLOR_PINK          10
#define COLOR_DARK_GREY     11
#define COLOR_GREY          12
#define COLOR_LIGHT_GREEN   13
#define COLOR_LIGHT_BLUE    14
#define COLOR_LIGHT_GREY    15

void clearScreen();
void setBackGroundColor(u_int8_t color);
void setBoarderColor(u_int8_t color);


#endif
