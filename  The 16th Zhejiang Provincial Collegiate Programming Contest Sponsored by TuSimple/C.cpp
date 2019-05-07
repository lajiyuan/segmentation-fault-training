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
int a[maxn],b[maxn];
multiset<int> s;
vector<int> v[maxn];
vector<int> tt;
int cc[maxn];
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        s.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==(*s.begin()))
            {
                int tmp=(*s.begin());
                multiset<int>::iterator it = s.upper_bound(tmp);
                if(it==s.end())
                {
                    int sum=0;
                    for(int j=i;j<=n;j++)
                    {
                        if(a[j]==tmp) cc[++sum]=j;
                        else b[j]=tmp;
                    }
                    for(int j=i-1;j>=1;j--)
                    {
                        if(a[j]!=tmp&&b[j]!=tmp)
                        {
                            b[cc[sum]]=b[j];
                            b[j]=tmp;
                            sum--;
                        }
                        if(sum==0) break;
                    }
                    if(sum!=0) flag=1;
                    break;
                }
                else
                {
                    b[i]=(*it);
                    s.erase(it);
                }
            }
            else
            {
                b[i]=(*s.begin());
                s.erase(s.begin());
            }
        }
        if(flag==0)
        {
            for(int i=1;i<=n;i++) v[i].clear();
            for(int i=1;i<=n;i++) v[a[i]].pb(i);
            for(int i=1;i<=n;i++)
            {
                if(v[i].empty()) continue;
                tt.clear();
                for(int j=0;j<v[i].size();j++) tt.push_back(b[v[i][j]]);
                sort(tt.begin(),tt.end());
                for(int j=0;j<v[i].size();j++) b[v[i][j]]=tt[j];
            }

            for(int i=1;i<=n;i++)
            {
                printf("%d",b[i]);
                if(i==n) printf("\n");
                else printf(" ");
            }
        }
        else
        {
            printf("Impossible\n");
        }
    }
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
