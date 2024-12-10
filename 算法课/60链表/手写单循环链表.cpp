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
    int head; // 初始化为-1 指向第一个节点
    int cnt;  // 可用节点数 下一个节点的索引
    LinkList() : head(-1), cnt(0) {}
    // 新的节点插入 原有的节点索引向后移动
    void insert(int pos, string x)
    {
        if (pos < 0 || pos > cnt)
            return; // 检查 pos 合法性
        val[cnt] = x;

        // 空链表插入
        if (head == -1)
        {
            nxt[cnt] = cnt; // 自成环
            head = cnt;
            cnt++;
            return;
        }

        cnt++; // 先增加计数，以便在下面使用新节点
        if (pos == 0)
        {
            // 头插
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
            return; // 越界检查

        cnt--; // 将计数提前减少

        // 删除头节点
        if (pos == 0)
        {
            int tail = head;
            while (nxt[tail] != head)
            {
                tail = nxt[tail];
            }
            // 链表中只有一个节点
            if (tail == head)
            {
                head = -1;
                return;
            }
            head = nxt[head];
            nxt[tail] = head;
            return;
        }

        // 删除非头节点
        int cur = head;
        for (int i = 0; i < pos - 1; i++)
        {
            cur = nxt[cur]; // 循环结束后，cur是pos-1位置的节点
        }

        // 待删除节点的下标为nxt[cur]
        int to_delete = nxt[cur];
        nxt[cur] = nxt[to_delete]; // 跳过待删除节点
    }
    string getKth(int k)
    {
        if (head == -1 || k < 0 || k >= cnt)
            return ""; // 越界处理
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
