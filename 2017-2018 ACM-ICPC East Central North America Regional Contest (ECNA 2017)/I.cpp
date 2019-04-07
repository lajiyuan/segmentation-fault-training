#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
stack<char>st1;
stack<int>st2;
bool judge(char c1,char c2)
{
    if(c2=='(')return true;
    if(c2==')')return false;
    if(c2=='*'||c2=='/')
    {
        if(c1=='*'||c1=='/')return false;
        else return true;
    }
    else
    {
        if(c1=='(')return true;
        else return false;
    }
}
int ccal(int num1,int num2,char c1)
{
    if(c1=='+')return num1+num2;
    if(c1=='-')return num1-num2;
    if(c1=='*')return num1*num2;
    if(c1=='/')return num1/num2;
}
bool cal(string str)
{
    int len=str.length();
    int sum=0;
    while(!st1.empty()) st1.pop();
    while(!st2.empty()) st2.pop();
    for(int i=0;i<len;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
           sum=sum*10+str[i]-'0';
        }
        else
        {
            if(sum!=0)
            {
                st2.push(sum);
                sum=0;
            }
            if(st1.empty())
            {
                st1.push(str[i]);
                continue;
            }
            char cc=st1.top();
            if(judge(cc,str[i])) st1.push(str[i]);
            else
            {
                while(!judge(cc,str[i]))
                {
                    if(cc=='('&&str[i]==')')
                    {
                        st1.pop();
                        break;
                    }
                    int num1,num2;
                    num2=st2.top();
                    st2.pop();
                    num1=st2.top();
                    st2.pop();
                    if(cc=='/'&&num2==0)return false;
                    if(cc=='/'&&(num1%num2!=0))return false;
                    st1.pop();
                    int resu=ccal(num1,num2,cc);
                    st2.push(resu);
                    if(st1.empty())break;
                    cc=st1.top();
                }
                if(str[i]!=')')st1.push(str[i]);
            }
        }
    }
    if(sum!=0)st2.push(sum);
    while(!st1.empty())
    {
        char cc=st1.top();
        st1.pop();
        int num1,num2;
        num2=st2.top();
        st2.pop();
        num1=st2.top();
        st2.pop();
        if(cc=='/'&&num2==0)return false;
        if(cc=='/'&&(num1%num2!=0))return false;
        int resu=ccal(num1,num2,cc);
        st2.push(resu);
    }
   //if(st2.top()==24) dbg(str);
    return  (st2.top()==24);
}
int c[5];
int check(int a[],int b[])
{
    int cnt=0;
    for(int i=0;i<4;i++) c[i]=b[i];
//    for(int i=0;i<4;i++) printf("%d ",a[i]);
//    puts("");
//    for(int i=0;i<4;i++) printf("%d ",b[i]);
//    puts("");
    for(int i=0;i<4;i++)
    {
        if(a[i]!=b[i])
        {
            for(int j=i+1;j<4;j++)
            {
                if(a[i]==b[j])
                {
                    cnt+=j-i;
                    for(int k=j;k>i;k--) swap(b[k],b[k-1]);
                    break;
                }
            }
        }
    }
    for(int i=0;i<4;i++) b[i]=c[i];
  //  memcpy(b,c,sizeof(c));
    return cnt*2;
}
int x[5];
int y[5];
string tostring(int x)
{
    string ans="";
    while(x)
    {
        ans=ans+char(x%10+'0');
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
char fu[5]="+-*/";
int solve(int x[])
{
    int tt=0x3f3f3f3f;
    string tmp="";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                tmp=tostring(x[0])+fu[i]+tostring(x[1])+fu[j]+tostring(x[2])+fu[k]+tostring(x[3]);
                //(tmp);
                if(cal(tmp))
                {
                    tt=min(tt,0);
                }
                tmp='('+tostring(x[0])+fu[i]+tostring(x[1])+')'+fu[j]+tostring(x[2])+fu[k]+tostring(x[3]);
                if(cal(tmp)) tt=min(tt,1);
                tmp=tostring(x[0])+fu[i]+'('+tostring(x[1])+fu[j]+tostring(x[2])+')'+fu[k]+tostring(x[3]);
                if(cal(tmp)) tt=min(tt,1);
                tmp=tostring(x[0])+fu[i]+tostring(x[1])+fu[j]+'('+tostring(x[2])+fu[k]+tostring(x[3])+')';
                if(cal(tmp)) tt=min(tt,1);
                tmp='('+tostring(x[0])+fu[i]+tostring(x[1])+fu[j]+tostring(x[2])+')'+fu[k]+tostring(x[3]);
                if(cal(tmp)) tt=min(tt,1);
                tmp=tostring(x[0])+fu[i]+'('+tostring(x[1])+fu[j]+tostring(x[2])+fu[k]+tostring(x[3])+')';
                if(cal(tmp)) tt=min(tt,1);
                tmp='('+tostring(x[0])+fu[i]+tostring(x[1])+')'+fu[j]+'('+tostring(x[2])+fu[k]+tostring(x[3])+')';
                if(cal(tmp)) tt=min(tt,2);
            }
        }
    }

    return tt;
}
int main()
{
    //freopen("D-2.in", "r", stdin);
    for(int i=0;i<4;i++) scanf("%d",&x[i]);
    for(int i=0;i<4;i++) y[i]=x[i];
    sort(x,x+4);
    int ans=0x3f3f3f3f;
    do
    {
        ans=min(ans,check(x,y)+solve(x));
    }while(next_permutation(x,x+4));
    if(ans==0x3f3f3f3f) printf("impossible\n");
    else printf("%d\n",ans);
    return 0;
}


