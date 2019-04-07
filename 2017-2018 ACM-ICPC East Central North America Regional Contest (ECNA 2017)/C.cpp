#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn =2e4+10;
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<<x<<endl
char input[maxn];
int main()
{
    //freopen("A-2.in","r",stdin);
    int n;
    scanf("%s", input + 1);
    n = strlen(input + 1);
    int sum = 0;
    for(int i = 1; i <= n / 2; i++)
    {
        sum += (input[i] - 'A');
    }
    for(int i = 1; i <= n / 2; i++)
    {
        int temp = input[i] - 'A';
        temp = (temp + sum) % 26;
        input[i] = temp + 'A';
    }
    sum = 0;
    for(int i = n / 2 + 1; i <= n; i++)
    {
        sum += (input[i] - 'A');
    }
    for(int i = n / 2 + 1; i <= n; i++)
    {
        int temp = input[i] - 'A';
        temp = (temp + sum) % 26;
        input[i] = temp + 'A';
    }
    for(int i = 1; i <= n / 2; i++)
    {
        int temp = input[i + n / 2] - 'A';
        int temp2 = input[i] - 'A';
        temp2 = (temp2 + temp) % 26;
        input[i] = temp2 + 'A';
        printf("%c", input[i]);
    }
    return 0;
}
