/* 
一家电信公司计划建设一些全新的5G信号基站，目标是覆盖一个城市中的部分小区。已知城市中有N个小区，每个小区的形状可视为一个长方形，大小为Hi * Wi。

公司计划安装的基站的信号发射强度可以根据情况调整。若强度P（P为整数）大于等于某小区区域较长的边的一半，则视为可以覆盖该小区。为了方便起见，所有基站的信号强度必须一致。

现在公司希望你帮忙计算，若需保证至少有K个小区都能被一个基站覆盖，信号基站需设置的最小信号发射强度是多少？

例如，有三个小区，其区域大小分别是2*3、3*5、5*7，K=2，则强度最少设为3才能保证可以至少覆盖前两个小区。

输入
第一行，两个用空格隔开的正整数N和K（1 ≤ K ≤ N ≤ 10^5），表示小区总数量和基站要覆盖的小区数量。

接下来的N行，每行包含用空格隔开的两个正整数Hi和Wi（1 ≤ Hi, Wi ≤ 10^5），表示第i个小区的两个边的长度。

输出
一个整数，表示可保证至少有K个小区被信号覆盖的基站的最小信号发射强度P。

 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断信号强度 p 是否能覆盖至少 k 个小区
bool is_covered(int p, const vector<pair<int, int>>& sizes, int k) {
    int count = 0;
    for (const auto& size : sizes) {
        int h = size.first, w = size.second;
        // 直接用整数计算，避免浮点数精度问题
        if (p * 2 >= max(h, w)) {
            count++;
            if (count >= k) { // 提前返回优化
                return true;
            }
        }
    }
    return count >= k;
}

int main() {
    // 输入处理
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> sizes[i].first >> sizes[i].second;
    }

    // 二分查找信号强度 P
    int low = 1;
    int high = 0;

    // 计算最大可能的信号强度（每个小区的最大边的一半）
    for (const auto& size : sizes) {
        high = max(high, (max(size.first, size.second) + 1) / 2);
    }

    int result = high;

    // 二分查找
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_covered(mid, sizes, k)) {
            result = mid;    // 记录当前可行的 P
            high = mid - 1;  // 尝试更小的 P
        } else {
            low = mid + 1;   // 尝试更大的 P
        }
    }

    // 输出结果
    cout << result << endl;

    return 0;
}