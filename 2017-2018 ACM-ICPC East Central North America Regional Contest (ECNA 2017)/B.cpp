#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 2e6+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
const  double eps = 1e-12;
const  double inf = 1e20;
const  double pi = acos(-1.0);
const int maxp = 2e6+10;
int sgn( double x)
{
    if (fabs(x) <eps) return 0;
    if(x <0) return -1;
    return 1;
}
inline  double sqr( double x)
{
    return x * x;
}
struct Point
{
    double x, y;
    Point() {}
    Point ( double _x,  double _y)
    {
        x = _x, y = _y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        cout <<"x= "<<x << " y= " << y << endl;
    }
    bool operator == (Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (Point b) const
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    Point operator - (const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    //叉积  |a||b|sin
    double  operator ^ (const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    //点积 |a||b|cos 向量点积之后反过来求夹角
    double  operator * (const Point & b) const
    {
        return x * b.x + y * b.y;
    }
    //利用库函数计算点到(0,0)的距离
    double  len()
    {
        return hypot(x, y);
    }
    //返回长度的平方
    double  len2()
    {
        return x * x + y * y;
    }
    //返回两点间距离
    double  distance(Point p)
    {
        return hypot(x - p.x, y - p.y);
    }
    //向量加法
    Point operator + (const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    //向量乘常数
    Point operator * (const double  &k) const
    {
        return Point(x * k, y * k);
    }
    //向量除以常数
    Point operator / (const double  &k) const
    {
        return Point (x / k, y / k);
    }
    //求a,b以当前点为中间点的角
    double  rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2( fabs((a - p) ^ (b - p)), (a - p) * (b - p) ));
    }
    //转换为长度为r的向量
    Point trunc(double  r)
    {
        double  l = len();
        if (!sgn(l)) return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    //绕点p逆时针旋转angle度，angle是弧度制
    Point rotat(Point p,double angle)
    {
        Point v=(*this)-p;
        double c=cos(angle),s=sin(angle);
        return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
struct Line
{
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s, e = _e;
    }
    //直线判断重合
    bool operator == (Line v)
    {
        return (s == v.s) && (e == v.e);
    }
    //根据一个点和倾斜角angle确定直线，0<=angle<pi
    Line (Point p, double  angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
            e = (s + Point (0, 1));
        else
            e = (s + Point (1, tan(angle)));
    }
    //ax+by+c确定直线
    Line(double  a, double  b, double  c)
    {
        if (sgn(a) == 0)
        {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        }
        else if (sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, (-c-a) / b);
        }
    }
    //得到s-e方向单位向量
    Point getV()
    {
        return e-s;
    }
    void input()
    {
        s.input();
        e.input();
    }
    void adjust()
    {
        if (e < s) swap(s, e);
    }
    //返回线段的长度
    double  length()
    {
        return s.distance(e);
    }
    //返回直线倾斜角
    double  angle()
    {
        double  k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0) k += pi;
        if (sgn(k - pi) == 0) k -= pi;
        return k;
    }
    //点和直线关系
    //1  在左侧
    //2  在右侧
    //3  在直线上
    int relation(Point p)
    {
        int c = sgn( (p - s) ^ (e - s) );
        if (c < 0) return 1;
        else if (c > 0) return 2;
        return 3;
    }
    //点在线段上的判断
    bool pointonseg(Point p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    //判断量直线平行或重合
    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    //两线段相交判断
    //2 规范相交
    //1 非规范相交-过端点
    //0 不相交
    int segcrossseg(Line v)
    {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if((d1^d2)==-2&&(d3^d4)==-2) return 2;
        return ((d1==0&&sgn((v.s-s)*(v.s-e))<=0)||(d2==0&&sgn((v.e-s)*(v.e-e))<=0)||(d3==0&&sgn((s-v.s)*(s-v.e))<=0)||(d4==0&&sgn((e-v.s)*(e-v.e))<=0));
    }
    Point lineprog(Point p)
    {
        return s + ( ((e - s) * ((e - s) * (p - s))) / ((e - s).len2()) );
    }
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2.0 * q.x - p.x, 2.0 * q.y - p.y);
    }
    double  dispointtoline(Point p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }
    double  dispointtoseg(Point p)
    {
        if (sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    //两直线关系
    //0 平行
    //1 重合
    //2 相交
    int linecrossline(Line v)
    {
        if((*this).parallel(v)) return v.relation(s)==3;
        return 2;
    }
    Point crosspoint(Line v)
    {
        double a1=(v.e-v.s)^(s-v.s);
        double a2=(v.e-v.s)^(e-v.s);
        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
};
struct circle
{
    Point p;
    double  r;
    circle() {}
    circle(Point _p, double  _r)
    {
        p = _p, r = _r;
    }
    circle (double  x, double  y, double  _r)
    {
        p = Point(x, y), r = _r;
    }
    void input()
    {
        p.input();
        scanf ("%lf", &r);
    }
    bool operator == (circle v)
    {
        return p == v.p && sgn(r - v.r) == 0;
    }
    bool operator < (circle v) const
    {
        return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));
    }
    //点与圆的关系 0--圆外，1--圆上，2--圆内
    int relation(Point b)
    {
        double dst = b.distance(p);
        if(sgn(dst-r)<0) return 2;
        else if(sgn(dst-r)==0) return 1;
        return 0;
    }
    int relationseg(Line v)
    {
        double  dst = v.dispointtoseg(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    int relationline(Line v)
    {
        double  dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0) return 2;
        else if (sgn(dst - r) == 0) return 1;
        return 0;
    }
    //求直线与圆的交点，返回交点个数
    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v)) return 0;
        Point a = v.lineprog(p);
        double  d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
    //与其他圆的关系
    //5.相离
    //4.外切
    //3.相交
    //2.内切
    //1.内含
    int relationcircle(circle v)
    {
        double d = p.distance(v.p);
        if(sgn(d-r-v.r)>0) return 5;
        if(sgn(d-r-v.r)==0) return 4;
        double l = fabs(r-v.r);
        if(sgn(d-r-v.r)<0&&sgn(d-l)>0) return 3;
        if(sgn(d-l)==0) return 2;
        if(sgn(d-l)<0) return 1;
    }
};
struct polygon
{
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int _n)
    {
        n=_n;
        for(int i=0;i<n;i++) p[i].input();
    }
    void add(Point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        for(int i=0;i<n;i++)
        {
            l[i]=Line(p[i],p[(i+1)%n]);
        }
    }
    void norm()
    {
        Point mi=p[0];
        for(int i=1;i<n;i++) mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    struct cmp
    {
        Point p;
        cmp(const Point &p0){p=p0;}
        bool operator()(const Point &aa,const Point &bb)
        {
            Point a=aa,b=bb;
            int d=sgn((a-p)^(b-p));
            if(d==0) return sgn(a.distance(p)-b.distance(p))<0;
            return d>0;
        }
    };
    void Graham(polygon &convex)//convex为得到的凸包点集
    {
        norm();
        int &top=convex.n;
        top=0;
        if(n==1)
        {
            top=1;
            convex.p[0]=p[0];
            return ;
        }
        if(n==2)
        {
            top=2;
            convex.p[0]=p[0];
            convex.p[1]=p[1];
            if(convex.p[0]==convex.p[1]) top--;
            return ;
        }
        convex.p[0]=p[0];
        convex.p[1]=p[1];
        top=2;
        for(int i=2;i<n;i++)
        {
            while(top>1&&sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2]))<=0) top--;
            convex.p[top++]=p[i];
        }
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
    }
    // 上下扫描法求凸包
    void getconvex(polygon &convex)
    {
       // for(int i=0;i<n;i++) p[i].output();
        sort(p,p+n);
        convex.n=n;
        for(int i=0;i<min(n,2);i++) convex.p[i]=p[i];
        if(convex.n==2&&(convex.p[0] == convex.p[1])) convex.n--;
        if(n<=2) return ;
        int &top=convex.n;
        top=1;
        for(int i=2;i<n;i++)
        {
            while(top&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<0) top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for(int i=n-3;i>=0;i--)
        {
            while(top!=temp&&sgn((convex.p[top]-p[i])^(convex.p[top-1]-p[i]))<0) top--;
            convex.p[++top]=p[i];
        }
        if(convex.n==2&&(convex.p[0]==convex.p[1])) convex.n--;
    }
    //求面积之前先极角排序
    double getarea()//得到凸包的面积
    {
        norm();
        double sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(p[i]^p[(i+1)%n]);
        }
        return fabs(sum)/2.0;
    }
    //3 点上
    //2 边上
    //1 内部
    //0 外部
    int relationPoint(Point q)
    {
        for(int i=0;i<n;i++) if(p[i] == q) return 3;
        getline();
        for(int i=0;i<n;i++) if(l[i].pointonseg(q)) return 2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            int k=sgn((q-p[j])^p[i]-p[j]);
            int u=sgn(p[i].y-q.y);
            int v=sgn(p[j].y-q.y);
            if(k>0&&u<0&&v>=0) cnt++;
            if(k<0&&v<0&&u>=0) cnt--;
        }
        return cnt!=0;
    }
}vex,vex2;
circle O[maxn];
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) O[i].input();
    vex.n=0;
    double ang = (2.0*PI)/10000.0;
    for(int i=1;i<=n;i++)
    {
        Point tmp = Point (O[i].p.x,O[i].p.y+O[i].r+10.0);
        for(int j=0;j<=10000;j++)
        {
            vex.add(tmp);
            tmp = tmp.rotat(O[i].p,ang);
        }
    }
    vex.Graham(vex2);
    vex2.getline();
    double ans=0;
    for(int i=0;i<vex2.n;i++)
    {
        ans=ans+vex2.l[i].length();
    }
    printf("%.20f\n",ans);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
