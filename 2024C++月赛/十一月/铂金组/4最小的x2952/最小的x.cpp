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
const int epison = 10e-6;
/*
(y+x)(y-x) = n
y+x =a
y-x = b;
x=a-y;
x= y-b;
y= (a+b)/2  x小  y也小
*/
set<int> se;
void fun(int n)
{
	REP(i,1,sqrt(n)+1)
	{
		if(n%i==0)
		{
			ll temp = i+n/i; //i就是a n/i就是b
			if(temp%2==0) //y是整数
			{
				se.insert(temp/2);
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll res = -1;
    fun(n);
    if(!se.empty())
    {
    	auto it = se.begin();
    	ll y = *it;
    	res = sqrt(y*y-n);
    }
     cout<<res<<endl;
    return 0;
}