#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
const int N = 1e5 + 5;
const int inf = 1e9;

int dp[N];               // dp[i] 表示凑成总价 i 所需的最小硬币数
vector<int> paths[N];    // paths[i] 存储凑成 i 的所有可能方案
vi coins;                // 硬币面值集合

void print_all_solutions(int s, vector<int> &current, vector<vector<int>> &results) {
    if (s == 0) {
        results.push_back(current); // 如果总金额为 0，记录当前方案
        return;
    }
    for (int c : paths[s]) {
        current.push_back(c);       // 选择当前硬币
        print_all_solutions(s - c, current, results); // 递归求解剩余金额
        current.pop_back();         // 回溯
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    fill(dp, dp + N, inf); // 初始化 dp 数组为无穷大
    dp[0] = 0;             // 凑成金额 0 需要 0 个硬币

    for (int i = 1; i <= s; i++) {
        for (int c : coins) {
            if (i - c >= 0 && dp[i - c] + 1 <= dp[i]) {
                if (dp[i - c] + 1 < dp[i]) {
                    dp[i] = dp[i - c] + 1; // 更新最小硬币数
                    paths[i].clear();     // 清空旧方案
                }
                paths[i].push_back(c);    // 添加当前硬币到方案中
            }
        }
    }

    if (dp[s] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[s] << endl;

        // 收集所有方案
        vector<vector<int>> results;
        vector<int> current;
        print_all_solutions(s, current, results);

        // 输出所有方案
        for (const auto &res : results) {
            for (int c : res) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
