/* 
题目描述

(1066)汉诺塔Ⅱ

在汉诺塔问题中,我们把三根柱子命名为A,B,C,把盘子从上到下编号为1~n。输出把n块盘
子从A柱子移到C柱子最少次数的操作步骤。
输入
一整数n(1≤n≤10)。
输出
操作步骤,如A->1->B,表示把编号1的盘子从A柱子移到B柱子。
输入样例
2
输出样例
A->1->B
A->2->C
B->1->C
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
// source src  destination des
void hanoi(int n, char src, char des, char help) {
    if (n == 1) {
        // 基本情况：只剩一个盘子，直接移动
        cout << src << "->" << n << "->" << des << endl;
        return;
    }

    // 1. 先将 n-1 个盘子从 A 移到 B，借助 C
    hanoi(n - 1, src, help, des);

    // 2. 将第 n 个盘子从 A 移到 C
    cout << src << "->" << n << "->" << des << endl;

    // 3. 再将 n-1 个盘子从 B 移到 C，借助 A
    hanoi(n - 1, help, des, src);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* 
    分解问题：

将 n-1 块盘子从柱子 A 移到柱子 B（借助柱子 C）。
将第 n 块盘子从柱子 A 移到柱子 C。
将 n-1 块盘子从柱子 B 移到柱子 C（借助柱子 A）。
递归解决：

对于每个子问题，递归地解决，直到只剩一个盘子可以直接移动。
合并结果：

每次递归结束时输出移动步骤，最终得到完整的移动过程。
     */

    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
