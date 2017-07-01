#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define  N    2000

void menu()
{
    int j,k,i;

    printf("\n");
        for(j=0;j<20;j++)
        printf(" ");
    for(i=0;i<6;i++)
        printf("**");
        printf(" Notepa ");
        for(i=0;i<6;i++)
        printf("**");
    printf("\n\n");
    for(j=0;j<20;j++)
    printf(" ");
     printf("[1] I want to write a new note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[2] I want to search my note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[3] I want to change my note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[0]   Exit\n\n");


     for(j=0;j<20;j++)
        printf(" ");
     for(i=0;i<16;i++)
        printf("**");
        printf("\n");


}


void write()
{
    int mon , day,c;
    char  ch;
    FILE *fp;
    if((fp = fopen("Cipher.bin","ab+")) == NULL)
    {
        printf("Failure to open Cipher!");
        exit(0);
    }
   printf("Please input date (XX.XX)\n");
      while(scanf("%d.%d",&mon,&day) == 0)
    {
           MessageBox(NULL,"Please input again (XX.XX)","Message",MB_OK);
         system("cls");

         menu();
         printf("Please input date (XX.XX)\n");
        while(getchar()!='\n');
    }
    fprintf(fp,"%d%d",mon,day);
    printf("Please input something to remember\n");
    while(getchar()!='\n');
    ch = getchar();
   while(ch != '\n')
   {
       fputc(ch,fp);
       ch = getchar();
   }
   fputc('\n',fp);
   fclose(fp);
   while(1)
   {
       printf("Do you want to.....\n");
       printf("[1]  Back to menu\n");
       printf("[2]  Exit\n");
       scanf("%d",&c);
   switch(c)
   {
    case 1:  system("cls"); contral();break;
    case 2:  exit(0);
    default :MessageBox(NULL,"Please input again (0~3)","Message",MB_OK);system("cls");


   }}

}

void search (c)
{

}

void change()
{

}

void contral()
{
    int n,j;
        while(1)
    {
       menu();
    for(j=0;j<20;j++)
     printf(" ");
       printf("Please input your choice(0~3) \n");

    while(scanf("%d",&n)==0)
    {
           MessageBox(NULL,"Please input again (0~3)","Message",MB_OK);
         system("cls");

         menu();
         printf("Please input your choice(0~3) \n");

        while(getchar()!='\n');
    }
    switch(n)
    {
        case  1: write();    system("cls");   exit(0);
        case  2: search();   system("cls");   exit(0);
        case  3: change();  system("cls");   exit(0);
        case  0: MessageBox(NULL,"See you!","Message",MB_OK);exit(0);
        default : MessageBox(NULL,"Please input again (0~3)","Message",MB_OK);system("cls");
    }

    }
}


int main()
{
    contral();
    return 0;
}
