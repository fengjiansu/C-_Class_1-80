/* 
题目描述

(1129)最大连续和

输入一个长度为n的整数序列A1,A2,…,An,求最大连续和。
换句话说,要找到1≤isj≤n,使得Ai+Ai+1+ …. +Aj尽量大。

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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

// 分治法求解最大连续和
int maxCross( vector<int>& arr, int left, int mid, int right) {
    // 从中间向左找最大和
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // 从中间向右找最大和
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    // 返回跨越中间的最大和
    return leftSum + rightSum;
}
// 不加& 会内存超限 因为每次调用都会开辟新的空间
int maxSum(vi& v, int l, int r)
{
    if (l == r)
    {
        return v[l];
    }
    int mid = l + (r - l) / 2;
    int maxLeft = maxSum(v, l, mid);
    int maxRight = maxSum(v, mid + 1, r);
    // 计算跨越中间的最大和
    int crossMax = maxCross(v, l, mid, r);
    /* 
    max({leftMax, rightMax, crossMax}) 这种用法是 C++11 及以上版本中 std::max 函数的重载版本，它可以接受一个初始化列表，用于比较多个值，并返回其中的最大值。

具体解释：
{leftMax, rightMax, crossMax} 是一个初始化列表，表示将这三个值放入一个容器中。
max 函数在接受初始化列表时，会遍历其中的所有元素，返回其中的最大值。
这种语法使得我们可以轻松比较多个值，而不需要嵌套的 max 函数调用。
     */
    return max({maxLeft, maxRight,crossMax});
}

int fun(vi& v, int l,int mid, int r)
{
    if(l == r) return v[l];
    fun(v, l, mid, mid);
    // 从中间向左找最大和
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += v[i];
        leftSum = max(leftSum, sum);
    }

    // 从中间向右找最大和
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += v[i];
        rightSum = max(rightSum, sum);
    }
    // 返回跨越中间的最大和
    return leftSum + rightSum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(n);
    REP(i, 0, n)
    {
        cin >> v[i];
    }
    cout<<maxSum(v, 0, n - 1);
    return 0;
}
