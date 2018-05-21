#include<stdio.h>
int main()
{
    int a[10000],b[10000],c[10000],n,i,k=0,j,l;
    scanf("%d",&n);
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
            for(l=0;l<n;l++)
                if(a[i]<b[j]&&b[j]<c[l])
                    k++;
        }
    }
    printf("%d\n",k);
    return 0;
}