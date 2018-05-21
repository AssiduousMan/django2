#include<stdio.h>
int main()
{
    char a[100][100],s[100],t;
    int i,j;
    for(i=0;i<3;i++)
    {
        gets(s);
        for(j=0;j<3;j++)
            a[i][j]=s[j];
    }
    for(i=0;i<3;i++)

    {
        j=0;
       if(a[i][j+2]<a[i][j])
       { t=a[i][j];
         a[i][j]=a[i][j+2];
         a[i][j+2]=t;
       }
        if(a[i][j+1]<a[i][j])
       { t=a[i][j];
         a[i][j]=a[i][j+1];
         a[i][j]=t;
       }

    }
    for(i=0;i<3;i++)
 {
    for(j=0;j<3;j++)
    {
        printf("%c",a[i][j]);
        printf(" ");

    }
    printf("\n");

  }
    return 0;
}
