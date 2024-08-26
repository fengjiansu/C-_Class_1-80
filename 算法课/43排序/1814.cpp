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
    int n;
    cin >> n;
    vi a;
    REP(i, 0, n)
    {
        int x;
        cin >> x;
        a.PB(x);
    }
    vi b(n);
    REP(i, 1, n)
    {
        // 负数有可能超出范围
        int j = min(abs(a[i] - a[i - 1]), n - 1);
        b[j]++;
    }
    bool flag = true;
    REP(i, 1, n)
    {
        if (b[i] == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Jolly" << "\n";
    }
    else
    {
        cout << "Not jolly";
    }
    return 0;
}
