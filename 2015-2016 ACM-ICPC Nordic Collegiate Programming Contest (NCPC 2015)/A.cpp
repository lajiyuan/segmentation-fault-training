#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 3e5+10;
const int INF = 0x3f3f3f3f;

#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define Fi first
#define Se second
#define pb push_back
vector<int>ss[maxn];
int vis[maxn];
int len;
struct node
{
    int u;
    int len;
};
node tree[maxn];
bool cmp(const node &a,const node &b)
{
    return a.len>b.len;
}
int pre[maxn];
pair<int,int> dfs(int u,int fa,int flag)
{
    vis[u]=flag;
    pair<int,int>h1,h2;
    h1.first=u;
    h2.first=u;
    h1.second=h2.second=0;
    for(int i=0;i<ss[u].size();i++)
    {
        int v=ss[u][i];
        if(v==fa)continue;
        pre[v]=u;
        pair<int,int> hh=dfs(v,u,flag);
        hh.second++;
        if(hh.second>h1.second)
        {
            h2=h1;
            h1=hh;
        }
        else if(hh.second>h2.second)h2=hh;
    }
    if(tree[flag].len<h1.second+h2.second)
    {
        tree[flag].len=h1.second+h2.second;
        tree[flag].u=u;
    }
    //dbg2(h1.first,h1.second);
    return h1;
}
int main()
{
    //freopen("A.in","r",stdin);
    int  n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ss[u].pb(v);
        ss[v].pb(u);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=++cnt;
            tree[cnt].u=i;
            tree[cnt].len=0;
            pre[i]=i;
            pair<int,int>s1=dfs(i,i,cnt);
            int cou=tree[cnt].len/2;
            int pp=s1.first;
            while(cou){
                pp=pre[pp];
                cou--;
            }
            tree[cnt].u=pp;
        }
    }
//    for(int i=1;i<=cnt;i++)
//    {
//        cout<<tree[i].u<<' '<<tree[i].len<<endl;
//    }
    sort(tree+1,tree+1+cnt,cmp);
    for(int i=2;i<=cnt;i++)
    {
        int u=tree[1].u;
        int v=tree[i].u;
       // cout<<u<<' '<<v<<endl;
        ss[u].pb(v);
        ss[v].pb(u);
    }
    dfs(0,0,n+1);
    printf("%d\n",tree[n+1].len);
    return 0;
}

