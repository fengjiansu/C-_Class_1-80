/* 
题目描述

(1072)最大的数

输入n,再输入n个整数,输出这n个整数中最大的数。
输入
第一行 输入一个整数n(n <= 100)。
第二行输入n个整数,用空格隔开,这些整数在区间(-2147483648,2147483647)。
输出
输出一个整数,表示最大的数。
输入样例
8
26387154
输出样例
8

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

// 递归函数，分治求解最大值
int findMax(const vector<int>& arr, int left, int right) {
    // 基准情况：如果数组只有一个元素，返回该元素
    if (left == right) {
        return arr[left];
    }

    // 找到中间点
    // 当 l 和 r 都是很大的正整数时，如果直接相加 (l + r)，
    //可能会导致整数溢出
    int mid = left + (right - left) / 2;

    // 递归计算左半部分和右半部分的最大值
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    // 返回两者中较大的一个
    return max(maxLeft, maxRight);
}
/* 
int findMax(int l,int r){


    if(r-l == 1) return a[l];
    int mid=(l+r)/2;
    int Imax=findMax(l,mid);
    int rmax=findMax(mid,r);
    return max(lmax,rmax);

}
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //用分治法的思想解决
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout<<findMax(v,0,n-1);
    return 0;
}
