#include<stdio.h>
#include<string.h>
int w(char s[])
{
    int i,j;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(s)-1-i;j++)
        {
            if(s[j]>s[j+1])
            {
                int t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
        }
    }
    for(i=0;i<strlen(s);i++)
    {
        printf("%c ",s[i]);
        if(i%3==2)
            putchar('\n');
    }
}
int main()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        char s[100];
        gets(s);
        w(s);
    }
}