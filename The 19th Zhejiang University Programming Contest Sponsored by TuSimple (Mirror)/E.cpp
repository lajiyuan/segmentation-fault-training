#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 2e5+10;
#define Fi first
#define Se second
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
ll a[maxn],b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
        ll tmp=0;
        int flag=0;
        for(int i=n;i>=1;i--)
        {
            if(tmp+b[i]>=a[i])
            {
                tmp=tmp+b[i]-a[i];
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0) puts("Yes");
        else puts("No");
    }
    return 0;
}
