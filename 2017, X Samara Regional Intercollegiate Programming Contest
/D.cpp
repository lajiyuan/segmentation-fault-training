#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
const int maxn =1e5+10;

int main()
{
 //freopen(".in","r",stdin);
 int n,x,y;
 scanf("%d%d",&n,&x);
 if(x<0) x=-x;
 int ans=0;
 for(int i=1;i<=n;i++)
 {
     scanf("%d",&y);
     ans=__gcd(ans,y);
 }
 if(x%ans==0) puts("YES");
 else puts("NO");
 return 0;
}

