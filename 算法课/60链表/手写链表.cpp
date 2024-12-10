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
struct LinkList
{
    int val[MAXN];
    int nxt[MAXN];
    int head; // 初始化为-1 指向第一个节点 
    int cnt; // 可用节点数 下一个节点的索引
    LinkList() : head(-1), cnt(0) {}
    // 新的节点插入 原有的节点索引向后移动
    void insert(int pos,int x)
    {
        if(pos <0) return;
        //head 刚开始指向-1,插入第一个节点的时候 ,head要更新
        // 插入的位置恰好是头节点
        if(head==-1||pos == head)
        {
            val[cnt] =x;
            nxt[cnt] = head;
            head = cnt;
            cnt++;
            return;
        }
        // 插入的时候和pos-1 以及pos位置的节点有关系 找到位置 pos -1 自然也知道pos 只是第几个 要通过指针的移动来找
        int cur = head;
        for(int i=0;i<pos-1&&cur!=-1;i++)
        {
            cur = nxt[cur];
        }
        if(cur == -1) return;
        val[cnt] = x;
        nxt[cnt] = nxt[cur]; //pos位置
        nxt[cur] = cnt;//pos-1位置的nxt位置指向 cnt
        cnt++;
         
    }
    void remove(int pos)
    {
        if(pos<0|| head==-1) return;
        //删除头节点 特殊情况
        if(pos == head)
        {
            head = nxt[head];
            cnt--;
            return;
        }
        int cur = head;
        for(int i=0;i<pos-1&&cur!=-1;i++)
        {
            cur = nxt[cur];
        }
        cnt--;
        // 此时删除的时候 要多判断一下有没有下一个节点
        if(cur == -1||nxt[cur]==-1) return;
        nxt[cur] = nxt[nxt[cur]];
    }
    int getKth(int k)
    {
        int cur = head;
        for(int i=0;i<k&&cur!=-1;i++)
        {
            cur = nxt[cur];
        }
        if(cur == -1) return -1;
        return val[cur];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LinkList list;
    list.insert(0, 10); // 插入 10
    list.insert(1, 20); // 插入 20
    list.insert(1, 15); // 在位置 1 插入 15

    cout << "第一个节点的值: " << list.getKth(0) << endl;
    cout << "第二个节点的值: " << list.getKth(1) << endl;
    cout << "第三个节点的值: " << list.getKth(2) << endl;

    list.remove(1); // 删除位置 1 的节点
    cout << "删除后第二个节点的值: " << list.getKth(1) << endl;
    return 0;
}
