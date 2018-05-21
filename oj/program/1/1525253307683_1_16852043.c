#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mid,a,b,c,t;
    for(;scanf("%c%c%c",&a,&b,&c)!=EOF;)
    {
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        if(a>c)
        {
            t=a;
            a=c;
            c=t;
        }
         if(b>c)
        {
            t=b;
            b=c;
            c=t;
        }

            printf("%c %c %c\n",a,b,c);
            scanf("%c",&a);

        }

}

