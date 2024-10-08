#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

struct Node
{
    int data;
    int left;
    int right;
};
Node nodes[26];       // 存储节点信息，索引 0~25 对应 'a'~'z'
bool has_node[26];    // 标记节点是否存在

// 前序遍历函数
void preOrder(int index) {
    if (index == -1) return;

    // 输出当前节点
    char node_char = 'a' + nodes[index].data;
    cout << node_char;

    // 递归遍历左子树
    preOrder(nodes[index].left);

    // 递归遍历右子树
    preOrder(nodes[index].right);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符

    // 初始化节点数组和标记数组
    for (int i = 0; i < 26; ++i) {
        nodes[i].data = i;
        nodes[i].left = -1;
        nodes[i].right = -1;
        has_node[i] = false;
    }

    char root_char;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        // 去除字符串中的空格
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        // 确保字符串长度为 3，如果长度不足，用 '*' 补齐
        while (s.length() < 3) {
            s += '*';
        }

        // 获取父节点和左右子节点
        char parent_char = s[0];
        char left_char = s[1];
        char right_char = s[2];

        int parent_index = parent_char - 'a';
        has_node[parent_index] = true;

        // 左子节点
        if (left_char != '*') {
            int left_index = left_char - 'a';
            nodes[parent_index].left = left_index;
            has_node[left_index] = true;
        } else {
            nodes[parent_index].left = -1;
        }

        // 右子节点
        if (right_char != '*') {
            int right_index = right_char - 'a';
            nodes[parent_index].right = right_index;
            has_node[right_index] = true;
        } else {
            nodes[parent_index].right = -1;
        }

        // 记录根节点的字符
        if (i == 0) {
            root_char = parent_char;
        }
    }

    // 根节点索引
    int root_index = root_char - 'a';

    // 前序遍历
    preOrder(root_index);
    cout << endl;

    return 0;
}
