#include <bits/stdc++.h>
using namespace std;

static int L[100000+5], R[100000+5]; // left[i], right[i] 分别表示 i号同学左右相邻的编号
static bool removed[100000+5];       // 标记某个同学是否已被移除

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    // 初始化：只有1号同学
    // 1号左右都为-1，表示只有1号一个人在队列中
    L[1] = -1;
    R[1] = -1;

    // 从2号同学开始插入
    for (int i = 2; i <= N; i++) {
        int k, p; cin >> k >> p;
        if (p == 0) {
            // i插入到k的左边
            int leftNeighbor = L[k];  // k的左邻居
            L[i] = leftNeighbor;      // i的左为原来的leftNeighbor
            R[i] = k;                 // i的右为k
            L[k] = i;                 // k的左为i
            if (leftNeighbor != -1) {
                R[leftNeighbor] = i;  // 原左邻居的右改为i
            }
        } else {
            // i插入到k的右边
            int rightNeighbor = R[k]; // k的右邻居
            R[i] = rightNeighbor;     // i的右为原来的rightNeighbor
            L[i] = k;                 // i的左为k
            R[k] = i;                 // k的右为i
            if (rightNeighbor != -1) {
                L[rightNeighbor] = i; // 原右邻居的左改为i
            }
        }
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        if (!removed[x]) {
            // 删除x号同学
            int leftN = L[x];
            int rightN = R[x];
            if (leftN != -1) R[leftN] = rightN;
            if (rightN != -1) L[rightN] = leftN;
            removed[x] = true;
        }
    }

    // 找到最左侧的同学
    int start = 1;
    // 不断向左找到最左边
    while (L[start] != -1) {
        start = L[start];
    }

    // 从start开始向右输出未被删除的同学
    // 有可能start已经被删除了，则需要找到第一个未删除的在右边的同学
    while (start != -1 && removed[start]) {
        start = R[start];
    }

    // 顺着right指针遍历
    bool first = true;
    for (int cur = start; cur != -1; cur = R[cur]) {
        if (!removed[cur]) {
            if (!first) cout << " ";
            cout << cur;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}