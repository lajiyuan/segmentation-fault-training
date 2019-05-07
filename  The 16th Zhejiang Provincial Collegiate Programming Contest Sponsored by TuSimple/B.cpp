#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
ll b[maxn];
vector<ll> ve;
ll abs_(ll x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
    //freopen("B.in","r",stdin);
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        ve.clear();
        ll x, y;
        scanf("%d%lld%lld", &n, &x, &y);
        ll A = -x, B = -y;
        int flag=0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i]);
            A += 1LL * i * b[i];
            B += 1LL * i * b[i] * b[i];
            if(B>=10000000000000000LL) flag=1;
        }
        if(flag==1)
        {
            printf("0\n");
        }
        else if(A==0&&B==0)
        {
            sort(b+1,b+1+n);
            ll cnt=0;
            ll pre=-1;
            ll ans=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]!=pre)
                {
                    ans=ans+(1LL*cnt*(cnt-1))/2;
                    pre=b[i];
                    cnt=1;
                }
                else cnt++;
            }
            ans=ans+(1LL*cnt*(cnt-1))/2;
            printf("%lld\n", ans);
        }
        else if(A==0||B==0)
        {
            printf("0\n");
        }
        else if((A<0&&B>0)||(A>0&&B<0))
        {
            printf("0\n");
        }
        else if((abs_(B)%abs_(A))!=0)
        {
            printf("0\n");
        }
        else
        {
            ll tt;
            if(A>0) tt=A;
            else tt=-A;
            for(ll i=1;i*i<=tt;i++)
            {
                if(tt%i==0)
                {
                    ve.push_back(i);
                    if(i*i!=tt) ve.push_back(tt/i);
                }
            }
            sort(ve.begin(),ve.end());
            ll ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<ve.size();j++)
                {
                    ll l=1LL*i;
                    ll r=1LL*i+ve[j];
                    if(r>n) break;
                    ll tmp1=1LL*(r-l)*(b[r]-b[l]);
                    ll tmp2=1LL*(r-l)*(b[r]*b[r]-b[l]*b[l]);
                    if(tmp1==A&&tmp2==B) ans++;
                }
            }
            printf("%lld\n", ans);
        }

    }

    return 0;
}
