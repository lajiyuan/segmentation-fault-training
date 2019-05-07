#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
bool vis[maxn];
vector<int> G[maxn];
void dfs(int rt)
{
    for(int i=0;i<G[rt].size();i++)
    {
        if(vis[G[rt][i]]) continue;
        vis[G[rt][i]]=1;
        dfs(G[rt][i]);
    }
}
struct cmp
{
    bool operator ()(int x,int y)
    {
        return x>y;
    }
};
priority_queue<int,vector<int> ,cmp> pq;
vector<int> ans;
int main()
{
    freopen("J.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        int u,v,n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int cnt=0;
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ++cnt;
                vis[i]=1;
                pq.push(i);
                dfs(i);
            }
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        while(!pq.empty())
        {
            int tp=pq.top();
            ans.push_back(tp);
            vis[tp]=1;
            pq.pop();
            for(int i=0;i<G[tp].size();i++)
            {
                int to=G[tp][i];
                if(vis[to]) continue;
                vis[to]=1;
                pq.push(to);
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<ans.size();i++)
        {
            printf("%d",ans[i]);
            if(i==ans.size()-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

