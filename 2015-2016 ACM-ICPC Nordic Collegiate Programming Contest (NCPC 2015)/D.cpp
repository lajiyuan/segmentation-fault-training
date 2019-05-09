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
int t[maxn];
int n,k;
int sum[maxn];
int main()
{
    //freopen(".in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        sum[t[i]]++;
        sum[t[i]+1000]--;
    }
    int tmp=0;
    int ans=0;
    for(int i=0;i<=100000;i++)
    {
        tmp=tmp+sum[i];
        ans=max(ans,tmp);
    }
    if(ans%k!=0) ans=ans/k+1;
    else ans=ans/k;
    printf("%d\n",ans);
    return 0;
}
