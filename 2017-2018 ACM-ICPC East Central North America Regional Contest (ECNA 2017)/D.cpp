#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include <stack>
using namespace std;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
stack <int> st;
int strtoint(char * str)
{
    int length = strlen(str);
    int res = 0;
    bool isneg = false;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == '-')
        {
            isneg = true;
            continue;
        }
        res = res * 10 + (str[i] - '0');
    }
    if(isneg)   return -res;
    else        return res;
}
int main()
{
    //freopen("D-1.in", "r", stdin);
    int n, k;
    char op[20];
    scanf("%d%d", &n, &k);
    int pos = 0;

    while(k--)
    {
        scanf("%s", op);
        if(op[0] == 'u')
        {
            scanf("%s", op);
            int cnt = strtoint(op);
            while(!st.empty() && cnt)
            {
                int cur = st.top();
                st.pop();
                pos = (pos - cur + n) % n;
                cnt--;
            }
        }
        else
        {
            int cnt = strtoint(op);
            if(cnt < 0)
            {
                int delta = 0 - cnt;
                int k = delta / n;
                cnt += k * n;
            }
            if(cnt < 0) cnt += n;
            pos = (pos + cnt) % n;
            st.push(cnt % n);
        }
    }

    printf("%d\n", pos);

    return 0;
}

