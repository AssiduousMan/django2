#include<stdio.h>
#define N 100
int main()
{
    int n,i,j,t;
    int a[N];
    int sum=0;
    scanf("%d",&n);

 for(i=0;i<n+1;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<n+1;i++)
    {
        if(a[i]==0)
            break;
        t=(a[i]/100+a[i]%100/50+a[i]%50/10+a[i]%10/5+a[i]%5/2+a[i]%2);
        sum+=t;
    }
    printf("%d",sum);
    return 0;
}
