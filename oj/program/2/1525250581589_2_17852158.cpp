#include<iostream>
using namespace std;
int main()
{
        int a[3][5];     int i,j,min,t,b,c;
        for(i=0;i<3;i++)
             for(j=0;j<5;j++)
                 cin>>a[i][j];
         min=a[1][0];
        for(i=0;i<3;i++) 
         {
                 for(j=1;j<5;j++)
         {        if(a[i][j]!=0)
                      if(min>a[i][j])
                                { min=a[i][j];        b=i;   c=j;      }
           }
              t=a[i][1];    a[i][1]=min;      a[b][c]=t;
         }
         for(i=0;i<3;i++)
{
                       for(j=1;j<5;j++)
                          cout<<a[i][j]<<" ";
                             cout<<endl;
}
}