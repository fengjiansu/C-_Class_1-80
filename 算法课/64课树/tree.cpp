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
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> p(n+1, -1);
    REP(i,2,n+1)
    {
        cin >> p[i];
    }
    int q;
    cin >> q;
    int a;
    while (q--)
    {
        cin >> a;
        if (a == 1)
        {
            cout << p[a]<<'\n'; //cout << '\n' << flush
            continue;
        }
        cout << p[p[a]] <<'\n';
    }
    return 0;
}
