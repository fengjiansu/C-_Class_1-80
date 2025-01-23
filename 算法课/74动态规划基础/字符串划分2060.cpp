#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)
/* 
题目要求将字符串划分成尽量少的回文子串。因此，我们的目标是：

找到一种划分，使得划分出的子串数量最少且每个子串是回文。
目标本质是最小化划分次数，这暗示我们需要定义一个关于划分次数的状态。
2. 思考“子问题”
要解决完整问题，可以通过将问题拆分为子问题来实现：

假设字符串是 s[0..n-1]，我们可以将其划分为两部分：
左部分： s[0..j-1]
右部分： s[j..i-1]
如果右部分 s[j..i-1] 是回文，那么问题的最优解就是左部分的最优解加上 1（当前的这一划分）。
这说明：

**子问题的解可以用更小子问题的解来构造，**从而具备“最优子结构”性质。

3. 状态定义
通过上述分析，我们可以定义状态：

dp[i] 表示前 i 个字符（即 s[0..i-1]）最少可以划分成的回文子串数量。
这一步是基于问题目标（划分次数）和子问题结构定义的。
关键点：
为什么是前 i 个字符？
因为这是自然的划分方式，可以逐步扩展问题规模。
为什么用最少划分次数作为状态？
这是问题的直接目标。

4. 状态转移分析
有了状态定义后，需要考虑如何通过更小的子问题得到当前状态。

如果子串 s[j..i-1] 是回文：
那么 s[0..i-1] 的最优划分数是 dp[j] + 1。
其中，dp[j] 是前 j 个字符的最优解，加上当前回文子串的划分。
因此：

?
 {dp[j]+1∣s[j..i-1]?是回文}
起点与边界：
空字符串不需要划分，dp[0] = 0。

 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
