#include<stdio.h>
#define N 3
main()
{
    char a[N],temp;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        scanf("%c",&a[i]);
    }
    for(j=0;j<N-1;j++)
         for(k=0;k<N-1-j;k++)
    {
        if(a[k]>a[k+1])
        {
            temp=a[k];
            a[k]=a[k+1];
            a[k+1]=temp;
        }

    }
    for(i=0;i<N;i++)
    {
        printf("%c ",a[i]);
    }

}
