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

int main()
{
    //freopen(".in","r",stdin);
    int n,p;
    scanf("%d%d",&n,&p);
    double tt=1.0*p/(1.0*(n+1));
    double ans=tt;
    for(int i=2;i<=1000000;i++)
    {
        tt=1.0*tt*(n+i-p);
        tt=tt/(1.0*(n+i));
        ans=max(ans,1.0*tt*i);
    }
    printf("%.12f\n",ans);
    return 0;
}
