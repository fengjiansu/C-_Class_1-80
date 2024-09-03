/*

由于大家都很喜欢喵，所以Keeper Chen开了一家店，大家都可以来看喵，为了缓解生活压力，需要门票25喵币。

于是每天都有同学排队拿着喵币来看喵，喵币共有三种面额，分别是25，50，100。

但是今天很不巧，Keeper Chen出门去店里忘记带钱liao，这就意味着开始时他手里是木有喵币进行找钱的。

这里规定每个排队的同学都只能自己买自己一个人的票，并且不允许破坏原始顺序买票，如果Keeper Chen遇到一个木有办法找钱的同学，则该同学和他后面的同学都不能进店看喵了，好可怜哦。

然后请问今天Keeper Chen的店里能进来几个同学看喵。

输入
第一行包含一个整数N，代表排队的同学人数。

第二行是N个数a_ia
i
?
 ??，a_ia
i
?
 代表排在第ii位的同学拿的喵币的面额。N\le100000N≤100000

输出
输出一行包含一个整数，代表Keeper Chen的店里今天能进来看喵的同学人数。
 */

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int count_25 = 0, count_50 = 0; // 记录持有的25喵币和50喵币数量
    int customers = 0; // 能进店的同学数量

    for (int i = 0; i < n; i++) {
        if (coins[i] == 25) {
            count_25++;
            customers++;
        } else if (coins[i] == 50) {
            if (count_25 > 0) {
                count_25--;
                count_50++;
                customers++;
            } else {
                break; // 无法找零
            }
        } else if (coins[i] == 100) {
            if (count_50 > 0 && count_25 > 0) {
                count_50--;
                count_25--;
                customers++;
            } else if (count_25 >= 3) {
                count_25 -= 3;
                customers++;
            } else {
                break; // 无法找零
            }
        }
    }

    cout << customers << endl;
    return 0;
}
