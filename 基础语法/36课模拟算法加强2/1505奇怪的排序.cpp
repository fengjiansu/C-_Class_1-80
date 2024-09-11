/*********************************
F. ��ֵ�����
����
����һ������Ϊn������a��

���������·�������

���Ƕ���һ������f(i)������Ϊ��� ai>a i+1����ô�ͽ���ai��ai+1
?

���ڵ�i�β��������i����������ִ��f(1),f(3),...,f(n-2)������ִ��f(2),f(4),...,f(n-1)��

����������ٴβ�������������ǵ����ģ�

����
��һ������n����ʾ���г��ȣ���֤n��999������nΪ������

�ڶ�������n��������ʾ�������

���
�����Ҫ�Ĳ������������һ��ʼ���������ɵģ����0
����
����
7
4 5 7 1 3 2 6
���
5
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
// �ж������Ƿ��Ѿ�����
bool is_sorted(const vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int operation_count = 0;

    // ���һ��ʼ�����������ģ����0
    while (!is_sorted(a)) {
        operation_count++;

        if (operation_count % 2 == 1) {
            // �����β���������f(1), f(3), ..., f(n-2)
            for (int i = 0; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        } else {
            // ż���β���������f(2), f(4), ..., f(n-1)
            for (int i = 1; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    swap(a[i], a[i + 1]);
                }
            }
        }
    }

    // �����Ҫ�Ĳ�������
    cout << operation_count << endl;
    return 0;
}
