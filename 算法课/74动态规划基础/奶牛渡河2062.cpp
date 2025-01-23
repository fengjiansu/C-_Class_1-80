#include <bits/stdc++.h>
using namespace std;
/* 
����ϣ�������� 
?
N ͷţ�Ӻӵ�һ���˵��԰�����ÿ�ι��ӻ�غӶ������� FJ ��ľ���ϡ�

�ؼ������������һ�ν���ţ�˵��԰�ʱ��FJ ������԰�ľ���ٻ��ص�ԭ�����Ա��ʣ�µ���ţ�������һ�ΰ�ʣ����ţ�˹�ȥ��Ͳ����ٻ�����

�� dp[i] ��ʾ���ڽ� ? ͷţ�˵��԰�������ľ����ʱ�����ڡ�����������Ҳ����׼���ٴ�����ţ��ȥ����������ʱ��**��

�� i=0����û��ţ�ڶ԰���ʱ��FJ ��ľ������ԭ������dp[0]=0.




 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // ǰ׺������ pre[i] = M_1 + M_2 + ... + M_i
    // pre[0] = 0
    vector<long long> pre(N+1, 0LL);
    for (int i = 1; i <= N; i++) {
        long long Mi;
        cin >> Mi;
        pre[i] = pre[i-1] + Mi;
    }

    // �����kͷţ���ӵ�ʱ�� T(k) = M + (M_1 + ... + M_k) = M + pre[k]
/*     auto T = [&](int k){
        return (long long)M + pre[k];
    }; */

    // dp[j]��ʾ��jͷţ�͵��԰���ľ���Ѿ��ص�ԭ������Сʱ��
    vector<long long> dp(N+1, LLONG_MAX);
    dp[0] = 0;

    // �𽥼���dp[1]~dp[N]
    for(int i= 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            // ���δ�jͷţ��iͷţ����Ҫ����ʱ��T(i-j)
            // ���j < N��˵����Ҫ������ʣ����ţ����Ҫ���ϻ���ʱ��T(0) = M
            long long cost = dp[j] + pre[i-j]+M;
            if(j< N) cost += M;  // FJ���Է���ʱ��

            dp[i] = min(dp[i], cost);
        }
    }

    // dp[N]��������ţ�������Ҳ�����Ҫ����ʱ����С��ʱ��
    cout << dp[N] << "\n";

    return 0;
}
