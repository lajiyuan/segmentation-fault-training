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


