#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Mod = 1000000007;
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
map<ll,int> mp1,mp2;
int f[15][7];
int lim,n;
ll pow_(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%Mod;
        b>>=1;
        a=a*a%Mod;
    }
    return ans;
}
ll inv_(ll p)
{
    p%=Mod;
    return pow_(p,Mod-2);
}
void dfs(int pos,int flag,ll tt)
{
    if(flag==1&&pos==lim+1)
    {
        mp1[tt]++;
        return ;
    }
    else if(flag==2&&pos==n+1)
    {
        mp2[tt]++;
        return ;
    }
    for(int i=1;i<=6;i++) dfs(pos+1,flag,(1LL*tt*f[pos][i])%Mod);
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d%d",&n,&x);
        mp1.clear();
        mp2.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=6;j++) scanf("%d",&f[i][j]);
        }
        if(x==0)
        {
            printf("0\n");
            continue;
        }
        lim = n/2;
        dfs(1,1,1);
        dfs(n/2+1,2,1);
        ll ans=0;
        for(map<ll,int>::iterator it=mp1.begin();it!=mp1.end();++it)
        {
            ll val = (*it).first;
            int cnt = (*it).second;
            ll in = inv_(val);
            ll tt = 1LL*x*in%Mod;
            if(mp2.find(tt)==mp2.end()) continue;
            ans=ans+1LL*mp2[tt]*cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

