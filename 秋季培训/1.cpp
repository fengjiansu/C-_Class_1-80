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
    string f;
    if (s[0] == '0')
    {
        cout << s << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
        f = s;
        bool flag = 1;
        auto j = s.size() - 1;
        if(s[j]=='0')
        {
            f[j] = '1';
            cout<<f<<endl;
            return 0;
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                if (flag)
                {
                    f[i] = '1';
                    flag = 0;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (flag)
                {
                    f[i] = '0';
                    flag = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout<<f<<endl;
    return 0;
}
