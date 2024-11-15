#include <iostream>
#include <string>
using namespace std;

// 递归函数，通过中序和后序遍历的区间构建先序遍历
void buildPreOrder(const string &inOrder, const string &postOrder, int inL, int inR, int postL, int postR) {
    if (inL > inR || postL > postR) return;  // 如果子树为空，返回

    // 后序遍历的最后一个元素是当前子树的根节点
    char root = postOrder[postR];
    cout << root;  // 输出根节点（先序遍历）

    // 在中序遍历中找到根节点的位置
    int rootPos = inL;
    while (inOrder[rootPos] != root) rootPos++;

    // 计算左子树的大小
    int leftSize = rootPos - inL;

    // 递归处理左子树
    buildPreOrder(inOrder, postOrder, inL, rootPos - 1, postL, postL + leftSize - 1);

    // 递归处理右子树
    buildPreOrder(inOrder, postOrder, rootPos + 1, inR, postL + leftSize, postR - 1);
}

int main() {
    string inOrder, postOrder;
    
    // 输入中序和后序遍历
    cin >> inOrder >> postOrder;
    
    // 调用递归函数构建并输出先序遍历
    buildPreOrder(inOrder, postOrder, 0, inOrder.size() - 1, 0, postOrder.size() - 1);
    cout << endl;

    return 0;
}