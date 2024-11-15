#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int max_sum; // 全局变量，存储最大连续和

// 递归函数，返回以位置 n 为结尾的最大连续和
int fun(vi& v, int n) {
    if (n == 0) return v[0];
    
    // 递归求以 n-1 结尾的最大和，并与当前元素 v[n] 相加
    int max_end_here = max(v[n], fun(v, n - 1) + v[n]);
    
    // 更新全局最大连续和
    max_sum = max(max_sum, max_end_here);
    
    return max_end_here;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vi v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    // 初始化最大和为第一个元素
    max_sum = v[0];
    
    // 调用递归函数，从第 n-1 个元素开始计算
    fun(v, n - 1);
    
    cout << max_sum << endl;
    return 0;
}
