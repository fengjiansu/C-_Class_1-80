#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;

struct DoubleList {
    int nxt[MAXN];   // ���ָ��
    int pre[MAXN];   // ǰ��ָ��
    int head;        // ͷ�ڵ�
    bool exist[MAXN]; // ��ǽڵ��Ƿ����
    
    void init() {
        head = 1;
        exist[1] = true;
        pre[1] = nxt[1] = -1;
    }
    
    // ��k����߻��ұ߲���i
    void insert(int i, int k, int p) {
        exist[i] = true;
        if (p == 0) {  // ���
            // �����½ڵ��ָ��
            pre[i] = pre[k];
            nxt[i] = k;
            
            // �������ڽڵ��ָ��
            if (pre[k] != -1) nxt[pre[k]] = i;
            pre[k] = i;
            
            // �����ͷ�����룬����head
            if (k == head) head = i;
        } else {  // �Ҳ�
            // �����½ڵ��ָ��
            pre[i] = k;
            nxt[i] = nxt[k];
            
            // �������ڽڵ��ָ��
            if (nxt[k] != -1) pre[nxt[k]] = i;
            nxt[k] = i;
        }
    }
    
    // ɾ���ڵ�x
    void remove(int x) {
        if (!exist[x]) return;
        
        exist[x] = false;
        // �������ڽڵ��ָ��
        if (pre[x] != -1) nxt[pre[x]] = nxt[x];
        if (nxt[x] != -1) pre[nxt[x]] = pre[x];
        
        // ���ɾ��ͷ�ڵ㣬����head
        if (x == head && nxt[x] != -1) head = nxt[x];
    }
    
    // ��ӡ����
    void print() {
        int cur = head;
        bool first = true;
        while (cur != -1) {
            if (exist[cur]) {
                if (!first) cout << " ";
                cout << cur;
                first = false;
            }
            cur = nxt[cur];
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    DoubleList list;
    list.init();
    
    // ����������
    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        list.insert(i, k, p);
    }
    
    // ����ɾ������
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        list.remove(x);
    }
    
    // ������ն���
    list.print();
    
    return 0;
}