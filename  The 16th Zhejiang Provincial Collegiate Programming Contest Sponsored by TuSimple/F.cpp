#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
char str[maxn];
bool judge(char x)
{
    if(x=='a'||x=='e'||x=='y'||x=='o'||x=='i'||x=='u') return true;
    return false;
}
int main()
{
    //freopen(".in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len=strlen(str);
        printf("%c",str[0]);
        for(int i=1;i<len;i++) if(!judge(str[i])) printf("%c",str[i]);
        puts("");accumulate
    }
    return 0;
}


