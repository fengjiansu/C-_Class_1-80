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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RFOR(it,c) for(auto &it:c)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    REP(a,1,4)
    {
        REP(b,1,4)
        {
            REP(c,1,4)
            {
                REP(d,1,4)
                {
                    cout<<a<<b<<c<<d<<endl;
                }
            }
        }
    }
    return 0;
}
