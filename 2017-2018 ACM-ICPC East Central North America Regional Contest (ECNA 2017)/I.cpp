#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;
const int MM = -19260817;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int parseAdd(std::stringstream& ss);
int parseNum(std::stringstream& ss) {
    if(ss.peek() == '(') {
        ss.get();
        int result = parseAdd(ss);
        if(result==-1) return -1;
        ss.get();
        return result;
    } else {
        int result;
        ss >> result;
        return result;
    }
}
int parseMul(std::stringstream& ss) {
    int result = parseNum(ss);
    if(result==-1) return -1;
    while(true) {
        char op = ss.peek();
        if(op != '*' && op != '/') break;
        ss.get();
        if(op == '*')
        {
            int tmp=parseNum(ss);
            if(tmp==-1) return -1;
            result *= tmp;
        }
        else
        {
            int tmp=parseNum(ss);
            if(tmp==0||(result%tmp!=0)||tmp==-1)return -1;
            result /= tmp;
        }
    }
    return result;
}
int parseAdd(std::stringstream& ss) {
    int result = parseMul(ss);
    if(result==-1) return -1;
    while(true) {
        char op = ss.peek();
        if(op != '+' && op != '-') break;
        ss.get();
        int tmp=parseMul(ss);
        if(tmp==-1) return -1;
        if(op == '+')result += tmp;
        else result -= tmp;
    }
    return result;
}
bool cal(string str)
{
    stringstream ss(str);
    if(parseAdd(ss)==24)
    {
        return true;
    }
    return false;
}
int c[5];
int check(int a[],int b[])
{
    int cnt=0;
    for(int i=0;i<4;i++) c[i]=b[i];
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
/*题意
给你4个数字，在他们中间添加四则运算符，交换两个相邻数字的代价为2,加一组括号的代价为1,求四个数字能凑出24的最小代价。

*/
/*做法
暴力枚举所有表达式判断可行性，可行则更新答案。
*/

