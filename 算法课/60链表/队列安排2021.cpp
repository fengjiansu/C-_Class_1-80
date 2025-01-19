#include <bits/stdc++.h>
using namespace std;

// 最大可能的人数
static const int MAXN = 100000 + 5;

int Lch[MAXN], Rch[MAXN]; // 分别存储每个人的左邻和右邻
bool inQueue[MAXN];       // 标记该编号的同学是否仍在队列

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 初始化：只有 1 号同学在队列中
    int head = 1;
    Lch[1] = 0;     // 表示 1 号左边无人
    Rch[1] = 0;     // 表示 1 号右边无人
    inQueue[1] = true;

    // 从 2 号开始逐个插入
    for (int i = 2; i <= N; i++) {
        int k, p;
        cin >> k >> p; // 读入要插入到 k 的左边 (p=0) 或右边 (p=1)
        inQueue[i] = true;

        if (p == 0) {
            // 插入到 k 的左边
            int leftK = Lch[k];
            Rch[i] = k;
            Lch[i] = leftK;

            // 如果 k 原本有左邻，则需要让那位左邻的右邻变为 i
            if (leftK != 0) {
                Rch[leftK] = i;
            } else {
                // k 原本是队列最左端，现在 i 成为新的左端
                head = i;
            }
            // k 的左邻更新为 i
            Lch[k] = i;

        } else {
            // 插入到 k 的右边
            int rightK = Rch[k];
            Lch[i] = k;
            Rch[i] = rightK;

            // 如果 k 原本有右邻，则需要让那位右邻的左邻变为 i
            if (rightK != 0) {
                Lch[rightK] = i;
            }
            // k 的右邻更新为 i
            Rch[k] = i;
        }
    }

    // 读入要删除的同学数量 M
    int M;
    cin >> M;

    while (M--) {
        int x;
        cin >> x;

        // 若 x 已经不在队列中，则忽略
        if (!inQueue[x]) continue;

        // 否则执行删除操作
        inQueue[x] = false;
        int left = Lch[x], right = Rch[x];

        // 让 x 的左邻和右邻互相连接
        if (left != 0) Rch[left] = right;
        if (right != 0) Lch[right] = left;

        // 如果 x 恰好是 head，则要更新 head
        if (x == head) {
            head = right; // 若 right 为 0，则队列已空
        }

        // 标记 x 已失效（可选）
        Lch[x] = 0;
        Rch[x] = 0;
    }

    // 最后从 head 开始，依次向右遍历输出
    int cur = head;
    bool firstPrint = true;
    while (cur != 0) {
        if (!firstPrint) cout << " ";
        firstPrint = false;
        cout << cur;
        cur = Rch[cur];
    }
    cout << "\n";

    return 0;
}
