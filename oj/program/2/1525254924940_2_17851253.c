#include<stdio.h>
int main()
{
    int a[100][100],b[100],i,j,l,n,k,t,min;
    for(i=0;i<100;i++)
    {
        scanf("%d",&b[i]);
        for(j=0;j<b[i];j++)
        {
            scanf("%d",&a[i][j]);
        }
        if(a[i][0]==0) break;
    }
    for(l=0;l<i;l++)
    {
        min=a[l][0];
        for(n=1;n<b[l];n++)
        {
            if(min>a[l][n])
            {
                min=a[l][n];
                t=n;
            }
        }
        int o;
        o=a[l][0];
        a[l][0]=a[l][t];
        a[l][t]=o;
    }
    for(l=0;l<i;l++)
    {
        for(n=0;n<b[l];n++)
        {
            printf("%d",a[l][n]);
            if(n<b[l]-1)
                printf(" ");
        }
        if(l<i-1)
            printf("\n");
    }
    return 0;
}