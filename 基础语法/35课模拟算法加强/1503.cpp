/* 
����һ��1\sim n1?n�����к�һ��˫�˶��У���ǰ��������ȡ�������е����֣�Ȼ������԰�ȡ�������ֲ��뵽˫�˶��е�ͷ������β����������������ֺ�˫�˶������ֵ�����С�����С�

����
��һ������n��n\le100n��100���ڶ�����������n����������֤��int��Χ�ڣ�

���
����ֵ�����С��˫�˶���

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        // ���˫�˶���Ϊ�գ�ֱ�Ӳ���ͷ��
        if (dq.empty()) {
            dq.push_back(num);
        } else {
            // �Ƚϲ���ͷ����β����Ч����������ʹ�ֵ����С����һ��
            if (num <= dq.front()) {
                dq.push_front(num);
            } else {
                dq.push_back(num);
            }
        }
    }

    // ���˫�˶����е�Ԫ��
    for (int i : dq) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
