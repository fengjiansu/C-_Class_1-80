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

bool is_int(double x)
{
    return fabs(x-round(x)) < 1e-9;
}

int fun(int n)
{
    for(int p = log2(n);p>=2;p--)
    {
        double x = pow(n,1.0/p);
        if(is_int(x))
        {
            // round ����һ�� double ���͵�ֵ������Ը����������������룬���������һ���ǳ����������
            long long xx = round(x);
            if(pow(xx,p)==n)
            return p;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}
/* 

#include <iostream>
#include <vector>
#include <map>

// ŷ������㷨�����Լ��
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// �� n �����������ֽ⣬��������������ָ��
std::map<int, int> primeFactorization(int n) {
    std::map<int, int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

// �ҵ����� p
int findLargestP(int n) {
    std::map<int, int> factors = primeFactorization(n);
    std::vector<int> exponents;

    // �ռ�������������ָ��
    for (const auto& factor : factors) {
        exponents.push_back(factor.second);
    }

    // ������ָ�������Լ��
    int result = exponents[0];
    for (int i = 1; i < exponents.size(); ++i) {
        result = gcd(result, exponents[i]);
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    int p = findLargestP(n);
    std::cout<< p << std::endl;

    return 0;
}


 */