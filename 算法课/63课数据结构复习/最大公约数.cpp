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
/* 
���Լ����Greatest Common Divisor, GCD����ָ�������������Ĺ�ͬ�����������Ǹ�����

���磺12 �� 18 �Ĺ�Լ���� 1, 2, 3, 6���������Ĺ�Լ���� 6�����ԣ�GCD(12, 18) = 6��
�ô���
�򻯷������� 18/24 ����Ϊ 3/4����Ҫ�� 18 �� 24 �����Լ�� GCD(18, 24) = 6��
�����ѧ���⣺�������У���������������Լ���������ǽ���ܶ����⣬����Լ�֡�ͬ�����⡢��С�������ȡ� 
�������� a �� b��a > b�������Լ�� GCD(a, b) = GCD(b, a % b)��

����

�� a �� b �� GCD������ת��Ϊ�� b �� a % b �� GCD��
�� a % b == 0 ʱ��b �������Լ����
�㷨��ʾ
����Ҫ�� GCD(48, 18)��

48 �� 18 = 2 �� 12������ GCD(48, 18) = GCD(18, 12)��
18 �� 12 = 1 �� 6������ GCD(18, 12) = GCD(12, 6)��
12 �� 6 = 2 �� 0������ GCD(12, 6) = 6��
���մ𰸣�GCD(48, 18) = 6��

*/

int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
