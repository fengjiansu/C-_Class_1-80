#include <bits/stdc++.h>
using namespace std;

// 因为题目限制 n <= 100，这里取稍大一点也无妨
static const int MAXN = 200;

// 全局数组：模拟单向链表
int head,tot,nxt[MAXN];      
// 存储人的姓名，因为每个节点都要有一个名字
// 也可以用 vector<string> name; 这里为了示例写成数组
string val[MAXN],loc[MAXN];

// 建立“空链表”：即哨兵节点指向自己
void initList() {
    head = 1;// 哨兵节点下标固定为1
    tot  = 1; // 从2开始分配给真实节点
    nxt[head] =0;  // 初始空环：head->next = head
}

// 在环的“尾部”插入一个新节点，保存姓名为 s
// 这等价于：将新节点插入到哨兵节点 head 的前面，保持循环结构
int insertNode(int p, string v) {
    int id = ++tot;    // 分配一个新节点下标
    val[id] = v;   // 存储姓名
    
    // 让新节点的 next 指向 哨兵的 next（即首个有效节点）
    nxt[id] = nxt[p];
    // 然后让 tail 的 next 指向新节点
    nxt[p] = id;
    // 更新 tail = id
    loc[id] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 输入 n, m
    int n, m;
    cin >> n >> m;

    // 初始化“哨兵环”
    initList();

    // 读入 n 个姓名，并链接成一个环
    // 为了方便，我们维护一个 tail 指针来记录最后一个节点
    int tail = head; // 初始等于哨兵
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insertNode(i, s);
    }

    // 现在, tail->next = head->next, 形成一个完整的循环单链表
    // head 本身不存有效数据，真正的人从 2~(n+1) 这些下标

    // 约瑟夫环过程
    // pre 指向当前节点的前驱(用于删除), cur 指向当前节点
    int pre = head;          // 刚开始让 pre=哨兵
    int cur = nxt[head];     // cur 指向第一个有效节点(第1个人)

    // 我们要依次删除 n 个人
    for (int remaining = n; remaining > 0; remaining--) {
        // 每轮报数报到第 m 个节点出圈
        // 已经在 cur 上，所以还需走 (m-1) 步
        for (int step = 1; step < m; step++) {
            pre = cur;
            cur = nxt[cur];
        }
        // 此时 cur 就是要出圈的人
        cout << nameArr[cur] << "\n";

        // 删除 cur, 即让 pre->next = nxt[cur]
        nxt[pre] = nxt[cur];

        // 更新 cur 为下一个节点
        cur = nxt[cur];
        // 如果只剩下最后一个人，就会在下一轮或者这轮结束后退出
    }

    return 0;
}
