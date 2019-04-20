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
    //freopen("D-3.in","r",stdin);
    int a1,b1,a2,b2;
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    int a3,b3,a4,b4;
    scanf("%d%d%d%d",&a3,&b3,&a4,&b4);
    ll  ans1=0,ans2=0;
    for(int i=a1;i<=b1;i++)
    {
        for(int j=a2;j<=b2;j++)
        {
            ans1=ans1+i+j;
        }
    }

    for(int i=a3;i<=b3;i++)
    {
        for(int j=a4;j<=b4;j++)
        {
            ans2=ans2+i+j;
        }
    }
    ll tmp1=1LL*ans1*(b3-a3+1)*(b4-a4+1);
    ll tmp2=1LL*ans2*(b2-a2+1)*(b1-a1+1);
    if(tmp1>tmp2) puts("Gunnar");
    else if(tmp1==tmp2) puts("Tie");
    else puts("Emma");
    return 0;

}
