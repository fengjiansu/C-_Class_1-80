#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char val;  // �ڵ��ֵ���ַ���
    int l, r;  // �����ӽڵ��������-1 ��ʾû���ӽڵ�
};

void preOrder(int root, vector<Node> &v)
{
    if (root == -1)  // ��û���ӽڵ�ʱ����
        return;
    cout << v[root].val;  // �����ǰ�ڵ��ֵ
    preOrder(v[root].l, v);  // �ݹ����������
    preOrder(v[root].r, v);  // �ݹ����������
}

int main()
{
    ios::sync_with_stdio(0);  // ����������Ч��
    cin.tie(0);  // ȡ�����������ͬ��
    
    int n;  // �ڵ�����
    cin >> n;
    
    vector<Node> v(n, {0, -1, -1});  // �洢���нڵ�
    string s;  // �洢�����ַ���
    
    for (int i = 0; i < n; i++)
    {
        cin >> s;  // ��ȡÿһ������
        v[i].val = s[0];  // �ڵ��ֵ���ַ����ĵ�һ���ַ�
        
        // �ж����ӽڵ��Ƿ����
        if (s[1] != '*')
        {
            v[i].l = s[1] - 'a';  // �������ӽڵ������
        }
        else
        {
            v[i].l = -1;  // û�����ӽڵ�
        }
        
        // �ж����ӽڵ��Ƿ����
        if (s[2] != '*')
        {
            v[i].r = s[2] - 'a';  // �������ӽڵ������
        }
        else
        {
            v[i].r = -1;  // û�����ӽڵ�
        }
    }
    
    preOrder(0, v);  // �Ӹ��ڵ㣨����0����ʼǰ�����
    cout << endl;  // �����ɺ���
    
    return 0;
}
