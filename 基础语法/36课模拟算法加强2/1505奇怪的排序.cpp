/*********************************
F. 奇怪的排序
描述
给定一个长度为n的排列a。

我们用以下方法排序：

我们定义一个函数f(i)，作用为如果 ai>a i+1，那么就交换ai和ai+1
?

对于第i次操作，如果i是奇数，则执行f(1),f(3),...,f(n-2)。否则执行f(2),f(4),...,f(n-1)。

请求出：多少次操作后，这个数列是递增的？

输入
第一行输入n，表示序列长度，保证n≤999，并且n为奇数。

第二行输入n个数，表示这个排列

输出
输出需要的操作次数，如果一开始排序就是完成的，输出0
样例
输入
7
4 5 7 1 3 2 6
输出
5
***********************************/
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
// 判断数组是否已经有序
bool is_sorted(const vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int operation_count = 0;

    // 如果一开始数组就是有序的，输出0
    while (!is_sorted(a)) {
        operation_count++;

        if (operation_count % 2 == 1) {
            // 奇数次操作：处理f(1), f(3), ..., f(n-2)
            for (int i = 0; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        } else {
            // 偶数次操作：处理f(2), f(4), ..., f(n-1)
            for (int i = 1; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        }
    }

    // 输出需要的操作次数
    cout << operation_count << endl;
    return 0;
}
