#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;

struct DoublyLinkedList {
    int val[MAXN];   // 存储节点值
    int pre[MAXN];   // 前驱指针
    int nxt[MAXN];   // 后继指针
    int head;        // 头节点索引
    int tail;        // 尾节点索引
    int cnt;         // 当前可用节点计数器

    // 初始化
    void init() {
        head = tail = -1;
        cnt = 0;
    }

    // 头部插入
    void push_front(int x) {
        val[cnt] = x;
        pre[cnt] = -1;
        nxt[cnt] = head;

        // 如果链表非空，更新原头节点的前驱
        if (head != -1) {
            pre[head] = cnt;
        } else {
            // 如果是第一个节点，同时更新尾指针
            tail = cnt;
        }

        head = cnt++;
    }

    // 尾部插入
    void push_back(int x) {
        val[cnt] = x;
        nxt[cnt] = -1;
        pre[cnt] = tail;

        // 如果链表非空，更新原尾节点的后继
        if (tail != -1) {
            nxt[tail] = cnt;
        } else {
            // 如果是第一个节点，同时更新头指针
            head = cnt;
        }

        tail = cnt++;
    }

    // 在指定位置后插入
    void insert_after(int prev_index, int x) {
        // 空链表或无效索引，视为头部插入
        if (head == -1 || prev_index == -1) {
            push_front(x);
            return;
        }

        // 找到前驱节点
        int current = head;
        for (int i = 0; current != -1 && i < prev_index; ++i) {
            current = nxt[current];
        }

        // 如果前驱节点不存在，插入到末尾
        if (current == -1) {
            push_back(x);
            return;
        }

        // 标准插入
        val[cnt] = x;
        pre[cnt] = current;
        nxt[cnt] = nxt[current];

        // 更新后继节点的前驱
        if (nxt[current] != -1) {
            pre[nxt[current]] = cnt;
        } else {
            // 如果插入到末尾，更新尾指针
            tail = cnt;
        }

        nxt[current] = cnt++;
    }

    // 删除指定索引的节点
    void remove(int index) {
        // 空链表或无效索引
        if (head == -1 || index < 0) return;

        // 找到要删除的节点
        int current = head;
        for (int i = 0; current != -1 && i < index; ++i) {
            current = nxt[current];
        }

        // 节点不存在
        if (current == -1) return;

        // 更新前驱节点的后继
        if (pre[current] != -1) {
            nxt[pre[current]] = nxt[current];
        } else {
            // 删除头节点
            head = nxt[current];
        }

        // 更新后继节点的前驱
        if (nxt[current] != -1) {
            pre[nxt[current]] = pre[current];
        } else {
            // 删除尾节点
            tail = pre[current];
        }
    }

    // 打印链表（正向）
    void print_forward() {
        int current = head;
        while (current != -1) {
            cout << val[current] << " ";
            current = nxt[current];
        }
        cout << endl;
    }

    // 打印链表（反向）
    void print_backward() {
        int current = tail;
        while (current != -1) {
            cout << val[current] << " ";
            current = pre[current];
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.init();

    // 测试插入
    list.push_front(10);
    list.push_back(20);
    list.insert_after(0, 15);
    list.push_back(30);

    cout << "正向打印：";
    list.print_forward();  // 输出: 10 15 20 30

    cout << "反向打印：";
    list.print_backward();  // 输出: 30 20 15 10

    // 测试删除
    list.remove(1);  // 删除15

    cout << "删除后正向打印：";
    list.print_forward();  // 输出: 10 20 30

    return 0;
}