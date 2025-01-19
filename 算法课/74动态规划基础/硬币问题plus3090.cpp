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
����̰���㷨 ѡ������ 2��5 1�� 2
{1,3,4} n=6   ���Ž��� ���� 3
̰��ѡ������ 4 �� 1  1 ����3

 */
const int N = 1e5 + 5;
const int inf = 1e9;
bool vis[N]; // �ж�dp[i]�Ƿ�����
int dp[N];   //
int f[N];    // ���ܼ�Ϊnʱ,���Ž�ѡ��ĵ�һ��Ӳ����
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
