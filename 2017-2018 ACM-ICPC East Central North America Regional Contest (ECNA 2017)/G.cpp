#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int dp[105][20005];
int a[maxn];
int sml[maxn];
int mp[maxn];
int maxx[maxn];
vector<int> v[maxn];
int main()
{
   //freopen("G-1.in", "r", stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=20000;i++)
    {
        sml[i]=i*2/3;
        v[sml[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    memset(maxx,-1,sizeof(maxx));
    maxx[0]=0;
    dp[0][m]=0;
    dp[1][sml[m]]=min(a[1],m);
    dp[1][m]=0;
    maxx[1]=dp[1][sml[m]];
    for(int i=2;i<=n;i++)
    {
        dp[i][m]=dp[i-1][m];
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<v[j].size();k++)
            {

                int val=v[j][k];

                if(val<=m&&dp[i-1][val]!=-1)
                {
                    //if(i==5&&j==400) dbg(val);
                    dp[i][j]=max(dp[i][j],dp[i-1][val]+min(val,a[i]));
                }
            }
            if(dp[i-1][sml[j]]!=-1&&dp[i-2][j]!=-1)
            {
                dp[i][j] = max(dp[i][j],dp[i-2][j]+min(j,a[i-1]));
                dp[i][j] = max(dp[i][j],dp[i-1][sml[j]]);
            }
            maxx[i]=max(maxx[i],dp[i][j]);
        }
        if(i>=2) dp[i][m]=max(dp[i][m],maxx[i-2]);
        maxx[i]=max(maxx[i],dp[i][m]);
    }
    printf("%d\n",maxx[n]);
    return 0;
}


