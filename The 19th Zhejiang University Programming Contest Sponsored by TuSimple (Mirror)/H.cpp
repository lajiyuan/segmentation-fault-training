#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
namespace fastIO
{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    bool IOerror=0;
    inline char nc()
    {
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend)
        {
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1)
            {
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
    {
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline void read(int &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x)
    {
        bool sign=0;
        char ch=nc();
        x=0;
        for (; blank(ch); ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (; ch>='0'&&ch<='9'; ch=nc())x=x*10+ch-'0';
        if (ch=='.')
        {
            double tmp=1;
            ch=nc();
            for (; ch>='0'&&ch<='9'; ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 2e5+10;
#define Fi first
#define Se second
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define pb push_back
#define mp make_pair
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int low[maxn],dfn[maxn];
int root[maxn];
int fa[maxn];
int cnt,sum,tot;
int head[maxn];
vector<int>ss[maxn];
struct node
{
    int to,nxt;
};
node edge[maxn*4];
int Find(int x)
{
    return x==root[x]?x:root[x]=Find(root[x]);
}
bool uno(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        root[fy]=fx;
        return true;
    }
    else return false;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
void tarjan(int u,int fat)
{
    dfn[u]=low[u]=++cnt;
    fa[u]=fat;
    int ff=0;
    for(int i=head[u];i+1;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]<=dfn[u])uno(u,v);
        }
        else if(dfn[v])
        {
            if(v==fat)
            {
                if(ff==0)ff++;
                else
                {
                    ff=0;
                    low[u]=min(low[u],dfn[v]);
                }
            }else if(v!=fat)
            {
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
}
vector<int>s2[maxn];
int dui[maxn];
vector<int>con[maxn];
int ff[maxn];
int vis1[maxn];
int vis2[maxn];
void dfs(int u,int flag)
{
    vis1[u]=flag;
    for(int i=0;i<con[u].size();i++)
    {
        int to=con[u][i];
        if(vis1[to])continue;
        dfs(to,flag);
    }
}
int f[maxn][20];
ll deep[maxn];
void dfs2(int u,int fat)
{
    f[u][0]=fat;
    vis2[u]=1;
    for(int i=1;i<=19;i++)
    {
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=0;i<con[u].size();i++)
    {
        int v=con[u][i];
        if(vis2[v]==1)continue;
        deep[v]=deep[u]+1;
        dfs2(v,u);
    }
}
int lca(int a,int b)
{
    int lim=0;
    if(deep[a]<deep[b])swap(a,b);
    while((1LL<<lim)<=deep[a]) lim++;
    for(int i=lim;i>=0;i--)
    {
        if(deep[a]-(1LL<<i)>=deep[b])a=f[a][i];
    }
    if(a==b)return a;
    for(int i=lim;i>=0;i--)
    {
        if(f[a][i]!=0&&f[a][i]!=f[b][i])
        {
            a=f[a][i],b=f[b][i];
        }
    }
    return f[a][0];
}
int main()
{
    int t;
    read(t);
    while(t--)
    {
        int n,m,q;
        read(n);
        read(m);
        read(q)
        for(int i=0;i<=n;i++)
        {
            dfn[i]=0;
            head[i]=-1;
            vis2[i]=0;
            root[i]=i;
            ss[i].clear();
            s2[i].clear();
            con[i].clear();
            ff[i]=0;
            vis1[i]=0;
            for(int j=0;j<=19;j++)f[i][j]=0;
            deep[i]=0;
        }
        cnt=tot=0;
        for(int i=0;i<m;i++)
        {
            int a,b;
            read(a);
            read(b);
            if(a==b)continue;
            addedge(a,b);
            addedge(b,a);
        }
        int nn=1;

        for(int i=1;i<=n;i++)
        {
            tarjan(i,i);
        }
        for(int i=1;i<=n;i++)
        {
            int fx=Find(i);
                ss[fx].pb(i);
        }
        sum=0;
        for(int i=1;i<=n;i++)
        {
            if(i==root[i])
            {
                ++sum;
                for(int j=0;j<ss[i].size();j++)
                {
                    s2[sum].pb(ss[i][j]);
                    dui[ss[i][j]]=sum;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=head[i];j+1;j=edge[j].nxt)
            {
                int u=i;
                int v=edge[j].to;
                if(dui[u]==dui[v])continue;
                else
                {
                    con[dui[u]].pb(dui[v]);
                    con[dui[v]].pb(dui[u]);
                }
            }
        }
        int cc=0;
        for(int i=1;i<=sum;i++)
        {
            if(!vis1[i])
            {
                ++cc;
                vis1[i]=cc;
                ff[cc]=i;
                dfs(i,cc);
            }
        }
        for(int i=1;i<=cc;i++) dfs2(ff[i],ff[i]);
        while(q--)
        {
            int u,v,w;
            read(u);
            read(v);
            read(w);
            u=dui[u];
            v=dui[v];
            w=dui[w];

            if(vis1[u]==vis1[v]&&vis1[v]==vis1[w])
            {
                if(u==v||u==w)
                {
                    printf("Yes\n");
                    continue;
                }
                int f1=1;
                int uv=lca(u,v);
                int uw=lca(u,w);
                int vw=lca(v,w);
                if(uv==u)
                {
                    if(vw==u&&uw==u) ;
                    else if(uw!=u);
                    else f1=0;
                }
                else if(uv==v)
                {
                    if(uw==u);
                    else f1=0;
                }
                else
                {
                    if(uw!=u)f1=0;
                }
                if(f1)printf("Yes\n");
                else printf("No\n");
            }else printf("No\n");
        }
    }
    return 0;
}


