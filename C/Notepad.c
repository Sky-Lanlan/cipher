#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define  N    2000
#define  B    500

void contral();

void  excmenu()
{
    int i,j,k=38;
    for(i=0;i<20;i++)
    printf(" ");
    for(i=0;i<20;i++)
    printf("**");
    printf("\n");
    for(i=0;i<2;i++)
    {

        for(j=0;j<19-i;j++)
        printf(" ");
        printf("*");
        for(k=0;k<20+i;k++)
            printf("  ");
             printf("*\n");

    }
      for(i=0;i<17;i++)
        printf(" ");
        printf("*");
        for(i=0;i<14;i++)
        printf(" ");
            printf("Welcome to Notepad");
             for(i=0;i<12;i++)
        printf(" ");
        printf("*\n");
         for(i=0;i<2;i++)
    {

        for(j=0;j<18+i;j++)
        printf(" ");
        printf("*");
        for(k=0;k<21-i;k++)
            printf("  ");
             printf("*\n");

    }
    for(i=0;i<20;i++)
    printf(" ");
    for(i=0;i<20;i++)
    printf("**");
    printf("\n");




}

void menu()
{
    int j,i;

    printf("\n");
        for(j=0;j<20;j++)
        printf(" ");
    for(i=0;i<6;i++)
        printf("**");
        printf(" Notepad ");
        for(i=0;i<11;i++)
        printf("*");
    printf("\n\n");
    for(j=0;j<20;j++)
    printf(" ");
     printf("[1] I want to WRITE a new note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[2] I want to SEARCH my note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[3] I want to CHANGE my note\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[4] Show me all Notepads!\n");
     for(j=0;j<20;j++)
        printf(" ");
     printf("[5] I want to DELETE my note !!!\n");
      for(j=0;j<20;j++)
        printf(" ");
     printf("[6] I want to RESET  my Notepad!!!\n");

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
    int mon =0 , day = 0,j,p=0;
    char  ch;
    FILE *fp;
    system("cls");
    excmenu();
         for(j=0;j<20;j++)
     printf(" ");
    if((fp = fopen("Cipher.bin","ab+")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
   printf("Please input data (XX.XX)\n");
      while(scanf("%d.%d",&mon,&day) == 0)
    {
           MessageBox(NULL,"Wrong data!","Message",MB_OK);
         system("cls");
         excmenu();
         for(j=0;j<20;j++)
     printf(" ");
         printf("Please input data (XX.XX)\n");
        while(getchar()!='\n');
    }

     while(mon==0||day == 0||mon>12||day >31)
    {
           MessageBox(NULL,"Wrong data!","Message",MB_OK);
         system("cls");
      excmenu();
         for(j=0;j<20;j++)
       printf(" ");
         printf("Please input data (XX.XX)\n");
        while(getchar()!='\n');
        scanf("%d.%d",&mon,&day) ;
    }
    if(mon<10)
            fprintf(fp,"%d",p);
    if(day<10)
        {
            mon*=10;

        }

    fprintf(fp,"%d%d",mon,day);
     fputc(',',fp);
     for(j=0;j<20;j++)
     printf(" ");
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
   system("pause");
   system("cls");
   contral();

}


char * trans(char a[])
{
    int i=0;
    char b[B];
    while(a[i]!='\n')
    {
        b[i] = a[i];
        i++;
    }
    b[i]='\0';
    return b;
}

void sear_d()
{
    int mon,day,n,i=0,j=0,flag=1;
    FILE *fp;
     char buf[B],buff[B],ot[B];
     const char* del=",";
    char* tem ;

    op: system("cls");
        excmenu();
         for(j=0;j<20;j++)
     printf(" ");
       j=0;
        printf("Please input the data you want to search(XX.XX)\n");
    while(scanf("%d.%d",&mon,&day) == 0)
    {
           MessageBox(NULL,"Please input again (XX.XX)","Message",MB_OK);
         system("cls");
         excmenu();
         for(j=0;j<20;j++)
     printf(" ");
     j=0;
         printf("Please input the data you want to search(XX.XX)\n");
        while(getchar()!='\n');
    }
    n = mon*100+day;
    if((fp = fopen("Cipher.bin","rb")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        tem=strtok(buf,del);
        if(n==atoi(tem))
         {
             flag = 0;
             while(buff[j] !='\n')
             {

                 if(i == 2)
               {

                   ot[i] = '.';
                        i++;
               }

               else if(i == 5)
               {
                   ot[i] = ' ';
                   i++,j++;
               }
                else
                    {
                    ot[i] = buff[j];
                   i++,j++;
                    }
             }
             ot[i] = '\0';
            printf("%s\n",ot);
            system("pause");

            i = j = 0;
        }

    }
    fclose(fp);
    if(flag)
    {
        MessageBox(NULL,"  None,please confirm your data","Message",MB_OK);
        goto op;
    }


}

void sear_t()
{
   int  i=0,j=0,flag=1,c;
    FILE *fp;
     char buff[B],ot[B],th[B];
     const char* del=",";
    char* tem ,*buf=buff;

    op: system("cls");
        excmenu();
         for(j=0;j<20;j++)
     printf(" ");
     j=0;
     printf("Please input the thing  you want to search\n");
    scanf("%s",th);
    if((fp = fopen("Cipher.bin","rb")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        strcpy(ot,buff);
         tem=strtok(buf,del);
         buf=NULL;
         tem=strtok(buf,del);
         buf= buff;
         tem = trans(tem);
         c=strcmp(tem,th);
       if( c==0)
        {
            flag = 0;
             while(ot[j] !='\n')
             {
                 if(i == 2)
               {

                   ot[i] = '.';
                        i++;
               }
               else if(i == 5)
               {
                   ot[i] = ' ';
                   i++,j++;
               }
                else
                    {
                    ot[i] = buff[j];
                   i++,j++;
                    }
             }
             th[i] = '\0';
            printf("%s\n",ot);
            system("pause");
            i = j = 0;

        }

    }
    fclose(fp);
   if(flag)
    {
        MessageBox(NULL,"  None,please confirm your thing","Message",MB_OK);
        excmenu();

        goto op;
    }

}

void search ()
{
    int d,j;
   cp:
       while(1)
    {
      system("cls");
     excmenu();
         for(j=0;j<20;j++)
     printf(" ");
    printf("[1] Search by data\n");
    for(j=0;j<20;j++)
     printf(" ");
    printf("[2] Search by thing\n");
    for(j=0;j<20;j++)
     printf(" ");
     printf("[3] Back to last menu\n");
     for(j=0;j<20;j++)
     printf(" ");
     printf("[0] Exit\n");
     for(j=0;j<20;j++)
     printf(" ");
    printf("Pease input your choice\n");
    while(scanf("%d",&d)==0)
    {
        MessageBox(NULL,"Wrong oder! Try again","Message",MB_OK);
        while(getchar()!='\n');
    }
    switch(d)
    {
    case 1:  sear_d();goto cp;
    case 2:   sear_t();goto cp;
    case 3: system("cls"); contral();
    case 0:    MessageBox(NULL,"See you!","Message",MB_OK); exit(0);

    default :MessageBox(NULL,"Please input again (0~3)","Message",MB_OK);

    }
    }
}

void change()
{

    int mon,day,n,i=0,j=0,flag=1,d=0,f,e,y=0;
    FILE *fp;
     char buf[B],buff[B],ot[B],ne[B];
     const char* del=",";
    char  cha[60][B]={0};
    char  *tem=NULL ;

    op: system("cls");
         excmenu();
         for(j=0;j<20;j++)
         printf(" ");
         j=0;
        printf("please input the day you want to change(XX.XX)\n") ;
    while(scanf("%d.%d",&mon,&day) == 0)
    {
           MessageBox(NULL,"Please input again (XX.XX)","Message",MB_OK);
         system("cls");
         menu();
        printf("please input the day you want to change(XX.XX)\n") ;
        while(getchar()!='\n');
    }
    n = mon*100+day;
    if((fp = fopen("Cipher.bin","rb")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        tem=strtok(buf,del);
        if(n==atoi(tem))
         {
             flag = 0;
             while(buff[j] !='\n')
             {
                  if(i == 2)
               {

                   ot[i] = '.';
                        i++;
               }

               else if(i == 5)
               {
                   ot[i] = ' ';
                   i++,j++;
               }
                else
                    {
                    ot[i] = buff[j];
                   i++,j++;
                    }
             }
             ot[i] = '\0';
            printf("%s\n",ot);
            i = j = 0;
        }

    }
    fclose(fp);
    if(flag)
    {
        MessageBox(NULL,"  None,please confirm your data","Message",MB_OK);
        goto op;
        excmenu();
         for(j=0;j<20;j++)
     printf(" ");
     j=0;
    }
    if((fp = fopen("Cipher.bin","rb+")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    printf("Please input new something to remember\n");
    while(getchar()!='\n');
    gets(ne);
    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        f = strlen(buf)-5;
        tem=strtok(buf,del);
        if(n == atoi(tem))
         {
             while(fgets(cha[i],B,fp)!=NULL)
             {

                 d+=strlen(cha[i++]);//d为之后的偏移量

             }

             d = -(d+f);//偏移量
             fseek(fp,d,SEEK_END);
             fprintf(fp,"%s",ne);
              fputc('\n',fp);
            for(e=0;e<i;e++)
             {
                 fputs(cha[e],fp);
             }

             y = f-strlen(ne)+1;
             if(y)
             {
                 while(y--)
             {
                 fputc(' ',fp);
             }
            fputc('\n',fp);
             }

             fclose(fp);
             MessageBox(NULL,"Success!","Message",MB_OK);
             system("cls");
             contral();
         }

    }




}

 void show()
 {
     int i=0,j=0;
    FILE *fp;
     char buff[B],ot[B];

     system("cls");
        excmenu();
         for(j=0;j<20;j++)
     printf(" ");
     j=0;

    if((fp = fopen("Cipher.bin","rb")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    while(fgets(buff,B,fp))
    {


             while(buff[j] !='\n')
             {
                  if(i == 2)
               {

                   ot[i] = '.';
                        i++;
               }

               else if(i == 5)
               {
                   ot[i] = ' ';
                   i++,j++;
               }
                else
                    {
                    ot[i] = buff[j];
                   i++,j++;
                    }
             }
             ot[i] = '\0';
             if(ot[0] != ' ')
         {
          printf("%s\n",ot);
      for(j=0;j<20;j++)
           printf(" ");
         }

            i = j = 0;
        }

    fclose(fp);
    system("pause");
    system("cls");
    contral();



 }


 void dele()
 {
     int mon,day,n,i=0,j=0,flag=1,d=0,f,e,y=0;
    FILE *fp;
     char buf[B],buff[B],ot[B];
     const char* del=",";
    char  cha[60][B]={0};
    char  *tem=NULL ;

    op: system("cls");
         excmenu();
         for(j=0;j<20;j++)
         printf(" ");
         j=0;
        printf("please input the day you want to DELETE(XX.XX)\n") ;
    while(scanf("%d.%d",&mon,&day) == 0)
    {
           MessageBox(NULL,"Please input again (XX.XX)","Message",MB_OK);
         system("cls");
         excmenu();
        printf("please input the day you want to DELETE(XX.XX)\n") ;
        while(getchar()!='\n');
    }
    n = mon*100+day;
    if((fp = fopen("Cipher.bin","rb")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }
    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        tem=strtok(buf,del);
        if(n==atoi(tem))
         {
             flag = 0;
             while(buff[j] !='\n')
             {
                if(i == 2)
               {

                   ot[i] = '.';
                        i++;
               }

               else if(i == 5)
               {
                   ot[i] = ' ';
                   i++,j++;
               }
                else
                    {
                    ot[i] = buff[j];
                   i++,j++;
                    }
             }
             ot[i] = '\0';
            printf("%s\n",ot);
            i = j = 0;
        }

    }
    fclose(fp);
    if(flag)
    {
        MessageBox(NULL,"  None,please confirm your data","Message",MB_OK);
        goto op;
        excmenu();
         for(j=0;j<20;j++)
     printf(" ");
     j=0;
    }
    if((fp = fopen("Cipher.bin","rb+")) == NULL)
    {
        MessageBox(NULL,"Failure to open Cipher!","Message",MB_OK);
        exit(0);
    }

    while(fgets(buf,B,fp))
    {
        strcpy(buff,buf);
        f = strlen(buf);
        tem=strtok(buf,del);
        if(n == atoi(tem))
         {
             while(fgets(cha[i],B,fp)!=NULL)
             {

                 d+=strlen(cha[i++]);//d为之后的偏移量

             }

             d = -(d+f);//偏移量
             fseek(fp,d,SEEK_END);
            for(e=0;e<i;e++)
             {
                 fputs(cha[e],fp);
             }

             y= f;
             if(y)
             {
                 while(y--)
             {
                 fputc(' ',fp);
             }
            fputc('\n',fp);
             }
             fclose(fp);
             system("pause");
             system("cls");
             contral();
         }

    }


 }

void cls()
{
    FILE *fp;
    fp = fopen("Cipher.bin","wb");
    fclose(fp);
    if((fp = fopen("Cipher.bin","ab+")) == NULL)
    {
        MessageBox(NULL,"Failure to create!","Message",MB_OK);
        exit(0);
    }
    else
    {
        MessageBox(NULL,"Success!","Message",MB_OK);
        fclose(fp);
        system("cls");
        contral();
    }

}

void contral()
{
    int n,j;
        while(1)
    {
       menu();
    for(j=0;j<20;j++)
     printf(" ");
       printf("Please input your choice(0~5) \n");

    while(scanf("%d",&n)==0)
    {
           MessageBox(NULL,"Please input again (0~5)","Message",MB_OK);
         system("cls");

         menu();
         for(j=0;j<20;j++)
     printf(" ");
         printf("Please input your choice(0~5) \n");

        while(getchar()!='\n');
    }
    switch(n)
    {
        case  1: write();      system("cls");   exit(0);
        case  2: search();   system("cls");   exit(0);
        case  3: change();  system("cls");   exit(0);
        case  4: show();       exit(0);
        case  5: dele();       exit(0);
        case  6:  cls();         exit(0);
        case  0: MessageBox(NULL,"See you!","Message",MB_OK);exit(0);
        default : MessageBox(NULL,"Please input again (0~5)","Message",MB_OK);system("cls");
    }

    }
}

int main()
{
    system("color 3f");
    contral();
    return 0;
}
