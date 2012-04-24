//
// This for testing of a C64 Sprite lib compileable with cc65
// The Makefile needs work.
//

#include "stdio.h"
#include "stdlib.h"
#include "SpriteHandler.h"
#include "spriteData.h"
#include "spriteBullet.h"

static const char preComputedPathX[63] = {
    170, 170, 169, 167, 165, 163, 160, 156, 152, 147, 142, 137, 132, 126, 120, 114, 108, 102, 96, 91, 85, 80, 75, 70, 66, 62, 59, 56, 53, 52, 51, 50, 50, 51, 52, 54, 56, 59, 63, 66, 71, 76, 81, 86, 92, 97, 103, 109, 115, 121, 127, 133, 138, 143, 148, 153, 157, 160, 163, 166, 168, 169, 170
};

static const char preComputedPathY[63] = {
    110, 116, 122, 128, 133, 139, 144, 149, 153, 157, 160, 163, 166, 168, 169, 170, 170, 169, 168, 167, 165, 162, 159, 155, 151, 146, 141, 136, 130, 124, 118, 112, 106, 101, 95, 89, 83, 78, 73, 69, 65, 61, 58, 55, 53, 51, 50, 50, 50, 51, 52, 54, 57, 60, 64, 68, 72, 77, 82, 88, 93, 99, 105
};

static const char preShooterPathX[63] = {
    231, 230, 229, 226, 223, 218, 213, 207, 200, 192, 183, 174, 165, 155, 145, 135, 124, 114, 104, 94, 84, 75, 67, 59, 51, 45, 39, 34, 30, 27, 25, 24, 24, 25, 27, 31, 35, 40, 46, 52, 60, 68, 77, 86, 96, 106, 116, 126, 137, 147, 157, 167, 176, 185, 193, 201, 208, 214, 219, 223, 227, 229, 231
};

int main(void){
    u_int8_t y, count;
    SpriteHandler sh[8];
    spriteBullet sb;

    setBackGroundColor(COLOR_BLACK);
    setBoarderColor(COLOR_BLACK);
    clearScreen();

    for(count=0;count<8;++count){
        sh[count].init = initSpriteHandler;
        sh[count].init(&sh[count], count);
        sh[count].setMemAddy(&sh[count], SPRITE0_ADDY);
        sh[count].setSolidColor(&sh[count], count);
    }
    // Space ship setup
    sh[0].setSolidColor(&sh[0], COLOR_GREY);
    sh[0].setMemAddy(&sh[0], SPRITE1_ADDY);
    sh[0].setMultiColorOn(&sh[0], TRUE);
    sh[0].setSharedMultiColors(&sh[0], COLOR_RED, COLOR_PINK);
    
    // Load in sprite data
    for(count=0;count<63;++count){
        // They're all pointing at the same mem addy
        sh[0].dataPtr[count] = spaceShipMultiColor[count];
        sh[1].dataPtr[count] = butterfly[count];
    }
    // Bullet setup
    sb.init = initBullet;
    sb.init(&sb, 1); // Use sprite 2, our ship is 1
    
    while(1){
        for(y=63;--y;){
            for(count=2;count<8;++count){
                sh[count].MoveTo(&sh[count], preComputedPathX[(y + (count*10))%63], preComputedPathY[(y + (count*10))%63]);
                if(!(sb.flags & BULLET_ACTIVE)){
                    sb.fireFrom(&sb, *sh[0].x, *sh[0].y);
                }
                // Move bullet
                sb.doMovement(&sb);
                // Move ship
                sh[0].MoveTo(&sh[0], preShooterPathX[y], 228);
                // Move butter flies
            }
        }
        // see if they are all killed
        if(!(sh[2].getIsActive(&sh[2]) || 
             sh[3].getIsActive(&sh[3]) || 
             sh[4].getIsActive(&sh[4]) || 
             sh[5].getIsActive(&sh[5]) || 
             sh[6].getIsActive(&sh[6]) || 
             sh[7].getIsActive(&sh[7])
             )){
            printf("GAME OVER");
            return(0);
        }
    }
    return 0;
}


