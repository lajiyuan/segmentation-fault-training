#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 2e6+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
char str[maxn];
char str2[maxn];
char Ma[maxn*2];
int Mp[maxn*2];
void manacher(int len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=str[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=Mp[i]+i;
            id=i;
        }
    }
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
        for(int i=0;i<2*len+1;i++) Mp[i]=0;
        scanf("%s",str2);
        int len2=strlen(str2);
        int l=-1,r=-1;
        for(int i=0;i<len;i++)
        {
            if(str[i]!=str2[i])
            {
                l=i;
                break;
            }
        }
        if(l==-1)
        {
            manacher(len);
            ll ans=0;
            for(int i=0;i<2*len+2;i++)
            {
                ll tt=Mp[i]/2;
                ans=ans+tt;
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=len-1;i>=0;i--)
        {
            if(str[i]!=str2[i])
            {
                r=i;
                break;
            }
        }
        int flag=0;
        for(int i=l,j=r;i<=r&&j>=l;i++,j--)
        {
            if(str[i]!=str2[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("0\n");
        }
        else
        {
            int sum=1;
            //dbg2(l,r);
            for(int i=l-1,j=r+1;i>=0&&j<len;i--,j++)
            {
                if(str[i]!=str[j]) break;
                sum++;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}

