#include<stdio.h>
int main()
{
    char a[3][3];
    int i,j,n;
    for(i=0;i<3;i++)
           gets(a[i]);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(n=j+1;n<3;n++)
                if(a[i][j]>a[i][n])
                {
                    char t;
                    t=a[i][j];
                    a[i][j]=a[i][n];
                    a[i][n]=t;
                }
        }
    }
    for(i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
        {
            printf("%c",a[i][j]);
            if(j!=2)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
