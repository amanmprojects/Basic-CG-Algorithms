#include <stdio.h>
#define MAX 10000



void plotPoint(int x, int y) {
    printf("(%d, %d)\n", x, y);
}


void midpointEllipseAlgorithm(int ry, int rx)
{
	int i, j;
	
	int xstack[MAX], ystack[MAX];
	int top = -1;
	
	
	void push(int x, int y)
	{
	        if(top != MAX - 1)
	        {
	            top++;
	            xstack[top] = x;
	            ystack[top] = y;
	        }
	}
	
	void display()
	{
	    for(i = 0; i <= top; i++)
	    {
	        plotPoint(xstack[i], ystack[i]);
	    }
	}
	
	
	// R1
	
	// Initial decision parameter
	float pk1 = (float) (ry * ry) + (rx * rx) / 4 - (ry * rx * rx); 
	
	//Starting pixel
	int x = 0, y = ry;
	
	push(x, y);
	while((2*x*ry*ry) < (2*y*rx*rx))
	{
	    //Incrementing x
	    x++;
	    
	    if(pk1 < 0)
	    {
	       pk1 = pk1 + 2*ry*ry*x + ry*ry;
	    }
	    else
	    {
	        y--;
	        pk1 = pk1 + ry*ry + 2*ry*ry*x - 2*rx*rx*y;
	    }
	    
	    push(x, y);
	}
	
	
	// R2
	//Initial decision parameter
	float pk2 = (float) ry*ry*(x+1/2)*(x+1/2) + rx*rx*(y-1)*(y-1) - rx*rx*ry*ry;
	
	while(y != 0)
	{
	    //Decrementing y
	    y--;
	    
	    if(pk2 >= 0)
	    {
	        pk2 = pk2 - 2*y*rx*rx + rx*rx;
	    }
	    else 
	    {
	        x++;
	        pk2 = pk2 + ry*ry*2*x - 2*y*rx*rx + rx*rx;
	    }
	    push(x,y);
	}
    
	
	

	
	// 4th quadrant i.e. Third and Fourth octants
	for(i = top; i >= 0; i--)
	{
	    push(xstack[i], -ystack[i]);
	}
	
	// 2nd and 3rd quadrant i.e. Fifth, Sixth, Seventh and Eight octants
	for(i = top; i >= 0; i--)
	{
	    push(-xstack[i], ystack[i]);
	}
	
	
	// Displaying the points / stack
	printf("Stack : \n");
	display();
}




void main()
{
	midpointEllipseAlgorithm(50,100);
}