#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

void ustaw_kolor(int c)
{
	HANDLE uchwyt;
	uchwyt=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(uchwyt,c);
}

void putpixel (int x, int y, int k)
{
	
	gotoxy(x,y);
	ustaw_kolor(k);
	cout << char(219);
	
}

void circle (int xk, int yk,int r, int k)
{
	float x,y;
	
	for(float a = 0 ; a < 2*M_PI ; a+=1)
	{
		x = r * cos(a);
		y = r * sin(a);
		putpixel (xk+x,yk+y,k);
	}
}

void fill (int xk, int yk,int r, int k)
{
	for(int i=0; i<r;i++)
	{
		circle(xk,yk,r-i,k);
	}
}
void ukl()
{
	for(int x=1;x<100;x++)
	{
		putpixel(x,30,15);
	}
	for(int y=1;y<60;y++)
	{
		putpixel(50,y,15);
	}
}

float sinus(float A, float B, float C, float x) //// y = A*sin(Bx+c)
{
	return A*sin(B*x+C);
}
int main(int argc, char** argv) 
{
	srand(time(0));

	char klawisz;
	float A = 1, B=1, C=0;
	
	while(1){
		ukl();
		float y;
		
		for(float x = -2*M_PI; x < 2*M_PI ; x+=0.01)
		{
			y = sinus(A,B,C,x);
			putpixel(50+5*x,30-y,1+rand()%15);
		}
		
		gotoxy(2,3);
		printf("F(x) = %2.2f*sin(%2.2f*x+%2.2f)",A,B,C);
		
		klawisz = getch();
		switch(klawisz){
				case 'q': A++; break;
				case 'a': A--; break;
				case 'w': B+=0.1; break;
				case 's': B-=0.1; break;
				case 'e': C+=0.1; break;
				case 'd': C-=0.1; break;
				
				}
	
		
		
		system("CLS");
	}
	getch();
	return 0;
	
}
