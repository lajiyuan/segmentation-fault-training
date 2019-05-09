#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxm = 1e5+10;
const int maxn = 1e4+10;
const int INF = 0x3f3f3f3f;

#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define Fi first
#define Se second
#define pb push_back
short int sum[maxn][maxn];
short int x[maxm],y[maxm];
int pre[maxn][2];
int main()
{
    //freopen("G-2.in","r",stdin);
    ios::sync_with_stdio(false);
    int n,m;
    int a,b,r;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>r;
        for(int j=0;j*j<=r*r;j++)
        {
            int tt=(int)sqrt(r*r-j*j);
            int x1 = a - tt;
            int y1 = b - j;
            int x2 = a + tt ;
            int y2 = b + j;
            x1 = max(0, x1);
            y1 = max(0, y1);
            x2 = min(10000, x2);
            y2 = min(10000, y2);

            sum[x1][y1]++;
            sum[x2 +1 ][y1]--;
            sum[x1  ][y2 + 1]--;
            sum[x2  +1][y2 + 1]++;
        }

    }
    for(int i=0;i<=10000;i++)
    {
        pre[i][0]=(int) sum[0][i];
        if(i>0) pre[i][0] = pre[i][0]+pre[i-1][0];
        if(pre[i][0]>0) sum[0][i]=1;
        else sum[0][i]=0;
    }
    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            pre[j][1]=(int) sum[i][j];
            if(i == 0 && j == 0) continue;
            if(i == 0)
            {
                pre[j][1]+=pre[j-1][1];
               // sum[i][j] += sum[i][j - 1];
            }
            else if(j == 0)
            {
                pre[j][1]+=pre[j][0];
                //sum[i][j] += sum[i - 1][j];
            }
            else
            {
                pre[j][1] = pre[j][1] - pre[j-1][0] + pre[j][0] + pre[j-1][1];
                //sum[i][j] = sum[i][j] - sum[i - 1][j - 1] +  sum[i - 1][j] + sum[i][j - 1] ;
            }
        }
        for(int j=0;j<=10000;j++)
        {
            if(pre[j][1] >0) sum[i][j]=1;
            else sum[i][j]=0;
            pre[j][0]=pre[j][1];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(sum[x[i]][y[i]]>0)
        {
            ans++;
        }
    }
    printf("%d\n",n-ans);
    return 0;
}


