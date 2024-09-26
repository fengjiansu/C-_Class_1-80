/*********************************
C. װ������
����
��1��n�����������ŵ�m����ͬ�ĺ����У�Ҫ����һ�պУ���ͬ�ķ��������ж����֣����ڶ���˹��������

��2��n�����������ŵ�m����ͬ�ĺ����У������пպУ���ͬ�ķ��������ж����֣�

����
����n��m��n,m��10^3
���
һ���ÿո�����������С�ʵĴ𰸣��𰸶�10^9+7ȡģ
����
����
8 5
���
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
#define REP(i,a,b) for(int i=a;i<b;i++)

const int MOD = 1e9 + 7;
const int MAXN = 1005;

// ˹������ S(n, m)
long long S[MAXN][MAXN];
// dp �������ڴ洢���������Ļ�����
long long dp[MAXN][MAXN];

// ����˹������
void compute_sterling() {
    // ��ʼ��˹������
    S[0][0] = 1;
    for (int n = 1; n < MAXN; ++n) {
        for (int m = 1; m <= n; ++m) {
            S[n][m] = (S[n-1][m-1] + m * S[n-1][m] % MOD) % MOD;
        }
    }
}

// ������������������ͬ�ĺ��ӵķ�����
void compute_partitions() {
    // ��ʼ��
    for (int i = 0; i < MAXN; ++i) {
        dp[i][0] = 1; // 0 ������Է�Ϊ 1 �ַ������ջ��֣�
    }
    for (int n = 1; n < MAXN; ++n) {
        for (int m = 1; m <= n; ++m) {
            dp[n][m] = (dp[n-1][m-1] + dp[n-m][m]) % MOD;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Ԥ����˹������
    compute_sterling();
    // Ԥ������������Ļ�����
    compute_partitions();

    // ��һ�ʴ𰸣�n �������������� m �����ӣ��޿պ�
    cout << S[n][m] << " ";

    // �ڶ��ʴ𰸣�n ����������������� m �����ӣ����пպ�
    cout << dp[n][m] << endl;

    return 0;
}
