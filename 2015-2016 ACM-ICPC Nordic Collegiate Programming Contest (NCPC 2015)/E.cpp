#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
struct data
{
    int l,r;
    bool operator <(const data &b) const
    {
        return r<b.r;
    }
}x[maxn];
int main()
{
    //ios::sync_with_stdio(false);
  //  freopen("E-3.in","r",stdin);
    //freopen("b.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i].l,&x[i].r);
    sort(x+1,x+1+n);
    multiset<int> s;
    int ans=0;
    int sz=0;
    for(int i=1;i<=n;i++)
    {
        if(s.empty())
        {
            s.insert(x[i].r);
            sz++;
            ans++;
        }
        else
        {
            set<int>::iterator it = s.lower_bound(x[i].l);
           // dbg(*it);
            if(it==s.begin())
            {
                if((*it)==x[i].l)
                {
                    s.erase(it);
                    s.insert(x[i].r);
                    ans++;
                }
                else
                {
                    if(sz==k) continue;
                    else
                    {
                        sz++;
                        s.insert(x[i].r);
                        ans++;
                    }
                }
            }
            else
            {
                if((*it)==x[i].l)
                {
                    s.erase(it);
                    s.insert(x[i].r);
                    ans++;
                }
                else
                {
                    --it;
                    s.erase(it);
                    s.insert(x[i].r);
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
