#include <iostream>
using namespace std;

int main()
{
   int a[3][1000];
   int i,j,n,sum=0;
   cin>>n;
   for(i=0;i<3;i++)
   {
       for(j=0;j<n;j++)
       {
           cin>>a[i][j];
       }
   }
   for(j=0;j<n;j++)
   {
       for(i=0;i<n;i++)
       {
           for(int x=0;x<n;x++)
           {
               if(a[0][j]<a[1][i]&&a[1][i]<a[2][x]&&a[0][j]<a[2][x])
               {
                   sum++;
               }
           }
       }
   }
   cout<<sum<<endl;
   return 0;
}
