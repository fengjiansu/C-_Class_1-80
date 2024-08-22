/*
题目描述



(1802) Napoleon Cake

Arkady想要做蛋糕。这个蛋糕有n层,他计划在第i层放ai的奶油,这些奶油会浸湿下面(包括第i层)的ai层,
他想知道,他做出来的蛋糕的每一层是否有奶油。
输入
多组测试数据,第一行输入t代表测试数据组数,接下来每一组测试数据输入n代表蛋糕的层数,接下来一行n
个数代表ai,其中:t≤200,1≤n≤2×105,0≤ai≤n,保证所有测试数据的n之和不超过2×105。
输出
对于每组测试数据,输出一行n个数,每个数为0或1,分别代表第i层是否有奶油。
输入样例
3
6
0 3 0 0 1 3
10
0 0 0 1 0 5 0 0 0 2
3
000
输出样例
1 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 0 0

 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // 测试数据组数
    cin >> t;
    while (t--)
    {
        int n; // 蛋糕层数
        cin >> n;
        vector<int> a(n); // 存储每层奶油的数量
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // 对于数列a 下标从0开始a[i]表示能从 第i - a[i]到 a[i]
        // 对这个区间加1
        vector<int> b(n,0);
        for(int i = 0; i < n; i++)
        {
            int l = max(i - a[i]+1,0);
            //注意右端点也可能超范围
            int r = i;
            //int r = min(i+1,n-1);
            b[l] += 1;
            if(r+1 < n)
            {
                b[r+1] -= 1;
            }
            
        }
        /* 
        0 0 0 0 0 0
        2 -1 -1
         */
        int sum = 0;
        for(int i = 0; i <n; i++)
        {
            sum += b[i];
            if(sum == 0) cout<<0<<" ";
            else cout<<1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[200005], b[200005];

void solve() {
    cin >> n;
    // 重置 b 数组，确保每次多组数据清空
    for (int i = 1; i <= n; i++) b[i] = 0;

    // 读取输入并计算最左影响范围
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i] + 1; // 表示当前层的最左影响范围
    }

    int left_bound = 200000; // 初始化一个较大的范围
    // 从后往前遍历，更新最左影响范围
    for (int i = n; i >= 1; i--) {
        left_bound = min(left_bound, a[i]); // 取最左的范围
        if (left_bound <= i) { // 如果当前层在影响范围内
            b[i] = 1; // 标记为被覆盖
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

 */