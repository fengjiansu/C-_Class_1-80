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
Node nodes[26];       // �洢�ڵ���Ϣ������ 0~25 ��Ӧ 'a'~'z'
bool has_node[26];    // ��ǽڵ��Ƿ����

// ǰ���������
void preOrder(int index) {
    if (index == -1) return;

    // �����ǰ�ڵ�
    char node_char = 'a' + nodes[index].data;
    cout << node_char;

    // �ݹ����������
    preOrder(nodes[index].left);

    // �ݹ����������
    preOrder(nodes[index].right);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ���Ի��з�

    // ��ʼ���ڵ�����ͱ������
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

        // ȥ���ַ����еĿո�
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        // ȷ���ַ�������Ϊ 3��������Ȳ��㣬�� '*' ����
        while (s.length() < 3) {
            s += '*';
        }

        // ��ȡ���ڵ�������ӽڵ�
        char parent_char = s[0];
        char left_char = s[1];
        char right_char = s[2];

        int parent_index = parent_char - 'a';
        has_node[parent_index] = true;

        // ���ӽڵ�
        if (left_char != '*') {
            int left_index = left_char - 'a';
            nodes[parent_index].left = left_index;
            has_node[left_index] = true;
        } else {
            nodes[parent_index].left = -1;
        }

        // ���ӽڵ�
        if (right_char != '*') {
            int right_index = right_char - 'a';
            nodes[parent_index].right = right_index;
            has_node[right_index] = true;
        } else {
            nodes[parent_index].right = -1;
        }

        // ��¼���ڵ���ַ�
        if (i == 0) {
            root_char = parent_char;
        }
    }

    // ���ڵ�����
    int root_index = root_char - 'a';

    // ǰ�����
    preOrder(root_index);
    cout << endl;

    return 0;
}
