#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[3],t;
    int i,j;
    for(i=0;i<3;i++)
        scanf("%c",&a[i]);
    int x,y;
    for(i=0;i<3;i++)
    {
        x=a[i];
        for(j=i;j<3;j++)
        {
            y=a[j];
            if(x>y);
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                x=a[i];
            }
        }
    }
    for(i=0;i<3;i++)
        printf("%c ",a[i]);
    return 0;
}
