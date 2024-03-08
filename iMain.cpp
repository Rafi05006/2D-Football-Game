#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib")

int x = 0, y = 0, r = 10, d = 0, p = 1, n = 0;
int gn = 0,nss=1;
int jflag = 0, j;
int mp=1;
float ballx = 638.0, bally = 360.0;
float ballx1 = 638.0, bally1 = 240.0;
int dx = 0, dy = 10, flag = 0, tball = 0, bdr = 0;
int score1 = 0,score2 =0;
int ballshow = 1, balldrop = 0;
float m, dp, dp1;
int gameState = 0;
int mmm=0,goals=0;
int gover=0;
int gk;
int gki, gks = 0;
int gkindex = 0;
int bleft1=5;
int bleft2=5;
char str_left1[100], str_left2[100];
char str_score1[100], str_score2[100];

int plays=1;
int music=1;

char home[20] = "pic\\coverre.bmp";
char menu[3][15] = {"pic\\1.bmp", "pic\\2.bmp", "pic\\3.bmp"};
char gkr[3][25] = {"pic\\rgoalk.bmp", "pic\\rgkr.bmp", "pic\\rgkr+.bmp"};
char gkrs[3][25] = {"pic\\rgoalk.bmp", "pic\\gksr1.bmp", "pic\\gksr+.bmp"};

char gkl[3][30] = {"pic\\rgoalkl.bmp", "pic\\rgkl.bmp", "pic\\rightgolle++ (1).bmp"};
char gkls[3][30] = {"pic\\rgoalkl.bmp", "pic\\gksl1.bmp", "pic\\gksl+.bmp"};

char gkmr[3][25] = {"pic\\rgoalk.bmp", "pic\\rgkmr.bmp", "pic\\rgkmr+.bmp"};
char gkmrs[3][25] = {"pic\\rgoalk.bmp", "pic\\rgkmr.bmp", "pic\\gkms.bmp"};

char gkml[3][25] = {"pic\\rgoalkmm.bmp", "pic\\rgkml.bmp", "pic\\rgkml+.bmp"};
char gkmls[3][25] = {"pic\\rgoalkmm.bmp", "pic\\rgkml.bmp", "pic\\gkmsl.bmp"};

struct buttonCordinate
{
	int x;
	int y;
} bCoordinate[3];

/*
	function iDraw() is called again and again by the system.

	*/

void iDraw()
{
	// place your drawing codes here
	iClear();
	if (gameState == 0)
	{
		iShowBMP(0, 0, home);
		for (int i = 0; i < 3; i++)
		{
			iShowBMP2(bCoordinate[i].x, bCoordinate[i].y, menu[i], 255);
		}
	}

	if (gameState == 1)
	{
		
		iShowBMP(0, 0, "pic\\gallery-Photoroom.bmp");
		iSetColor(0,0,0);
		
		iFilledRectangle(1077,560,150,100);
		iFilledRectangle(774,560,245,100);
		iFilledRectangle(588,93,100,36);
		if (flag == 1)
		{
			iFilledRectangle(12,304,23,325);
			iShowBMP(14, 306, "pic\\power bar.bmp");
		}
		iSetColor(255,255,255);

		if (gn == 0)
		{
			iShowBMP2(610, 350, "pic\\rgoalk.bmp", 255);
		}
		if(mp==1)
		{	iSetColor(255,255,255);	
			iText(600,100,"Player 1",GLUT_BITMAP_TIMES_ROMAN_24);
			
		}
		else
		{	iSetColor(255,255,255);	
			iText(600,100,"Player 2",GLUT_BITMAP_TIMES_ROMAN_24);
			
		}
		if (ballshow !=0)
		{
			iShowBMP2(ballx1 - 8, bally1, "pic\\football.bmp", 0);
			iShowBMP2(ballx, 335, "pic\\arrow.bmp",0);
			if (flag == 1)
			{
				iShowBMP2(50, bally-2,  "pic\\arrow1.bmp",0);
			}
		}
		if(nss==1)
		{
			sprintf(str_left1, "Player 1-shot left : %d", bleft1);
			sprintf(str_left2, "Player 2-shot left : %d", bleft2);
			sprintf(str_score1, "Player 1 : %d", score1);
			sprintf(str_score2, "Player 2 : %d", score2);
			nss--;
		}
		if (flag == 2)
		{
			if (gk == 1)
			{
				gn++;
				if (ballshow !=0)
					iShowBMP2(610, 350, gkr[gkindex], 255);
				else
					iShowBMP2(610, 350, gkrs[gkindex], 255);
			}

			else if (gk == 2)
			{
				gn++;
				if (ballshow !=0)
					iShowBMP2(420, 350, gkl[gkindex], 255);
				else
					iShowBMP2(420, 350, gkls[gkindex], 255);
			}
			else if (gk == 3)
			{
				gn++;
				if (ballshow !=0)
					iShowBMP2(610, 350, gkmr[gkindex], 255);
				else
					iShowBMP2(610, 350, gkmrs[gkindex], 255);
			}
			else if (gk == 4)
			{
				gn++;
				if (ballshow !=0)
					iShowBMP2(570, 350, gkml[gkindex], 255);
				else
					iShowBMP2(570, 350, gkmls[gkindex], 255);
			}
			
			if (gks ==1 && gkindex>0 && bally>=365 && bally<=495 && ballx>=391 && ballx<875)
			{
				
				if (ballshow != 0)
				{
					PlaySound("pic//1.wav",NULL,SND_ASYNC);
					iSetColor(0,0,0);
					iFilledRectangle(600,195,90,30);
					iSetColor(255,255,255);
					iText(610, 200, "GOAL!", GLUT_BITMAP_TIMES_ROMAN_24);
					
					goals=1;
				}
					
				if (j == 1 && ballshow != 0 )
				{
					if(mp==1)
					{
						gover++;
						bleft1--;
						score1++;
						j--;
					}
					else
					{
						gover++;
						bleft2--;
						score2++;
						j--;
					}
				}
				
				if(mp==1)
				{
					sprintf(str_left1, "Player 1-shot left : %d", bleft1);
					sprintf(str_score1, "Player 1 : %d", score1);
				}
				
				else
				{
					sprintf(str_left2, "Player 2-shot left : %d", bleft2);
					sprintf(str_score2, "Player 2 : %d", score2);
				}
			}
			else if (gkindex>0 &&gks==0)
			{
				
				if (ballshow == 0 || mmm==1||bally<365)
				{
					PlaySound("pic//3.wav",NULL,SND_ASYNC);
					iSetColor(0,0,0);
					iFilledRectangle(600,195,90,30);
					iSetColor(255,255,255);
					
					iText(610, 200, "MISS", GLUT_BITMAP_TIMES_ROMAN_24);
					if(j==1)
					{
						gover++;
						if(mp==1)
						{
							bleft1--;
						}
						else
						{
							bleft2--;
						}
						j--;
					}
				}
					
				if(mp==1)
				{
					sprintf(str_left1, "Player 1-shot left : %d", bleft1);
					sprintf(str_score1, "Player 1 : %d", score1);
				}
				
				else
				{
					sprintf(str_left2, "Player 2-shot left : %d", bleft2);
					sprintf(str_score2, "Player 2 : %d", score2);
				}
				
			}
			iSetColor(255, 255, 255);
		}
		iText(800, 620, str_left1, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 570, str_left2, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1100, 620, str_score1, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1100, 570, str_score2, GLUT_BITMAP_TIMES_ROMAN_24);
		if(gover>=10)
		{
			if(score1>score2)
			{
				if(gkindex==0)
				{
					iSetColor(255,255,255);
					iFilledRectangle(0,0,1280,720);
					iSetColor(0,0,0);
					iText(564, 620, str_score1, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(564, 570, str_score2, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(530,300,"Press F6 to continue",GLUT_BITMAP_TIMES_ROMAN_24);
					iText(564,350,"Player 1 win",GLUT_BITMAP_TIMES_ROMAN_24);
				}
				
			}
			else if(score1<score2)
			{
				if(gkindex==0)
				{
					iSetColor(255,255,255);
					iFilledRectangle(0,0,1280,720);
					iSetColor(0,0,0);
					iText(564, 620, str_score1, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(564, 570, str_score2, GLUT_BITMAP_TIMES_ROMAN_24);	
					iText(530,300,"Press F6 to continue",GLUT_BITMAP_TIMES_ROMAN_24);
					iText(564,350,"Player 2 win",GLUT_BITMAP_TIMES_ROMAN_24);
				}
				
			}
			else 
			{
				if(gkindex==0)
				{
					iSetColor(255,255,255);
					iFilledRectangle(0,0,1280,720);
					iSetColor(0,0,0);
					
					iText(620,300,"Press F6 to continue",GLUT_BITMAP_TIMES_ROMAN_24);
					iText(620,350,"Draw",GLUT_BITMAP_TIMES_ROMAN_24);
				}
				
			}
		}
	}
	if (gameState == 2)
	{
		iShowBMP(0,0,"pic//instructions.bmp");
	}
	if (gameState == 3)
	{
		iShowBMP(0,0,"pic//about.bmp");
	}
	
}

void change()
{
	if (jflag == 1)
	{
		gkindex++;
		if (gkindex == 3)
		{
			gkindex = 0;
			plays=0;
			jflag = 0;
		}
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		for (int i = 0; i < 3; i++)
		{
			if (mx >= bCoordinate[i].x && mx <= bCoordinate[i].x + 470 && my >= bCoordinate[i].y+10 && my <= bCoordinate[i].y + 120)
			{
				gameState = i + 1;
				music=1;
				if(gameState==1)
				{
					PlaySound("pic//2.wav",NULL,SND_LOOP|SND_ASYNC);
				}
			}
			
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 's' && flag==0)
	{
		gk = (rand()%4)+1;

		flag++;
		dx = 0;
		
		
	}
	if (key == ' ' && flag == 1)
	{
		dy = 0;
		j = 1;
		tball++;
		flag = 2;
		jflag = 1;

	}

	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_F6)
	{
		gameState = 1;
		x = 0, y = 0, r = 10, d = 0, p = 1;
		gn = 0;
		jflag = 0;
		gover=0;
		ballx = 638.0, bally = 360.0;
		ballx1 = 638.0, bally1 = 240.0;
		dx = 15, dy = 5, flag = 0, tball = 0, bdr = 0;
		score1=0,score2=0;
		nss=1;
		ballshow = 1, balldrop = 0;
		mmm=0;
		gameState = 0;
		goals=0;
		gover=0;
		bleft1=5;
		bleft2=5;
		gk = (rand() % 4) + 1;
		gki, gks = 0;
		gkindex = 0;
		plays=1;
		music=0;
		PlaySound(0,0,0);
	}
	// place your codes for other keys here
}
void ballChange()
{
	ballx = ballx + dx;

	if ((ballx < 260 || ballx > 1020))
	{
		dx = -dx;
	}

	bally = bally + dy;
	if (bally < 300 || bally > 600)
	{
		dy = -dy;
	}
}

void ballthrow()
{

	if (tball > 0)
	{

		m = (bally1 - bally) / (ballx1 - ballx);
		dp = (bally - bally1) / 10.0;
		dp1 = dp / m;

		if (bally > bally1 && balldrop == 0)
		{
			bally1 = bally1 + dp;
			ballx1 = ballx1 + dp1;
		}
		if (bally1 > bally - 5 && ballshow !=0)
		{
			balldrop = 1;
		}
		if(ballshow==1 && jflag==0 && bally<380)
		{
			
			ballshow=1;
			x = 0, y = 0, r = 10, d = 0, p = 1;
			gn = 0;
			jflag = 0;
			mp=mp*-1;
			ballx = 638.0, bally = 360.0;
			ballx1 = 638.0, bally1 = 240.0;
			dx = 15, dy = 10, flag = 0, tball = 0, bdr = 0;
			score1,score2;
			ballshow = 1, balldrop = 0;
			mmm=0;
			plays=1;
			goals=0;
			gk = rand() % 4 + 1;
			gki, gks = 0;
			gkindex = 0;
		}
		if(ballshow==0 && gkindex==0 && jflag==0)
		{
			ballshow=1;
			x = 0, y = 0, r = 10, d = 0, p = 1;
			gn = 0;
			jflag = 0;
			mp=mp*-1;
			ballx = 638.0, bally = 360.0;
			ballx1 = 638.0, bally1 = 240.0;
			dx = 15, dy = 10, flag = 0, tball = 0, bdr = 0;
			score1,score2;
			ballshow = 1, balldrop = 0;
			mmm=0;
			plays=1;
			goals=0;
			gk = rand() % 4 + 1;
			gki, gks = 0;
			gkindex = 0;
		}
		if (balldrop == 1 && bally1 > 375 && ballshow !=0 )
		{
			if (bally1 < 385) 
			{
				
				
				ballshow=1;
				x = 0, y = 0, r = 10, d = 0, p = 1;
				gn = 0;
				jflag = 0;
				mp=mp*-1;
				ballx = 638.0, bally = 360.0;
				ballx1 = 638.0, bally1 = 240.0;
				dx = 15, dy = 10, flag = 0, tball = 0, bdr = 0;
				score1,score2;
				ballshow = 1, balldrop = 0;
				mmm=0;
				plays=1;
				goals=0;
				gk = rand() % 4 + 1;
				gki, gks = 0;
				gkindex = 0;
			}
			dp1 = -10;
			dp = 0;
			bally1 = bally1 + dp1;
		}
	}
}

void gscore()
{

	if (gkindex == 1)
	{
		if (gk == 1)
		{
			if (ballx < 875 && bally > 365 && ballx > 750 && bally < 490)
			{
				if(jflag==1)
				ballshow = 0;
				gks=0;
			}
			else if (ballx >= 391 && bally > 365 && bally < 490 && ballx <= 750)
			{
				gks = 1;
				
			}
			else
			{
				mmm=1;
				gks=0;
			}
		}
		if (gk == 2)
		{
			if (ballx < 580 && bally > 365 && ballx > 391 && bally < 490)
			{
				if(jflag==1)
				ballshow = 0;
				gks=0;
			}
			else if (ballx >= 580 && bally > 365 && bally < 490 && ballx < 875)
			{
				gks = 1;
				
			}
			else
			{
				mmm=1;
				gks=0;
			}
		}
	}

	if (gk == 3)
	{
		if (((ballx >= 754 && ballx < 875) || (ballx <= 630 && ballx > 391)) && bally > 365 && bally < 490)
		{
			gks = 1;
		}
		else if (ballx < 754 && bally > 365 && ballx > 630 && bally < 490)
		{
			if(jflag==1)
			ballshow = 0;
			gks=0;
		}

		else
		{
			mmm=1;
			gks=0;
		}
	}
	if (gk == 4)
	{
		if (((ballx >= 650 && ballx < 875) || (ballx1<= 590 && ballx > 391)) && bally > 365 && bally < 490)
		{
			gks = 1;
		}
		else if (ballx < 650 && bally > 365 && ballx> 590 && bally < 490)
		{
			if(jflag==1)
			ballshow = 0;
			gks=0;
		}

		else
		{
			mmm=1;
			gks=0;
		}
	}
}

int main()
{

	// place your own initialization codes here.
	int sum = 100;

	for (int i = 2; i >= 0; i--)
	{
		bCoordinate[i].x = 100;
		bCoordinate[i].y = sum;
		sum += 150;
	}

	iSetTimer(1, ballChange);
	iSetTimer(1, ballthrow);
	iSetTimer(500, change);
	iSetTimer(1, gscore);
	dx = 15;
	dy = 10;
	
	
	
	iInitialize(1280, 720, "Football");
	return 0;
}
