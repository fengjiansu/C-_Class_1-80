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
const int N = 1e5 + 5;
const int INF = 1e9;
int r[N][N];
int dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> r[i][j];
        }
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + r[j][i]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}
