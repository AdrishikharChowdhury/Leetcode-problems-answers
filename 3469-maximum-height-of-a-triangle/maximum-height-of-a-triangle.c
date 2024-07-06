#include <stdbool.h>

int calculateHeight(int color1, int color2) {
    int height = 0;
    int currentRowBalls = 1;
    bool useColor1 = true;
    
    while (true) {
        if (useColor1) {
            if (color1 >= currentRowBalls) {
                color1 -= currentRowBalls;
                height++;
                currentRowBalls++;
                useColor1 = false;
            } else {
                break;
            }
        } else {
            if (color2 >= currentRowBalls) {
                color2 -= currentRowBalls;
                height++;
                currentRowBalls++;
                useColor1 = true;
            } else {
                break;
            }
        }
    }
    
    return height;
}

int maxHeightOfTriangle(int red, int blue) {
    int height1 = calculateHeight(red, blue);
    int height2 = calculateHeight(blue, red);
    return (height1 > height2) ? height1 : height2;
}