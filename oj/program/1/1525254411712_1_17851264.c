#include<stdio.h>
int main()
{
   char temp;
    char a[3];
    char c[3];
    char e[3];
    int i;





    int b[3],d[3],f[3];gets(a);
    for(i=0;i<3;i++)
        b[i]=a[i];
        if(b[0]>b[1])
    {
        temp=a[1];
        a[1]=a[0];
        a[0]=temp;
    }
    if(b[0]>b[2])
    {
        temp=a[2];
        a[2]=a[0];
        a[0]=temp;

    }
    if(b[1]>b[2])
    {
        temp=a[2];
        a[2]=a[1];
        a[1]=temp;
    }
    for(i=0;i<3;i++)
        d[i]=c[i];
        if(d[0]>d[1])
    {
        temp=c[1];
        c[1]=c[0];
        c[0]=temp;
    }

    if(d[0]>d[2])
    {
        temp=c[2];
        c[2]=c[0];
        c[0]=temp;

    }
    if(d[1]>d[2])
    {
        temp=c[2];
        c[2]=c[1];
        c[1]=temp;
    } gets(e);gets(c);
     for(i=0;i<3;i++)
        f[i]=e[i];
        if(f[0]>f[1])
    {
        temp=e[1];
        e[1]=e[0];
        e[0]=temp;
    }

    if(f[0]>f[2])
    {
        temp=e[2];
        e[2]=e[0];
        e[0]=temp;

    }
    if(f[1]>f[2])
    {
        temp=e[2];
        e[2]=e[1];
        e[1]=temp;
    }
printf("%c %c %c\n",a[0],a[1],a[2]);
printf("%c %c %c\n",e[0],e[1],e[2]);printf("%c %c %c\n",c[0],c[1],c[2]);

    return 0;
}
