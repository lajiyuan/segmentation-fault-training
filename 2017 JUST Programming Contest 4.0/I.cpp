#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 2e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
#define pb push_back

int c[maxn], last[maxn];
int dp[maxn];
vector<int> ve[maxn];

int main()
{
    int t, n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= 200000; i++)    ve[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
            ve[c[i]].pb(i);
        }
        memset(last, -1, sizeof(last));
        for(int i = 1; i <= n; i++) dp[i] = 0x3f3f3f3f;
        dp[1] = 0;
        for(int i = 1; i <= 200000; i++)
        {
            for(int j = 1; j < ve[i].size(); j++)
            {
                int id = ve[i][j], id2 = ve[i][j - 1];
                last[id] = id2;
            }
        }
        for(int i = 2; i <= n; i++)
        {
            if(last[i] != -1)
                dp[i] = min(dp[i - 1], dp[last[i]]) + 1;
            else
                dp[i] = dp[i - 1] + 1;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}


