/* 
题目描述

(1042)杨辉三角

输入n,打印杨辉三角的前n行。

输入
一个整数n(1≤n≤10)。

输出
杨辉三角的前n行。

输入样例
5

输出样例
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
 */
#include <bits/stdc++.h>

using namespace std;

int a[15][15];
int main()
{
   int n;
   cin>>n;
   for (int i = 0; i < n; i++) {
        a[i][0] = 1;  // 每行的第一个元素都是1
        a[i][i] = 1;  // 每行的最后一个元素也是1
        // 提醒学生 j=0时全为1 所以列从1开始
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];  // 根据杨辉三角的性质填充中间的元素
        }
    }

    // 输出杨辉三角
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;  // 换行
    }


   return 0;
}
