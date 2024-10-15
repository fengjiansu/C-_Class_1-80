#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    // 计算第一行和最后一行的元素之和
    for (int j = 0; j < n; ++j) {
        sum += matrix[0][j];
        if (m > 1) {
            sum += matrix[m - 1][j];
        }
    }

    // 计算第一列和最后一列的元素之和（排除已经计算过的角落）
    for (int i = 1; i < m - 1; ++i) {
        sum += matrix[i][0];
        if (n > 1) {
            sum += matrix[i][n - 1];
        }
    }

    cout << sum << endl;
    return 0;
}