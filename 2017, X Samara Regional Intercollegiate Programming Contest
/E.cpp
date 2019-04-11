#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
const int maxn =2e5+10;
ll t[maxn],b[maxn];
int main()
{
  //freopen("E-4.in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
  for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
  ll ans=0;
  int j=1;
  while(j<=m&&b[j]<=t[1]) j++;
  for(int i=1;i<=n-1;i++)
  {
      ll pre=t[i];
      for(;j<=m&&b[j]<=t[i+1];j++)
      {
          if(b[j]-pre<pre-t[i]+t[i+1]-b[j])
          {
              ans=ans+b[j]-pre;
              pre=b[j];
          }
          else
          {
              ans=ans+pre-t[i];
              ans=ans+2LL*(t[i+1]-b[j]);
              pre=t[i+1];
              while(j<=m&&b[j]<=t[i+1]) j++;
              break;
          }
      }
      ans=ans+min(pre-t[i],t[i+1]-pre);
     // dbg(ans);
  }
  int maxx=-0x3f3f3f3f;
  for(int i=1;i<=m;i++) maxx=max((ll)maxx,b[i]);
  int minn=0x3f3f3f3f;
  for(int i=1;i<=m;i++) minn=min((ll)minn,b[i]);
  if(maxx>t[n]) ans=ans+2LL*(maxx-t[n]);
  if(minn<t[1]) ans=ans+2LL*(t[1]-minn);
  printf("%lld\n",ans);
  return 0;
}
