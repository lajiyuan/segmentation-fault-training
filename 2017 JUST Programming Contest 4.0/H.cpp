#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e6+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl

char matrix[55][55];

int main()
{
    int t, n, m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        int inner = 0, outer = 0;
        for(int i = 1; i <= n; i++) scanf("%s", matrix[i] + 1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i == 1 || i == n || j == 1 || j == m)
                {
                    outer += (matrix[i][j] == '0');
                }
                else inner += (matrix[i][j] == '1');
            }
        }
        if(outer > inner)   printf("-1\n");
        else                printf("%d\n", outer);
    }
    return 0;
}


