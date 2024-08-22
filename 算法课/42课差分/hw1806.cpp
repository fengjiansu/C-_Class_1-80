
/* 
(1806)取石子

【题目描述】
Alice和Bob在玩游戏。他们有n堆石子,第i堆石子有 ai 个,保证初始时
ai≤ai+1,(1≤i<n)。现在他们轮流对这些石子进行操作,每次操作人可以选择满足
aj>ai-1(ao 视为0)的一堆石子,并从中取走一个。谁最后不能取了谁输。Alice先
手,他们都使用最优策略,请判断最后谁会胜利。

【输入】
第一行一个整数n,表示石子堆数(1≤n≤100)。
接下来一行n个数,第i个数为aj,(1≤ai≤109),意义如上所述。

【输出】
"Alice"或“Bob",表示谁会赢。
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,a;
   cin>>n;
   /* 
   5 7  a b
   4 5  a n
   
    */
   long long s = 0;
   for(int i=0;i<n;i++)
   {
    cin>>a;
    s+=a;
   }
   if(s%2==1)
   {
       cout<<"Alice";
   }
   else
   {
       cout<<"Bob";
   }
   return 0;
}
