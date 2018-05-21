#include<iostream>
using namespace std;
#include<cstring>
int main()
{
    char a[3][3],b;
    int i,j,t;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    cin>>a[i][j];
for(t=1;t<=3;t++)
    for(i=0;i<3;i++)
    {
        for(j=0;j<t;j++)
        {
            if(a[i][j]>a[i][j+1])
            {   b=a[i][j];      a[i][j]=a[i][j+1];      a[i][j+1]=b;    }
            if(j==1)    break;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<a[i][j]<<" ";
    cout<<endl;
    }
}
