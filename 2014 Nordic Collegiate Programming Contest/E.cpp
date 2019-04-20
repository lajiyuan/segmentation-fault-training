#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl

int a[maxn], cnt[10 * maxn], prefix[10 * maxn];

int main()
{
    //freopen("E-2.cpp","r",stdin);

    int n;
    scanf("%d", &n);

    int left = 0x3f3f3f3f, right = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        left = min(left, a[i]);
        right = max(right, a[i]);
    }

    for(int i = 1; i <= right; i++) prefix[i] = prefix[i - 1] + cnt[i];
    int answer = 0x3f3f3f3f;
    for(int i = 0; i <= right; i++)
    {
        int temp = i;
        temp += prefix[right] - prefix[i];
        answer = min(answer, temp);
    }

    printf("%d\n", answer);

    return 0;
}
