/*
题目描述

(1644)是否存在两倍数

先给出一个整数n,接下来给出n个整数数字ai(这是一个大数组)。若这n个整数存在一个
数字是另一个数字的两倍,则输出YES,否则输出NO(1<n,ai≤10000)。
输入
第一行一个整数数字n,表示接下来整数的个数。
第二行共n个整数,需要依次判断是否存在两倍数。
输出
根据题目要求输出YES或NO。

输入样例
5
13479

输出样例
NO

思路1:嵌套循环
思路2:开桶
遍历后不存在,输出NO。
一旦找到两倍数,输出YES。
-- “标记变量法”
 */
#include <bits/stdc++.h>

int a[10005];
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[t]++;
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] && a[i * 2])
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
