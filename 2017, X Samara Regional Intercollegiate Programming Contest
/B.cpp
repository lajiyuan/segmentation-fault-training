#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
const int maxn =2e5+10;
char str[maxn];
vector<int> tm[26];
int main()
{
  //freopen("B.in","r",stdin);
  char tmp[10]="happiness";
  scanf("%s",str);
  int len=strlen(str);
  int cnt=0;
  vector<int> ans;
  ans.clear();
  for(int i=0;i<=len-9;i++)
  {
    int flag=0;
    for(int j=i,k=0;j<i+9;j++,k++)
    {
        if(str[j]!=tmp[k])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        ans.push_back(i+1);
        cnt++;
    }
  }
  for(int i=0;i<len;i++) tm[str[i]-'a'].push_back(i+1);
  if(cnt>=3) puts("NO");
  else
  {
    puts("YES");
    if(cnt==0)
    {
        for(int i=0;i<26;i++)
        {
            if(tm[i].size()>1)
            {
                printf("%d %d\n",tm[i][0],tm[i][1]);
                return 0;
            }
        }
        printf("%d %d\n",1,2);
    }
    else if(cnt==1)
    {
        printf("%d %d\n",ans[0],ans[0]+1);
    }
    else
    {
         printf("%d %d\n",ans[0],ans[1]+1);
    }
  }
  return 0;
}
