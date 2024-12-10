#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
const int MAXN = 1e5 + 10;  // ����ʵ������������ڵ���

// ����ģ��ṹ
struct LinkedList {
    int val[MAXN];   // �洢�ڵ�ֵ
    int nxt[MAXN];   // �洢��һ���ڵ������
    int head;        // ͷ�ڵ�����
    int cnt;         // ��ǰ���ýڵ������

     // ��ʼ��
    void init() {
        head = -1;  // ����ʼΪ��
        cnt = 0;    // ��һ���ڵ�����Ϊ0
    }

    // ��ָ��λ��p ֮�����ֵ x ��Ҫ��ȷ֪������λ�õĽڵ� p ��������
    void insert_after(int p, int x) {
        val[cnt] = x;
        nxt[cnt] = nxt[p];
        nxt[p] = cnt;
        cnt++;
    }

    /* // ͷ������
    void push_front(int x) {
        val[cnt] = x;
        nxt[cnt] = head;
        head = cnt++;
    }

    // β������
    void push_back(int x) {
        if (head == -1) {
            push_front(x);
            return;
        }
        
        int cur = head;
        while (nxt[cur] != -1) cur = nxt[cur];
        
        val[cnt] = x;
        nxt[cnt] = -1;
        nxt[cur] = cnt;
        cnt++;
    } */

    // �²���Ľڵ�ŵ�����,����Ҫ֪��ǰ���ڵ������
    void insert(int prev, int x) {
        if (prev < -1) return; // ��Чλ��

        // ���������뵽ͷ��
        if (prev == -1 || prev == head) {
            // ���뵽ͷ��
            val[cnt] = x;
            nxt[cnt] = head;
            head = cnt++;
            return;
        }

        //����ǰ���ڵ� prev
        int current = head;
        for(int i = 0; i < prev- 1 && current != -1; ++i) {
            current = nxt[current];
        }

        if(current == -1) {
            // ���ǰ���ڵ㲻���� (��Чλ��)
            return;
        }

        // ʹ�ü��Ĳ����߼�
        insert_after(current, x);
    }
    // ɾ��p�ڵ����Ľڵ�
    void remove(int p)
    {
        nxt[p]=nxt[nxt[p]];
    }

    // ɾ��λ�� pos �Ľڵ㣨0-based��
    void remove_at(int pos) {
        if (head == -1 || pos < 0) return; // ���������Чλ��

        if (pos == 0) {
            // ɾ��ͷ�ڵ�
            head = nxt[head];
            return;
        }

        // �ҵ�λ�� pos-1 �Ľڵ�
        int current = head;
        for(int i = 0; i < pos - 1 && current != -1; ++i) {
            current = nxt[current];
        }

        if(current == -1 || nxt[current] == -1) {
            // λ����Ч
            return;
        }

        // ɾ����ǰ�ڵ����һ���ڵ�
        nxt[current] = nxt[nxt[current]];
    }

    // ��ȡ�� k ��Ԫ�ص�ֵ��0-based������������ڷ��� -1
    int getKth(int k) const {
        int current = head;
        for(int i = 0; i < k && current != -1; ++i) {
            current = nxt[current];
        }
        if(current == -1) return -1;
        return val[current];
    }

    // ��ӡ�������ڵ��ԣ�
    void print() const {
        int current = head;
        while(current != -1) {
            printf("%d ", val[current]);
            current = nxt[current];
        }
        printf("\n");
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkedList list;
    list.init();

    // ʹ��ʾ��
    list.insert(-1,5);
    list.insert(0,6);
    list.insert(1,7);
    list.print();  // ���:7 6 5

    list.remove(1);
    list.print();  // ���: 5 6
    return 0;
}


