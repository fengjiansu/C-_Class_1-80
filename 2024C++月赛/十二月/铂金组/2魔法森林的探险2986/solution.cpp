#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int n, int c, int dist) {
    int count = 1;  // 先放置第一头牛
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

    sort(stalls.begin(), stalls.end());  // 排序

    int left = 1, right = stalls[n-1] - stalls[0];  // 最小距离为 1，最大距离为最大坐标差
    int best_dist = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, n, c, mid)) {
            best_dist = mid;
            left = mid + 1;  // 尝试更大的距离
        } else {
            right = mid - 1;  // 尝试更小的距离
        }
    }

    cout << best_dist << endl;
    return 0;
}
