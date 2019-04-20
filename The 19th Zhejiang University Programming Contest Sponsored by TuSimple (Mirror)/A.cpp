#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 2e5+10;
#define Fi first
#define Se second
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int a[maxn],b[maxn];
int fa[maxn],fb[maxn];
set<int> ain,aim,gaon,gaom;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) scanf("%d",&fa[i]);
        for(int i=1;i<=m;i++) scanf("%d",&fb[i]);
        ain.clear();
        aim.clear();
        gaon.clear();
        gaom.clear();
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==0) ain.insert(a[i]);
            else gaon.insert(a[i]);
        }

        for(int i=1;i<=m;i++)
        {
            if(fb[i]==0) aim.insert(b[i]);
            else gaom.insert(b[i]);
        }
        int ans=0;
        for(set<int>::iterator it=ain.begin();it!=ain.end();++it)
        {
            int tt=(*it);
            if(gaom.empty()) continue;
            if(*gaom.begin()<tt)
            {
                ans++;
                int tmp=(*gaom.begin());
                gaom.erase(tmp);
            }
        }

        for(set<int>::iterator it=gaon.begin();it!=gaon.end();++it)
        {
            int tt=(*it);
            if(aim.empty()) continue;
            set<int>::iterator itt=aim.upper_bound(tt);
            if(itt==aim.end()) continue;
            int tmp=(*itt);
            ans++;
            aim.erase(tmp);
        }

        printf("%d\n",ans);
    }
    return 0;
}

