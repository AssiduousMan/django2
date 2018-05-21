#include<iostream.h>
#include<cstring>
int main()
{   
     string   a[3][3],t;
     int i,j;
   for(i=0;i<3;i++)
      for(j=0;j<3;j++)
     cin>>a[i][j];
for(j=0;j<3;j++)
for(i=0;i<3;i++)
{
     if(q[j][i]<q[j][i+1])
          t=q[j][i];    q[j][i]=q[j][i+1];    q[j][i+1]=t;
}
   for(i=0;i<3;i++)
{
      for(j=0;j<3;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
}
cout<<endl;
}