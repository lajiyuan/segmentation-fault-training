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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        if(n==1) printf("8 9\n");
        else printf("%lld %lld\n",2LL*n,3LL*n);
    }
    return 0;
}
