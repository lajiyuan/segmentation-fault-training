#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
vector<int> G[maxn];
int fat[maxn];
int sum[maxn];
void dfs(int rt,int fa)
{
    fat[rt]=fa;
    sum[rt]=1;
    for(int i=0;i<G[rt].size();i++)
    {
        int to=G[rt][i];
        if(to==fa) continue;
        dfs(to,rt);
        sum[rt]+=sum[to];
    }
}
int main()
{
    //freopen("F-2.in", "r", stdin);
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0,-1);
    ll ans=0;
    int pos;
    for(int i=0;i<=n;i++)
    {
        ll res=0;
        int cnt=sum[i]-1;
        res=res+1LL*cnt*(n-cnt);
        for(int j=0;j<G[i].size();j++)
        {
            int to=G[i][j];
            if(to==fat[i]) continue;
            res=res+1LL*sum[to]*(n-sum[to]);
        }
        res/=2;
        if(res>ans)
        {
            ans=res;
            pos=i;
        }
    }
    vector<int> tmp;
    tmp.push_back(n+1-sum[pos]);
    for(int i=0;i<G[pos].size();i++)
    {
        int to=G[pos][i];
        if(to==fat[pos]) continue;
        tmp.push_back(sum[to]);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    ll ans2=ans-1LL*tmp[0]*tmp[1];
    printf("%lld %lld\n",ans,ans2);
    return 0;
}



