#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int n, int c, int dist) {
    int count = 1;  // �ȷ��õ�һͷţ
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= dist) {
            count++;
            last_position = stalls[i];
            if (count == c) return true;
        }
    }

    return false;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());  // ����

    int left = 1, right = stalls[n-1] - stalls[0];  // ��С����Ϊ 1��������Ϊ��������
    int best_dist = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, n, c, mid)) {
            best_dist = mid;
            left = mid + 1;  // ���Ը���ľ���
        } else {
            right = mid - 1;  // ���Ը�С�ľ���
        }
    }

    cout << best_dist << endl;
    return 0;
}
