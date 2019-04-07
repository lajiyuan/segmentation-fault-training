#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn =205;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int dis[8][2]={1,0,-1,0,0,1,0,-1,1,-1,-1,-1,1,1,-1,1};
int n,m;
char pic[maxn][maxn];
int getid(int x,int y)
{
    return (x-1)*m+y;
}
int ans;
int flag;
int vis[40005];
int okk[40005];
vector<int>G[40005];
void dfs(int now,int pre,int rt)
{
    if(flag==1) return ;
    for(int i=0;i<G[now].size();i++)
    {
        int to=G[now][i];
        if(pre!=rt&&to==rt)
        {
            flag=1;
            ans++;
            return ;
        }
        if(vis[to]) continue;
        vis[to]=1;
        dfs(to,now,rt);
        if(flag==1) return ;
    }
}
int main()
{
    //freopen("A-3.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",pic[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pic[i][j]=='.') continue;
            okk[getid(i,j)]=1;
            for(int k=0;k<8;k++)
            {
                int tx=i+dis[k][0];
                int ty=j+dis[k][1];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&pic[tx][ty]=='#')
                {
                    int u=getid(i,j);
                    int v=getid(tx,ty);
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
    }
    ans=0;
    for(int i=1;i<=n*m;i++)
    {
        if(!vis[i]&&okk[i])
        {
            vis[i]=1;
            flag=0;
            dfs(i,-1,i);
        }
    }
    printf("%d\n",ans);
    return 0;
}

