/*********************************
A. 쳲��������еĵ�1001��
����
���쳲��������еĵ�1001���һ��Ϊ1����2��Ϊ1��

�����ʼ��ÿһ�����ǰ����֮�͡�
����
��

���
���һ����ֵ����ʾ쳲��������е�1001��
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
// �߾��ȼӷ��������������߾�������ӣ���������� result ��
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;  // ��ʼʱû�н�λ��carry Ϊ 0
    int max_size = max(a.size(), b.size());
    
    // �ӵ�λ����λ��λ���
    for (int i = 0; i < max_size || carry; ++i) {
        int sum = carry;  // ���ȼ�����һ�ֵĽ�λ
        
        // �����ǰλ��С�� a �ĳ��ȣ�ȡ a �ĵ�ǰλ
        if (i < a.size()) sum += a[i];
        
        // �����ǰλ��С�� b �ĳ��ȣ�ȡ b �ĵ�ǰλ
        if (i < b.size()) sum += b[i];
        
        // ���㵱ǰλ��ֵ����������
        result.push_back(sum % 10);  // ֻ������λ��
        
        // ���½�λ
        carry = sum / 10;  // ��λ�� sum ��ʮλ����
    }
    return result;
}

// ��ӡ�߾�����
void print(const vector<int>& num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        cout << num[i];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1001;  // Ҫ�����쳲�������������

    // ��ʼ��쳲��������е�ǰ����
    vector<int> fib1(1, 1);  // ��1�� 1
    vector<int> fib2(1, 1);  // ��2�� 1

    // �����3���1001��
    for (int i = 3; i <= n; ++i) {
        vector<int> fib_next = add(fib1, fib2);  // �߾������
        fib1 = fib2;  // ����ǰ����
        fib2 = fib_next;
    }

    // �����1001��쳲��������е�ֵ
    print(fib2);
    return 0;
}
