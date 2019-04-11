#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<random>
#include<time.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
const int maxn =1005;
const int Mod = 1000000007;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
mt19937 rnd(time(0));
ll a[maxn][maxn];
ll b[maxn][maxn];
ll c[maxn][maxn];
ll t[maxn],sum1[maxn],sum2[maxn],sum3[maxn];
int main()
{
 // freopen("I.in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          scanf("%lld",&a[i][j]);
      }
  }
    for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          scanf("%lld",&b[i][j]);
      }
  }
    for(int i=1;i<=n;i++)
  {
      for(int j=1;j<=n;j++)
      {
          scanf("%lld",&c[i][j]);
      }
  }
  int tt=10;
  int flag=0;
  {
      for(int i=1;i<=n;i++) t[i]=rnd()%Mod;
      memset(sum1,0,sizeof(sum1));
      memset(sum1,0,sizeof(sum2));
      memset(sum1,0,sizeof(sum3));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum1[i]=(sum1[i]+a[j][i]*t[j])%Mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum2[i]=(sum2[i]+b[j][i]*sum1[j])%Mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum3[i]=(sum3[i]+c[j][i]*t[j])%Mod;
        }
    }
    for(int i=1;i<=n;i++) if(sum2[i]!=sum3[i]) flag=1;
  }

    if(flag==0) puts("YES");
    else puts("NO");

  return 0;
}


