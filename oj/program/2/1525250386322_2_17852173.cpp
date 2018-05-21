#include <iostream>

using namespace std;

int main()
{
   int n,a[100];
   while(cin>>n&&n)
   {
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int Min=0;
        for(i=1;i<n;i++)
        {
            if(a[Min]>a[i])
            {
                Min=i;
            }
        }
        int t=a[0];
        a[0]=a[Min];
        a[Min]=t;
        for(i=0;i<n-1;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n-1];
        cout<<endl;
   }
   return 0;
}
