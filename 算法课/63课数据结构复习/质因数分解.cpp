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


/* 
质因数分解（Prime Factorization）是将一个正整数表示为几个质数的乘积的过程。

质数：只能被 1 和自身整除的数，比如 2, 3, 5, 7, 11 等。
质因数：一个数的质因数是能整除它的质数。
举例：
36 的质因数分解为：
36 = 2^2 \times 3^2 ] 这里，2 和 3 是 36 的质因数，且指数分别为 2。

84 的质因数分解为：
84 = 2^2 \times 3^1 \times 7^1 ] 这里，2、3、7 都是质因数。

质因数分解的过程
假设要对一个数 n=84 进行质因数分解：

从最小的质数 2 开始：84÷2=42，所以 2 是一个质因数。
再次除以 2：
42÷2=21。
21 不能再被 2 整除，所以换下一个质数 3：
21÷3=7，所以 3 是一个质因数。
7 是质数，且只能被自身整除：
7÷7=1。
质因数分解完成：
84=2^2*3^1*7^1。

 */
map<int, int> fun(int n)
{
    map<int, int> res;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
            
        }
    }
    // n自身也要考虑
    if (n > 1)
    {
        res[n] = 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 84;
    map<int,int> res;
    res = fun(n);
    for(auto &it:res)
    {
        cout<<it.first<<":"<<it.second<<endl;
    }
    return 0;
}
