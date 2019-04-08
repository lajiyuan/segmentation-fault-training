#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
string str1,str2;
char del(char a,char b)
{
    int tmp=(a-'A')-(b-'A');
    tmp=(tmp+26)%26;
    return char(tmp+'A');
}
int main()
{
    cin>>str1>>str2;
    int len1=str1.length();
    int len2=str2.length();
    string ans="";
    for(int i=0;i<len1;i++)
    {
        ans=ans+del(str1[i],str2[i]);
        str2=str2+del(str1[i],str2[i]);
    }
    cout<<ans<<endl;
    return 0;
}
