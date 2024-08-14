/* 
题目描述

(1044)寻找最大的数

读入一个n行m列的矩阵,输出其中最大的数所在的行号和列号。

输入
第一行两个整数n,m(1≤n,m≤10)。
接下来是一个n行m列的矩阵,矩阵中的每个数字是不大于100的整数。

输出
最大的数所在的行号和列号中间用空格分开,如果有多个最大的数,随便输出其中一个就可。

输入样例
34
1235
3650
1375

输出样例
33
 */
#include <bits/stdc++.h>

using namespace std;

int a[15][15];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int max = a[0][0];
    //需要额外两个变量记录最大值的行列
    int x = 0, y = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
          if (a[i][j] > max)
          {
              max = a[i][j];
              x = i;
              y = j;
          }
      }
   }
   cout<<x+1<<" "<<y+1;
   return 0;
}
