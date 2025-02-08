#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 /* 
 
 
  */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    
    // b[i] 表示最终盒子 i 保留的糖果数
    vector<long long> b(n, 0);
    // 第 1 个盒子最多能保留 min(a[0], x) 颗
    b[0] = min(a[0], x);
    // 从第 2 个盒子开始（下标 1），根据前一个盒子的保留数确定当前盒子的上界
    for (int i = 1; i < n; i++){
        b[i] = min(a[i], x - b[i-1]);
    }
    
    long long sum_b = 0;
    for (int i = 0; i < n; i++){
        sum_b += b[i];
    }
    
    // 吃掉的糖果数 = 原有总数 - 最多能保留的糖果数
    cout << total - sum_b << "\n";
    return 0;
}
