#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl

#define mpp make_pair
string name[20];

string input;

queue <string> que;

vector <pair<string, string> > ans;

bool isok[1005];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        cin >> name[i];
        if(i>=5)que.push(name[i]);
    }

    cin >> input;
    int length = input.length();
    int cnt = 0;
    int maxvalue = 0;
    string wf[2],ws[2],bf[2],bs[2];
    wf[0]=wf[1]=name[1];
    ws[0]=ws[1]=name[3];
    bf[0]=bf[1]=name[2];
    bs[0]=bs[1]=name[4];
    char la='.';
    for(int i = 0; i < length; i++)
    {
        if(input[i]=='W')
        {
            swap(wf[0],ws[0]);
            string s1=que.front();
            que.pop();
            que.push(bs[0]);
            bs[0]=bf[0];
            bf[0]=s1;
            bf[1]=bs[0];
            bs[1]=bf[0];
            if(input[i]==la)
            {
                cnt++;
            }
            else
            {
                cnt=1;
                la=input[i];
            }
            if(cnt>maxvalue)
            {
                ans.clear();
                ans.push_back(mpp(wf[1],ws[1]));
                maxvalue=cnt;
            }
            else if(cnt==maxvalue)
            {
                ans.push_back(mpp(wf[1],ws[1]));
            }
        }
        else
        {
            swap(bf[0],bs[0]);
            string s1=que.front();
            que.pop();
            que.push(ws[0]);
            ws[0]=wf[0];
            wf[0]=s1;
            wf[1]=ws[0];
            ws[1]=wf[0];
            if(input[i]==la) cnt++;
            else
            {
                cnt=1;
                la=input[i];
            }
            if(cnt>maxvalue)
            {
                ans.clear();
                ans.push_back(mpp(bf[1],bs[1]));
                maxvalue=cnt;
            }
            else if(cnt==maxvalue)
            {
                ans.push_back(mpp(bf[1],bs[1]));
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        auto cur = ans[i];
        cout << cur.first << " " << cur.second << endl;
    }

    return 0;
}

