#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e3+10;
const int maxm = 1e5+10;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
string str[105];
map<string,int> mp;
vector<int> G[maxn];
vector<ll> W[maxn];
int dis[maxn];
ll ans[maxn];
int main()
{
    //freopen("D.in","r",stdin);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    //scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        mp[str[i]]=i;
    }
    mp["English"]=0;
    for(int i=1;i<=m;i++)
    {
        string str1,str2;
        ll w;
        cin>>str1>>str2>>w;
        int u=mp[str1];
        int v=mp[str2];
        G[u].push_back(v);
        W[u].push_back(w);

        G[v].push_back(u);
        W[v].push_back(w);
    }
    memset(dis,-1,sizeof(dis));
    queue<int> que;
    dis[0]=0;
    que.push(0);
    while(!que.empty())
    {
        int tp=que.front();
        que.pop();
        for(int i=0;i<G[tp].size();i++)
        {
            int to=G[tp][i];
            if(dis[to]!=-1) continue;
            dis[to]=dis[tp]+1;
            que.push(to);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==-1)
        {
            puts("Impossible");
            return 0;
        }
    }
    memset(ans,0x3f,sizeof(ans));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            int to=G[i][j];
            if(dis[to]==dis[i]+1)
            {
                ans[to]=min(ans[to],W[i][j]);
            }
        }
    }
    ll sum=0;
    for(int i=1;i<=n;i++) sum=sum+ans[i];
    cout<<sum<<endl;
    return 0;
}
