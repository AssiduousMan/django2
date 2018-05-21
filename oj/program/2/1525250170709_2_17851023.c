#include<stdio.h>
int main()
{
    int a[101],i,n,mi,t;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1,mi=0;i<n;i++)
        {
            if(a[mi]>a[i])
                mi=i;
        }
        t=a[mi];
        a[mi]=a[0];
        a[0]=t;
        for(i=0;i<n;i++)
        {
            if(i==n-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
}
