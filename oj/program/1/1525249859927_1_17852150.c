#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100][4],t;
    int n;
    scanf("%d",&n);
    int i,j;
    for(j=0;j<n;j++)
    {
        scanf("%s",a[j]);
        printf("\n");
    }
    int x,y,z;
    for(z=n;z>0;z--)
    for(i=0;i<3;i++)
    {
        x=a[z][i];
        for(j=i;j<3;j++)
        {
            y=a[z][j];
            if(x>y);
            {
                t=a[z][i];
                a[z][i]=a[z][j];
                a[z][j]=t;
                x=a[z][i];
            }
        }
    }
    for(z=0;z<n;z++)
    {for(i=0;i<3;i++)
        printf("%c ",a[z][i]);
        printf("\n");}
    return 0;
}
