#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        // ��������ֱ���ų�
        if (s.size() % i != 0)
            continue;
        bool flag = true;
        for (int j = 0; j < s.size(); j++)
        {
            // �����ǰ�ַ��͵�i���ַ���ͬ�����˳�ѭ��
            if (s[j] != s[j % i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
