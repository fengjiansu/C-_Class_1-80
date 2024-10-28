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
const int N = 1e5+5;
bool fx[N];
bool fy[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll wx=n,wy=n;
	for(int i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		
		if(!fx[x])
		{
			wx--;
			fx[x] = true;
		}
		if(!fy[y])
		{
			wy--;
			fy[y] = true;
		}
		cout<<wx*wy<<" ";
	}
	return 0;
}
