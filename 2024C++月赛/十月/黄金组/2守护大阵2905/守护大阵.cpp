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
    // �����һ�к����һ�е�Ԫ��֮��
    for (int j = 0; j < n; ++j) {
        sum += matrix[0][j];
        if (m > 1) {
            sum += matrix[m - 1][j];
        }
    }

    // �����һ�к����һ�е�Ԫ��֮�ͣ��ų��Ѿ�������Ľ��䣩
    for (int i = 1; i < m - 1; ++i) {
        sum += matrix[i][0];
        if (n > 1) {
            sum += matrix[i][n - 1];
        }
    }

    cout << sum << endl;
    return 0;
}