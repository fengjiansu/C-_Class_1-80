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
    ll k;
    cin >> n >> k;
    vector<ll> x(n);

    // ��������
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // �������������
    sort(x.begin(), x.end());

    ll ans = 0;
    int j = 0;

    // ˫ָ�����
    for (int i = 0; i < n; ++i) {
        // ���� j���ҵ��������� x[j] - x[i] <= k ��λ��
        while (j < n && x[j] - x[i] <= k) {
            ++j;
        }
        // �ۼ�������������������
        ans += (j - i - 1);
    }

    cout << ans << endl;
    return 0;
}
