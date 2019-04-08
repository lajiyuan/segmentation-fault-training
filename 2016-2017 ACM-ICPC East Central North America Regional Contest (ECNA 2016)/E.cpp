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
int main()
{
    string str;
    cin>>str;
    int len=str.length();
    int ans=0x3f3f3f3f;
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<=len-i;j++)
        {
            string tmp=str.substr(i,j);
            int st=0;
            int pos=str.find(tmp,st);
            int cnt=0;
            while(pos!=-1)
            {
                cnt++;
                st=pos+j;
                pos=str.find(tmp,st);
            }
            ans=min(ans,len-cnt*j+cnt+j);
        }
    }
    cout<<min(ans,len)<<endl;
    return 0;
}

