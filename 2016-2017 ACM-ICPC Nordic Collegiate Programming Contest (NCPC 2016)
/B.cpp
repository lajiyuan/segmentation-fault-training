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

const int maxn =2e6+10;

#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
int n,m;
string str[maxn];
char s1[maxn];
map<string,int>con;
string sym[maxn];
string str2[maxn];
vector<pair<int,int> >ss[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s1);
        str[i]=s1;
        int len=strlen(s1);
        for(int j=0;j<s1;j++)
        {
            string s2=str[i].substr(0,j+1);
            if(con[s2]==0)
            {
                con.[s2]=1;
                sym[i]=s2;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%s",s1);
        int len1=strlen(s1);
        string s3;
        s3=s1;
        int la=0;
        string s4;
        for(int j=0;j<len1;j++)
        {
            s4=s3.substr(0,j+1);
            if(con[s4])
            {

            }
        }
    }
    return 0;
}
