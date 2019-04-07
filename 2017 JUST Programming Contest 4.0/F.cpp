#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<unordered_map>
using namespace std;
typedef pair<int,int> pii;
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ok cout<<"OK"<<endl
const int maxn = 1e4+10;
struct T
{
    int l,r,mid;
    int maxx,id;
}tree[maxn<<2];
int a[maxn];
void push_up(int rt)
{
    if(tree[rt<<1].maxx>=tree[rt<<1|1].maxx)
    {
        tree[rt].maxx=tree[rt<<1].maxx;
        tree[rt].id=tree[rt<<1].id;
    }
    else
    {
        tree[rt].maxx=tree[rt<<1|1].maxx;
        tree[rt].id=tree[rt<<1|1].id;
    }
    return ;
}
void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].maxx=a[l];
        tree[rt].id=l;
        return ;
    }
    int mid=tree[rt].mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
pii query(int rt,int l,int r)
{
    if(tree[rt].l>r||tree[rt].r<l) return pii(-1,0);
    if(tree[rt].l>=l&&tree[rt].r<=r) return pii(tree[rt].maxx,tree[rt].id);
    pii ans1,ans2;
    if(tree[rt].mid>=l) ans1=query(rt<<1,l,r);
    if(tree[rt].mid<r) ans2=query(rt<<1|1,l,r);
    if(ans1.first>=ans2.first) return ans1;
    else return ans2;
}
char Ma[maxn*2];
int Mp[maxn*2];
int manacher(char s[],int len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
    int ans=0;
   // for(int i=0;i<2*len+2;i++) dbg2(i,Mp[i]);
    for(int i=0;i<2*len+2;i++)
    {
        Mp[i]--;
        if(i%2==0) ans=ans+((Mp[i]+1)/2);
        else ans=ans+Mp[i]/2;
      //  ans=ans+Mp[i];
    }
    return ans;
}
char str[50],str2[50];
unordered_map<string,int> mp;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            int le=strlen(str);
            a[i]= manacher(str,le);
            string tt=str;
           // dbg2(tt,a[i]);
            mp[tt]=i;
        }
        build(1,1,n);
        while(q--)
        {
            scanf("%s%s",str,str2);
            string tt=str,tt2=str2;;
            int pos1=mp[tt];
            int pos2=mp[tt2];
            if(pos1>pos2) swap(pos1,pos2);
            pii ans = query(1,pos1,pos2);
            printf("%d\n",ans.second);
        }
    }
    return 0;
}

