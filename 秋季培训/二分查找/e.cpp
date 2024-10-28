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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    REP(i, 0, m)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    REP(i, 0, n)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll res = 0;
    REP(i, 0, n)
    {
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if (it == a.end())
        {
            res += b[i] - a[a.size() - 1];
        }
        else
        {
            if (it != a.begin())
            {
                auto pre = prev(it);
                res += min(b[i] - *pre, *it - b[i]);
            }
            else
            {
                res += *it - b[i];
            }
        }
    }
    cout << res << endl;
    return 0;
}
