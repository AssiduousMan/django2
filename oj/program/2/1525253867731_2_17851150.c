#include<stdio.h>
int main()
{
    int n,i,a[100],j;
    for(i=0;i<n+1;i++)
    {
        scanf("%d",&a[i]);
        n=a[0];
    }
    int d=a[1];
    for(i=1;i<n+1;i++)
    {
        if(d>a[i+1])
            d=a[i+1];
    }
    for(i=1;a[i]!=d;i++);
    int t=a[1];
    a[1]=d;
    a[i]=t;
    for(j=1;j<n+1;j++)
        printf("%d ",a[j]);
    putchar('\n');
}