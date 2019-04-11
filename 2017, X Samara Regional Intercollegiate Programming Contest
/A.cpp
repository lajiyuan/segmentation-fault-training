#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
const int maxn =2e5+10;
struct node
{
    string str;
    int sign;
    int len;
    int pos;
    int sss;
};
node ee[maxn];
char ss[maxn];
stack<char>s1;
bool cmp(const node &a,const node &b)
{
    if(a.sign==b.sign)
    {
        if(a.sss==b.sss)
        {
            if(a.sss==0)
            return  (a.len < b.len) || (a.len == b.len && ((a.str.length() - a.len) > (b.str.length() - b.len)));
            else return ((a.str.length()-a.len ) > (b.str.length()-b.len));
        }
        else return a.sss<b.sss;
    }
    else return a.sign<b.sign;
}
int main()
{
    //freopen("A2.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ss);
        int len=strlen(ss);
        for(int j=0;j<len;j++)
        {
            if(s1.empty())s1.push(ss[j]);
            else
            {
                if(s1.top()=='('&&ss[j]==')')
                {
                    s1.pop();
                }
                else s1.push(ss[j]);
            }
        }
       // cout<<s1.size()<<endl;
        string a;
        while(!s1.empty())
        {
            a+=s1.top();
            s1.pop();
        }
        reverse(a.begin(),a.end());
        ee[i].str=a;
        int sum=0;
        int ff=0;
        for(int j=0;j<a.length();j++)
        {
            if(a[j]==')')
            {
                sum++;
            }
            else
            {
                ff=1;
                break;
            }
        }
        if(sum==0)ee[i].sign=0;
        else if(ff==1)ee[i].sign=1;
        else ee[i].sign=2;
        ee[i].len=sum;
        ee[i].pos=i;
        if(ee[i].str.length()-ee[i].len>=ee[i].len)ee[i].sss=0;
        else   ee[i].sss=1;
        //cout<<i<<' '<<ee[i].sss<<endl;
        //cout<<ee[i].str<<' '<<ee[i].sign<<' '<<ee[i].len<<endl;
    }
    sort(ee+1,ee+1+n,cmp);
    int sum1=0;
    int sum2=0;
    int ff=1;
    for(int i=1;i<=n;i++)
    {
        string a=ee[i].str;
        for(int j=0;j<a.length();j++)
        {
            if(a[j]==')')
            {
                sum1--;
                if(sum1<0)
                {
                    ff=0;
                    break;
                }
            }
            else sum1++;
        }
       // cout<<i<<' ' <<sum1<<endl;
    }
    if(sum1==0&&ff)
    {
        printf("YES\n");
        printf("%d",ee[1].pos);
        for(int i=2;i<=n;i++)printf(" %d",ee[i].pos);
        puts("");
    }
    else printf("NO\n");
    return 0;
}

