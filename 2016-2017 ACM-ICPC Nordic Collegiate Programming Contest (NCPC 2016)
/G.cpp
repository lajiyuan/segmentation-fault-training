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
const int INF = 0x3f3f3f3f;
const int maxn =1e5+10;

#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
char str[maxn];
int bel(int x)
{
    if(x==0) return INF;
    if(x>=1&&x<=10) return 5;
    if(x>=11&&x<=15) return 4;
    if(x>=16&&x<=20) return 3;
    if(x>=21&&x<=25) return 2;
}
int main()
{
    //freopen("G-6.in","r",stdin);
    scanf("%s",str);
    int len=strlen(str);
    int a=25,b=0;
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='W')
        {
            cnt++;
            if(cnt>=3&&a>=6) b+=2;
            else b++;
            if(b>bel(a))
            {
                b-=bel(a);
                a--;
            }
        }
        else
        {
            cnt=0;
            if(a<=20&&a!=0) b--;
            if(b==-1)
            {
                if(a==20)
                {
                    b=0;
                }
                else
                {
                    a++;
                    b=bel(a)-1;
                }
            }
        }
    }
    if(a==0) printf("Legend\n");
    else printf("%d\n",a);
    return 0;
}

