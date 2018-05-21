#include<stdio.h>
int main()
{
    int a[100][100],b[100],i,j,l,n,t=0,min;
    for(i=0;i<100;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==0)
            break;
        else
            for(j=0;j<b[i];j++)
            {
                scanf("%d",&a[i][j]);
            }
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
        int k;
        k=a[l][0];
        a[l][0]=a[l][t];
        a[l][t]=k;
    }
    for(l=0;l<i;l++)
    {
        for(n=0;n<b[l];n++)
        {
            printf("%d",a[l][n]);
            if(n<b[l]-1)
                printf(" ");
        }
        if(n<b[l])
            printf("\n");
    }
    return 0;
}