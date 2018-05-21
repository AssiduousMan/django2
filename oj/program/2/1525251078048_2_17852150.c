#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100][100];
    int n[100],i,j,c,m,t;
    for(i=0;i<100;i++)
    {
        c=i;
        scanf("%d",&n[c]);
        if(n[c]==0)break;
        for(j=0;j<n[c];j++)
        scanf("%d",&a[i][j]);
    }
    m=a[0][0];
    for(i=0;i<=c;i++)
    {
        for(j=0;j<n[i];j++)
        {
            if(a[i][m]>a[i][j])
            m=j;
        }
        t=a[i][m];
        a[i][m]=a[i][0];
        a[i][0]=t;
    }
    for(i=0;i<=c;i++)
    {
        for(j=0;j<n[i];j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
