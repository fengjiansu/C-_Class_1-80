/* 
题目描述

(1041)行列互换

军队里面有一种阵型训练方式叫做行列互换,即所有士兵原先站成一个n行m列的矩形方阵,
行列互换的时候,原先第i行第j列的士兵就会站到第j行第i列的位置上。编程模拟行列互换的
过程。
输入
第一行两个整数n,m(1≤n,m≤100)。
接下来是一个n行m列的矩阵,表示每个士兵的编号。
输出
行列互换后的矩阵。
输入样例
23
123
456
输出样例
14
25
36
 */
#include <bits/stdc++.h>

using namespace std;
int a[105][105];
int b[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            //提示学生写
            b[j][i] = a[i][j];
        }
    }
    //输出也是学生写
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
   return 0;
}
