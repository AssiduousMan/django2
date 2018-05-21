#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char s[100];
    gets(s);
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
