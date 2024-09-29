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
    int a[85] = {};
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    double avg = sum * 1.0 / n;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < avg)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
