/*
题目描述

(1646)Mc生存

MC玩家在“我的世界”开了一个nxn(n≤100)的方阵,现在他有m个火把和k个萤石,分别放在(X1,yi)~(Xm,ym)和
(01,P1)~(Ok,pk)的位置,没有光或没放东西的地方会生成怪物。请问在这个方阵中有几个点会生成怪物?
输入
第一行为n,m,k。
第2到第m+1行分别是火把的位置Xi,yi。
第m+2到第m+k+1行分别是萤石的位置Oi,pi。
注:可能没有萤石,但一定有火把。所有数据保证在int范围内。

输出
有几个点会生出怪物。

输入样例
510
33

输出样例
12

火把照亮范围
|暗|暗| 光 |暗|暗|
|暗|光|光|光|暗|
|光|光|火把|光|光|
|暗|光|光|光|暗|
|暗|暗| 光 |暗|暗|

萤石照亮范围
|光|光|光|光|光|
[光|光|光|光|光|
|光|光|萤石|光|光|
光|光| 光|光|光|
|光|光|光|光|光|
 */
#include <bits/stdc++.h>

using namespace std;

bool a[105][105];
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};
int main()
{
   int n, m, k;
   cin >> n >> m >> k;
   int cnt = 0;

   // 处理火把的照亮范围
   for (int i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      // 推荐使用偏移的方法，最后输出的时候额外处理
      x += 2;
      y += 2;
      for (int j = x - 2; j <= x + 2; j++)
      {
         for (int k = y - 2; k <= y + 2; k++)
         {
            // if (j >= 0 && j < n && k >= 0 && k < n)

            // 说先写好写的
            if (j == x || k == y)
            {
               a[j][k] = true;
            }
         }
      }
      // 照亮四个对角格子
      for (int i = 0; i < 4; i++)
      {
         int nx = x + dx[i];
         int ny = y + dy[i];

         a[nx][ny] = true;
         /* if (x - 1 >= 0 && y - 1 >= 0)
            a[x - 1][y - 1] = true;
         if (x - 1 >= 0 && y + 1 < n)
            a[x - 1][y + 1] = true;
         if (x + 1 < n && y - 1 >= 0)
            a[x + 1][y - 1] = true;
         if (x + 1 < n && y + 1 < n)
            a[x + 1][y + 1] = true; */
      }
   }

   // 先写萤石 比较简单 但是火把要写在上方
   // 处理萤石的照亮范围
   for (int i = 0; i < k; i++)
   {
      int o, p;
      cin >> o >> p;
      o--;
      p--;
      o += 2;
      p += 2;
      // 转换为0索引

      // 照亮5x5区域
      // cout<<a[0][4]<<endl;
      for (int j = o - 2; j <= o + 2; j++)
      {
         for (int k = p - 2; k <= p + 2; k++)
         {
            // 可以先不写if语句 直接写之后提醒学生会出错

            a[j][k] = true;
         }
      }
   }

   // 统计未被照亮的点数
   for (int i = 2; i < n + 2; i++)
   {
      for (int j = 2; j < n + 2; j++)
      {
         if (a[i][j] == false)
         {
            cnt++;
         }
         // cout<<a[i][j]<<" ";
      }
      // cout<<endl;
   }
   cout << cnt;
   return 0;
}
