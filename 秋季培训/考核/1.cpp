/* 

小明是一位冒险者，在游戏中需要收集资源来升级装备。他目前已经收集了X单位的资源，而想要升级装备，需要达到Y单位资源。

每天，小明可以选择以下两种方式来收集资源：

普通采集：获得1单位资源。
强化采集：获得K单位资源，但只能在当前资源数量是K的整数倍时使用。
你需要帮助小明计算，最少需要多少天才能使资源数量达到Y。

例如，X=3，Y=11，K=2： 第一天，资源数量为3，只能选择普通采集，资源数量变为4； 第二天，选择强化采集，资源数量变为6； 依此类推，接下来每天都可以使用强化采集，到第五天达到采集目标。

输入
三个用空格隔开的正整数X、Y和K（1 ≤ X < Y ≤ 10^8 , 2 ≤ K < Y），表示小明当前的资源数量、目标资源数量，以及强化采集时可采集的资源数量。

输出
一个整数，表示小明最少需要花费的天数。
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long x, y, k;
    cin >> x >> y >> k;

    long long days = 0;
    while (x < y) {
        if (x % k == 0) {
            // 计算剩余距离通过 k 的步长到达 y 的天数
            days += (y - x + k - 1) / k; // 等价于 ceil((y - x) / k)
            break;
        } else {
            // 调整到下一个 k 的倍数
            long long days_to_adjust = k - (x % k);
            if (x + days_to_adjust > y) {
                // 如果调整超过目标 y，则逐个加1即可
                days += (y - x);
                break;
            }
            x += days_to_adjust;
            days += days_to_adjust;
        }
    }

    cout << days << endl;
    return 0;
}
改一下逻辑
#include <iostream>
using namespace std;

int main() {
    long long x, y, k;
    cin >> x >> y >> k;

    // 若已达到或超过目标
    if (x >= y) {
        cout << 0 << "\n";
        return 0;
    }

    long long days = 0;
    // 找到大于等于 x 的最小 k 的倍数
    long long next_multiple = ((x + k - 1) / k) * k;

    // 如果下一个 k 的倍数比 y 还大，那么直接用一日一格走到 y
    if (next_multiple > y) {
        days = y - x;
    } else {
        // 先走到下一个 k 的倍数
        days += (next_multiple - x);
        // 从这个 k 的倍数起，以 k 为步长跳到 y
        long long remain = y - next_multiple;
        days += (remain + k - 1) / k; // 相当于向上取整的除法
    }

    cout << days << "\n";
    return 0;
}
