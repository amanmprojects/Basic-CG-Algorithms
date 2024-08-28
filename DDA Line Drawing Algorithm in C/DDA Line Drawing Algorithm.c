#include <stdio.h>
#include <math.h>

int main(void){
    int x1, x2, y1, y2;
    
    // Setting the coordinates at compilation
    // Starting Co-ordinates
    x1 = 1;
    y1 = 1;
    // Ending Co-ordinates
    x2 = 5;
    y2 = 7;
    
    int dy = y2-y1;
    int dx = x2-x1;
    
    // Slope
    float m = (float)dy/dx;
    
    // Next x,y co-rdinates
    float xk = x1, yk = y1;
    
    // Rounded co-ordinates
    int xk_round = (int)(x1+0.5), yk_round = (int)(y1+0.5);
    
    printf("The pixels are: ");
    printf("\n(%d, %d)", xk_round, yk_round);
    
    // Main loop for finding intermediate pixels
    do{
        if(m == 1){
            xk += 1.0;
            yk += 1.0;
        }
        else if(m < 1){
            xk += 1.0;
            yk += m;
        }
        else if(m > 1){
            yk += 1.0;
            xk += (1/m);
        }
        
        // Rounding Manually Because round() function from math.h is giving undefined error
        xk_round = (int)(xk + 0.5);  
        yk_round = (int)(yk + 0.5);  

        // xk_round = round(xk);
        // yk_round = round(yk);
        
        printf("\n(%d, %d)", xk_round, yk_round);
        
        // Debugging
        // printf("\nNon approx : %f %f", xk, yk);
        // printf("\nEquality x : %d, Equality y : %d", (xk_round == x2),(yk_round == y2));
    } while(!(x2 == xk_round && y2 == yk_round));
    
    return 0;
    
}