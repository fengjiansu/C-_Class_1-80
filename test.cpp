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
	vector<ll> a(21,1);
        vector<ll> s(21,0);
        map<ll,ll> mp;
        REP(i,1,21)
        {
            s[i] = s[i-1]+a[i];
            mp[s[i]] = i+1;
        }
		RFOR(x,s)
		{
			cout<<x<<" ";
		}
	return 0;
}
