#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn =2e6+10;

#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
struct node
{
    int x1,y1;
    int x2,y2;
    node(){}
    node(int x1,int y1,int x2,int y2)
    {
        this->x1=x1;
        this->y1=y1;
        this->x2=x2;
        this->y2=y2;
    }
};
int n,m,q;
node inst[maxn];
int num[1005][1005];
int root[maxn];
int Find(int x)
{
    return x==root[x]?x:root[x]=Find(root[x]);
}
set<int>ss;
int getnum(int i,int j)
{
    return m*(i-1)+j;
}
void solve(int u,int v,int i,int j)
{
    //cout<<u<<' '<<v<<' '<<i<<' '<<j<<endl;
    int fx=Find(getnum(u,v));
    if(num[i][j]==0)
    {
        int fx1=Find(getnum(i,j));
        int rt=min(fx,fx1);
        if(fx!=fx1)
        {
            root[fx+fx1-rt]=rt;
        }
    }
}
int ans[maxn];
int main()
{
    //freopen("A3.in","r",stdin);

    scanf("%d%d%d",&m,&n,&q);
    for(int i=1;i<=q;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        inst[i]=node(x1,y1,x2,y2);
        if(x1==x2)for(int j=y1;j<=y2;j++)num[x1][j]++;
        else if(y1==y2)for(int j=x1;j<=x2;j++)num[j][y1]++;
    }
    for(int i=0;i<=2000005;i++)root[i]=i;
    for(int i=0;i<=n;i++)num[i][0]=1;
    for(int i=0;i<=m;i++)num[0][i]=1;
    for(int i=0;i<=n+1;i++)num[i][m+1]=1;
    for(int i=0;i<=m+1;i++)num[n+1][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(num[i][j]==0)
            {
                solve(i,j,i-1,j);
                solve(i,j,i,j-1);
                solve(i,j,i+1,j);
                solve(i,j,i,j+1);
            }
        }
    }

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(num[i][j]==0)
    {
        //dbg3(i,j,Find(getnum(i,j)));

        ss.insert(Find(getnum(i,j)));
    }
    int cnt=ss.size();
    ans[q]=cnt;


    for(int i=q;i>=1;i--)
    {
        ss.clear();
        node p1=inst[i];
        int x1,y1,x2,y2;
        x1=p1.x1, x2=p1.x2, y1=p1.y1, y2=p1.y2;
        if(x1==x2)for(int j=y1;j<=y2;j++){
            if(num[x1-1][j]==0)ss.insert(Find(getnum(x1-1,j)));
            if(num[x1][j-1]==0)ss.insert(Find(getnum(x1,j-1)));
            if(num[x1+1][j]==0)ss.insert(Find(getnum(x1+1,j)));
            if(num[x1][j+1]==0)ss.insert(Find(getnum(x1,j+1)));
            //dbg3(x1,j,*ss.begin());
            //if(num[x1-1][j])ss.insert(Find(getnum(x1-1,j)));
        }
        else if(y1==y2)for(int j=x1;j<=x2;j++)
        {
            if(num[j-1][y1]==0)ss.insert(Find(getnum(j-1,y1)));
            if(num[j][y1-1]==0)ss.insert(Find(getnum(j,y1-1)));
            if(num[j+1][y1]==0)ss.insert(Find(getnum(j+1,y1)));
            if(num[j][y1+1]==0)ss.insert(Find(getnum(j,y1+1)));
            //num[j][y1]++;
        }
        int cnt1=ss.size();
        //dbg(*ss.begin());
        ss.clear();
        if(x1==x2)for(int j=y1;j<=y2;j++)
        {
            num[x1][j]--;
            if(num[x1][j]==0)
            {
                solve(x1,j,x1-1,j);
                solve(x1,j,x1,j-1);
                solve(x1,j,x1+1,j);
                solve(x1,j,x1,j+1);
            }
        }
        else if(y1==y2)for(int j=x1;j<=x2;j++)
        {
            num[j][y1]--;
            if(num[j][y1]==0)
            {
                solve(j,y1,j-1,y1);
                solve(j,y1,j,y1-1);
                solve(j,y1,j+1,y1);
                solve(j,y1,j,y1+1);
            }
        }

        if(x1==x2)for(int j=y1;j<=y2;j++){
                if(num[x1][j]==0)ss.insert(Find(getnum(x1,j)));
                if(num[x1-1][j]==0)ss.insert(Find(getnum(x1-1,j)));
                if(num[x1][j-1]==0)ss.insert(Find(getnum(x1,j-1)));
                if(num[x1+1][j]==0)ss.insert(Find(getnum(x1+1,j)));
                if(num[x1][j+1]==0)ss.insert(Find(getnum(x1,j+1)));
            //if(num[x1-1][j])ss.insert(Find(getnum(x1-1,j)));
        }
        else if(y1==y2)for(int j=x1;j<=x2;j++)
        {
            if(num[j][y1]==0)ss.insert(Find(getnum(j,y1)));
            if(num[j-1][y1]==0)ss.insert(Find(getnum(j-1,y1)));
            if(num[j][y1-1]==0)ss.insert(Find(getnum(j,y1-1)));
            if(num[j+1][y1]==0)ss.insert(Find(getnum(j+1,y1)));
            if(num[j][y1+1]==0)ss.insert(Find(getnum(j,y1+1)));
        }
        int cnt2=ss.size();
       // dbg3(cnt1,cnt2,cnt);
        cnt=cnt+cnt2-cnt1;
        ans[i-1]=cnt;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}

