#include<stdio.h>
int main()
{
    int n,a[10],count=0,c,i,t;
    while(scanf("%d\n",&n)!=EOF&&n!=0)
    {

        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
             a[i]=t;
        }
        c=a[0];
       for(i=1;i<n;i++)
        {
            if(a[0]>a[i])
            {
            a[0]=a[i];
            count=i;
            }
        }
         a[count]=c;
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }


    return 0;
}
