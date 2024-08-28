#include <stdio.h>


void main(void)
{
    int x1 = 0, y1 = 0;
    int x2 = 12, y2 = 7;
    
    
    int dx = x2-x1;
    int dy = y2-y1;
    
    int d = 2*dy - dx;
    
    
    int x = x1, y = y1;
    
    printf("Starting Pixel: (%d, %d)\n", x, y);
    printf("Intermediate Pixels : \n");
    printf("(%d, %d)\n", x,y);
    while(x != x2 || y != y2)
    {
        if(d < 0)
        {
            x = x+1;
            d = d + 2 * dy;
        }
        else{
            x = x+1;
            y = y+1;
            d = d + 2 * (dy - dx);
        }
        printf("(%d, %d)\n", x,y);
    }
    printf("Ending Pixel: (%d, %d)", x2,y);
}