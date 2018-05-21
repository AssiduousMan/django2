#include<stdio.h>
int main()
{
    char ch[4],t;
    int i,j;
    gets(ch);
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            if(ch[j]>ch[j+1])
            {
                t=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=t;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        putchar(ch[i]);
        if(i<2)
            printf(" ");
        else
            printf("\n");
    }
}
