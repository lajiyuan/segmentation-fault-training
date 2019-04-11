#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

#define dbg(x) cout<<#x<<" = "<<x<<endl
#define Fi first
#define Se second
const int maxn =4e5+10;
struct data
{
    int l,r,val;
    int id;
    bool operator <( const data &b)const
    {
        if(l==b.l) return r<b.r;
        return l<b.l;
    }
}x[maxn];
struct T
{
    int l,r,mid;
    int id;
}tree[maxn<<2];
pll ans[maxn];
void push_up(int rt)
{
    int lid=tree[rt<<1].id;
    int rid=tree[rt<<1|1].id;
    if(ans[lid].first>ans[rid].first)
    {
        tree[rt].id=lid;
    }
    else if(ans[lid].first==ans[rid].first)
    {
        if(ans[lid].second<ans[rid].second)
        {
            tree[rt].id=lid;
        }
        else tree[rt].id=rid;
    }
    else tree[rt].id=rid;
}
void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].id=-1;
    if(l==r) return ;
    int mid=tree[rt].mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void update(int rt,int pos,ll val,int t,int id)
{
    if(tree[rt].l==tree[rt].r)
    {
        if(val>ans[tree[rt].id].Fi||(val==ans[tree[rt].id].Fi&&t<ans[tree[rt].id].Se))
        {
            tree[rt].id=id;
        }
        return ;
    }
    if(tree[rt].mid>=pos) update(rt<<1,pos,val,t,id);
    else update(rt<<1|1,pos,val,t,id);
    push_up(rt);
}
int query(int rt,int l,int r)
{
    if(tree[rt].l>r||tree[rt].r<l) return -1;
    if(tree[rt].l>=l&&tree[rt].r<=r) return tree[rt].id;
    int anst=-1;
    if(tree[rt].mid>=l) anst=query(rt<<1,l,r);
    if(tree[rt].mid<r)
    {
        int res=query(rt<<1|1,l,r);
        if(res==-1) return anst;
        if(ans[anst].Fi<ans[res].Fi||(ans[anst].Fi==ans[res].Fi&&ans[anst].Se>ans[res].Se))
            anst=res;
    }
    return anst;
}
int Hash[maxn];
int pre[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x[i].l,&x[i].r,&x[i].val);
        x[i].id=i;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        Hash[++cnt]=x[i].l;
        Hash[++cnt]=x[i].r;
    }
    sort(Hash+1,Hash+1+cnt);
    int d=unique(Hash+1,Hash+1+cnt)-Hash-1;
    sort(x+1,x+1+n);
    build(1,1,d);
    int pos=-1;
    pll res=pll(-1,-1);
    for(int i=1;i<=n;i++)
    {
        int l=lower_bound(Hash+1,Hash+1+d,x[i].l)-Hash;
        int r=lower_bound(Hash+1,Hash+1+d,x[i].r)-Hash;
        int tmp=query(1,1,l);
        int id=x[i].id;
        if(tmp==-1)
        {
            ans[id].first=x[i].val;
            ans[id].second=x[i].r-x[i].l;
            pre[id]=x[i].id;
        }
        else
        {
            pre[id]=tmp;
            ans[id].Fi=ans[tmp].Fi+x[i].val;
            ans[id].Se=ans[tmp].Se+x[i].r-x[i].l;
        }
        update(1,r,ans[id].Fi,ans[id].Se,x[i].id);
        if(ans[id].Fi>res.Fi||(ans[id].Fi==res.Fi&&ans[id].Se<res.Se))
        {
            pos=id;
            res=ans[id];
        }
    }
    vector<int> tmp;
    tmp.push_back(pos);
    while(pos!=pre[pos])
    {
        pos=pre[pos];
        tmp.push_back(pos);
    }
    printf("%d %lld %lld\n",(int)tmp.size(),res.Fi,res.Se);
    sort(tmp.begin(),tmp.end());
    for(int i=0;i<tmp.size();i++) printf("%d ",tmp[i]);
    return 0;
}
