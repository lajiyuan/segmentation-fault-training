#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 3e5+10;
const int INF = 0x3f3f3f3f;

#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define Fi first
#define Se second
#define pb push_back
bool dp[105][10005];
int st[maxn],en[maxn],ti[maxn];
int main()
{
    //freopen("F-3.in","r",stdin);
    int t;
    scanf("%d",&t);
    int flag=0;
    while(t--)
    {
        int T,n;
        scanf("%d%d",&T,&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&st[i],&en[i]);
            ti[i]=en[i]-st[i];
        }
        memset(dp,false,sizeof(dp));
        for(int i=0;i<=T;i++) dp[0][i]=true;
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=T;j++)
            {
                if(dp[i][j])
                {
                    if(j+ti[i+1]<=T) dp[i+1][j+ti[i+1]]=true;
                    if(j-ti[i+1]>=0) dp[i+1][j-ti[i+1]]=true;
                }
            }
        }
        int tt=0;
        for(int i=0;i<=T;i++) if(dp[n][i]) tt=1;
        if(tt==0) flag=1;
    }
    if(flag==0) puts("possible");
    else puts("impossible");
    return 0;
}

