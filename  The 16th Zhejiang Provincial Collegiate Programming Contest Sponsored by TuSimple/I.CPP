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
char str2[maxn];
int main()
{
    //freopen(".in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int tmp=0;
        int len=strlen(str);
        for(int i=0;i<len;i++) tmp=(tmp+str[i]-'0')%3;
        tmp=(tmp-1+3)%3;
        scanf("%s",str2);
        int tmp2=0;
        int len2=strlen(str2);
        for(int i=0;i<len2;i++) tmp2=(tmp2+str2[i]-'0')%3;
        int sum1,sum2;
        if(tmp%3==1) sum1=1;
        else sum1=0;
        if(tmp2%3==1) sum2=1;
        else sum2=0;

        printf("%d\n",(sum2-sum1+2)%2);
    }
    return 0;
}

