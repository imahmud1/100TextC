#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
struct r_people
{
    char rp[100];
};

void gotoxy (int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    struct r_people s[100];
    int x=1, y=1, i, num;
    char ch, t[100];
    i = 0;
    FILE *fl;
    fl = fopen("test.txt", "r");
    while((fscanf(fl, "%s\n", &s[i].rp))==1)
        {
            i++;
        }
        fclose(fl);
    num = i;
    while(1)
    {
        system("cls");
        gotoxy(x,y);
        printf(">>");
        gotoxy(8,0);
        for(i=0; i<num; i++)
        {
            printf("\t%s\n", s[i].rp);
        }
        ch = getch();
        switch(ch)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case '27':
            exit(0);
        }
        gotoxy(x,y);
        printf(">>");
        gotoxy(8,0);
        for(i=0; i<num; i++)
        {
            printf("\t%s\n", s[i].rp);
        }

    }
}
