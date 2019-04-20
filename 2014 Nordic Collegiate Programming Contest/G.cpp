#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 1e3+10;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int x[maxn];
vector<int>G1[maxn];
vector<int>G2[maxn];
int vis[maxn];
vector<int> G3[maxn];
int ind[maxn];
vector<int> tt;//当前联通块
vector<int> cir;
void dfs(int rt)
{
    tt.push_back(rt);
    for(int i=0;i<G1[rt].size();i++)
    {
        int to=G1[rt][i];
        if(vis[to]) continue;
        vis[to]=1;
        dfs(to);
    }
}
int flag;
int col[maxn];
void dfs1(int rt)
{
    if(flag!=0) return ;
    col[rt]=1;
    for(int i=0;i<G2[rt].size();i++)
    {
        int to=G2[rt][i];
        if(col[to]==1)
        {
            flag=to;
            return ;
        }
        dfs1(to);
        if(flag!=0) return ;
    }
    return ;
}
bool dp[maxn][maxn];
int n,k;
vector<pii> vv;
int main()
{
    //freopen("G-3.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        G2[x[i]].push_back(i);
        G1[x[i]].push_back(i);
        G1[i].push_back(x[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            tt.clear();
            dfs(i);
            int ss=tt.size();
            for(int j=0;j<tt.size();j++)
            {
                flag=0;
                memset(col,0,sizeof(col));
                dfs1(tt[j]);
                if(flag!=0) break;
            }
            memset(col,0,sizeof(col));
            int t1=flag;
            col[t1]=1;
            int cc=1;
            while(x[t1]!=flag)
            {
                t1=x[t1];
                cc++;
                col[t1]=1;
                cir.push_back(t1);
            }
            vv.push_back(pii(cc,ss));
        }
    }
    dp[0][0]=1;
    for(int i=vv[0].first;i<=vv[0].second;i++) dp[0][i]=1;
    for(int i=1;i<vv.size();i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(int k=vv[i].first;k<=vv[i].second;k++)
            {
                if(j>=k) dp[i][j]|=dp[i-1][j-k];
            }
        }
    }
    int all=vv.size();
    int ans=0;
    for(int i=1;i<=k;i++) if(dp[all-1][i]) ans=i;
    printf("%d\n",ans);
    return 0;
}

