#include<stdio.h>
#include<conio.h>
#include <Windows.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
	int height=25;
	int width=80;
	int gameover=0;
typedef struct
{
 int type,life;
}object;
typedef struct
{
 int status;  //status=0 null , status=1 something present
 object obj;
}coordinate;

	enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
	enum eDirection dir;
void drawinit();
void main()
{
	coordinate globalco[width][height];
    Draw();
    drawinit(&globalco,width,height);
		/*while(!gameover){
			Draw();
			Input();
			Logic();
			Sleep(10);
		}
		if(score==300) printf("Congrats You won");                  //score not implemented.....yet
		else printf("Too bad.... try again");
		*/

	}
void Draw(){
		int i,j;
		system("cls");
		for (i=1;i<=width;i++)
		{
			if(i==1) printf("%c",201);
			else if(i==(width)) printf("%c",187);           //prints top border
			else printf("%c",205);
		}

		printf("\n");
		for(j=1;j<=height-2;j++){
			for(i=1;i<=width;i++){
				if(i==1 || i==width)
                    printf("%c",186);        //prints side border, pacman(C), "dot(.)",,,
                else
                    printf(" ");
            }
			printf("\n");
		}

		for (i=1;i<=width;i++)
		{
			if(i==1) printf("%c",200);
			else if(i==width) printf("%c",188);           //lower border
			else printf("%c",205);
		}
    /*for(i=0;i<5;i++)                //Splash screen
     {  gotoxy(30,10);
        printf("GET READY!!!");
        Sleep(500);
        gotoxy(30,10);
        printf("            ");
        Sleep(500); }
    */
    gotoxy(0,0);
    getch();
	}
void drawinit(coordinate *globalco,int width,int height)
{int x,y;

    for (y=2;y<=height-1;y++)
    {
        for (x=2;x<=width-2;x++)
            { globalco[x][y] = malloc(sizeof(coordinate));
                if (*globalco[x][y]->status !=0 )
                {
                    gotoxy(x,y);
                printf("%d",x);
                }
            }
    }
}
/*

	void Draw(){
		int i,j;
		system("cls");
		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",201);
			else if(i==width-1) printf("%c",187);           //prints top border
			else printf("%c",205);
		}

		printf("\n");
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(j==0 || j==width-1) printf("%c",186);        //prints side border, pacman(C), "dot(.)",,,
                                                                //add ghosts too
				else if(j==x && i==y) printf("C");

				else printf(".");

			}
			printf("\n");
		}

		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",200);
			else if(i==width-1) printf("%c",188);           //lower border
			else printf("%c",205);
		}

	}

	void Input(){
		if(_kbhit()){
			switch(_getch()){                           //if user presses stuff then only getch() activates and hence takes input
				case 'a':
					dir=LEFT;
					break;

				case 'd':
					dir=RIGHT;
					break;

				case 'w':
					dir=UP;
					break;


				case 's':
					dir=DOWN;
					break;

				case 'x':
					gameover=true;
					break;
			}
		}
	}

	void Logic(){

			switch(dir){                            //pacman's co-ordinate changes when corresponding key is pressed
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
			}
		if(x>width) x=width-2;
		if(y>height) y=height-1;
		if(x<0) x=1;
		if(y<0)y=0;
	}
*/
