#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 2005;
#define Fi first
#define Se second
#define ok cout<<"OK"<<endl;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
char pic[maxn][maxn];
char num[maxn][maxn];
char str[maxn];
int get(int x,int y)
{
    return 81*(num[x][y]-'0')+27*(num[x-1][y]-'0')+9*(num[x+1][y]-'0')+3*(num[x][y-1]-'0')+(num[x][y+1]-'0');
}
int maxx;
int vis[maxn][maxn];
int main()
{
//    freopen("C.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                vis[i][j]=-1;
            }
        }
        int a,b;
        ll k;
        scanf("%d%d%lld",&a,&b,&k);
        scanf("%s",str);
        for(int i=1;i<=n;i++) scanf("%s",num[i]+1);
      //  cout<<"OK"<<endl;
        pii pre=pii(a,b);
        ll cnt=0;
        int ans=0;
        while(++cnt<=k)
        {
            int dis=get(pre.Fi,pre.Se);
          //  dbg2(dis,str[dis]);
            int x=pre.Fi;
            int y=pre.Se;
           // dbg2(x,y);
           // dbg(vis[x][y]);
            if(vis[x][y]==-1) vis[x][y]=ans;
            else
            {
                if(vis[x][y]==ans) break;
                else vis[x][y]=ans;
            }
           // ok;
            if(str[dis]=='U')
            {
                if(num[x-1][y]=='1') break;
                pre=pii(x-1,y);
            }
            else if(str[dis]=='D')
            {
                if(num[x+1][y]=='1') break;
                pre=pii(x+1,y);
            }
            else if(str[dis]=='L')
            {
                if(num[x][y-1]=='1') break;
                pre=pii(x,y-1);
            }
            else if(str[dis]=='R')
            {
                if(num[x][y+1]=='1') break;
                pre=pii(x,y+1);
            }
            else if(str[dis]=='P')
            {
                if(num[x][y]=='2')
                {
                    ans++;
                    num[x][y]='0';
                }
                else
                {
                    break;
                }
            }
            else if(str[dis]=='I')
            {
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

