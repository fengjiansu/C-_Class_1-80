#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin >> n;
    /* 
    n阶楼梯 每次可以走1,2,3,4步 问有多少种走法
     */

    // 递推
    int f[100];
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    f[4] = 8;
    for (int i = 5; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4];
    }
    cout << f[n];

    return 0;
}


