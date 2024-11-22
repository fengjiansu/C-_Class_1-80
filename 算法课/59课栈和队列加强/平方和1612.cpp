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

    int l = 0; // ��߽�
    long long cur = 0; // ��ǰ����ƽ����
    vector<pair<int, int>> res; // �洢�������

    for (int r = 0; r < n; r++) { // �ұ߽����
        cur += a[r] * a[r]; // �����ұ߽��ƽ��

        // ��ƽ���ͳ��� k ʱ����С����
        while (cur > k && l <= r) {
            cur -= a[l] * a[l];
            l++;
        }

        // ����պõ��� k����¼��ǰ����
        if (cur == k) {
            res.emplace_back(l + 1, r + 1); // 1-based ����
        }
    }

    // �����Ҷ˵�����
    sort(res.begin(), res.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second < y.second;
    });

    // ������
    for (const auto& p : res) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

