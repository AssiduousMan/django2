#include<iostream>
using namespace std;
int main()
{
        int n,s[99],i,j=0,t,m=0,l=0,a=0,b=0;
     for(i=0;i<99;i++)
     {
         cin>>n;
         b=b+n;
         if(n==0)
            break;
         if(n!=0)
         {
             for(;j<b;j++)
             {
                cin>>s[j];
             }
             for(;m<b;m++)
             {
                 for(;l<b;l++)
                 {
                     if(s[m]>s[l])
                     {
                         t=s[m];
                         s[m]=s[l];
                         s[l]=t;
                     }
                 }
             }

         }
         for(;a<b;a++)
             {
                 if(a==b-1)
                    cout<<s[a]<<endl;
                 if(a!=b-1)
                    cout<<s[a]<<' ';
             }
     }
    return 0;
}