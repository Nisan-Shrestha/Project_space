#include<stdio.h>
#include<conio.h>
#include <Windows.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
	int debug;
	int height=25;
	int width=80;
	int gameover=0;
    int dir_player=0;
    int shoot=0;
    int score=0;
    int player_bullet_used=0;
    int player_max_bullet=3;
typedef struct bullet
{
    int x,y,dy;
    int max;
    int used;
};

typedef struct hero
{
    int x,y;
    int last_x;
};

typedef struct coordinate
{
    int status;  //status=0 null , status=1

};

//	enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
//	enum eDirection dir;

void main()
{int i;
	struct coordinate globalco[height][width];
	struct hero player;
    struct bullet player_bullet[player_max_bullet];
    draw_init_splash();                 // Border and get ready
    init_enemy(globalco);          // sets enemy position in background
    draw_init_enemy(globalco);       // displays enemy setup
	player.x=40;                        // player position initialization
	player.y=24;                        // player position initialization
    for(i=1 ; i <= player_max_bullet ; i++)
        player_bullet[i].used=0;            //empties all player bullet slot

		while(!gameover){
			draw_player(&player);       //update player position
			input();                    //take input

            if (dir_player!=0)
            {
                player.last_x = player.x;   //save last position in temporary variable to print empty space and clean screen at the point ; refer to void draw_player();
                player.x += dir_player;     //update to new position according to input(); from user
                dir_player=0;
            }

            if (shoot == 1 && player_bullet_used < player_max_bullet)
            { for(i=1 ; i <= player_max_bullet ; i++)
                { printf("aaa: %d \n",player_bullet[i].used);
                Sleep(50);}
                player_bullet_used += 1 ;
                printf(" bullet used: %d\n",player_bullet_used);
                for(i=1 ; i <= player_max_bullet ; i++)
                { printf("%d \n",player_bullet[i].used);
                Sleep(50);
                    if (player_bullet[i].used=0)
                    {
                        player_bullet[i].used=1;
                        player_bullet_release(player_bullet,&player,i);
                        gotoxy(10,10);
                        printf("asadas");
                        Sleep(500);
                       goto outofloop;

                    }
                }
                outofloop:
                shoot=0;
            }
            if (player_bullet_used < player_max_bullet)
            {
                    player_bullet_release(player_bullet,&player);
            }

            draw_player_bullet(player_bullet);
*/
            Sleep(20);
		}
		if(score==300) printf("Congrats You won");                  //score not implemented.....yet
		else printf("Too bad.... try again");
}

    void draw_init_splash()
    {
        int i,j;
        system("cls");
        for (i=1;i<=width;i++)
        {
            if(i==1) printf("%c",201);
            else if(i==(width)) printf("%c",187);           //prints top border
            else printf("%c",205);
        }

        printf("\n");

        for(j=1;j<=height-2;j++)
        {
            for(i=1;i<=width;i++)
            {
                if(i==1 || i==width)
                    printf("%c",186);        //prints side border,
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

/*      for(i=0;i<5;i++)                //Splash screen "get ready!".
        {   gotoxy(30,10);
            printf("GET READY!!!");
            Sleep(500);
            gotoxy(30,10);
            printf("            ");
            Sleep(500);
        }
 */
	}

    void init_enemy(struct coordinate globalco[][height]) //sets status of certain coordinates as enemy
    {
        int x,y;
        for (y=2;y<=(height-1);y++)
        {
            for (x=2;x<=width-2;x++)
            {
                if(x%2==0 || y>= (2+10))
                    globalco[x][y].status =0;
                else
                    globalco[x][y].status =1;
            }
        }
    }

    void draw_init_enemy(struct coordinate globalco[][height]) // displays enemy setup but draw_init_enemy
    {
        int x,y;
        for (y=2;y<=height-1;y++)
        {
            for (x=2;x<=width-2;x++)
            {
                if (globalco[x][y].status==1)
                {
                    gotoxy(x,y);
                    printf("%c",157);
                }
        }
    }
    gotoxy(80,25);
}

	void draw_player(struct hero *player)
	{
	    if (player->x != player->last_x)
	    {
	        gotoxy(player->last_x,player->y);
            printf(" ");
            gotoxy(player->x,player->y);
            printf("%c",142);
            gotoxy(80,25);
        }

	}

	void input(){
		if(_kbhit()){
			switch(_getch()){                           //if user presses stuff then only getch() activates and hence takes input
				case 'a':
					dir_player=-1;
					break;

				case 'd':
					dir_player=1;
					break;

				case 's':
					shoot = 1;
					printf("shot: %d",debug++);
					break;
				case 'x':
					gameover=1;
					break;
                default:
                    shoot=0;
                    dir_player=0;
                    break;
			}
		}
	}
	void shoot_check(struct bullet player_bullet[])
	{int i;
	    if (shoot == 1 && player_bullet_used < player_max_bullet)
            {
                player_bullet_used+=1;
                for(i=1;player_bullet[i].used==0;i++);
                player_bullet[i].used=1;
                 //player_bullet_release(player_bullet[i],&player);
                shoot=0;
            }
	}
    void player_bullet_release(struct bullet player_bullet[],struct hero *player, int i)
    {   int j;

            player_bullet[i].x = player->x;
            player_bullet[i].y = (player->y-1);
            player_bullet[i].dy=-1;


    }

    void draw_player_bullet(struct bullet player_bullet[])
    {int i;
        for(i=1;i<=player_max_bullet;i++)
        {
            if (player_bullet[i].used=1)
            {
                gotoxy(player_bullet[i].x,player_bullet[i].y);
                printf("1");

                player_bullet[i].y+=player_bullet[i].dy;  //update bullet one step up
            }
        }
    }

/*	void Logic(){

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
