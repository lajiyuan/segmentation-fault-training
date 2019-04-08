#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 405;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
ll GCD[maxn][maxn];
ll dp[maxn][maxn];
ll a[maxn];
ll dfs(int l,int r)
{
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=LL_INF;
    for(int i=l+1;i<=r-1;i++)
    {
        dp[l][r]=min(dp[l][r],GCD[l][r]+dfs(l,i)+dfs(i,r));
    }
    return dp[l][r];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) a[i+n]=a[i];
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                GCD[i][j]=__gcd(a[i],a[j]);
            }
        }
        for(int i=1;i<=2*n;i++) dp[i][i]=0;
        for(int i=1;i<2*n;i++) dp[i][i+1]=0;
        ll ans=LL_INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=min(ans,dfs(i,j)+dfs(j,i+n)+GCD[i][j]);
            }
        }
        printf("%lld\n",ans);
    }

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
