#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<iterator>
#include<algorithm>

int Z[3][100000];
using namespace std;
int main()
{
    int N;int count=0;
    memset(Z,0,sizeof(Z));
    cin>>N;
 for(int i=0;i<N;i++)  //输入A 
 {
     cin>>Z[0][i];
 }
  for(int i=0;i<N;i++)//输入B 
 {
     cin>>Z[1][i];
 }
  for(int i=0;i<N;i++)//输入C 
 {
     cin>>Z[2][i];
 }
 //全排列 
 for(int i=0;i<N;i++)
 {
    for(int j=0;j<N;j++)
    {
        for(int k=0;k<N;k++) {
          if(Z[0][i]<Z[1][j]&&Z[1][j]<Z[2][k]) count++;
          }
    }
 }
 cout<<count<<endl;
 return 0;

}
