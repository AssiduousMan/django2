#include<stdio.h>
int main()
{
    int n,i,j,k,m=0;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    scanf("%d",&c[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                if(a[i]<b[j]<c[k])
                m++;
        }
    }
    printf("%d",m);
}