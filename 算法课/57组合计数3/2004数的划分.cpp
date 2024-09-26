/*********************************
A. 蜜蜂路线
描述
一只蜜蜂在下图所示的数字蜂房上爬动,已知它只能从标号小的蜂房爬到标号大的相邻蜂房,现在问你：蜜蜂从蜂房 1 开始爬到蜂房 n，有多少种爬行路线？ 

输入
输入 n 的值（1≤n≤50）。

输出
爬行有多少种路线。

样例
输入
14
输出
377
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // 创建数组保存到达每个蜂房的路径数
    ll dp[51];  // 因为 n 最大到 50，所以创建大小为 51 的数组
    
    // 初始化前两项
    dp[1] = 1;  // 蜂房1的路线数
    dp[2] = 1;  // 蜂房2的路线数
    
    // 通过递推关系求解后续的路径数
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    // 输出到达第 n 号蜂房的路线数
    cout << dp[n] << endl;
    
    return 0;
}
