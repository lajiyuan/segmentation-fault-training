#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6+10;
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
        for(int i=1;i<=n;i++) b[i]=0;
        int maxx=a[1];
        for(int i=2;i<=n-1;i++)
        {
            if(a[i]>=maxx) b[i]++;
            maxx=max(maxx,a[i]);
        }
        int minn=a[n];
        for(int i=n-1;i>=2;i--)
        {
            if(a[i]<=minn) b[i]++;
            minn=min(minn,a[i]);
        }
        int ans=0;
        for(int i=2;i<=n-1;i++) if(b[i]==2) ans++;
        printf("%d\n",ans);
    }
    return 0;
}

