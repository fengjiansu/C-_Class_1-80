/*********************************
C. 装球问题
描述
（1）n个有区别的球放到m个相同的盒子中，要求无一空盒，不同的方案总数有多少种？（第二类斯特林数）

（2）n个无区别的球放到m个相同的盒子中，可以有空盒，不同的方案总数有多少种？

输入
输入n和m，n,m≤10^3
输出
一行用空格隔开输出两个小问的答案，答案对10^9+7取模
样例
输入
8 5
输出
1050 18
***********************************/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

const int MOD = 1e9 + 7;
const int MAXN = 1005;

// 斯特林数 S(n, m)
long long S[MAXN][MAXN];
// dp 数组用于存储无区别的球的划分数
long long dp[MAXN][MAXN];

// 计算斯特林数
void compute_sterling() {
    // 初始化斯特林数
    S[0][0] = 1;
    for (int n = 1; n < MAXN; ++n) {
        for (int m = 1; m <= n; ++m) {
            S[n][m] = (S[n-1][m-1] + m * S[n-1][m] % MOD) % MOD;
        }
    }
}

// 计算无区别的球放入相同的盒子的方案数
void compute_partitions() {
    // 初始化
    for (int i = 0; i < MAXN; ++i) {
        dp[i][0] = 1; // 0 个球可以分为 1 种方案（空划分）
    }
    for (int n = 1; n < MAXN; ++n) {
        for (int m = 1; m <= n; ++m) {
            dp[n][m] = (dp[n-1][m-1] + dp[n-m][m]) % MOD;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 预计算斯特林数
    compute_sterling();
    // 预计算无区别球的划分数
    compute_partitions();

    // 第一问答案：n 个有区别的球放入 m 个盒子，无空盒
    cout << S[n][m] << " ";

    // 第二问答案：n 个无区别的球放入最多 m 个盒子，可有空盒
    cout << dp[n][m] << endl;

    return 0;
}
