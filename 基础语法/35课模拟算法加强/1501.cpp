#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
int f1(int x, int y) // 把y从x进制转换为10进制
{
    int ans = 0;
    int t = 1;
    while (y)
    {
        // 重复取最后一位数字 乘以当前位权 累加起来
        // 位权t通过不断乘以x
        ans += (y % 10) * t;
        t *= x;
        y /= 10;
    }
    return ans;
}
int fun2(int x, int y) // 把y从10进制转换为x进制
{
    int ans = 0;
    int t = 1;
    while (y)
    {
        ans += (y % x) * t;
        t *= 10;
        y /= x;
    }
    return ans;
}
void solve()
{
    int  f, x, y;
    cin >> f >> x >> y;
    if (f == 1)
    {
        cout << fun1(x, y) << endl;
    }
    else if (f == 0)
    {
        cout << fun2(x, y) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
