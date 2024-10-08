#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char val;  // 节点的值（字符）
    int l, r;  // 左右子节点的索引，-1 表示没有子节点
};

void preOrder(int root, vector<Node> &v)
{
    if (root == -1)  // 当没有子节点时返回
        return;
    cout << v[root].val;  // 输出当前节点的值
    preOrder(v[root].l, v);  // 递归遍历左子树
    preOrder(v[root].r, v);  // 递归遍历右子树
}

int main()
{
    ios::sync_with_stdio(0);  // 提高输入输出效率
    cin.tie(0);  // 取消输入输出流同步
    
    int n;  // 节点数量
    cin >> n;
    
    vector<Node> v(n, {0, -1, -1});  // 存储所有节点
    string s;  // 存储输入字符串
    
    for (int i = 0; i < n; i++)
    {
        cin >> s;  // 读取每一行输入
        v[i].val = s[0];  // 节点的值是字符串的第一个字符
        
        // 判断左子节点是否存在
        if (s[1] != '*')
        {
            v[i].l = s[1] - 'a';  // 计算左子节点的索引
        }
        else
        {
            v[i].l = -1;  // 没有左子节点
        }
        
        // 判断右子节点是否存在
        if (s[2] != '*')
        {
            v[i].r = s[2] - 'a';  // 计算右子节点的索引
        }
        else
        {
            v[i].r = -1;  // 没有右子节点
        }
    }
    
    preOrder(0, v);  // 从根节点（索引0）开始前序遍历
    cout << endl;  // 输出完成后换行
    
    return 0;
}
