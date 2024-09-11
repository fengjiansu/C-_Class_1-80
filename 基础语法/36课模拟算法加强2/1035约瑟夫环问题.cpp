/* 
B.约瑟夫环问题
描述

n个人围成一个圈,从第一个人开始报数,数到m的人出圈。再由下一个人开始报数,

数到m的人出圈;输出依次出圈的人的编号

输入

两个整数n,m(1≤m≤n≤100)

输出

依次出圈的人的编号
输入
5 2
输出
2 4 1 5 3

 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
      deque<int> dq;
    // 初始化队列，将 1 到 n 的编号放入队列
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    // 开始模拟报数过程
    while (!dq.empty()) {
        // 将前 m-1 个元素移到队列末尾
        for (int i = 1; i < m; i++) {
            dq.push_back(dq.front());  // 把队首元素移到队尾
            dq.pop_front();            // 移除队首元素
        }
        // 输出出圈的人的编号
        cout << dq.front() << " ";
        dq.pop_front();  // 把数到 m 的人移除队列
    }
    return 0;
}
