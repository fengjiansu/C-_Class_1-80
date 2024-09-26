/*********************************
B. 矩阵
描述
你要将n个0和n个1排列成一行，要求无论在哪个位置，从左到右的0的数量都要大于等于1的数量，请问有几种排列方法？

输入
正整数n（1≤n≤100）。

输出
方案数 t 对 100 取模后的结果。

样例
输入
2
输出
2
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

const int MOD = 100;  // 模数



// 计算卡特兰数并对 MOD 取模
int catalan(int n) {
    // 初始化卡特兰数数组
    vector<int> catalan(n + 1);
    catalan[0] = catalan[1] = 1;
    
    // 递推计算卡特兰数
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]) % MOD;
        }
    }
    
    // 返回结果
    return catalan[n];

    return 0;
}

int main() {
    int n;
    cin >> n;
    
    // 计算卡特兰数对 MOD 取模后的结果
    cout << catalan(n) << endl;

    return 0;
}
