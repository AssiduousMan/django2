#include<stdio.h>
int main()
{
    char a[3],t;
    int i,j;
    for(i=0;i<3;i++)
        scanf("%c",&a[i]);
    for(i=1;i<3;i++)
        for(j=0;j<=3-i;j++)
            if(a[j]>a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    for(i=0;i<3;i++)
        printf("%c ",a[i]);
}