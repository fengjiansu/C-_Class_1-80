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
// ʹ�ð�����˹����ɸ������������
vector<int> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false; // 0 �� 1 ��������
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int S;
    cin >> S;

    // ��ȡ����С�ڵ��� S ������
    vector<int> primes = sieve(S);

    int max_product = 0;

    // ���������ԣ��ҵ���Ϊ S �������ԣ�������˻�
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            if (primes[i] + primes[j] == S) {
                int product = primes[i] * primes[j];
                if (product > max_product) {
                    max_product = product;
                }
            }
        }
    }

    cout << max_product << endl;
    return 0;
}
