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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<char>> v(3, vector<char>(3));

    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            cin >> v[i][j];
        }
    }
    map<char,bool> f;
    REP(i,0,26)
    {
        f['a' + i] = true;
    }
    ll r1 = 0, r2 = 0;
    REP(i, 0, 3)
    {
        char a, b, c;
        a = v[i][0];
        b = v[i][1];
        c = v[i][2];
        set<char> se;
        se.insert(a);
        se.insert(b);
        se.insert(c);
        if (se.size() == 1)
        {
            r1++;
        }
        if (se.size() == 2)
        {
            f[a] = false;
            f[b] = false;
            f[c] = false;
            r2++;
        }
    }
    REP(j, 0, 3)
    {
        char a, b, c;
        a = v[0][j];
        b = v[1][j];
        c = v[2][j];
        set<char> se;
        se.insert(a);
        se.insert(b);
        se.insert(c);
        if (se.size() == 1)
        {
            r1++;
        }
        if (se.size() == 2)
        {
            if (f[a] && f[b] && f[c])
            {
                r2++;
            }
            f[a] = false;
            f[b] = false;
            f[c] = false;
        }
    }
    char a, b, c;
    a = v[0][0];
    b = v[1][1];
    c = v[2][2];
    set<char> se;
    se.insert(a);
    se.insert(b);
    se.insert(c);
    if (se.size() == 1)
    {
        r1++;
    }
    if (se.size() == 2)
    {
        if (f[a] && f[b] && f[c])
        {
            r2++;
        }
        f[a] = false;
        f[b] = false;
        f[c] = false;
    }
    a = v[0][2];
    b = v[1][1];
    c = v[2][0];
    se.clear();
    se.insert(a);
    se.insert(b);
    se.insert(c);
    if (se.size() == 1)
    {
        r1++;
    }
    if (se.size() == 2)
    {
        if (f[a] && f[b] && f[c])
        {
            r2++;
        }
        f[a] = false;
        f[b] = false;
        f[c] = false;
    }
    cout << r1 << endl
         << r2 << endl;
    return 0;
}
