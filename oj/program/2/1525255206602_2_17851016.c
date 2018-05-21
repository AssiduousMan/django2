#include<stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
    int nums[N];
    int i;
    int m=nums[0];
    int t;
    for(i=0;i<N;i++)
    {
        scanf("%d",nums+i);
        if(nums[0]==0)
            exit(0);
    }
    for(i=0;i<N;i++)
    {
        if(nums[i]<m)
        {
            t=nums[i];
            nums[i]=m;
            m=t;
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}
