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

int main() {
    ll h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    ll cnt = 0;
    REP(x1,1,h1)
    {
        REP(x2,1,h1)
        {
            REP(y1,1,h2)
            {
                REP(y2,1,h2)
                {
                    int x3 = h1 - x1 - x2;
                    int y3 = h2 - y1 - y2;
                    int z1 = w1-x1-y1;
                    int z2 = w2-x2-y2;
                    int z3 = w3 - x3 - y3;
                    if(x3>0 && y3>0 && z1>0 && z2>0 && z3>0)
                    {
                        if(z1+z2+z3==h3)
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
