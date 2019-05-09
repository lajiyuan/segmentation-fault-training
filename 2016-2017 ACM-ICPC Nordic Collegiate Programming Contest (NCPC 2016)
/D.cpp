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
typedef pair<int,ll> pil;
const int maxn =1e5+10;

#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
ll a[maxn];
vector<pil> v;
int main()
{
    //freopen("D-4.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==1)
    {
        printf("100\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            if(a[1]<a[2]) v.pb(pil(-1,a[i]));
            else v.pb(pil(1,a[i]));
            continue;
        }
        if(a[i]>a[i-1]&&a[i]>=a[i+1]) v.pb(pil(1,a[i]));
        if(a[i]<=a[i-1]&&a[i]<a[i+1]) v.pb(pil(-1,a[i]));
    }
    ll ans=100;
    ll cnt=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].Fi==-1)
        {
            if(i==(int)(v.size()-1)) break;
            cnt=min((ll)100000,ans/v[i].Se);
            ans=ans-cnt*v[i].Se;
        }
        else
        {
            ans=ans+1LL*cnt*v[i].Se;
            cnt=0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

