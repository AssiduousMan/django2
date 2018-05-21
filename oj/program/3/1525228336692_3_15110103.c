#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[MAXN],b[MAXN],c[MAXN];
int n,sum;

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  for(int i=0;i<n;i++)scanf("%d",&b[i]);
  for(int i=0;i<n;i++)scanf("%d",&c[i]);
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);
  sum = 0;
  for(int i=0;i<n;i++){
    int x = (lower_bound(a,a+n,b[i]) - a);
    int y = (n - (upper_bound(c,c+n,b[i]) - c));
    sum += x*y;
  }
  cout<<sum<<endl;
  return 0;
}