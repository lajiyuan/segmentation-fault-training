#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<math.h>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn =1e5+10;
const double eps = 0.00001;
#define Fi first
#define Se second
#define pb push_back
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
    double dis(Point &p)
    {
        return hypot(x-p.x,y-p.y);
    }
};
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    return 1;
}
double solve(Point s1,Point e1,Point s2,Point e2)
{
    double A = (e2.x-s2.x-e1.x+s1.x)*(e2.x-s2.x-e1.x+s1.x)+(e2.y-s2.y-e1.y+s1.y)*(e2.y-s2.y-e1.y+s1.y);
    double B = (e2.x-s2.x-e1.x+s1.x)*(s2.x-s1.x)+(e2.y-s2.y-e1.y+s1.y)*(s2.y-s1.y);
    double C = (s2.x-s1.x)*(s2.x-s1.x)+(s2.y-s1.y)*(s2.y-s1.y);
    if(sgn(A)==0)
    {
        if(sgn(B)<0) return sqrt(C);
        else return sqrt(2.0*B+C);
    }
    double t = -B/A;
    if(sgn(t)<=0) t = 0;
    if(sgn(t-1)>=0) t = 1;
    return sqrt(A*t*t+2.0*B*t+C);
}
Point Y(Point a,Point b,double x)
{
    double dis=a.dis(b);
    double rate=x/dis;
    double px = a.x+(b.x-a.x)*rate;
    double py = a.y+(b.y-a.y)*rate;
    return Point(px,py);
}
Point s1[maxn],s2[maxn];
int main()
{
    freopen("K-2.in","r",stdin);
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&s1[i].x,&s1[i].y);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%lf%lf",&s2[i].x,&s2[i].y);
    int pos1=1,pos2=1;
    double ans=1e18;
    while(pos1<n&&pos2<m)
    {
        double dis1 = s1[pos1].dis(s1[pos1+1]);
        double dis2 = s2[pos2].dis(s2[pos2+1]);
       // dbg2(pos1,pos2);
        if(sgn(dis1-dis2)<0)
        {
            Point p = Y(s2[pos2],s2[pos2+1],dis1);
            ans=min(ans,solve(s1[pos1],s1[pos1+1],s2[pos2],p));
            s2[pos2]=p;
            pos1++;
        }
        else
        {
            Point p = Y(s1[pos1],s1[pos1+1],dis2);
            ans=min(ans,solve(s1[pos1],p,s2[pos2],s2[pos2+1]));
            s1[pos1]=p;
            pos2++;
        }
        if(sgn(ans)==0) break;
    }
    printf("%.20f\n",ans);
    return 0;
}
