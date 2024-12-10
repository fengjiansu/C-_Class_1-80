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
const int MAXN = 1e5 + 10;  // 根据实际问题调整最大节点数

// 链表模拟结构
struct LinkedList {
    int val[MAXN];   // 存储节点值
    int nxt[MAXN];   // 存储下一个节点的索引
    int head;        // 头节点索引
    int cnt;         // 当前可用节点计数器

     // 初始化
    void init() {
        head = -1;  // 链表开始为空
        cnt = 0;    // 第一个节点索引为0
    }

    // 在指定位置p 之后插入值 x 需要明确知道插入位置的节点 p 的索引。
    void insert_after(int p, int x) {
        val[cnt] = x;
        nxt[cnt] = nxt[p];
        nxt[p] = cnt;
        cnt++;
    }

    /* // 头部插入
    void push_front(int x) {
        val[cnt] = x;
        nxt[cnt] = head;
        head = cnt++;
    }

    // 尾部插入
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

    // 新插入的节点放到后面,则需要知道前驱节点的索引
    void insert(int prev, int x) {
        if (prev < -1) return; // 无效位置

        // 空链表或插入到头部
        if (prev == -1 || prev == head) {
            // 插入到头部
            val[cnt] = x;
            nxt[cnt] = head;
            head = cnt++;
            return;
        }

        //查找前驱节点 prev
        int current = head;
        for(int i = 0; i < prev- 1 && current != -1; ++i) {
            current = nxt[current];
        }

        if(current == -1) {
            // 如果前驱节点不存在 (无效位置)
            return;
        }

        // 使用简洁的插入逻辑
        insert_after(current, x);
    }
    // 删除p节点后面的节点
    void remove(int p)
    {
        nxt[p]=nxt[nxt[p]];
    }

    // 删除位置 pos 的节点（0-based）
    void remove_at(int pos) {
        if (head == -1 || pos < 0) return; // 空链表或无效位置

        if (pos == 0) {
            // 删除头节点
            head = nxt[head];
            return;
        }

        // 找到位置 pos-1 的节点
        int current = head;
        for(int i = 0; i < pos - 1 && current != -1; ++i) {
            current = nxt[current];
        }

        if(current == -1 || nxt[current] == -1) {
            // 位置无效
            return;
        }

        // 删除当前节点的下一个节点
        nxt[current] = nxt[nxt[current]];
    }

    // 获取第 k 个元素的值（0-based），如果不存在返回 -1
    int getKth(int k) const {
        int current = head;
        for(int i = 0; i < k && current != -1; ++i) {
            current = nxt[current];
        }
        if(current == -1) return -1;
        return val[current];
    }

    // 打印链表（用于调试）
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

    // 使用示例
    list.insert(-1,5);
    list.insert(0,6);
    list.insert(1,7);
    list.print();  // 输出:7 6 5

    list.remove(1);
    list.print();  // 输出: 5 6
    return 0;
}


