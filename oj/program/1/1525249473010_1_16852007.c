#include <stdio.h>
int main()
{
    int i=0,j=0;
  char a,b,c,t;

    while(1)
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
      printf("%c %c %c",a,b,c);
      scanf("%c",&a);
      printf("\n");
    }
}
