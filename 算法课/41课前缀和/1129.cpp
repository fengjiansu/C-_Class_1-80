/* 
题目描述

(1129)最大连续和

输入一个长度为n的整数序列A1,A2,…,An,求最大连续和。换句话说,要找到1≤i≤j
≤n,使得Ai+Ai+1+ ... +Aj尽量大。

输入
第一行输入序列长度n,n≤105。第二行依次输入n个整数(范围-1000~1000)。

输出
一个整数,最大连续和。

输入样例
8
1 -3 7 -5 8 -3 -2 6

输出样例
11
 */
#include <bits/stdc++.h>

using namespace std;
int a[100005];
int pre[100005];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    pre[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
/* 
 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            sum += pre[j] - pre[i-1];
        }
    }
 */

      int maxSum = pre[0];  // 最大和
    int minSum = 0;       // 前缀和的最小值（初始为0）

    for (int j = 0; j < n; j++) {
        maxSum = max(maxSum, pre[j] - minSum); //每次计算 pre[j] - minSum，这个差值表示以 j 结尾的最大连续子数组和。
        minSum = min(minSum, pre[j]);
    }

    cout << maxSum << endl;
    return 0;
}
