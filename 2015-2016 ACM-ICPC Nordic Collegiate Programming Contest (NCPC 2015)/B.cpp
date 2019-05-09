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
vector<vector<int> > solve(int n)
{
    if(n==1)
    {
        vector<int> tmp;
        tmp.pb(1);
        vector<vector<int> > tt;
        tt.pb(tmp);
        return tt;
    }
    vector<vector<int> > tt=solve(n-1);
    vector<vector<int> > ans;
    for(int j=0;j<tt.size();j++)
    {
        for(int i=1;i<=n;i++)
        {
            vector<int> tmp=tt[j];
            if(j%2==0)
            {
                tmp.insert(tmp.begin()+n-i,n);
            }
            else
            {
                tmp.insert(tmp.begin()+i-1,n);
            }
            ans.push_back(tmp);
        }
    }
    return ans;
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n;
    scanf("%d",&n);
    vector<vector<int> > ans=solve(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
