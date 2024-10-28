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
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    set<char> ss;
    for (auto &c : s)
    {
        ss.insert(c);
    }
    cin >> q;
 while (q--)
    {
        char a, b;
        cin >> a >> b;
        if (ss.find(a) != ss.end())
        {
            s.replace(s.find(a), 1, b);
        }
    }
    for (auto &c : ss)
    {
        cout << c;
    }
    return 0;
}
