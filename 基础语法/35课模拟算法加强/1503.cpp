/* 
给定一个1\sim n1?n的排列和一个双端队列，从前到后依次取出排列中的数字，然后你可以把取出的数字插入到双端队列的头部或者尾部。求插完所有数字后双端队列中字典序最小的排列。

输入
第一行输入n，n\le100n≤100。第二行依次输入n个整数（保证在int范围内）

输出
输出字典序最小的双端队列

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
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        // 如果双端队列为空，直接插入头部
        if (dq.empty()) {
            dq.push_back(num);
        } else {
            // 比较插入头部和尾部的效果，插入能使字典序更小的那一侧
            if (num <= dq.front()) {
                dq.push_front(num);
            } else {
                dq.push_back(num);
            }
        }
    }

    // 输出双端队列中的元素
    for (int i : dq) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
