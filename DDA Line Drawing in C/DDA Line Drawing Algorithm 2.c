#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void dda(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = (dx > dy) ? dx : dy;

    float xInc = (float) (x2 - x1) / steps;
    float yInc = (float) (y2 - y1) / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        printf("(%d, %d)\n", (int) x, (int) y);
        x += xInc;
        y += yInc;
    }
}

int main() {
    int x1 = 0, y1 = 0, x2 = 12, y2 = 20;
    dda(x1, y1, x2, y2);
    return 0;
}
