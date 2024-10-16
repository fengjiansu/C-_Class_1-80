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
最大公约数（Greatest Common Divisor, GCD）是指两个或多个整数的共同因数中最大的那个数。

例如：12 和 18 的公约数是 1, 2, 3, 6，其中最大的公约数是 6。所以，GCD(12, 18) = 6。
用处：
简化分数：将 18/24 化简为 3/4，需要求 18 和 24 的最大公约数 GCD(18, 24) = 6。
求解数学问题：在数论中，求解两个数的最大公约数帮助我们解决很多问题，比如约分、同余问题、最小公倍数等。 
两个整数 a 和 b（a > b）的最大公约数 GCD(a, b) = GCD(b, a % b)。

即：

求 a 和 b 的 GCD，可以转化为求 b 和 a % b 的 GCD。
当 a % b == 0 时，b 就是最大公约数。
算法演示
假设要求 GCD(48, 18)：

48 ÷ 18 = 2 余 12，所以 GCD(48, 18) = GCD(18, 12)。
18 ÷ 12 = 1 余 6，所以 GCD(18, 12) = GCD(12, 6)。
12 ÷ 6 = 2 余 0，所以 GCD(12, 6) = 6。
最终答案：GCD(48, 18) = 6。

*/

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
