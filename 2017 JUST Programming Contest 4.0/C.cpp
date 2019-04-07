#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
const int maxn = 1e5+10;
const int Mod = 1000000007;
struct data
{
    int id;
    int val;
}a[maxn];
bool cmp(const data &a,const data &b)
{
    return a.val<b.val;
}
int b[maxn];
int ans[maxn];
map<int,int> mp;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].val);
            a[i].id=i;
            b[i]=a[i].val;
            mp[a[i].val]++;
        }

        sort(b+1,b+1+n);
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            int id=a[i].id;
            ans[id]=0;
            int pos = lower_bound(b+1,b+1+n,Mod-b[i])-b;
            pos --;
            if(b[pos]==b[i]&&mp[b[i]]==1) pos--;
            if(pos==0) ;
            else ans[id]=max(ans[id],(b[i]+b[pos])%Mod);

            if(i==n) ans[id]=max(ans[id],(b[i]+b[i-1])%Mod);
            else ans[id]=max(ans[id],(b[i]+b[n])%Mod);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]);
            if(i==n) puts("");
            else printf(" ");
        }
    }
    return 0;
}

