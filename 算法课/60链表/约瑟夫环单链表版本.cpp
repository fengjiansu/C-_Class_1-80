#include <bits/stdc++.h>
using namespace std;

// ��Ϊ��Ŀ���� n <= 100������ȡ�Դ�һ��Ҳ�޷�
static const int MAXN = 200;

// ȫ�����飺ģ�ⵥ������
int head,tot,nxt[MAXN];      
// �洢�˵���������Ϊÿ���ڵ㶼Ҫ��һ������
// Ҳ������ vector<string> name; ����Ϊ��ʾ��д������
string val[MAXN],loc[MAXN];

// �����������������ڱ��ڵ�ָ���Լ�
void initList() {
    head = 1;// �ڱ��ڵ��±�̶�Ϊ1
    tot  = 1; // ��2��ʼ�������ʵ�ڵ�
    nxt[head] =0;  // ��ʼ�ջ���head->next = head
}

// �ڻ��ġ�β��������һ���½ڵ㣬��������Ϊ s
// ��ȼ��ڣ����½ڵ���뵽�ڱ��ڵ� head ��ǰ�棬����ѭ���ṹ
int insertNode(int p, string v) {
    int id = ++tot;    // ����һ���½ڵ��±�
    val[id] = v;   // �洢����
    
    // ���½ڵ�� next ָ�� �ڱ��� next�����׸���Ч�ڵ㣩
    nxt[id] = nxt[p];
    // Ȼ���� tail �� next ָ���½ڵ�
    nxt[p] = id;
    // ���� tail = id
    loc[id] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ���� n, m
    int n, m;
    cin >> n >> m;

    // ��ʼ�����ڱ�����
    initList();

    // ���� n �������������ӳ�һ����
    // Ϊ�˷��㣬����ά��һ�� tail ָ������¼���һ���ڵ�
    int tail = head; // ��ʼ�����ڱ�
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insertNode(i, s);
    }

    // ����, tail->next = head->next, �γ�һ��������ѭ��������
    // head ��������Ч���ݣ��������˴� 2~(n+1) ��Щ�±�

    // Լɪ�򻷹���
    // pre ָ��ǰ�ڵ��ǰ��(����ɾ��), cur ָ��ǰ�ڵ�
    int pre = head;          // �տ�ʼ�� pre=�ڱ�
    int cur = nxt[head];     // cur ָ���һ����Ч�ڵ�(��1����)

    // ����Ҫ����ɾ�� n ����
    for (int remaining = n; remaining > 0; remaining--) {
        // ÿ�ֱ��������� m ���ڵ��Ȧ
        // �Ѿ��� cur �ϣ����Ի����� (m-1) ��
        for (int step = 1; step < m; step++) {
            pre = cur;
            cur = nxt[cur];
        }
        // ��ʱ cur ����Ҫ��Ȧ����
        cout << nameArr[cur] << "\n";

        // ɾ�� cur, ���� pre->next = nxt[cur]
        nxt[pre] = nxt[cur];

        // ���� cur Ϊ��һ���ڵ�
        cur = nxt[cur];
        // ���ֻʣ�����һ���ˣ��ͻ�����һ�ֻ������ֽ������˳�
    }

    return 0;
}
