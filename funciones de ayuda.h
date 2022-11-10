#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK	        0
#define BLUE	        1
#define GREEN	        2
#define CYAN	        3
#define RED	            4
#define MAGENTA	        5
#define BROWN	        6
#define LIGHTGRAY	    7
#define DARKGRAY	    8
#define LIGHTBLUE	    9
#define LIGHTGREEN	    10
#define LIGHTCYAN	    11
#define LIGHTRED	    12
#define LIGHTMAGENTA	13
#define YELLOW	        14
#define WHITE	        15


void maximitzar_finestra()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_SPACE,0x39,0,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
    keybd_event(VK_SPACE,0x39,KEYEVENTF_KEYUP,0);
    keybd_event(0x58,0x47,0,0);
    keybd_event(0x58,0x47,KEYEVENTF_KEYUP,0);
}

void SetColor2(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void mygotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}


void dibuixa_titol ()
{
    FILE *f1;
    int x,y;
    char c1;

    maximitzar_finestra ();
    HideCursor();

    f1 = fopen ("presenta.txt","r");

    SetColor2(LIGHTGREEN,BLACK);
    x = MIDDLE_X; y = MIDDLE_Y;
    while (!feof(f1)) {
        mygotoxy (x,y);
        c1 = fgetc(f1);

        if (c1 == '\n') {
            Sleep (150);
            y = y + 1;
            x = MIDDLE_X;
        }
        else {
            x = x + 1;
        }
        putchar (c1);

    }


    SetColor2(LIGHTCYAN,BLACK);
    mygotoxy (MIDDLE_X + 20,y + 5);
    printf ("Prem INTRO per a continuar...");
    getchar ();

    fclose (f1);
}
