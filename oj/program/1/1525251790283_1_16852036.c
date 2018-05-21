#include <stdio.h>
#include <stdlib.h>
int main()
{
   int k;
   static char st1[15],st2[]="x",st3[]="y";
   gets(st1);
   k=strcmp(st1,st2,st3);
   if(k==0)
    puts(st1);
   if(k>0)
    printf("st1>st2\n");
   if(k<0)
    printf("st1<st2\n");
   return 0;
}
