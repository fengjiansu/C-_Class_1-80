/* 
题目描述

(1627)修改字符串

输入包含10个字符的字符串,对于首个字符和最后一个字符,如果是大写
字母或数字,则将其换成小写字母。例如D换成d,H换成h,0换成a、1换
成b、2换成c ... 9换成j。

输入
一行含有10个字符的字符串,保证字符只可能是字母或数字。

输出
一行修改后的字符串。

输入样例
2xHappyenD

输出样例
cxHappyend
 */
#include <bits/stdc++.h>

using namespace std;

char c[15];
int main()
{
   cin >> c;
   // '0'的ANSCII 码为48
   // 'A'的ANSCII 码为65
   //'a'的ANSCII 码为97
   if(c[0] >= 'A' && c[0] <= 'Z')
   {
      c[0] += 32;
   }
   else if(c[0] >= '0' && c[0] <= '9')
   {
    c[0] += 'a'-'0';
   }
   return 0;
}
