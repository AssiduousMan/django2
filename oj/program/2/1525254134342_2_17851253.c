#include<stdio.h>
int main()
{
    int a[100][100],b[100],i,j,l,n,k;
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
        for(n=0;n<b[l];n++)
            for(k=n+1;k<b[l];k++)
                {
                    if(a[l][n]>a[l][k])
                    {
                        int p=0;
                        p=a[l][n];
                        a[l][n]=a[l][k];
                        a[l][k]=p;
                    }
                }
    }
    for(l=0;l<i;l++)
    {
        for(n=0;n<b[l];n++)
        {
            printf("%d",a[l][n]);
            if(n<b[i])
                printf(" ");
        }
        printf("\n");
            
    }
    return 0;
}