 #include<stdio.h>
 #include<iostream>
 #include<algorithm>
 #include<string.h>
 #include <stack>
 using namespace std;
 typedef long long ll;
 typedef pair<int, int> pii;
 #define dbg(x) cout<<#x<<" = "<<x<<endl
 const int maxn = 2e5+10;
 ll a[maxn];
 stack <pii> st;
 int main()
 {
     //freopen(".in","r",stdin);
     int n;
     scanf("%d", &n);

     ll sum = 0;
     for(int i = 1; i <= n; i++)
     {
        scanf("%lld", &a[i]);
        sum += a[i];
     }

     if(sum > n - 1)
     {
         printf("NO\n");
         return 0;
     }

     int id = 2;
     for(int i = 1; i <= n; i++)
     {
        for(int j = 1; j <= a[i]; j++)
        {
            st.push(pii(i, id));
            id++;
        }
     }

     printf("YES\n");
     while(!st.empty())
     {
         pii cur = st.top();
         st.pop();
         printf("%d %d\n", cur.first, cur.second);
     }

     return 0;
 }
