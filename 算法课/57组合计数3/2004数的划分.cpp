/*********************************
A. �۷�·��
����
һֻ�۷�����ͼ��ʾ�����ַ䷿������,��֪��ֻ�ܴӱ��С�ķ䷿������Ŵ�����ڷ䷿,�������㣺�۷�ӷ䷿ 1 ��ʼ�����䷿ n���ж���������·�ߣ� 

����
���� n ��ֵ��1��n��50����

���
�����ж�����·�ߡ�

����
����
14
���
377
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // �������鱣�浽��ÿ���䷿��·����
    ll dp[51];  // ��Ϊ n ��� 50�����Դ�����СΪ 51 ������
    
    // ��ʼ��ǰ����
    dp[1] = 1;  // �䷿1��·����
    dp[2] = 1;  // �䷿2��·����
    
    // ͨ�����ƹ�ϵ��������·����
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    // �������� n �ŷ䷿��·����
    cout << dp[n] << endl;
    
    return 0;
}
