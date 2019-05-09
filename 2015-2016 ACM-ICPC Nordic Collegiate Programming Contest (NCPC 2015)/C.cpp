#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 3e5+10;
const int INF = 0x3f3f3f3f;

#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define Fi first
#define Se second
#define pb push_back
char str[maxn];
int main()
{
    //freopen(".in","r",stdin);
    scanf("%s",str);
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i+=3)
    {
        if(str[i]!='P') ans++;
        if(str[i+1]!='E') ans++;
        if(str[i+2]!='R') ans++;
    }
    printf("%d\n",ans);
    return 0;
}
