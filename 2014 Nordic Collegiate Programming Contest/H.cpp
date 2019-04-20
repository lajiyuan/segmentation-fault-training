#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 4e5+10;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
int a[maxn],b[maxn];
int c[maxn],d[maxn];
int getMin(int s[400010],int n)
{
    int i=0,j=1,k=0,t;
    while(i<n&&j<n&&k<n) if(t=s[(i+k)%n]-s[(j+k)%n])
    {
        if(t>0) i+=k+1;else j+=k+1;
        if(i==j) j++;
        k=0;
    }
    else k++;
    return i<j?i:j;
}
vector<int> ans1,ans2;
int main()
{
    //freopen("H.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n-1;i++) c[i-1]=a[i+1]-a[i];
    c[n-1]=360000-a[n]+a[1];
    for(int i=1;i<=n-1;i++) d[i-1]=b[i+1]-b[i];
    d[n-1]=360000-b[n]+b[1];

    for(int i=0;i<n;i++) c[i+n]=c[i];
    for(int j=0;j<n;j++) d[j+n]=d[j];

//
//    for(int i=0;i<n;i++) dbg2(i,c[i]);
//    for(int i=0;i<n;i++) dbg2(i,d[i]);
    int pos1=getMin(c,n);
    int pos2=getMin(d,n);
   // dbg2(pos1,pos2);

    for(int i=pos1;i<n;i++) ans1.push_back(c[i]);
    for(int i=0;i<pos1;i++) ans1.push_back(c[i]);

    for(int i=pos2;i<n;i++) ans2.push_back(d[i]);
    for(int i=0;i<pos2;i++) ans2.push_back(d[i]);

    for(int i=0;i<ans1.size();i++)
    {
        if(ans1[i]!=ans2[i])
        {
            puts("impossible");
            return 0;
        }
    }
    puts("possible");
    return 0;
}


