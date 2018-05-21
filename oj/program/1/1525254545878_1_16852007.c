#include <stdio.h>
int main()
{
    int i=0,j=0;
    char a,b,c,t,e=0;
    char a1[3][3];
    while(e<3)
    {
      scanf("%c%c%c",&a,&b,&c);
      if(a>c)
      {
      t=a;
      a=c;
      c=t;
      }
      if(a>b)
      {
      t=a;
      a=b;
      b=t;
      }
      if(b>c)
      {
      t=b;
      b=c;
      c=t;
      }


      a1[e][0]=a;
      a1[e][1]=b;
      a1[e][2]=c;
      scanf("%c",&a);
   e++;
    }
    for(j=0;j<3;j++)
    {
    for(i=0;i<3;i++)
    {
         printf(" %c",a1[j][i]);
    }
     printf("\n");
    }


}
