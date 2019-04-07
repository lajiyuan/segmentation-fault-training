#include<stdio.h>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
const int mod=1e9+7;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ll ele1;
        scanf("%lld",&ele1);
        ll sum1=ele1;
        ll sum2=0;
        for(int i=2;i<=n;i++)
        {
            scanf("%lld",&ele1);
            sum2=(sum1*ele1%mod+sum1+ele1)%mod;
            sum1=sum2;
        }
        if(n==1)sum2=sum1;
        printf("%lld\n",sum2%mod);
    }
   return 0;
}
