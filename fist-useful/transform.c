#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define   N  4000
void step1();
void step2();

int main()
{
    step1();
    step2();
    return 0;
}
void step1(void)
{
    FILE *p,*fp;
    int n=0;
    char dt[N];
    fp=fopen("ctt.txt","r");
    p=fopen("yue.txt","w");
    if(fp==NULL||p==NULL)
       printf("error\n"),exit(1);
    while(1)
    {
       if(!fgets(dt,N,fp)) break;
       if((dt[0]=='\n')||(dt[0]==' ')) n++;
       if((dt[0]!=' ')&&dt[0]!='\n')
       {
         fprintf(p,"%s",dt);
         n=0;
       }
       if(n>4)
         fputc('@',p),n=0;
    }
    fclose(fp);
    fclose(p);
    printf("success!\n");
}
void step2()
{
    int y=0;
    char ch;
    FILE *t,*p;
    char s[N];
    p=fopen("yue.txt","r");
    t=fopen("final.txt","w");
    do
    {
        ch=fgetc(p);
        s[y++]=ch;
        if(s[y-1]=='\n')
        s[y-1]=' ';
        if(s[y-1]=='@')
                s[y-1]='\n';
        if(ch==EOF)
         {
            s[y-1]='\0';
            fputs(s,t);
            break;
         }
    }while(1);
    fclose(t);
    fclose(p);
    getchar();
}
