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

const int maxn = 105;
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
int dis[4][2]={0,1,0,-1,1,0,-1,0};
char str[maxn][maxn];
int vis[maxn][maxn];
int tt[maxn][maxn];
pii pa,pb;
int n,m;
int cnt0;
void dfs0(int x,int y)
{
    cnt0++;
    for(int i=0;i<4;i++)
    {
        int tx=x+dis[i][0];
        int ty=y+dis[i][1];
        if(tx<0||tx>n+1||ty<0||ty>m+1||vis[tx][ty]||tt[tx][ty]==1) continue;
        vis[tx][ty]=1;
        dfs0(tx,ty);
    }
}
int flaga,flagb;
void dfs1(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dis[i][0];
        int ty=y+dis[i][1];
        if(tx<0||tx>n+1||ty<0||ty>m+1||vis[tx][ty]||str[tx][ty]=='X') continue;
        if(str[tx][ty]=='A')
        {
            flaga=1;
            continue;
        }
        if(str[tx][ty]=='B')
        {
            flagb=1;
            continue;
        }
        vis[tx][ty]=1;
        dfs1(tx,ty);
    }
}
int cal(int x[105][105])
{
    memset(vis,0,sizeof(vis));
    memcpy(tt,x,105*105*sizeof(int));
    vis[0][0]=1;
    dfs0(0,0);
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(!vis[i][j]&&tt[i][j]==0)
            {
                cnt0=0;
                vis[i][j]=1;
                dfs0(i,j);
                return cnt0;
            }
        }
    }
    return 0;
}
int col[maxn][maxn];
pii cross[3];
int cx;
bool check(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int tx=x+dis[i][0];
        int ty=y+dis[i][1];
        if(tx<=0||tx>n||ty<=0||ty>m) return false;
        if(str[tx][ty]=='.') return false;
    }
    return true;
}
void dfs(int x,int y,int dir)
{
    col[x][y]=1;
    if(dir==-1)
    {
        for(int i=0;i<4;i++)
        {
            int tx=x+dis[i][0];
            int ty=y+dis[i][1];
            if(tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||str[tx][ty]=='.') continue;
            vis[tx][ty]=1;
            dfs(tx,ty,i);
        }
    }
    else
    {
        if(check(x,y))
        {
            cross[++cx].Fi=x;
            cross[cx].Se=y;
            int tx=x+dis[dir][0];
            int ty=y+dis[dir][1];
            vis[tx][ty]=1;
            dfs(tx,ty,dir);
        }
        else
        {
             for(int i=0;i<4;i++)
            {
                int tx=x+dis[i][0];
                int ty=y+dis[i][1];
                if(tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||str[tx][ty]=='.') continue;
                vis[tx][ty]=1;
                dfs(tx,ty,i);
            }
        }
    }
}
int cntaa,cntbb;
void dfs2(int x,int y,int dir,int co,int flag,int now)
{
    col[x][y]=co;
    if(now==1) cntaa+=flag;
    else cntbb+=flag;
    if(dir==-1)
    {
        for(int i=0;i<4;i++)
        {
            int tx=x+dis[i][0];
            int ty=y+dis[i][1];
            if(tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||str[tx][ty]=='.') continue;
            vis[tx][ty]=1;
            dfs2(tx,ty,i,co,flag,now);
        }
    }
    else
    {
        if(check(x,y))
        {
            int tx=x+dis[dir][0];
            int ty=y+dis[dir][1];
            vis[tx][ty]=1;
            dfs2(tx,ty,dir,1-co,1-flag,now);
        }
        else
        {
             for(int i=0;i<4;i++)
            {
                int tx=x+dis[i][0];
                int ty=y+dis[i][1];
                if(tx<=0||tx>n||ty<=0||ty>m||vis[tx][ty]||str[tx][ty]=='.') continue;
                vis[tx][ty]=1;
                dfs2(tx,ty,i,co,flag,now);
            }
        }
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",col[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='A') pa=pii(i,j);
            else if(str[i][j]=='B') pb=pii(i,j);
        }
    }
    memset(vis,0,sizeof(vis));
    memset(col,0,sizeof(col));
    vis[pa.Fi][pa.Se]=1;
    dfs(pa.Fi,pa.Se,-1);
    int cnta  = cal(col);
    memset(vis,0,sizeof(vis));
    memset(col,0,sizeof(col));
    cx=0;
    vis[pb.Fi][pb.Se]=1;
    dfs(pb.Fi,pb.Se,-1);
    int cntb = cal(col);
    memset(vis,0,sizeof(vis));
    dfs1(0,0);
    memset(col,0,sizeof(col));
    memset(vis,0,sizeof(vis));
    cntaa=0,cntbb=0;
    vis[pa.Fi][pa.Se]=1;
    if(flaga==0) dfs2(pa.Fi,pa.Se,-1,1,1,1);
    else dfs2(pa.Fi,pa.Se,-1,0,0,1);
     memset(vis,0,sizeof(vis));
      vis[pb.Fi][pb.Se]=1;
    if(flagb==0) dfs2(pb.Fi,pb.Se,-1,1,1,2);
    else dfs2(pb.Fi,pb.Se,-1,0,0,2);
    cntaa--;
    cntbb--;
    col[cross[1].Fi][cross[1].Se]=1;
    col[cross[2].Fi][cross[2].Se]=1;
    int ansmid = cal(col);
    printf("%d %d %d\n",cnta-ansmid-cntbb,cntb-ansmid-cntaa,ansmid);
    return 0;
}
