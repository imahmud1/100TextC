#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct profile
{
    char name[100], tx[100], sname[100], cname[100];
    int tm, code, ccode;
};
void svpfn(char *nm)
{
    FILE *fl;
    fl = fopen("profile.txt", "a");
    fprintf(fl, "%s\n", nm);
    fclose(fl);

}
int svpfc(int nm)
{
    FILE *fl;
    fl = fopen("profile.txt", "a");
    fprintf(fl, "%d\n", nm);
    fclose(fl);

}
void prof()
{
    struct profile s[100];
    printf("Enter your name:");
    scanf("%s", s[0].name);
    printf("Enter a Passcode:");
    scanf("%d", &s[0].code);
    svpfn(s[0].name);
    svpfc(s[0].code);
    system ("cls");
}
int menu()
{
    struct profile s[100];
    int mn;
    printf("Hello %s What do you want to do today?\n", s[0].name);
    printf("1. Search for people\n");
    printf("2. Chat with someone\n");
    printf("Enter Choice:");
    scanf("%d", &mn);
    system ("cls");
    return mn;
}
void search()
{
    struct profile s[100];
    int i, j, n=0;
    FILE *fl;
    fl = fopen("profile.txt", "r");
    i=0;
    while((fscanf(fl, "%s\n", &s[i].sname))==1)
    {
        fscanf(fl, "%d\n", &s[i].code);
        i++;
    }

    fclose(fl);
    printf("Enter your name:");
    scanf("%s", s[0].name);
    printf("Available for chat: %d\n", i-1);
    printf("Profile Names\n\n");

    for(j=0; j<=i; j++)
    {
        if(strcmp(s[j].sname, s[0].name)==0)
        {
            n++;
        }
        else
        {
            printf("%s\n", s[j].sname);
        }
    }
}

void cchat(char *name, char *fln)
{
    /*struct profile s[100];*/
    char t[1000], p[100],y[10];
    int n, i;
    fln="imahmudtahsin.txt";
    FILE *fl;
    fl = fopen(fln, "r");
    while(fgets(t, sizeof(t), fl) != NULL)
    {
        printf("%s", t);
    }
    fclose(fl);
    printf("\n\n1: Refresh\n");
    printf("2: Reply\n");
    printf("3: Go Back\n");
    printf("\nEnter Choice:");
    scanf("%d", &n);
    if(n==1)
    {
        system ("cls");
        cchat(name, fln);
    }
    else if(n==2)
    {
        printf("\n");
        printf("Write Reply: ");
        gets(y);
        gets(p);
        fl = fopen(fln, "a");
        fprintf(fl, "%s: %s\n", name, p);
        fclose(fl);
        system ("cls");
        cchat(name, fln);
    }
}
void schat()
{
    int n;
    FILE *fl;
    fl = fopen("trg.txt", "w");
    n = 1;
    fprintf(fl, "%d", n);
    fclose(fl);
}
void chat()
{
    struct profile s[100];
    int i, j, n;
    schat();
    printf("Enter your name:");
    scanf("%s", s[0].name);
    printf("Enter your Passcode:");
    scanf("%d", &s[0].code);
    printf("Enter your Friends name:");
    scanf("%s", s[0].cname);
    cchat(s[0].name);


}
void trg()
{
    struct profile s[100];
    int n;
    FILE *fl;
    fl = fopen("trg.txt", "r");
    fscanf(fl, "%d", &n);
    if(n==1)
        chat();
}
int main()
{
    int men;
    prof();
    trg();
    do
    {
        men = menu();
        switch(men)
        {
        case 1:
            search();
            break;
        case 2:
            chat();
            break;
        }
    }
    while(men != 3);
}
