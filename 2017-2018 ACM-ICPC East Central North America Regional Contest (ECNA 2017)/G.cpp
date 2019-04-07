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
/*题意
有一个商店，在n天中每天会推出一个食物量为$c_i$的食品，
最初主人公的卡路里为m，如果吃掉某天的食物或者吃掉某天食物的一部分，主人公的卡路里变为之前的2/3
能吃掉食物的前提是主人公的卡路里大于要吃掉的食物量。
同时，如果主人公一天不吃食物，主人公的卡路里回到上一次吃食物前的状态，
如果主人公连续两天选择不吃食物，则主人公的卡路里恢复为m，问n天之后主人公能获取的最大食物量。

*/
/*做法
dp[i][j]表示第i轮之后能剩余卡路里为j的最大食物获取量，之后按照题意进行转移即可。
如果第i轮选择吃/不吃东西，则从上一轮转移过来。
对于满卡路里的状态，还可以从两轮之前转移过来。
最后要注意判断状态的可达行，有些状态之前到达不了则不能转移。

*/

