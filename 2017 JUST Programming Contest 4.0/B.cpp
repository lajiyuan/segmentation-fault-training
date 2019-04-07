#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
int a[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int pos;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=-1)
            {
                pos=i;
                break;
            }
        }
        for(int i=pos-1;i>=1;i--)
        {
            if(a[i]==-1) a[i]=((a[i+1]-1)+m)%m;
            else continue;
        }
        for(int i=pos;i<=n;i++)
        {
            if(a[i]==-1) a[i]=(a[i-1]+1)%m;
            else continue;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d",a[i]);
            if(i!=n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
