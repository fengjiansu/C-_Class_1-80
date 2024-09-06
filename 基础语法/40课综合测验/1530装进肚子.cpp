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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n), diff(n);
    
    // 输入 a 数组 (早上吃的甜蜜值)
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 输入 b 数组 (晚上吃的甜蜜值)
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // 计算甜蜜值差 diff[i] = a[i] - b[i]
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    // 将巧克力按照甜蜜值差值排序
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }
    
    sort(idx.begin(), idx.end(), [&](int i, int j) {//lambda 表达式 
        return diff[i] > diff[j];  // 根据差值从大到小排序
    });
    
    // 计算最大甜蜜值
    long long max_sweetness = 0;
    
    // 选择前 k 个巧克力在早上吃
    for (int i = 0; i < k; i++) {
        max_sweetness += a[idx[i]];
    }
    
    // 剩余的巧克力在晚上吃
    for (int i = k; i < n; i++) {
        max_sweetness += b[idx[i]];
    }
    
    // 输出最大甜蜜值
    cout << max_sweetness << endl;
    
    return 0;
}
/* 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义结构体存储每个巧克力的甜蜜值
struct Chocolate {
    int morning_sweetness;  // 早上的甜蜜值
    int evening_sweetness;  // 晚上的甜蜜值
    int diff;               // 甜蜜值差 a[i] - b[i]
};

// 自定义排序函数，按照甜蜜值差从大到小排序
bool compare(const Chocolate &a, const Chocolate &b) {
    return a.diff > b.diff;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Chocolate> chocolates(n);

    // 输入每个巧克力的早上甜蜜值
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i].morning_sweetness;
    }

    // 输入每个巧克力的晚上甜蜜值
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i].evening_sweetness;
        // 计算甜蜜值差
        chocolates[i].diff = chocolates[i].morning_sweetness - chocolates[i].evening_sweetness;
    }

    // 按照甜蜜值差从大到小排序
    sort(chocolates.begin(), chocolates.end(), compare);

    long long max_sweetness = 0;

    // 选择前 k 个巧克力在早上吃，剩下的巧克力在晚上吃
    for (int i = 0; i < k; i++) {
        max_sweetness += chocolates[i].morning_sweetness;
    }
    for (int i = k; i < n; i++) {
        max_sweetness += chocolates[i].evening_sweetness;
    }

    // 输出最大甜蜜值
    cout << max_sweetness << endl;

    return 0;
}


 */
