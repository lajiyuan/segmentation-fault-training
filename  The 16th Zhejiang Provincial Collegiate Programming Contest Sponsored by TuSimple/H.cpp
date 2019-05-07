#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
int sum[maxn];
ll a[maxn];
int main()
{
    //freopen("H.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) sum[i]=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=2;i<=n-1;i++)
        {
            if(a[i]>a[i-1]&&a[i]>a[i+1]) sum[i]++;
        }
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+sum[i];
        int ans=sum[n];
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            if(i>=2) tmp+=sum[i-2];
            if(i<=n-2) tmp+=(sum[n]-sum[i+1]);
            if(i>2&&a[i-1]>a[i-2]&&a[i-1]>a[i+1]) tmp++;
            if(i<=n-2&&a[i+1]>a[i+2]&&a[i+1]>a[i-1]) tmp++;
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}

