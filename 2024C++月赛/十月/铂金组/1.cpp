#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;

long long a[MAXN], diff[MAXN];

// �������� [l, r] ���� d
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

    // ��ȡ��ʼ����ֵ����ʼ���������
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];  // ��ʼ���������
    }

    // ����ÿ������
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long d;
            cin >> l >> r >> d;
            update_range(l, r, d);  // ������������
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;

            // Ӧ�ò�������ȡ��ǰ������ֵ
            long long sum = 0;
            long long current_brightness = 0;

            for (int i = 1; i <= r; ++i) {
                current_brightness += diff[i];  // ͨ���ۼӲ������õ���ǰ����
                if (i >= l) {
                    sum += current_brightness;
                }
            }

            cout << sum << '\n';  // �������[l, r]�������ܺ�
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
