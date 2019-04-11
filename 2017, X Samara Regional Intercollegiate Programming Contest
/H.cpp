#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
const int maxn =1e3+10;
int pic[maxn][maxn];
int max1[maxn][maxn];
int max2[maxn][maxn];
int max3[maxn][maxn];
int max4[maxn][maxn];
int n,m;
int main()
{
  // freopen("H.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&pic[i][j]);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {

            max1[i][j]=max(pic[i][j],max(max1[i-1][j],max1[i][j-1]));
        }
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            max3[i][j]=max(pic[i][j],max(max3[i+1][j],max3[i][j-1]));
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            max2[i][j]=max(pic[i][j],max(max2[i][j+1],max2[i-1][j]));
        }
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            max4[i][j]=max(pic[i][j],max(max4[i+1][j],max4[i][j+1]));
        }
    }

//    print(max1);
//    print(max2);
//    print(max3);
//    print(max4);
    int ans=0x3f3f3f3f;
    pair<int,int> pos;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int tmp=0;
            tmp=max(tmp,max1[i-1][j-1]);
            tmp=max(tmp,max2[i-1][j+1]);
            tmp=max(tmp,max3[i+1][j-1]);
            tmp=max(tmp,max4[i+1][j+1]);
            if(tmp<ans)
            {
                ans=tmp;
                pos.first=i;
                pos.second=j;
            }
        }
    }
    printf("%d %d\n",pos.first,pos.second);
   return 0;
}

