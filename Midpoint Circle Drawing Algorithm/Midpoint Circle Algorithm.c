#include <stdio.h>
#define MAX 100



void plotPoint(int x, int y) {
    printf("(%d, %d)\n", x, y);
}


void midpointCircleAlgorithm(int r)
{
	int x = 0;
	int y = r;
	int pk = (1 - r);
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
	

    // First octant
	do
	{
		push(x,y);

		if(pk < 0)
		{
			pk += 2 * x + 3;
		}
		else
		{
			pk += (2*x - 2*y + 5);
			y--;
		}
		x++;
	} while(x <= y);
	
	

	// Second octant
	for(i = top; i >= 0; i--)
	{
	    push(ystack[i], xstack[i]);
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
	midpointCircleAlgorithm(10);
}
