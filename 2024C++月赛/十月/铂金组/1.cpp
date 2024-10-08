#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

long long a[MAXN], diff[MAXN];

// 更新区间 [l, r] 增加 d
void update_range(int l, int r, long long d) {
    diff[l] += d;
    if (r + 1 < MAXN) {
        diff[r + 1] -= d;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // 读取初始亮度值并初始化差分数组
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];  // 初始化差分数组
    }

    // 处理每个操作
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long d;
            cin >> l >> r >> d;
            update_range(l, r, d);  // 更新区间亮度
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;

            // 应用差分数组获取当前的亮度值
            long long sum = 0;
            long long current_brightness = 0;

            for (int i = 1; i <= r; ++i) {
                current_brightness += diff[i];  // 通过累加差分数组得到当前亮度
                if (i >= l) {
                    sum += current_brightness;
                }
            }

            cout << sum << '\n';  // 输出区间[l, r]的亮度总和
        }
    }

    return 0;
}
11/1/2024 3:00:00 PM
11/2/2024 3:00:00 PM
11/15/2024 3:00:00 PM
11/16/2024 3:00:00 PM
11/28/2024 3:00:00 PM
11/29/2024 3:00:00 PM
12/12/2024 3:00:00 PM
12/13/2024 3:00:00 PM
12/25/2024 3:00:00 PM
12/26/2024 3:00:00 PM
