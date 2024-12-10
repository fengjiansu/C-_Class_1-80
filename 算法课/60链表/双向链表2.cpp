#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10; 
int pre[MAXN+1], nxt[MAXN+1];
// 假设链表中的节点编号为1~N
// pre[i] = j 表示j在i的左边
// nxt[i] = j 表示j在i的右边
// 若为-1表示没有对应的邻居

// 初始化：只有一个节点1
// pre[1] = -1, nxt[1] = -1
void init() {
    pre[1] = -1;
    nxt[1] = -1;
}

// 在k的右边插入x
void insertAfter(int k, int x) {
    int R = nxt[k];   // k的右邻居
    nxt[k] = x;
    pre[x] = k;
    nxt[x] = R;
    if (R != -1) {
        pre[R] = x;
    }
}

// 在k的左边插入x
void insertBefore(int k, int x) {
    int L = pre[k];    // k的左邻居
    pre[x] = L;
    nxt[x] = k;
    pre[k] = x;
    if (L != -1) {
        nxt[L] = x;
    }
}

// 根据ID删除节点x
void removeByID(int x) {
    int L = pre[x], R = nxt[x];
    if (L != -1) nxt[L] = R;
    if (R != -1) pre[R] = L;
    // 将x从链表中移除
    pre[x] = -1;
    nxt[x] = -1;
}

// 从最左侧节点开始打印当前链表
void printListFromLeft() {
    // 找最左侧节点
    int start = 1;
    while (pre[start] != -1) {
        start = pre[start];
    }

    // 从start往右遍历输出
    for (int cur = start; cur != -1; cur = nxt[cur]) {
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 初始化只含节点1的双向链表
    init();

    // 假设插入一些节点测试：
    // 在1右边插入2：链表为 1 -> 2
    insertAfter(1, 2);
    // 在1左边插入3：链表为 3 -> 1 -> 2
    insertBefore(1, 3);
    // 在2右边插入4：链表为 3 -> 1 -> 2 -> 4
    insertAfter(2, 4);

    // 删除节点2：链表变为 3 -> 1 -> 4
    removeByID(2);

    // 打印当前链表：3 1 4
    printListFromLeft();

    return 0;
}
