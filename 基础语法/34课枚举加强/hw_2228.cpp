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

int n, a[1000], ma = 0;
bool isTriangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
        return true;
    else
        return false;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (isTriangle(a[i], a[j], a[k]))
                {
                    ma = max(ma, a[i] + a[j] + a[k]);
                }
            }
        }
    }

    if (!ma)
        cout << 0;
    else
        cout << ma;

    return 0;
}
