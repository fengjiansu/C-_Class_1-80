/* 
��Ŀ����

(1066)��ŵ����

�ں�ŵ��������,���ǰ�������������ΪA,B,C,�����Ӵ��ϵ��±��Ϊ1~n�������n����
�Ӵ�A�����Ƶ�C�������ٴ����Ĳ������衣
����
һ����n(1��n��10)��
���
��������,��A->1->B,��ʾ�ѱ��1�����Ӵ�A�����Ƶ�B���ӡ�
��������
2
�������
A->1->B
A->2->C
B->1->C
 */
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
// source src  destination des
void hanoi(int n, char src, char des, char help) {
    if (n == 1) {
        // ���������ֻʣһ�����ӣ�ֱ���ƶ�
        cout << src << "->" << n << "->" << des << endl;
        return;
    }

    // 1. �Ƚ� n-1 �����Ӵ� A �Ƶ� B������ C
    hanoi(n - 1, src, help, des);

    // 2. ���� n �����Ӵ� A �Ƶ� C
    cout << src << "->" << n << "->" << des << endl;

    // 3. �ٽ� n-1 �����Ӵ� B �Ƶ� C������ A
    hanoi(n - 1, help, des, src);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* 
    �ֽ����⣺

�� n-1 �����Ӵ����� A �Ƶ����� B���������� C����
���� n �����Ӵ����� A �Ƶ����� C��
�� n-1 �����Ӵ����� B �Ƶ����� C���������� A����
�ݹ�����

����ÿ�������⣬�ݹ�ؽ����ֱ��ֻʣһ�����ӿ���ֱ���ƶ���
�ϲ������

ÿ�εݹ����ʱ����ƶ����裬���յõ��������ƶ����̡�
     */

    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
