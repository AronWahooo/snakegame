#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int height=20,width=20,x,y,xf,yf,k,m1,end,i,j;
void setup() {
    x = height / 2;
    y = width / 2;

    while (1) {
        switch (rand() % 2) {
            case 0:
                xf = rand() % height;
                if (xf != 0)
                    break;
            case 1:
                yf = rand() % width;
                if (yf != 0)
                    break;
        }
        break;
    }
}

void draw() {
    system("cls"); 

    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if ((i == 0 || i == height) && (j == 0 || j == width))
                printf("+");
            else if (i == 0 || i == height)
                printf("-");
            else if (j == 0 || j == width)
                printf("|");
            else {
                if (i == x && j == y)
                    printf("O");
                else if (i == xf && j == yf)
                    printf("#");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    if (x == height || y == width || x == 0 || y == 0) {
        end = 2;
    }

    if (x == xf && y == yf) {
        do {
            switch (rand() % 2) {
                case 0:
                    xf = rand() % height;
                    if (xf != 0)
                        break;
                case 1:
                    yf = rand() % width;
                    if (yf != 0)
                        break;
            }
            break;
        } while (x == xf && y == yf);
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

