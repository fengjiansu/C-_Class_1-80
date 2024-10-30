#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RFOR(it, c) for (auto &it : c)
vector<pair<ll, bool>> vp;
bool check(ll d)
{
    for (auto &seg : vp)
    {
        ll f = seg.F;     // ��Ⱦ�εĳ���
        ll g = 2 * d + 1; // ������Χ
        if (seg.S)        // �߽��Ⱦ��
        {
            if (g > 2 * f - 1)
                return false;
        }
        else // �Ǳ߽��Ⱦ��
        {
            if (g > f)
                return false;
        }
    }
    return true;
}

int main()
{
    ll N;
    cin >> N;
    string str;
    cin >> str;
    /*
    Ԥ����

��������ַ��� s ĩβ���һ�� '0'�����㴦��
�����ַ��� s���������� '1' �μ�¼���������� v �����С�
v �е�ÿ��Ԫ����һ�� pair<int, int>�����У�
first ��ʾ���� '1' �εĳ��� f��
second ��ʾ�ö��Ƿ����ַ����ı߽磨1 ��ʾ�ڱ߽磬0 ��ʾ���ڣ�
     */
    str += '0';
    ll cnt = 0;
    REP(i, 0, N + 1)
    {
        if (str[i] == '1')
        {
            cnt++;
        }
        else
        {
            bool atBoundary = (i - cnt == 0) || (i == N);
            vp.PB(MP(cnt, atBoundary));
            cnt = 0;
        }
    }
    sort(vp.begin(), vp.end());
    ll l = 0, r = vp[0].F - 1; // �������� ?��󲻳�����̸�Ⱦ�εĳ��ȼ�һ�������޷�������̵ĸ�Ⱦ�Ρ�
    ll res = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    // ������С��ʼ��Ⱦ������
    ll ans = 0;
    if (res == -1)
    {
        // �޷��������и�Ⱦ��
        cout << -1 << endl;
        return 0;
    }
    else
    {
        ll g = 2 * res + 1;
        for (auto &seg : vp)
        {
            ll f = seg.F;                // ��Ⱦ�γ���
            ll needed = (f + g - 1) / g; // �ȼ��� ceil(1.0 * f / g)
            ans += needed;
        }
        cout << ans << endl;
    }

    return 0;
}
