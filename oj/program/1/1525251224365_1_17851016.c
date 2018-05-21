#include<stdio.h>
void fun(char *i,char *j,char *k)
{
    char *t;
    if(i>j)
    {
        t = i;
        i = j;
        j = t;
    }
    if(i>k)
    {
        t = i;
        i = k;
        k = t;
    }
    if(k>j)
    {
        t = k;
        k = j;
        j = t;
    }
    printf("%c %c %c",*i,*j,*k);
}
int main()
{
    char i,j,k,a,b,c,d,e,f;
    scanf("%c%c%c",&i,&j,&k);
    fun(&i,&j,&k);
    return 0;
}
