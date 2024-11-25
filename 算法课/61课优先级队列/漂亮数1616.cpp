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

bool fun(int n)
{
    /* 
     if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
     */
    vector<int> f={2,3,5};

    for(auto &it:f)
    {
        while(n%it==0) n/=it;
    }
    return n==1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    unordered_set<ll> s;
    vector<int> v = {2,3,5};
    s.insert(1);
    pq.push(1);
    ll res = 0;
    for(int i=0;i<1500;i++)
    {
        ll x = pq.top();pq.pop();
        res = x;
        for(auto &it:v)
        {
            ll y = x*it;
            if(!s.count(y))
            {
                s.insert(y);
                pq.push(y);
            }
        }
        
    }
    cout<<res;
    return 0;
}
