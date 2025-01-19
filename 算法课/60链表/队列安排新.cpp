#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;

struct DoubleList {
    int nxt[MAXN];   // 后继指针
    int pre[MAXN];   // 前驱指针
    int head;        // 头节点
    bool exist[MAXN]; // 标记节点是否存在
    
    void init() {
        head = 1;
        exist[1] = true;
        pre[1] = nxt[1] = -1;
    }
    
    // 在k的左边或右边插入i
    void insert(int i, int k, int p) {
        exist[i] = true;
        if (p == 0) {  // 左插
            // 更新新节点的指针
            pre[i] = pre[k];
            nxt[i] = k;
            
            // 更新相邻节点的指针
            if (pre[k] != -1) nxt[pre[k]] = i;
            pre[k] = i;
            
            // 如果在头部插入，更新head
            if (k == head) head = i;
        } else {  // 右插
            // 更新新节点的指针
            pre[i] = k;
            nxt[i] = nxt[k];
            
            // 更新相邻节点的指针
            if (nxt[k] != -1) pre[nxt[k]] = i;
            nxt[k] = i;
        }
    }
    
    // 删除节点x
    void remove(int x) {
        if (!exist[x]) return;
        
        exist[x] = false;
        // 更新相邻节点的指针
        if (pre[x] != -1) nxt[pre[x]] = nxt[x];
        if (nxt[x] != -1) pre[nxt[x]] = pre[x];
        
        // 如果删除头节点，更新head
        if (x == head && nxt[x] != -1) head = nxt[x];
    }
    
    // 打印队列
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
    
    // 处理插入操作
    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        list.insert(i, k, p);
    }
    
    // 处理删除操作
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        list.remove(x);
    }
    
    // 输出最终队列
    list.print();
    
    return 0;
}