#include<stdio.h>
int main()
{
    int n;
    int temp=0;
    int i,j,k;
    scanf("%d",&n);
    int a[n],b[n],c[n];

    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    scanf("%d",&b[i]);

    for(i=0;i<n;i++)
    scanf("%d",&c[i]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(a[i]<b[j]&&b[j]<c[k])
                    temp++;


    printf("%d",temp);
}
