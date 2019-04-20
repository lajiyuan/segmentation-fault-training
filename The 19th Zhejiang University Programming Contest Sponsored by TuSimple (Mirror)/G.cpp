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
ll d[maxn];
vector<ll> v1,v2;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)  scanf("%lld",&d[i]);
        v1.clear();
        v2.clear();
        for(int i=1;i<=n;i++)
        {
            if(d[i]<0) v1.push_back(d[i]);
            else if(d[i]>0) v2.push_back(d[i]);
        }
        sort(v1.begin(),v1.end());
        ll ans=0;
        ll flag1=0;
        for(int i=0;i<v1.size();i+=k)
        {
            if(flag1==0) flag1=-v1[i];
            else ans=ans-2LL*v1[i];
            if(i+k>=v1.size()) break;
        }

        sort(v2.begin(),v2.end(),greater<ll>());

        ll flag2=0;
        for(int i=0;i<v2.size();i+=k)
        {
            if(flag2==0) flag2=v2[i];
            else ans=ans+2LL*v2[i];
            if(i+k>=v2.size()) break;
        }

        ans=ans+min(2LL*flag1+flag2,2LL*flag2+flag1);
        printf("%lld\n",ans);
    }
    return 0;
}

