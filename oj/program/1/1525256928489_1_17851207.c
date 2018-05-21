#include<stdio.h>
int main()
{
    char a[100][100],s[100],t;
    int i,j,k;
    for(i=0;i<3;i++)
    {
        gets(s);
        for(j=0;j<3;j++)
            a[i][j]=s[j];
    }
    for(i=0;i<3;i++)
    for(k=1;k<3;k++)
        for(j=0;j<3-k;j++)
     {
       if(a[i][j]>a[i][j+1])
       {
           t=a[i][j];
           a[i][j]=a[i][j+1];
           a[i][j+1]=t;
       }
     }
    for(i=0;i<3;i++)
 {
    for(j=0;j<3;j++)
    {
        printf("%c",a[i][j]);
        if(j<2)
        printf(" ");

    }
    printf("\n");

  }
   printf("\n");
    return 0;
}
