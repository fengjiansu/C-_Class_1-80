/* 
D.�ȶ�����
����

����һ������,һ��ת���ǽ�һ����������������������г��ֵĴ�����

����{2,1,1,4,3,1,2}��,2����2��,1����3��,3��4����1��,��ô������н���
һ��ת��֮��ͱ����{2,3,3,1,1,3,2},ͬ��,��������ת������{2,3,3,2,2,3,2},����
����ת������{4,3,3,4,4,3,4}��֮��������оͲ��ᷢ���仯�ˡ�

����һ������,������ȶ�֮�����������ô���ġ�

����

������n(n��1000),Ȼ������һ������n��������,��֤ÿ������n

���

�������ȶ��������
����
����
7
2 1 1 4 3 1 2
���
4 3 3 4 4 3 4
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

// ʹ��Ͱ�������������е�ת��
vector<int> transform(const vector<int>& seq, int n) {
    vector<int> bucket(n + 1, 0);  // ����Ͱ���飬��СΪ n+1����ʼֵΪ 0
    vector<int> result(seq.size());

    // ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int num : seq) {
        bucket[num]++;
    }

    // ����ת���������
    for (int i = 0; i < seq.size(); i++) {
        result[i] = bucket[seq[i]];
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);

    // ��������
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    // ���Ͻ���ת����ֱ�������ȶ�
    while (true) {
        vector<int> new_seq = transform(seq, n);

        // ��鵱ǰ�����Ƿ��ȶ�
        if (new_seq == seq) {
            break;
        }

        // ���µ�ǰ����
        seq = new_seq;
    }

    // ����ȶ��������
    for (int i = 0; i < n; i++) {
        cout << seq[i] << " ";
    }

    return 0;
}
