#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn =1e6+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
int a[maxn];
int b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ll ans=0;
        for(int i=0;i<=20;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]&(1<<i)) b[j]=1;
                else b[j]=0;
            }
            int tt=0;
            ll tmp = (1<<i);
            for(int j=n;j>=1;j--)
            {
                if(b[j]==1) tt++;
                else tt=0;
                ans = ans +1LL*tt*tmp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

