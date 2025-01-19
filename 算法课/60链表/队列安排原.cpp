#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int head, tail, tot, pre[N], nxt[N], val[N], loc[N]; 
/* 
head/tail ,head 为头节点,tail 为尾节点,不存储有效数据
两个是哨兵节点的编号 起到边界守卫或者说占位标识的存在,
就像在城门口放一个守卫士兵用来把守、检查进出，
哨兵节点在链表中专门用来“守住”链表的头部或尾部，从而简化插入、删除时对边界的处理。
loc[v] 记录“值 v 存在于节点 id”
 */
void init()
{
    // 头尾各占用1个编号
    tot = 2; //新的节点从3开始
    head = 1;
    tail = 2;
    //任何节点都插入到head 和tail之间,
    //真正的首节点就是head->next  最后1个节点为 tail->pre
    //表示空链表状态
    nxt[head] = tail; // nxt[1] = 2;
    pre[tail] = head;// pre[2] = 1;
}
void insert(int p, int v){ 
    int id = ++tot;  // 新建一个节点 id
    val[id] = v;
    // 将 id 插入到 p 之后的位置
    pre[nxt[p]] = id; // 先找到p后面的节点 nxt[p]
    nxt[id] = nxt[p]; // 必须紧接着把 节点v 的nxt域指向 p后面的节点
    nxt[p] = id; // 然后才能更改p的nxt域此时不需要p后面节点的位置了
    pre[id] = p;
    // loc[v] 记录“值 v 存在于节点 id”
    loc[v] = id;
}

void remove(int p)
{
    nxt[pre[p]] = nxt[p];
    pre[nxt[p]] = pre[p];
    loc[val[p]] = 0; //注意这里 表示id为p的节点已经不存在了
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