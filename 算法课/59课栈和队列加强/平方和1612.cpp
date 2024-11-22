#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0; // 左边界
    long long cur = 0; // 当前窗口平方和
    vector<pair<int, int>> res; // 存储结果区间

    for (int r = 0; r < n; r++) { // 右边界遍历
        cur += a[r] * a[r]; // 加入右边界的平方

        // 当平方和超过 k 时，缩小窗口
        while (cur > k && l <= r) {
            cur -= a[l] * a[l];
            l++;
        }

        // 如果刚好等于 k，记录当前区间
        if (cur == k) {
            res.emplace_back(l + 1, r + 1); // 1-based 索引
        }
    }

    // 按照右端点排序
    sort(res.begin(), res.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second < y.second;
    });

    // 输出结果
    for (const auto& p : res) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

