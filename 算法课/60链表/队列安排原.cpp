#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int head, tail, tot, pre[N], nxt[N], val[N], loc[N]; 
/* 
head/tail ,head Ϊͷ�ڵ�,tail Ϊβ�ڵ�,���洢��Ч����
�������ڱ��ڵ�ı�� �𵽱߽���������˵ռλ��ʶ�Ĵ���,
�����ڳ��ſڷ�һ������ʿ���������ء���������
�ڱ��ڵ���������ר����������ס�������ͷ����β�����Ӷ��򻯲��롢ɾ��ʱ�Ա߽�Ĵ���
loc[v] ��¼��ֵ v �����ڽڵ� id��
 */
void init()
{
    // ͷβ��ռ��1�����
    tot = 2; //�µĽڵ��3��ʼ
    head = 1;
    tail = 2;
    //�κνڵ㶼���뵽head ��tail֮��,
    //�������׽ڵ����head->next  ���1���ڵ�Ϊ tail->pre
    //��ʾ������״̬
    nxt[head] = tail; // nxt[1] = 2;
    pre[tail] = head;// pre[2] = 1;
}
void insert(int p, int v){ 
    int id = ++tot;  // �½�һ���ڵ� id
    val[id] = v;
    // �� id ���뵽 p ֮���λ��
    pre[nxt[p]] = id; // ���ҵ�p����Ľڵ� nxt[p]
    nxt[id] = nxt[p]; // ��������Ű� �ڵ�v ��nxt��ָ�� p����Ľڵ�
    nxt[p] = id; // Ȼ����ܸ���p��nxt���ʱ����Ҫp����ڵ��λ����
    pre[id] = p;
    // loc[v] ��¼��ֵ v �����ڽڵ� id��
    loc[v] = id;
}

void remove(int p)
{
    nxt[pre[p]] = nxt[p];
    pre[nxt[p]] = pre[p];
    loc[val[p]] = 0; //ע������ ��ʾidΪp�Ľڵ��Ѿ���������
}
int main()
{
    init();
    insert(head, 1);
    int n, m, k, p;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> k >> p;
        if (p == 0)
        {
            insert(pre[loc[k]], i);
        }
        else
        {
            insert(loc[k], i);
        }
    }
    cin >> m;
    while (m--)
    {
        cin >> k;k
        remove(loc[k]);
    }
    for (int i = nxt[head]; i != tail; i = nxt[i])
    {
        cout << val[i] << " ";
    }
    return 0;
}