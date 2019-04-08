include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
const int inf=0x3f3f3f3f;
vector<int>ss[maxn];
int dis[maxn];
int curedge[maxn],head[maxn];
int ecnt;
int s,t;
struct node
{
    int v,nxt;
    int w;
};
node edge[maxn];
void init()
{
    ecnt=0;
    memset(head,-1,sizeof(head));
    memset(curedge,-1,sizeof(curedge));
    memset(dis,-1,sizeof(dis));
    //memset(edge,0,sizeof(edge));
}
void addedge(int u,int v,int w)
{
    edge[ecnt].v=v;
    edge[ecnt].w=w;
    edge[ecnt].nxt=head[u];
    head[u]=ecnt++;
}
bool bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[t]=0;
    queue<int>q;
    q.push(t);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i+1;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(dis[v]==-1&&edge[i^1].w>0)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }

    return dis[s]!=-1;
}
int dfs(int u,int v,int flow)
{
    if(u==t)return flow;
    int delta=flow;
    for(int &i=curedge[u];i+1;i=edge[i].nxt)
    {
        if(dis[u]==dis[edge[i].v]+1&&edge[i].w>0)
        {
            int d=dfs(edge[i].v,v,min(delta,edge[i].w));
            edge[i].w-=d;
            edge[i^1].w+=d;
            delta-=d;
            if(delta==0)break;
        }
    }
    return flow-delta;
}
int dinic()
{
    int ans=0;
    while(bfs())
    {
        memcpy(curedge,head,sizeof(head));
        ans+=dfs(s,t,inf);
    }
    return ans;
}
bool v1[305];
int main()
{
    //freopen("I1.in","r",stdin);
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    memset(v1,false,sizeof(v1));
    init();
    s=n+m+p+1;
    t=n+m+p+2;
    for(int i=1;i<=n;i++)
    {
        addedge(s,i,1);
        addedge(i,s,0);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int n1;
            scanf("%d",&n1);
            addedge(i,n+n1,1);
            addedge(n1+n,i,0);
        }
    }
    for(int i=1;i<=p;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int n1;
            scanf("%d",&n1);
            addedge(n1+n,n+m+i,1);
            addedge(n+m+i,n1+n,0);
            v1[n1+n]=1;
        }
        int mm;
        scanf("%d",&mm);
        addedge(n+m+i,t,mm);
        addedge(t,n+m+i,0);
    }
    for(int i=1;i<=m;i++)
    {
        if(v1[i+n]==0)
        {
            v1[i+n]=1;
            addedge(i+n,t,1);
            addedge(t,n+i,0);
        }
    }
    //ok;
    //for(int i=0;i<ecnt;i++)cout<<edge[i].v<< ' '<<edge[i].w<<endl;
    int ans=dinic();
    cout<<ans<<endl;
    return 0;
}

