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

const int maxn = 1e5+5;
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
queue<int> q[3];
int x,n,m;
ll ans=0;
bool  dfs(int n,int a,int b,int c)
{
    if(n==0) return true;
    if(n==q[a].front())
    {
        ans=ans+(1LL<<(n-1));
        q[a].pop();
        return dfs(n-1,a,c,b);
    }
    else if(n==q[c].front())
    {
        q[c].pop();
        return dfs(n-1,b,a,c);
    }
    return false;
}
int main()
{
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&x);
       n=max(n,x);
       q[0].push(x);
    }
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&x);
       n=max(n,x);
       q[1].push(x);
    }
    scanf("%d",&m);
    while(m--)
    {
       scanf("%d",&x);
       n=max(n,x);
       q[2].push(x);
    }
    if(dfs(n,0,1,2))
    {
        printf("%lld\n",ans);
    }
    else
    {
        puts("No");
    }
    return 0;
}
