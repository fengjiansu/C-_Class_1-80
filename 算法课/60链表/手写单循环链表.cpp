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
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
const int MAXN = 1e5 + 10;
struct LinkList
{
    string val[MAXN];
    int nxt[MAXN];
    int head; // ��ʼ��Ϊ-1 ָ���һ���ڵ�
    int cnt;  // ���ýڵ��� ��һ���ڵ������
    LinkList() : head(-1), cnt(0) {}
    // �µĽڵ���� ԭ�еĽڵ���������ƶ�
    void insert(int pos, string x)
    {
        if (pos < 0 || pos > cnt)
            return; // ��� pos �Ϸ���
        val[cnt] = x;

        // ���������
        if (head == -1)
        {
            nxt[cnt] = cnt; // �Գɻ�
            head = cnt;
            cnt++;
            return;
        }

        cnt++; // �����Ӽ������Ա�������ʹ���½ڵ�
        if (pos == 0)
        {
            // ͷ��
            int tail = head;
            while (nxt[tail] != head)
                tail = nxt[tail];
            nxt[cnt - 1] = head;
            head = cnt - 1;
            nxt[tail] = head;
            return;
        }

        int cur = head;
        for (int i = 0; i < pos - 1; i++)
            cur = nxt[cur];

        nxt[cnt - 1] = nxt[cur];
        nxt[cur] = cnt - 1;
    }

    void remove(int pos)
    {
        if (head == -1 || pos < 0 || pos >= cnt)
            return; // Խ����

        cnt--; // ��������ǰ����

        // ɾ��ͷ�ڵ�
        if (pos == 0)
        {
            int tail = head;
            while (nxt[tail] != head)
            {
                tail = nxt[tail];
            }
            // ������ֻ��һ���ڵ�
            if (tail == head)
            {
                head = -1;
                return;
            }
            head = nxt[head];
            nxt[tail] = head;
            return;
        }

        // ɾ����ͷ�ڵ�
        int cur = head;
        for (int i = 0; i < pos - 1; i++)
        {
            cur = nxt[cur]; // ѭ��������cur��pos-1λ�õĽڵ�
        }

        // ��ɾ���ڵ���±�Ϊnxt[cur]
        int to_delete = nxt[cur];
        nxt[cur] = nxt[to_delete]; // ������ɾ���ڵ�
    }
    string getKth(int k)
    {
        if (head == -1 || k < 0 || k >= cnt)
            return ""; // Խ�紦��
        int cur = head;
        for (int i = 0; i < k; i++)
        {
            cur = nxt[cur];
        }
        return val[cur];
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkList l;
    
    return 0;
}
