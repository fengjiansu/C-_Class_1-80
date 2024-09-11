/*********************************
A. 斐波那契数列的第1001项
描述
输出斐波那契数列的第1001项。第一项为1，第2项为1。

第三项开始，每一项等于前两项之和。
输入
无

输出
输出一个数值，表示斐波那契数列第1001项
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
// 高精度加法函数，将两个高精度数相加，结果保存在 result 中
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;  // 初始时没有进位，carry 为 0
    int max_size = max(a.size(), b.size());
    
    // 从低位到高位逐位相加
    for (int i = 0; i < max_size || carry; ++i) {
        int sum = carry;  // 首先加上上一轮的进位
        
        // 如果当前位数小于 a 的长度，取 a 的当前位
        if (i < a.size()) sum += a[i];
        
        // 如果当前位数小于 b 的长度，取 b 的当前位
        if (i < b.size()) sum += b[i];
        
        // 计算当前位的值，并存入结果
        result.push_back(sum % 10);  // 只保留个位数
        
        // 更新进位
        carry = sum / 10;  // 进位是 sum 的十位部分
    }
    return result;
}

// 打印高精度数
void print(const vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1001;  // 要计算的斐波那契数列项数

    // 初始化斐波那契数列的前两项
    vector<int> fib1(1, 1);  // 第1项 1
    vector<int> fib2(1, 1);  // 第2项 1

    // 计算第3项到第1001项
    for (int i = 3; i <= n; ++i) {
        vector<int> fib_next = add(fib1, fib2);  // 高精度相加
        fib1 = fib2;  // 更新前两项
        fib2 = fib_next;
    }

    // 输出第1001项斐波那契数列的值
    print(fib2);
    return 0;
}
