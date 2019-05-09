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

const int maxn =1e5+10;

#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

ll f[] = {0, 1, 2, 9, 262144};

ll pow_mod(ll a, ll b, ll mod)
{
    ll res = 1 % mod;
    a = a % mod;
    while(b)
    {
        if(b & 1)   res = (res * a) % mod;
        b = (b >> 1);
        a = (a * a) % mod;
    }
    return res;
}

ll phi(ll n)
{
    ll res = n;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res = res - res / i;
            while(n % i == 0)   n /= i;
        }
    }
    if(n > 1)   res = res - res / n;
    return res;
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll solve(int n, ll mod)
{
    if(n <= 4)  return f[n] % mod;
    if(mod == 1)    return 0;
    ll temp = phi(mod);
    ll res = solve(n - 1, temp);
    if(gcd(1LL * n, mod) == 1)  return pow_mod(1LL * n, res, mod);
    return pow_mod(1LL * n, res + temp, mod);
}

int main()
{
    //freopen(".in","r",stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    printf("%lld\n", solve(n, 1LL * m));

    return 0;
}
