#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
#define pb push_back
#define mp make_pair
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int vis[maxn];
vector<pair<int,int> >ss[maxn];
int vis2[maxn];
bool dfs(int u,int flag)
{
    vis2[u]=1;
    for(int i=0;i<ss[u].size();i++)
    {
        int ff=1;
        pair<int,int>vv=ss[u][i];
        if(vis[vv.first])
        {
           // cout<<u<<' '<<vv.first<<' '<<flag<<' '<<vis[vv.first]<<' '<<endl;
            if(vv.second==1)
            {
                //cout<<u<<' '<<vv.first<<' '<<flag<<' '<<vis[vv.first]<<' '<<endl;
                if(vis[vv.first]==flag)return false;
                else continue;
            }
            else
            {
                if(vv.second==0)
                {
                    //cout<<u<<' '<<vv.first<<' '<<flag<<' '<<vis[vv.first]<<' '<<endl;
                    if(vis[vv.first]==1&&flag==1)continue;
                    else return false;
                }
                else
                {
                   // cout<<u<<' '<<vv.first<<' '<<flag<<' '<<vis[vv.first]<<' '<<endl;
                    if(vis[vv.first]==2&&flag==2)continue;
                    else return false;
                }
            }
        }
        else
        {
            if(vv.second==1)
            {
                if(flag==1)
                {
                    vis[vv.first]=2;
                    ff= dfs(vv.first,2);
                }
                else
                {
                    vis[vv.first]=1;
                    ff= dfs(vv.first,1);
                }
            }
            else
            {
                if(vv.second==0)
                {
                    if(flag!=1)return false;
                    vis[vv.first]=1;
                    ff= dfs(vv.first,1);
                }
                else
                {
                    if(flag!=2)return false;
                    vis[vv.first]=2;
                    ff= dfs(vv.first,2);
                }
            }
        }
        if(ff==1)continue;
        else return false;
    }
    return true;
//    if(ff==1)return true;
//    else return false;
}
int vis1[maxn];
int cnt[maxn];
bool dfs1(int u,int flag,int &sum)
{
    if(flag==2)sum+=1;
    for(int i=0;i<ss[u].size();i++)
    {
        int ff=1;
        pair<int,int>vv;
        vv=ss[u][i];
        if(vis[vv.first])
        {
            if(flag==vis[vv.first])return false;
        }
        else
        {
            if(flag==1)
            {
                vis[vv.first]=2;
                if(!dfs1(vv.first,2,sum))ff=0;
            }
            else
            {
                vis[vv.first]=1;
                if(!dfs1(vv.first,1,sum))ff=0;
            }
        }
        if(ff==0)return false;
    }
    return true;
}
void dfs2(int u,int flag)
{
    //cout<<u<<' '<<(int)ss[u].size()<<endl;
    for(int i=0;i<ss[u].size();i++)
    {
        pair<int,int>vv;
        vv=ss[u][i];
        //cout<<vv.first<<endl;
        if(vis1[vv.first])continue;
        else
        {
            vis1[vv.first]=flag;
            dfs2(vv.first,flag);
        }
    }

}
int main()
{
    //freopen("A3.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int flag=1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        int sign;
        scanf("%d%d%d",&u,&v,&sign);
        ss[u].pb(mp(v,sign));
        ss[v].pb(mp(u,sign));
        if(sign==2)
        {
            vis[u]=vis[v]=2;
        }
        else if(sign==0)
        {
           // if(vis[i]==2)flag=0;
            vis[u]=vis[v]=1;//1 none
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis2[i]==0)
        if(vis[i]==1||vis[i]==2)
        {
            if(vis[i]==1)
            {

                if(!dfs(i,1))flag=0;
            }
            else if(!dfs(i,2))flag=0;
        }
    }
    if(flag)
    {
        int sum=0;
        for(int i=1;i<=n;i++)if(vis[i]==2)sum++;
        int cc=3;
        memcpy(vis1,vis,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis1[i]==0)
            {
                vis1[i]=cc;
                dfs2(i,cc);
                cc++;
            }
        }
        cc--;
        for(int i=1;i<=n;i++)
        {
            if(vis1[i]>=3)cnt[vis1[i]]++;
        }
//        for(int i=1;i<=n;i++)cout<<vis1[i]<<' ';
//        puts("");
        int ff=1;
        for(int i=1;i<=n;i++)
        {
            int sum1=0;
            if(vis[i]==0)
            {
                vis[i]=1;
                if(!dfs1(i,1,sum1))ff=0;
                //cout<<sum1<<endl;
                int ans=min(sum1,cnt[vis1[i]]-sum1);
                sum+=ans;
            }
        }
        if(ff)
        cout<<sum<<endl;
        else printf("impossible\n");
    }
    else printf("impossible\n");
    return 0;
}
