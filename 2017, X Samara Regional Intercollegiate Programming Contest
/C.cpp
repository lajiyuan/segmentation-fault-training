 #include<stdio.h>
 #include<iostream>
 #include<algorithm>
 #include<string.h>
 using namespace std;
 typedef long long ll;
 #define dbg(x) cout<<#x<<" = "<<x<<endl
 const int maxn =1e5+10;

 int main()
 {
     //freopen(".in","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int n1,m1;
    scanf("%d%d",&n1,&m1);
    int flag;
    if(n1==m1)
    {
        int ans;
        if(n>=m)
        {
            if(n+k<=n1)ans=n+k+m;
            else ans=n1;
        }
        else
        {
            if(m+k<=m1)ans=n+k+m;
            else ans=m1;
        }
        printf("%d\n",ans);
        return 0;
    }
    if(n1<m1)flag=0;
    else flag=1;
    int ans=0;
    if(flag==0)
    {
        if(n+k<=n1)
        {
            if(m+k<=m1)ans=n+k+m;
            else ans=m1;
            //ans=min(m1,n+k+min(m,m1));
        }
        else ans=n1;
    }
    else
    {
        if(m+k<=m1)
        {
            if(n+k<=n1)ans=n+k+m;
            else ans=n1;
            //ans=min(n1,m+k+min(n,n1));
        }
        else ans=m1;
    }
    printf("%d\n",ans);
     return 0;
 }

