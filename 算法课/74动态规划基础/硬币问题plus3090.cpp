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

/*

coins={1 2 5}  n = 12
按照贪心算法 选择最大的 2个5 1个 2
{1,3,4} n=6   最优解是 两个 3
贪心选择最大的 4 和 1  1 三个3

 */
const int N = 1e5 + 5;
const int inf = 1e9;
bool vis[N]; // 判断dp[i]是否计算过
int dp[N];   //
int f[N];    // 当总价为n时,最优解选择的第一个硬币是
vi coins;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    coins.resize(n);
    REP(i, 0, n)
    {
        cin >> coins[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= s; i++)
    {
        dp[i] = inf;
        for (auto c : coins)
        {
            if (i - c >= 0 && dp[i-c]+1<dp[i])
            {
                dp[i] =  dp[i - c] + 1;
                f[i] = c;
            }
        }
    }
    if (dp[s] == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[s] << endl;
        while (s > 0)
        {
            cout << f[s] << " ";
            s -= f[s];
        }
    }
    return 0;
}
