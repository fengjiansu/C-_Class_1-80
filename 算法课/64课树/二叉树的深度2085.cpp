#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int l, r;  // 左右子节点的编号
};


int max_depth = 1;  // 最大深度，初始值为1，因为根节点深度为1

// 深度优先搜索（DFS）计算树的深度
void dfs(int node, int depth,vector<Node> &tree) {
    if (node == 0) return;  // 如果当前节点是0，说明没有子节点，返回
    max_depth = max(max_depth, depth);  // 更新最大深度
    dfs(tree[node].l, depth + 1);  // 递归遍历左子节点
    dfs(tree[node].r, depth + 1);  // 递归遍历右子节点
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n+1);  // 用来存储树的每个节点

    // 输入每个节点的左右子节点
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].l >> tree[i].r;
    }

    // 从根节点（1号节点）开始进行深度优先搜索
    dfs(1, 1,tree);

    // 输出树的最大深度
    cout << max_depth << endl;

    return 0;
}
