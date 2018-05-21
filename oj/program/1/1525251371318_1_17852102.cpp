#include<iostream>
using namespace std;
int main()
{
    int i,j;
    char l;
    char a[9];
    cin>>a[0]>>a[1]>>a[2];
    cin>>a[3]>>a[4]>>a[5];
    cin>>a[6]>>a[7]>>a[8];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[j]>a[i])
            {
                l=a[j];
                a[j]=a[i];
                a[i]=l;
            }
        }
    }
        for(i=3;i<6;i++)
    {
        for(j=3;j<6;j++)
        {
            if(a[j]>a[i])
            {
                l=a[j];
                a[j]=a[i];
                a[i]=l;
            }
        }
    }
        for(i=6;i<9;i++)
    {
        for(j=6;j<9;j++)
        {
            if(a[j]>a[i])
            {
                l=a[j];
                a[j]=a[i];
                a[i]=l;
            }
        }
    }
    cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl<<a[3]<<' '<<a[4]<<' '<<a[5]<<endl<<a[6]<<' '<<a[7]<<' '<<a[8]<<endl;
    return 0;
}