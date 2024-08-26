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
    vi v;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 1)
        {
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ",";
        }
    }
    return 0;
}
