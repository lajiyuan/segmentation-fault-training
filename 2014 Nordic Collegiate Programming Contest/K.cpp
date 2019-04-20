#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int main()
{
    //freopen("C-2.in","r",stdin);

    ll C, cap = 0;
    int n;
    ll a, b, c;
    scanf("%lld", &C);
    scanf("%d", &n);

    bool isok = true;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        cap -= a;
        if(cap < 0)
        {
            isok = false;
        }
        cap += b;
        if(cap > C)
        {
            isok = false;
        }
        if(cap < C && c)
        {
            isok = false;
        }
        if(i == n && cap)
        {
            isok = false;
        }
        if(i == n && c)
        {
            isok = false;
        }
    }

    if(!isok)   printf("impossible\n");
    else  printf("possible\n");

    return 0;
}
