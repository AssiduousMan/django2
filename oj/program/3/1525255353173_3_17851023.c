#include<stdio.h>
int main()
{
    int a[100000],b[100000],c[100000],i,j,k,n,totle;
    scanf("%d",&n);
        for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(totle=0,i=0;i<n;i++)
    {
        if(a[i]>=1&&a[i]<=n)
        {
            for(j=0;j<n;j++)
            {
                if(b[j]>=1&&b[j]<=n)
                {
                    for(k=0;k<n;k++)
                    {
                        if(c[k]>=1&&c[k]<=n)
                        {
                            if(a[i]<b[j]&&b[j]<c[k])
                                totle++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",totle);
}
