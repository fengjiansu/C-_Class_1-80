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
    int m, n;
    cin >> m >> n;
    //stack��queue������ͨ���±�ֱ�ӷ���,������deque
    deque<int> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int toy;
        cin >> toy;
        bool found = false;
        for (int j = 0; j < q.size(); j++)
        {
            if (q[j] == toy)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cnt++;
            if (q.size() == m)
            {
                q.pop_front();
            }
            // ����������Ҷ�
            q.push_back(toy);
        }
    }
    cout << cnt;

    return 0;
}
