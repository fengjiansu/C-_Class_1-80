/*********************************
B. ����
����
��Ҫ��n��0��n��1���г�һ�У�Ҫ���������ĸ�λ�ã������ҵ�0��������Ҫ���ڵ���1�������������м������з�����

����
������n��1��n��100����

���
������ t �� 100 ȡģ��Ľ����

����
����
2
���
2
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

const int MOD = 100;  // ģ��



// ���㿨���������� MOD ȡģ
int catalan(int n) {
    // ��ʼ��������������
    vector<int> catalan(n + 1);
    catalan[0] = catalan[1] = 1;
    
    // ���Ƽ��㿨������
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]) % MOD;
        }
    }
    
    // ���ؽ��
    return catalan[n];

    return 0;
}

int main() {
    int n;
    cin >> n;
    
    // ���㿨�������� MOD ȡģ��Ľ��
    cout << catalan(n) << endl;

    return 0;
}
