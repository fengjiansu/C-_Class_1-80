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
int dp[N];

vi coins;
int fun(int n)
{
    if(n<0) return inf; // ���ﲻ����INT_MAX ������+1�ᵼ��Խ������
    if (n == 0)
        return 0;
    if (vis[n])
        return dp[n];
    int res = inf;
    for (auto c : coins)
    {
        res = min(res, fun(n - c) + 1);
    }
    vis[n] = true;
    return dp[n] = res;
}
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
    if(fun(s)==inf)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout << fun(s) << endl;
    }
    return 0;
}
