#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
const int maxn =2e5+10;
char name[maxn][30];
int u[maxn],v[maxn];
int main()
{
    //freopen("G-3.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",name[i]);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
    int pos=1;
    int cnt=0;
    for(int i=m;i>=1;i--)
    {
        if(u[i]==pos)
        {
            cnt++;
            pos=v[i];
        }
    }
    if(cnt==0)
    {
        printf("%s",name[1]);
    }
    else
    {
        string ans="";
        char tmp[]="I_love_";
        for(int i=0;i<cnt;i++) printf("%s",tmp);
        printf("%s",name[pos]);
    }

    return 0;
}

