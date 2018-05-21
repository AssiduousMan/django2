#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i,j;
   char a[10];
   int iTemp;
   for(i=0;i<10;i++)
   {
       scanf("%c",&a[i]);
   }
   for(i=1;i<10;i++)
   {
       for(j=9;i>=i;j--)
       {
           if(a[j]<a[j-1]){
            iTemp=a[j-1];
            a[j-1]=a[j];
            a[j]=iTemp;
       }
   }
   }
for(i=0;i<10;i++)
{
    printf("%c\t",a[i]);
    if(i==2)
        printf("\n");
}
return 0;
}
