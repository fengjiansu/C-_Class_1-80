/* 
题目描述
(1112)查找字符串
给你n个字符串,接下来给你一个待查找字符串,输出待查找字符串出现的序号。
字符串长度不超过80,n <= 26。
输入
第一行输入一个整数n(n <= 26)。
接下来输入n个字符串,每个字符串占一行。
最后输入一个待查找字符串。
输出
输出一个整数,输出待查找字符串出现的序号。
输入样例 输出样例
2
Zhang
Chu
Li
Chu
 */
#include <bits/stdc++.h>

using namespace std;
char str[50][85];
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       //二维数组需要两个循环
       //提醒学生一维字符数组输入时可以怎么样
       cin>>str[i];
   }
   char s[85];
   cin>>s;
   for(int i=0;i<n;i++)
   {
       if(strcmp(str[i],s)==0)
       {
           cout<<i+1;
           return 0;
       }
  }
   return 0;
}
