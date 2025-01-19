#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
const int N = 1e5 + 5;
const int inf = 1e9;

int dp[N];               // dp[i] ��ʾ�ճ��ܼ� i �������СӲ����
vector<int> paths[N];    // paths[i] �洢�ճ� i �����п��ܷ���
vi coins;                // Ӳ����ֵ����

void print_all_solutions(int s, vector<int> &current, vector<vector<int>> &results) {
    if (s == 0) {
        results.push_back(current); // ����ܽ��Ϊ 0����¼��ǰ����
        return;
    }
    for (int c : paths[s]) {
        current.push_back(c);       // ѡ��ǰӲ��
        print_all_solutions(s - c, current, results); // �ݹ����ʣ����
        current.pop_back();         // ����
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

    fill(dp, dp + N, inf); // ��ʼ�� dp ����Ϊ�����
    dp[0] = 0;             // �ճɽ�� 0 ��Ҫ 0 ��Ӳ��

    for (int i = 1; i <= s; i++) {
        for (int c : coins) {
            if (i - c >= 0 && dp[i - c] + 1 <= dp[i]) {
                if (dp[i - c] + 1 < dp[i]) {
                    dp[i] = dp[i - c] + 1; // ������СӲ����
                    paths[i].clear();     // ��վɷ���
                }
                paths[i].push_back(c);    // ��ӵ�ǰӲ�ҵ�������
            }
        }
    }

    if (dp[s] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[s] << endl;

        // �ռ����з���
        vector<vector<int>> results;
        vector<int> current;
        print_all_solutions(s, current, results);

        // ������з���
        for (const auto &res : results) {
            for (int c : res) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
