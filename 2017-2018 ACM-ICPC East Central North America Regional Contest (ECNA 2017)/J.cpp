#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 1e5+5;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl

int jim[20][2];
int person[20][3];

int main()
{
    //freopen("J.in", "r", stdin);

    for(int i = 1; i <= 10; i++)
    {
        scanf("%d%d", &jim[i][0], &jim[i][1]);
    }

    for(int i = 1; i <= 10; i++)
    {
        scanf("%d%d%d", &person[i][0], &person[i][1], &person[i][2]);
    }

    int t = 0;
    for(int T = 1; T <= 3; T++)
    {
        for(int i = 1; i <= 10; i++)
        {
            if(t < person[i][2])
            {
                t += (jim[i][0] + jim[i][1]);
                person[i][2] = max(person[i][2], t - jim[i][1]);
            }
            else
            {
                int temp = t - person[i][2];
                temp = temp % (person[i][0] + person[i][1]);
                if(temp == 0)
                {
                    int delta = person[i][0] + jim[i][0] + jim[i][1];
                    person[i][2] = max(t + person[i][0] + person[i][1], t + delta - jim[i][1]);
                    t += delta;
                }
                else if(temp >= person[i][0])
                {
                    int delta = jim[i][0] + jim[i][1];
                    person[i][2] = max(t + (person[i][0] + person[i][1] - temp), t + delta - jim[i][1]);
                    t += delta;
                }
                else
                {
                    int delta = person[i][0] - temp + jim[i][0] + jim[i][1];
                    person[i][2] = max(t + person[i][0] - temp + person[i][1], t + delta - jim[i][1]);
                    t += delta;
                }
            }
        }
    }
    t -= jim[10][1];
    printf("%d\n", t);

    return 0;
}
/*题意
Jim要去健身房锻炼，健身房共有10个器械
对于Jim来说，使用第i个器械需要耗费t_i的时间，
使用完这个器械之后，他需要r_i的时间进行休息。
现在Jim要从1号器械按顺序使用到10号器械，且要进行三个回合。
每台器械，都有一个主人，在Jim不使用该机器的时候，循环使用它。
对于第i个器械的主人第一次开始使用它的时刻为S_i，每次使用耗费T_i的时间，
使用完这个器械之后，他需要R_i的时间进行休息。
如果Jim开始使用某个器械的时间与主人这一次开始使用这个器械的时间相同的话，
Jim会让这个器械的主人先用。
问Jim多长时间能完成健身（第三回合使用第10个器械后的休息时间不计）。


*/
/*做法
按顺序对三个回合进行计算，当Jim使用器械i时，计算当前时间t与S_i的差值delta，之后将delta对T_i+R_i进行取模。
这时，我们可以方便地判断主人使用该器械的状态（使用OR休息）。
之后，按照题意进行分类讨论，然后更新S_i和t。
最后的t减去r_{10}就是答案。

*/

