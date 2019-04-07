#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn =1e4+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl

char input[maxn];
int prefix[maxn][30];

int main()
{
    int t, n, q, l, r;
    char c[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &q);
        scanf("%s", input);
        memset(prefix, 0, sizeof(prefix));
        prefix[0][input[0] - 'a'] = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(input[i] == j + 'a') prefix[i][j] = prefix[i - 1][j] + 1;
                else                    prefix[i][j] = prefix[i - 1][j];
            }
        }
        while(q--)
        {
            scanf("%d%d", &l ,&r);
            scanf("%s", c);
            int ch = c[0] - 'a';
            l--, r--;
            int l1 = l % n;
            int r1 = r % n;
            ll answer = 0;
            if(l1 == 0)
                answer += 1LL * prefix[n - 1][ch];
            else
                answer += 1LL * (prefix[n - 1][ch] - prefix[l1 - 1][ch]);
            answer += 1LL * prefix[r1][ch];
            l = l - l1 + n;
            r -= r1;
            int k = r - l;
            k /= n;
            answer += 1LL * k * prefix[n - 1][ch];
            printf("%lld\n", answer);
        }
    }
    return 0;
}

