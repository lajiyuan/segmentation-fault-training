#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include <unordered_map>
using namespace std;
const int maxn = 5e2+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

bool is[maxn][maxn], has[maxn][maxn];
unordered_map<string, int> mp;

int main()
{
    //freopen("E-3.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m;
    string a, op, b;
    cin >> n >> m;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> op >> b;
        int u, v;
        if(mp.find(a) == mp.end())
        {
            mp[a] = ++cnt;
        }
        u = mp[a];
        if(mp.find(b) == mp.end())
        {
            mp[b] = ++cnt;
        }
        v = mp[b];
        if(op[0] == 'i')
        {
            is[u][v] = true;
        }
        else if(op[0] == 'h')
        {
            has[u][v] = true;
        }
    }

    for(int i = 1; i <= cnt; i++)   is[i][i] = 1;

    /*
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 1; j <= cnt; j++)
        {
            dbg3(i, j, rela[i][j]);
        }
    }
    */

    for(int k = 1; k <= cnt; k++)
    {
        for(int i = 1; i <= cnt; i++)
        {
            for(int j = 1; j <= cnt; j++)
            {
                if(is[i][k] && is[k][j])    is[i][j] = true;
                if(has[i][k] && has[k][j])  has[i][j] = true;
                if(is[i][k] && has[k][j])  has[i][j] = true;
                if(has[i][k] && is[k][j])  has[i][j] = true;
            }
        }
    }

    /*
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 1; j <= cnt; j++)
        {
            dbg3(i, j, rela[i][j]);
        }
    }
    */

    for(int i = 1; i <= m; i++)
    {
        cin >> a >> op >> b;
        int u = mp[a], v = mp[b];
        int ty = -1;
        if(op[0] == 'i')        ty = 1;
        else if(op[0] == 'h')   ty = 2;
        //dbg3(u, v, ty);
        if(ty == 1)
        {
            if(is[u][v]) cout << "Query " << i << ": true\n";
            else        cout << "Query " << i << ": false\n";
        }
        else if(ty == 2)
        {
            if(has[u][v]) cout << "Query " << i << ": true\n";
            else        cout << "Query " << i << ": false\n";
        }
    }

    return 0;
}

