#include<iostream>
using namespace std;
int main()
{
       int N,i,j,k,r=0;
    cin>>N;
    int A[N],B[N],C[N];
        cin>>A[0]>>A[1]>>A[2];
        cin>>B[0]>>B[1]>>B[2];
        cin>>C[0]>>C[1]>>C[2];
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
