#include <bits/stdc++.h>
using namespace std;
/* 
我们希望把所有 
?
N 头牛从河的一侧运到对岸，且每次过河或回河都必须有 FJ 在木筏上。

关键：当不是最后一次将奶牛运到对岸时，FJ 必须独自把木筏再划回到原岸，以便接剩下的奶牛；而最后一次把剩余奶牛运过去后就不必再回来。

令 dp[i] 表示：在将 ? 头牛运到对岸，并且木筏此时返回在“出发岸”（也就是准备再带更多牛过去）的最少总时间**。

当 i=0（还没有牛在对岸）时，FJ 和木筏都在原岸，故dp[0]=0.




 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 前缀和数组 pre[i] = M_1 + M_2 + ... + M_i
    // pre[0] = 0
    vector<long long> pre(N+1, 0LL);
    for (int i = 1; i <= N; i++) {
        long long Mi;
        cin >> Mi;
        pre[i] = pre[i-1] + Mi;
    }

    // 计算带k头牛过河的时间 T(k) = M + (M_1 + ... + M_k) = M + pre[k]
/*     auto T = [&](int k){
        return (long long)M + pre[k];
    }; */

    // dp[j]表示把j头牛送到对岸且木筏已经回到原岸的最小时间
    vector<long long> dp(N+1, LLONG_MAX);
    dp[0] = 0;

    // 逐渐计算dp[1]~dp[N]
    for(int i= 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            // 本次从j头牛到i头牛，需要过河时间T(i-j)
            // 如果j < N，说明还要回来接剩余奶牛，需要加上回来时间T(0) = M
            long long cost = dp[j] + pre[i-j]+M;
            if(j< N) cost += M;  // FJ独自返回时间

            dp[i] = min(dp[i], cost);
        }
    }

    // dp[N]即所有奶牛都过河且不再需要返回时的最小总时间
    cout << dp[N] << "\n";

    return 0;
}
