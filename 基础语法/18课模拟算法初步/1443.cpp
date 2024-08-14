/* 
题目描述

(1443)补充粉笔

一个班级有n个学生,编号1-n,从1号开始每个学生会依次回答问题,当第n个回答完后,
又会从1号开始。老师的粉笔盒里有k只粉笔,第i个同学回答问题会消耗掉ai只粉笔,如果
这时ai大于剩余的粉笔,则这个学生需要补充粉笔,输出第一个需要补充粉笔的学生的编
号。

输入
第一行两个正整数n、k;第二行n个数a1,a2, .. ,an (1≤n,ai≤105,1≤k≤109)。

输出
一个数表示答案,即第一个需要补充粉笔的学生的编号。

输入样例
3 22
515

输出样例
1
 */
#include <bits/stdc++.h>

using namespace std;

int a[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int j = 0;
    while (sum<=k)
    {
        sum+=a[j];
        j++;
        j = j%n;
    }
    cout<<j;
   return 0;
}
