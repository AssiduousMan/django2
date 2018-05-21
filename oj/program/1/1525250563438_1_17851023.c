#include<stdio.h>
int main()
{
    char ch[3],t;
    int i,j;
    while(scanf("%c%c%c",&ch[0],&ch[1],&ch[2])==3)
    {
    for(i=0;i<2;i++)
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
        if(i<2)
            printf("%c ",ch[i]);
        else
            printf("%c\n",ch[i]);
    }
    getchar();
    }
}
