/* 
题目描述
(1242)对角线求和
给你一个长度为n的正方形矩阵,求它的两个对角线上数字的和。
输入
第一行一个整数n(1≤n≤100)。
接下来一个n行n列的矩阵(矩阵中的每个数大于等于0且小于等于100)。
输出
输出一个整数表示答案。
输入样例
3
111
111
111
输出样例
5
 */
#include <bits/stdc++.h>

using namespace std;

int a[105][105];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    /* for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j || i + j == n - 1)
            {
                sum += a[i][j];
            }
        }
    } */
    //视班级情况讲下面这种做法
    for (int i = 0; i < n; i++)
    {
       sum += a[i][i] +a[i][n - i - 1];
    } 

   if(n%2)
   {
       sum -= a[n/2][n/2];
   }
   cout<<sum;
   return 0;
}
