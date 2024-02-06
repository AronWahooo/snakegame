#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=20,width=20,x,y,xf,yf,k,m1,end,i,j;
void setup()
{
	x=height/2;
	y=width/2;
		label1:
		xf=rand()%height;
		if(xf == 0)
		goto label1;
		label2:
		yf=rand()%width;
		if(yf == 0) 
		goto label2;
}
void draw()
{
	system("cls");
	for(i=0;i<=height;i++)
	{
		for(j=0;j<=width;j++)
	 		{
	 			if (i==height && j==0)
					{
						printf("|");
					}
				else if (i==height && j==width)
					{
						printf("|");
					}
	 			else if(i==0 || i==height)
	 				{
	 					printf("_");
					}
				else if(j==0 || j==width)
					{
						printf("|");
					}
				else 
					{
						if(i==x && j==y)
						{
							printf("O");
						}
						else if (i==xf && j==yf)
						{
							printf("#");
						}
						else
						printf(" ");
					}
	 		}
	 		printf("\n");
	}
	if(x==height || y==width || x==0 || y==0)
	{
		end = 2;
	}
	if(x==xf && y == yf)
		{
		label3:
		xf=rand()%height;
		if(xf == 0)
		goto label3;
		label4:
		yf=rand()%width;
		if(yf == 0) 
		goto label4;	
		}
}

void move()
{
	if(kbhit())
	
		switch(getch())
	{
		case 'a':
			y=y-1;
		break;
		case 'w':
			x=x-1;
		break;
		case 'd':
			y++;
		break;
		case 's':
			x++;
		break;
	}
}
int main()
{
	setup();
	draw();
	while(end!=2)
	{
		move();
		draw();
	}
}

