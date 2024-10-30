#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
vector<pair<ll, bool>> vp;
bool check(ll d)
{
    for (auto &seg : vp)
    {
        ll f = seg.F;     // 感染段的长度
        ll g = 2 * d + 1; // 传播范围
        if (seg.S)        // 边界感染段
        {
            if (g > 2 * f - 1)
                return false;
        }
        else // 非边界感染段
        {
            if (g > f)
                return false;
        }
    }
    return true;
}

int main()
{
    ll N;
    cin >> N;
    string str;
    cin >> str;
    /*
    预处理：

将输入的字符串 s 末尾添加一个 '0'，方便处理。
遍历字符串 s，将连续的 '1' 段记录下来，存入 v 向量中。
v 中的每个元素是一个 pair<int, int>，其中：
first 表示连续 '1' 段的长度 f。
second 表示该段是否在字符串的边界（1 表示在边界，0 表示不在）
     */
    str += '0';
    ll cnt = 0;
    REP(i, 0, N + 1)
    {
        if (str[i] == '1')
        {
            cnt++;
        }
        else
        {
            bool atBoundary = (i - cnt == 0) || (i == N);
            vp.PB(MP(cnt, atBoundary));
            cnt = 0;
        }
    }
    sort(vp.begin(), vp.end());
    ll l = 0, r = vp[0].F - 1; // 传播距离 ?最大不超过最短感染段的长度减一，否则无法覆盖最短的感染段。
    ll res = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    // 计算最小初始感染者人数
    ll ans = 0;
    if (res == -1)
    {
        // 无法覆盖所有感染段
        cout << -1 << endl;
        return 0;
    }
    else
    {
        ll g = 2 * res + 1;
        for (auto &seg : vp)
        {
            ll f = seg.F;                // 感染段长度
            ll needed = (f + g - 1) / g; // 等价于 ceil(1.0 * f / g)
            ans += needed;
        }
        cout << ans << endl;
    }

    return 0;
}
