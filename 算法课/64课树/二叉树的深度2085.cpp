#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int l, r;  // �����ӽڵ�ı��
};


int max_depth = 1;  // �����ȣ���ʼֵΪ1����Ϊ���ڵ����Ϊ1

// �������������DFS�������������
void dfs(int node, int depth,vector<Node> &tree) {
    if (node == 0) return;  // �����ǰ�ڵ���0��˵��û���ӽڵ㣬����
    max_depth = max(max_depth, depth);  // ����������
    dfs(tree[node].l, depth + 1);  // �ݹ�������ӽڵ�
    dfs(tree[node].r, depth + 1);  // �ݹ�������ӽڵ�
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n+1);  // �����洢����ÿ���ڵ�

    // ����ÿ���ڵ�������ӽڵ�
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].l >> tree[i].r;
    }

    // �Ӹ��ڵ㣨1�Žڵ㣩��ʼ���������������
    dfs(1, 1,tree);

    // �������������
    cout << max_depth << endl;

    return 0;
}
