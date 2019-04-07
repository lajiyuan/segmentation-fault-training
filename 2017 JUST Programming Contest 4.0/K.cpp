#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
int sum[26];
char str[50];
ll solve(ll x)
{
    ll ans=1;
    for(int i=1;i<=x;i++) ans=ans*i;
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=0;i<26;i++) sum[i]=0;
        for(int i=0;i<n;i++) sum[str[i]-'a']++;
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(sum[i]%2==1) cnt++;
        }
        if(cnt>1)
        {
            printf("0\n");
            continue;
        }
        ll ans=solve(n/2);
        for(int i=0;i<26;i++)
        {
            ans=ans/(solve(sum[i]/2));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

