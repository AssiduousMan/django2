#include<iostream>
using namespace std;
int main()
{
       int N,i,j,k,r=0;
    cin>>N;
    int A[N],B[N],C[N];
    for(i=0;i<N;i++)
    {
        cin>>A[i];
    }
        for(j=0;j<N;j++)
    {
        cin>>B[j];
    }
        for(k=0;k<N;k++)
    {
        cin>>C[k];
    }
    for(i=1;i<N+1;i++)
    {
        for(j=1;j<N+1;j++)
        {
            for(k=1;k<N+1;k++)
            {
                if(i>=1&&j>=1&&k>=1&&i<=N&&j<=N&&k<=N&&A[i-1]<B[j-1]&&B[j-1]<C[k-1]&&A[i-1]<C[k-1])
                    r=r+1;
            }
        }
    }
    cout<<r<<endl;
}
