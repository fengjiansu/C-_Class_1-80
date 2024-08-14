/* (1389)对角线

题目描述
输入整数N,输出主对角方阵。
(主对角矩阵:矩阵的主对角线(从左上至右下)由数字"1"组成,矩阵的剩余部分由数字"0
“组成)。
输入
一个整数N(1≤N≤15)。
输出
一个NxN的方阵,数字之间用空格隔开(具体详见样例)。
输入样例
5
输出样例
10000
01000
00100
00010
00001 */
#include <bits/stdc++.h>

using namespace std;

int a[16][16];
int main()
{
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
        //让学生设想一下副对角线条件
        //if(i+j==n-1)
         if (i==j) 
         {
            a[i][j] = 1;
         }
      }
  }
  // 输出二维数组 可以让学生去写
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << a[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
