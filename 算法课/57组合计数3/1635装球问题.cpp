/*********************************
C. 装球问题
描述
（1）n个有区别的球放到m个相同的盒子中，要求无一空盒，不同的方案总数有多少种？（第二类斯特林数）

（2）n个无区别的球放到m个相同的盒子中，可以有空盒，不同的方案总数有多少种？

输入
输入n和m，n,m≤10^3
输出
一行用空格隔开输出两个小问的答案，答案对10^9+7取模
样例
输入
8 5
输出
1050 18
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
#define REP(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;//10的9次方+7
const int MAXN = 1005;

// 斯特林数 S(n, m)
long long S[MAXN][MAXN];
// P 数组用于存储无区别的球的划分数
long long P[MAXN][MAXN];

// 计算斯特林数
void compute_sterling()
{
    // 初始化斯特林数
    /* S(n,m)=S(n?1,m?1)+m?S(n?1,m)
    S(0,0)=1
    S(n,0)=0对于?n>0
    S(0,m)=0对于?m>0
    S(n,m)=0 如果?m>n?或?m<0
    S(n,n)=1 对于所有?n≥0
    S(n,1)=1 对于所有?n≥1
    */
    S[0][0] = 1;
    /* for(int i = 1; i < MAXN; ++i)
    {    S[i][0] = 0;//n>0,m=0
    }
    for(int j=1;j<MAXN;++j)
    {
        S[0][j] = 0;//n=0,m>0
    } */
    // n=0时都为0,m=0时都为0
    for (int n = 1; n < MAXN; ++n)
    {
        for (int m = 1; m <= n; ++m)
        {
            S[n][m] = (S[n - 1][m - 1] + m * S[n - 1][m] % MOD) % MOD;
        }
    }
}

// 计算无区别的球放入相同的盒子的方案数
void compute_partitions()
{
    // 初始化 P(n,m) =p(n,m-1)+P(n-m,m)
    /* 
    当n=0时  p(0,m) = 1//0 个球可以分为 1 种方案（空划分）
    当m>n时   P(n,m)=P(n,n)
    
     */
    for(int j = 0; j < MAXN; ++j)
    {
        P[0][j] = 1; // 0 个球可以分为 1 种方案（空划分）
    }
    for(int n = 1; n < MAXN; ++n)
    {
        for (int m = 1; m < MAXN; ++m)
        {
            if(m>n)
            {
                P[n][m] = P[n][m-1];
            }
            else
            {
                P[n][m] = (P[n][m - 1] + P[n - m][m]) % MOD;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // 预计算斯特林数
    compute_sterling();
    // 预计算无区别球的划分数
    compute_partitions();

    // 第一问答案：n 个有区别的球放入 m 个盒子，无空盒
    cout << S[n][m] << " ";

    // 第二问答案：n 个无区别的球放入最多 m 个盒子，可有空盒
    cout << P[n][m] << endl;

    return 0;
}
