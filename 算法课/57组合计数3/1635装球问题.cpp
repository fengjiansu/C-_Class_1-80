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
#define REP(i, a, b) for (int i = a; i < b; i++)

const int MOD = 1e9 + 7;//10��9�η�+7
const int MAXN = 1005;

// ˹������ S(n, m)
long long S[MAXN][MAXN];
// P �������ڴ洢���������Ļ�����
long long P[MAXN][MAXN];

// ����˹������
void compute_sterling()
{
    // ��ʼ��˹������
    /* S(n,m)=S(n?1,m?1)+m?S(n?1,m)
    S(0,0)=1
    S(n,0)=0����?n>0
    S(0,m)=0����?m>0
    S(n,m)=0 ���?m>n?��?m<0
    S(n,n)=1 ��������?n��0
    S(n,1)=1 ��������?n��1
    */
    S[0][0] = 1;
    /* for(int i = 1; i < MAXN; ++i)
    {    S[i][0] = 0;//n>0,m=0
    }
    for(int j=1;j<MAXN;++j)
    {
        S[0][j] = 0;//n=0,m>0
    } */
    // n=0ʱ��Ϊ0,m=0ʱ��Ϊ0
    for (int n = 1; n < MAXN; ++n)
    {
        for (int m = 1; m <= n; ++m)
        {
            S[n][m] = (S[n - 1][m - 1] + m * S[n - 1][m] % MOD) % MOD;
        }
    }
}

// ������������������ͬ�ĺ��ӵķ�����
void compute_partitions()
{
    // ��ʼ�� P(n,m) =p(n,m-1)+P(n-m,m)
    /* 
    ��n=0ʱ  p(0,m) = 1//0 ������Է�Ϊ 1 �ַ������ջ��֣�
    ��m>nʱ   P(n,m)=P(n,n)
    
     */
    for(int j = 0; j < MAXN; ++j)
    {
        P[0][j] = 1; // 0 ������Է�Ϊ 1 �ַ������ջ��֣�
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

    // Ԥ����˹������
    compute_sterling();
    // Ԥ������������Ļ�����
    compute_partitions();

    // ��һ�ʴ𰸣�n �������������� m �����ӣ��޿պ�
    cout << S[n][m] << " ";

    // �ڶ��ʴ𰸣�n ����������������� m �����ӣ����пպ�
    cout << P[n][m] << endl;

    return 0;
}
