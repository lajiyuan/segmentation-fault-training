#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn =105;
const int INF = 0x3f3f3f3f;
#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
vector<int> v[4];
char op[4];
int a[5];
int solve(char x)
{
    if(x>='2'&&x<='9') return x-'0';
    if(x=='A') return 14;
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
}
int cal(char op[2])
{
    if(op[1]=='s') return 100+solve(op[0]);
    if(op[1]=='h') return 200+solve(op[0]);
    if(op[1]=='d') return 300+solve(op[0]);
    if(op[1]=='c') return 400+solve(op[0]);
}
int x[maxn],tmp[maxn];
int dp[maxn][maxn];
int LCS(int n)
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==tmp[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int dfs(int flag)
{
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int pos=a[i];
        if(flag&(1<<i))
        {
            for(int j=0;j<v[pos].size();j++) tmp[++cnt]=v[pos][j];
        }
        else for(int j=(int)v[pos].size()-1;j>=0;j--) tmp[++cnt]=v[pos][j];
    }
   // for(int i=1;i<=cnt;i++) dbg2(i,tmp[i]);
    return cnt-LCS(cnt);
}
int main()
{
    //freopen("C.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",op);
        x[i]=cal(op);
        if(op[1]=='s') v[0].pb(cal(op));
        if(op[1]=='h') v[1].pb(cal(op));
        if(op[1]=='d') v[2].pb(cal(op));
        if(op[1]=='c') v[3].pb(cal(op));
    }
    for(int i=0;i<4;i++) sort(v[i].begin(),v[i].end());
    for(int i=0;i<4;i++) a[i]=i;
    int ans=INF;
    do
    {
        for(int i=0;i<=15;i++)
        {
            int tmp=dfs(i);
            ans=min(ans,tmp);
        }
    }while(next_permutation(a,a+4));
    printf("%d\n",ans);
    return 0;
}

